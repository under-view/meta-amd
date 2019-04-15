do_install_append_amd(){
    # Do not allow mini-x-session to force a display size
    sed -i "/^xrandr \-s/d" ${D}/${bindir}/mini-x-session
}
