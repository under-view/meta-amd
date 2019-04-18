python populate_packages_append () {
    pixbuf_pkgs = d.getVar('PIXBUF_PACKAGES').split()
    for pkg in pixbuf_pkgs:
        d.setVar('pkg_postinst_%s' % pkg, '')
}
