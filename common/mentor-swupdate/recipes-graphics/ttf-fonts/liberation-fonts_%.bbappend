python add_fontcache_postinsts_append () {
    for pkg in d.getVar('FONT_PACKAGES').split():
        d.setVar('pkg_postinst_%s' % pkg, '')
}
