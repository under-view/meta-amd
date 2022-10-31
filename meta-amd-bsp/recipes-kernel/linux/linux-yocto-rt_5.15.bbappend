require linux-yocto-5.15.inc

PR := "${INC_PR}.0"

KBRANCH:amd ?= "v5.15/standard/preempt-rt/base"
SRCREV_machine:amd ?= "dba1b7d90813231782bdeda1bd169c93b35c94e0"
