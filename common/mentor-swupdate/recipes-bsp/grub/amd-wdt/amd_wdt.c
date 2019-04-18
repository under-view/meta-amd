/* amd_wdt.c - AMD Watchdog Driver and API for grub cfg & console */
/* 
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2019 Mentor Graphics, a Siemens business
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Author: Arsalan H. Awan <ArsalanHAwan@github>
 *  Email:  Arsalan_Awan@mentor.com
 */

#include <grub/types.h>
#include <grub/misc.h>
#include <grub/mm.h>
#include <grub/pci.h>
#include <grub/err.h>
#include <grub/dl.h>
#include <grub/extcmd.h>
#include <grub/i18n.h>
#include "amd_wdt.h"

#define PCI_VENDOR_ID_AMD		0x1022

//#define AMD_WDT_DEBUG

GRUB_MOD_LICENSE ("GPLv3+");

static struct
{
  grub_uint8_t *ptr;
  grub_uint8_t fired;
  int mapped;
  grub_uint32_t base;
  grub_pci_device_t dev;
} watchdog;

static int found = 0;

static void
writel (grub_uint32_t val, grub_uint8_t reg)
{
  watchdog.ptr[reg] = val & 0xff;
  watchdog.ptr[reg + 1] = (val >> 8) & 0xff;
  watchdog.ptr[reg + 2] = (val >> 16) & 0xff;
  watchdog.ptr[reg + 3] = (val >> 24) & 0xff;
}

static grub_uint32_t
readl (grub_uint8_t reg)
{
  return watchdog.ptr[reg] +
         (watchdog.ptr[reg + 1] << 8) +
         (watchdog.ptr[reg + 2] << 16) +
         (watchdog.ptr[reg + 3] << 24);
}

static void
amd_wdt_start (void)
{
  grub_uint32_t val;
  /* Start the watchdog timer */
  val = readl (AMD_WDT_CONTROL(0));
  val |= AMD_WDT_START_STOP_BIT;
  writel (val, AMD_WDT_CONTROL(0));
}

static void
amd_wdt_stop (void)
{
  grub_uint32_t val;
  /* Stop the watchdog timer */
  val = readl (AMD_WDT_CONTROL(0));
  val &= ~AMD_WDT_START_STOP_BIT;
  writel (val, AMD_WDT_CONTROL(0));
}

static void
amd_wdt_ping (void)
{
  grub_uint32_t val;
  /* Trigger/Ping watchdog timer */
  val = readl (AMD_WDT_CONTROL(0));
  val |= AMD_WDT_TRIGGER_BIT;
  writel (val, AMD_WDT_CONTROL(0));
}

static grub_uint16_t
amd_wdt_get_time (void)
{
  /* Read watchdog COUNT register */
  return readl (AMD_WDT_COUNT(0)) & AMD_WDT_COUNT_MASK;
}

static void
amd_wdt_set_time (grub_uint32_t t)
{
  if (t < AMD_WDT_MIN_TIMEOUT)
    t = AMD_WDT_MIN_TIMEOUT;
  else if (t > AMD_WDT_MAX_TIMEOUT)
    t = AMD_WDT_MAX_TIMEOUT;

  /* Write new timeout value to watchdog COUNT register */
  writel (t, AMD_WDT_COUNT(0));
}

static void
amd_wdt_enable (void)
{
  grub_uint8_t val;
  /* Enable watchdog timer */
  grub_outb(AMD_PM_WATCHDOG_EN_REG, AMD_IO_PM_INDEX_REG);
  val = grub_inb(AMD_IO_PM_DATA_REG);
  val |= AMD_PM_WATCHDOG_TIMER_EN;
  grub_outb(val, AMD_IO_PM_DATA_REG);
}

static void
amd_wdt_disable (void)
{
  grub_uint8_t val;
  /* Disable watchdog timer */
  grub_outb(AMD_PM_WATCHDOG_EN_REG, AMD_IO_PM_INDEX_REG);
  val = grub_inb(AMD_IO_PM_DATA_REG);
  val &= ~AMD_PM_WATCHDOG_TIMER_EN;
  grub_outb(val, AMD_IO_PM_DATA_REG);
}

static void
amd_wdt_set_resolution (grub_uint8_t freq)
{
  grub_uint8_t val;
  /* Set the watchdog timer resolution */
  grub_outb(AMD_PM_WATCHDOG_CONFIG_REG, AMD_IO_PM_INDEX_REG);
  val = grub_inb(AMD_IO_PM_DATA_REG);
  /* Clear the previous frequency setting, if any */
  val &= ~AMD_PM_WATCHDOG_CONFIG_MASK;
  /* Set the new frequency value */
  val |= freq;
  grub_outb(val, AMD_IO_PM_DATA_REG);
}

static void
amd_wdt_set_timeout_action (const char * action)
{
  grub_uint32_t val;
  val = readl (AMD_WDT_CONTROL(0));

  /*
  * Set the watchdog timeout action.
  *
  * If action is specified anything other than reboot or shutdown,
  * we default it to reboot.
  */
  if (grub_strncmp(action, "shutdown", 8) == 0)
    val |= AMD_WDT_ACTION_RESET_BIT;
  else
    val &= ~AMD_WDT_ACTION_RESET_BIT;
}

static grub_uint8_t
amd_wdt_check_fired (void)
{
  grub_uint32_t val;
  /* Read watchdog fired bit */
  val = readl (AMD_WDT_CONTROL(0));
  return val & AMD_WDT_FIRED_BIT;
}

static grub_err_t
grub_cmd_amd_wdt (grub_extcmd_context_t ctxt  __attribute__ ((unused)),
                      int argc, char **args)
{
  if (argc < 1)
    return grub_error (GRUB_ERR_BAD_ARGUMENT,
      N_("usage: amd-wdt <command>\ncommands: enable disable start stop ping getstatus gettime settime"));

  if (grub_strcasecmp (args[0], "enable") == 0)
    amd_wdt_enable ();
  else if (grub_strcasecmp (args[0], "disable") == 0)
    amd_wdt_disable ();
  else if (grub_strcasecmp (args[0], "start") == 0)
  {
    amd_wdt_start ();
    amd_wdt_ping ();
  }
  else if (grub_strcasecmp (args[0], "stop") == 0)
    amd_wdt_stop ();
  else if (grub_strcasecmp (args[0], "ping") == 0)
    amd_wdt_ping ();
  else if (grub_strcasecmp (args[0], "getstatus") == 0)
  {
    grub_printf ("%d", watchdog.fired);
    return watchdog.fired;
  }
  else if (grub_strcasecmp (args[0], "gettime") == 0)
    grub_printf ("%d", amd_wdt_get_time ());
  else if (grub_strcasecmp (args[0], "settime") == 0)
  {
    amd_wdt_set_time (grub_strtol(args[1], 0, 0));
    amd_wdt_start ();
    amd_wdt_ping ();
    amd_wdt_stop ();
  }
  else
    return grub_error (GRUB_ERR_BAD_ARGUMENT,
                       N_("error: unknown command"));

  return GRUB_ERR_NONE;
}

/* Helper for finding AMD WDT on the PCI bus */
static int
find_wdt (grub_pci_device_t dev, 
          grub_pci_id_t pciid __attribute__ ((unused)),
          void *data __attribute__ ((unused)))
{
  grub_pci_address_t addr;
  grub_uint32_t device_id;
  grub_uint32_t vendor_id;

#ifdef AMD_WDT_DEBUG
  grub_printf ("bus=%d, device=%d, function=%d\n", dev.bus, dev.device, dev.function);
#endif

  addr = grub_pci_make_address (dev, GRUB_PCI_REG_DEVICE);
  device_id = grub_pci_read_word (addr);

#ifdef AMD_WDT_DEBUG
  grub_printf ("addr GRUB_PCI_REG_DEVICE = 0x%x\n", addr);
#endif

  addr = grub_pci_make_address (dev, GRUB_PCI_REG_VENDOR);
  vendor_id = grub_pci_read_word (addr);

#ifdef AMD_WDT_DEBUG
  grub_printf ("addr GRUB_PCI_REG_VENDOR = 0x%x\n", addr);

  grub_printf ("PCI_DEVICE_ID = 0x%x | 0x%x, PCI_VENDOR_ID = 0x%x | 0x%x\n", device_id, PCI_DEVICE_ID_AMD_CARRIZO_SMBUS, vendor_id, PCI_VENDOR_ID_AMD);
#endif

  if (device_id == PCI_DEVICE_ID_AMD_CARRIZO_SMBUS && vendor_id == PCI_VENDOR_ID_AMD)
  {
    watchdog.base = AMD_ACPI_MMIO_BASE + AMD_WDT_MEM_MAP_OFFSET;

#ifdef AMD_WDT_DEBUG
    grub_printf ("watchdog.base = 0x%x\n", watchdog.base);

    for (grub_uint16_t i=0; i<0x100; i+=4)
    {   
      addr = grub_pci_make_address (dev, i); 
      grub_printf ("0x%x: 0x%x\n", i, grub_pci_read (addr));
    }
#endif

    watchdog.dev = dev;
    found = 1;
    return 1;
  }
  return 0;
}

static grub_err_t
amd_wdt_init (void)
{
  grub_pci_iterate (find_wdt, NULL);
  if (!found)
    return grub_error (GRUB_ERR_IO, "Couldn't find watchdog timer");

  watchdog.ptr = (void *) grub_pci_device_map_range (watchdog.dev,
                                                     watchdog.base,
                                                     AMD_WDT_MEM_MAP_SIZE);

  watchdog.mapped = 1;

#ifdef AMD_WDT_DEBUG
  grub_printf ("watchdog.ptr = %p\n", watchdog.ptr);

  for (grub_uint16_t i=0; i<AMD_WDT_MEM_MAP_SIZE; i++)
  {
    grub_outb(i, AMD_IO_PM_INDEX_REG);
    grub_printf ("watchdog reg[%d] = 0x%x\n", i, grub_inb(AMD_IO_PM_DATA_REG));
  }
#endif

  watchdog.fired = amd_wdt_check_fired ();

  amd_wdt_enable ();
  amd_wdt_set_resolution (AMD_PM_WATCHDOG_1SEC_RES);
  amd_wdt_set_timeout_action (_("reboot"));
  amd_wdt_stop ();
  amd_wdt_set_time (AMD_WDT_DEFAULT_TIMEOUT);

  grub_printf ("AMD Watchdog setup complete!\n");

  return GRUB_ERR_NONE;
}

static grub_err_t
amd_wdt_fini (void)
{
  if (watchdog.mapped)
      grub_pci_device_unmap_range (watchdog.dev,
                                   watchdog.ptr,
                                   AMD_WDT_MEM_MAP_SIZE);

  return GRUB_ERR_NONE;
}

static grub_extcmd_t cmd;

GRUB_MOD_INIT(amd-wdt)
{
  amd_wdt_init ();

  if (watchdog.mapped)
  {
    grub_printf ("watchdog reboot %sdetected\n", watchdog.fired ? "" : "not ");

    cmd = grub_register_extcmd ("amd-wdt", grub_cmd_amd_wdt, 0, 0,
                                N_("AMD Watchdog Timer"), 0);
  }
}

GRUB_MOD_FINI(amd-wdt)
{
  amd_wdt_fini ();

  if (watchdog.mapped)
    grub_unregister_extcmd (cmd);
}
