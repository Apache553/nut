# Network UPS Tools: man
#

# Notes:
# - sources (.txt) and groff formats are both distributed,
# - only sources are versioned ; groff files are generated at worst
#   during 'make dist' (while preparing a release tarball)
# - HTML files are built upon request, if AsciiDoc is available,
# - groff update will only happen if AsciiDoc is available too,
# - all this can probably (and hopefully) be improved, but I've not
#   found a way to do pattern replacement on the fly for target deps!
#   FIXME: investigate an autogen.sh hook
# - Ref: http://www.gnu.org/software/hello/manual/automake/Man-pages.html
# - WITH_MANS can be enabled if either we are building man-pages, or if
#   the --with-doc=man=auto detected an inability to build the man-pages
#   but enabled the DOC_INSTALL_DISTED_MANS toggle so we deliver disted
#   files from source tree

# Is "egrep == grep -E" always valid? (maybe all a job for configure.ac)
#EGREP = egrep
EGREP = grep -E

# Base configuration and client manpages, always installed
SRC_CONF_PAGES = \
	nut.conf.txt \
	ups.conf.txt \
	upsd.conf.txt \
	upsd.users.txt \
	upsmon.conf.txt \
	upssched.conf.txt

if WITH_MANS
MAN_CONF_PAGES = \
	nut.conf.5 \
	ups.conf.5 \
	upsd.conf.5 \
	upsd.users.5 \
	upsmon.conf.5 \
	upssched.conf.5
endif

man5_MANS = $(MAN_CONF_PAGES)

HTML_CONF_MANS = \
	nut.conf.html \
	ups.conf.html \
	upsd.conf.html \
	upsd.users.html \
	upsmon.conf.html \
	upssched.conf.html

# NOTE: Currently SRC_DRIVERTOOL_PAGES are a separate list to generate
# a linkman-drivertool-names.txt file, but historically remain part of
# MAN/HTML_CLIENT_PAGES in the bigger picture.
SRC_DRIVERTOOL_PAGES = \
	nut-driver-enumerator.txt \
	upsdrvctl.txt \
	upsdrvsvcctl.txt

SRC_CLIENT_PAGES = \
	$(SRC_DRIVERTOOL_PAGES) \
	nutupsdrv.txt \
	upsc.txt \
	upscmd.txt \
	upsd.txt \
	upslog.txt \
	upsmon.txt \
	upsrw.txt \
	upssched.txt

if WITH_MANS
MAN_CLIENT_PAGES = \
	nutupsdrv.8 \
	nut-driver-enumerator.8 \
	upsc.8 \
	upscmd.8 \
	upsd.8 \
	upsdrvctl.8 \
	upsdrvsvcctl.8 \
	upslog.8 \
	upsmon.8 \
	upsrw.8 \
	upssched.8
endif

man8_MANS = $(MAN_CLIENT_PAGES)

HTML_CLIENT_MANS = \
	nutupsdrv.html \
	nut-driver-enumerator.html \
	upsc.html \
	upscmd.html \
	upsd.html \
	upsdrvctl.html \
	upsdrvsvcctl.html \
	upslog.html \
	upsmon.html \
	upsrw.html \
	upssched.html

SRC_TOOL_PAGES = nut-scanner.txt nut-recorder.txt

if WITH_MANS
MAN_TOOL_PAGES = nut-scanner.8 nut-recorder.8
endif

man8_MANS += $(MAN_TOOL_PAGES)

HTML_TOOL_MANS = nut-scanner.html nut-recorder.html

# CGI (--with-cgi) related manpages
SRC_CGI_PAGES = \
	hosts.conf.txt \
	upsset.conf.txt \
	upsstats.html.txt \
	upsset.cgi.txt \
	upsstats.cgi.txt \
	upsimage.cgi.txt

if WITH_MANS
MAN5_CGI_PAGES = \
	hosts.conf.5 \
	upsset.conf.5 \
	upsstats.html.5

MAN8_CGI_PAGES = \
	upsset.cgi.8 \
	upsstats.cgi.8 \
	upsimage.cgi.8
endif

if WITH_CGI
man5_MANS += $(MAN5_CGI_PAGES)
man8_MANS += $(MAN8_CGI_PAGES)
endif

HTML_CGI_MANS = \
	hosts.conf.html \
	upsset.conf.html \
	upsstats.html.html \
	upsset.cgi.html \
	upsstats.cgi.html \
	upsimage.cgi.html


# Development (--with-dev) related manpages
SRC_DEV_PAGES = \
	upsclient.txt \
	upscli_add_host_cert.txt \
	upscli_cleanup.txt \
	upscli_connect.txt \
	upscli_disconnect.txt \
	upscli_fd.txt \
	upscli_get.txt \
	upscli_init.txt \
	upscli_list_next.txt \
	upscli_list_start.txt \
	upscli_readline.txt \
	upscli_sendline.txt \
	upscli_splitaddr.txt \
	upscli_splitname.txt \
	upscli_ssl.txt \
	upscli_strerror.txt \
	upscli_upserror.txt \
	libnutclient.txt \
	libnutclient_commands.txt \
	libnutclient_devices.txt \
	libnutclient_general.txt \
	libnutclient_misc.txt \
	libnutclient_tcp.txt \
	libnutclient_variables.txt \
	nutscan.txt \
	nutscan_scan_snmp.txt \
	nutscan_scan_usb.txt \
	nutscan_scan_xml_http_range.txt \
	nutscan_scan_nut.txt \
	nutscan_scan_avahi.txt \
	nutscan_scan_ipmi.txt \
	nutscan_scan_eaton_serial.txt \
	nutscan_display_ups_conf.txt \
	nutscan_display_parsable.txt \
	nutscan_cidr_to_ip.txt \
	nutscan_new_device.txt \
	nutscan_free_device.txt \
	nutscan_add_option_to_device.txt \
	nutscan_add_device_to_device.txt \
	nutscan_init.txt \
	nutscan_get_serial_ports_list.txt \
	libupsclient-config.txt \
	skel.txt

if WITH_MANS
# NOTE: nutclient_*.3 has no source counterpart (libnutclient_*.txt)

LIBNUTCLIENT_MISC_DEPS= \
	nutclient_authenticate.3 \
	nutclient_logout.3 \
	nutclient_device_login.3 \
	nutclient_get_device_num_logins.3 \
	nutclient_device_master.3 \
	nutclient_device_forced_shutdown.3

$(LIBNUTCLIENT_MISC_DEPS): libnutclient_misc.3
	touch $@

LIBNUTCLIENT_TCP_DEPS= \
	nutclient_tcp_create_client.3 \
	nutclient_tcp_disconnect.3 \
	nutclient_tcp_get_timeout.3 \
	nutclient_tcp_is_connected.3 \
	nutclient_tcp_reconnect.3 \
	nutclient_tcp_set_timeout.3

$(LIBNUTCLIENT_TCP_DEPS): libnutclient_tcp.3
	touch $@

LIBNUTCLIENT_GENERAL_DEPS= \
	nutclient_destroy.3

$(LIBNUTCLIENT_GENERAL_DEPS): libnutclient_general.3
	touch $@

LIBNUTCLIENT_VARIABLES_DEPS= \
	nutclient_get_device_rw_variables.3 \
	nutclient_get_device_variable_description.3 \
	nutclient_get_device_variables.3 \
	nutclient_get_device_variable_values.3 \
	nutclient_has_device_variable.3 \
	nutclient_set_device_variable_value.3 \
	nutclient_set_device_variable_values.3

$(LIBNUTCLIENT_VARIABLES_DEPS): libnutclient_variables.3
	touch $@

LIBNUTCLIENT_COMMANDS_DEPS= \
	nutclient_execute_device_command.3 \
	nutclient_get_device_command_description.3 \
	nutclient_get_device_commands.3 \
	nutclient_has_device_command.3

$(LIBNUTCLIENT_COMMANDS_DEPS): libnutclient_commands.3
	touch $@

LIBNUTCLIENT_DEVICES_DEPS= \
	nutclient_get_device_description.3 \
	nutclient_get_devices.3 \
	nutclient_has_device.3

$(LIBNUTCLIENT_DEVICES_DEPS): libnutclient_devices.3
	touch $@

MAN3_DEV_PAGES = \
	upsclient.3 \
	upscli_add_host_cert.3 \
	upscli_cleanup.3 \
	upscli_connect.3 \
	upscli_disconnect.3 \
	upscli_fd.3 \
	upscli_get.3 \
	upscli_init.3 \
	upscli_list_next.3 \
	upscli_list_start.3 \
	upscli_readline.3 \
	upscli_readline_timeout.3 \
	upscli_sendline.3 \
	upscli_sendline_timeout.3 \
	upscli_splitaddr.3 \
	upscli_splitname.3 \
	upscli_ssl.3 \
	upscli_strerror.3 \
	upscli_upserror.3 \
	libnutclient.3 \
	libnutclient_commands.3 \
	$(LIBNUTCLIENT_COMMANDS_DEPS) \
	libnutclient_devices.3 \
	$(LIBNUTCLIENT_DEVICES_DEPS) \
	libnutclient_general.3 \
	$(LIBNUTCLIENT_GENERAL_DEPS) \
	libnutclient_misc.3 \
	$(LIBNUTCLIENT_MISC_DEPS) \
	libnutclient_tcp.3 \
	$(LIBNUTCLIENT_TCP_DEPS) \
	libnutclient_variables.3 \
	$(LIBNUTCLIENT_VARIABLES_DEPS) \
	nutscan.3 \
	nutscan_scan_snmp.3 \
	nutscan_scan_usb.3 \
	nutscan_scan_xml_http_range.3 \
	nutscan_scan_nut.3 \
	nutscan_scan_avahi.3 \
	nutscan_scan_ipmi.3 \
	nutscan_scan_eaton_serial.3 \
	nutscan_display_ups_conf.3 \
	nutscan_display_parsable.3 \
	nutscan_cidr_to_ip.3 \
	nutscan_new_device.3 \
	nutscan_free_device.3 \
	nutscan_add_option_to_device.3 \
	nutscan_add_device_to_device.3 \
	nutscan_get_serial_ports_list.3 \
	nutscan_init.3

upscli_readline_timeout.3: upscli_readline.3
	touch $@

upscli_sendline_timeout.3: upscli_sendline.3
	touch $@

MAN1_DEV_PAGES = \
	libupsclient-config.1
endif

if WITH_DEV
man3_MANS = $(MAN3_DEV_PAGES)

if !WITH_PKG_CONFIG
man1_MANS = $(MAN1_DEV_PAGES)
endif
# WITH_DEV
endif

HTML_DEV_MANS = \
	upsclient.html \
	upscli_add_host_cert.html \
	upscli_cleanup.html \
	upscli_connect.html \
	upscli_disconnect.html \
	upscli_fd.html \
	upscli_get.html \
	upscli_init.html \
	upscli_list_next.html \
	upscli_list_start.html \
	upscli_readline.html \
	upscli_sendline.html \
	upscli_splitaddr.html \
	upscli_splitname.html \
	upscli_ssl.html \
	upscli_strerror.html \
	upscli_upserror.html \
	libnutclient.html \
	libnutclient_commands.html \
	libnutclient_devices.html \
	libnutclient_general.html \
	libnutclient_misc.html \
	libnutclient_tcp.html \
	libnutclient_variables.html \
	nutscan.html \
	nutscan_scan_snmp.html \
	nutscan_scan_usb.html \
	nutscan_scan_xml_http_range.html \
	nutscan_scan_nut.html \
	nutscan_scan_avahi.html \
	nutscan_scan_ipmi.html \
	nutscan_scan_eaton_serial.html \
	nutscan_display_ups_conf.html \
	nutscan_display_parsable.html \
	nutscan_cidr_to_ip.html \
	nutscan_new_device.html \
	nutscan_free_device.html \
	nutscan_add_option_to_device.html \
	nutscan_add_device_to_device.html \
	nutscan_get_serial_ports_list.html \
	nutscan_init.html \
	libupsclient-config.html \
	skel.html


# Drivers related manpages

# (--with-drivers=...)
if SOME_DRIVERS
man8_MANS += $(DRIVER_MAN_LIST)

else

# (--with-serial)
SRC_SERIAL_PAGES = \
	al175.txt	\
	apcsmart.txt	\
	apcsmart-old.txt	\
	bcmxcp.txt 	\
	belkin.txt 	\
	belkinunv.txt	\
	bestfortress.txt	\
	bestuferrups.txt	\
	bestups.txt 	\
	bestfcom.txt	\
	blazer-common.txt	\
	blazer_ser.txt	\
	clone.txt \
	dummy-ups.txt	\
	etapro.txt	\
	everups.txt	\
	gamatronic.txt	\
	genericups.txt	\
	isbmex.txt	\
	ivtscd.txt	\
	liebert.txt	\
	liebert-esp2.txt	\
	masterguard.txt	\
	metasys.txt	\
	mge-shut.txt	\
	mge-utalk.txt	\
	oneac.txt		\
	microdowell.txt	\
	microsol-apc.txt	\
	nutdrv_siemens_sitop.txt	\
	optiups.txt	\
	powercom.txt 	\
	powerpanel.txt	\
	rhino.txt		\
	riello_ser.txt	\
	safenet.txt	\
	solis.txt		\
	tripplite.txt	\
	tripplitesu.txt	\
	upscode2.txt	\
	victronups.txt	\
	apcupsd-ups.txt

if WITH_MANS
MAN_SERIAL_PAGES = \
	al175.8	\
	apcsmart.8	\
	apcsmart-old.8	\
	bcmxcp.8 	\
	belkin.8 	\
	belkinunv.8	\
	bestfortress.8	\
	bestuferrups.8	\
	bestups.8 	\
	bestfcom.8	\
	blazer_ser.8	\
	clone.8 \
	dummy-ups.8	\
	etapro.8	\
	everups.8	\
	gamatronic.8	\
	genericups.8	\
	isbmex.8	\
	ivtscd.8	\
	liebert.8	\
	liebert-esp2.8	\
	masterguard.8	\
	metasys.8	\
	mge-shut.8	\
	mge-utalk.8	\
	oneac.8		\
	microdowell.8	\
	microsol-apc.8	\
	nutdrv_siemens_sitop.8	\
	optiups.8	\
	powercom.8 	\
	powerpanel.8	\
	rhino.8		\
	riello_ser.8	\
	safenet.8	\
	solis.8		\
	tripplite.8	\
	tripplitesu.8	\
	upscode2.8	\
	victronups.8	\
	apcupsd-ups.8
endif

if WITH_SERIAL
man8_MANS +=  $(MAN_SERIAL_PAGES)
endif

HTML_SERIAL_MANS = \
	al175.html	\
	apcsmart.html	\
	apcsmart-old.html	\
	bcmxcp.html 	\
	belkin.html 	\
	belkinunv.html	\
	bestfortress.html	\
	bestuferrups.html	\
	bestups.html 	\
	bestfcom.html	\
	blazer_ser.html	\
	clone.html \
	dummy-ups.html	\
	etapro.html	\
	everups.html	\
	gamatronic.html	\
	genericups.html	\
	isbmex.html	\
	ivtscd.html	\
	liebert.html	\
	liebert-esp2.html	\
	masterguard.html	\
	metasys.html	\
	mge-shut.html	\
	mge-utalk.html	\
	oneac.html		\
	microdowell.html	\
	microsol-apc.html	\
	nutdrv_siemens_sitop.html	\
	optiups.html	\
	powercom.html 	\
	powerpanel.html	\
	rhino.html		\
	riello_ser.html	\
	safenet.html	\
	solis.html		\
	tripplite.html	\
	tripplitesu.html	\
	upscode2.html	\
	victronups.html	\
	apcupsd-ups.html

# (--with-snmp)
SRC_SNMP_PAGES = snmp-ups.txt
if WITH_MANS
MAN_SNMP_PAGES = snmp-ups.8
endif

if WITH_SNMP
man8_MANS += $(MAN_SNMP_PAGES)
endif

HTML_SNMP_MANS = snmp-ups.html

# (--with-usb)
SRC_USB_LIBUSB_PAGES = \
	bcmxcp_usb.txt \
	blazer-common.txt	\
	blazer_usb.txt	\
	nutdrv_atcl_usb.txt \
	richcomm_usb.txt \
	riello_usb.txt	\
	tripplite_usb.txt \
	usbhid-ups.txt

if WITH_MANS
MAN_USB_LIBUSB_PAGES = \
	bcmxcp_usb.8 \
	blazer_usb.8 \
	nutdrv_atcl_usb.8 \
	richcomm_usb.8 \
	riello_usb.8	\
	tripplite_usb.8 \
	usbhid-ups.8
endif

if WITH_USB
man8_MANS += $(MAN_USB_LIBUSB_PAGES)
endif

HTML_USB_LIBUSB_MANS = \
	bcmxcp_usb.html \
	blazer_usb.html	\
	nutdrv_atcl_usb.html \
	richcomm_usb.html \
	riello_usb.html	\
	tripplite_usb.html \
	usbhid-ups.html

# (--with-serial / --with-usb)
SRC_SERIAL_USB_PAGES = \
	nutdrv_qx.txt

if WITH_MANS
MAN_SERIAL_USB_PAGES = \
	nutdrv_qx.8
endif

if WITH_SERIAL
man8_MANS += $(MAN_SERIAL_USB_PAGES)
else
if WITH_USB
man8_MANS += $(MAN_SERIAL_USB_PAGES)
endif
endif

HTML_SERIAL_USB_MANS = \
	nutdrv_qx.html

# (--with-neon)
SRC_NETXML_PAGES = netxml-ups.txt
if WITH_MANS
MAN_NETXML_PAGES = netxml-ups.8
endif

if WITH_NEON
man8_MANS += $(MAN_NETXML_PAGES)
endif

HTML_NETXML_MANS = netxml-ups.html

# (--with-powerman)
SRC_POWERMAN_PAGES = powerman-pdu.txt
if WITH_MANS
MAN_POWERMAN_PAGES = powerman-pdu.8
endif

if WITH_LIBPOWERMAN
man8_MANS += $(MAN_POWERMAN_PAGES)
endif

HTML_POWERMAN_MANS = powerman-pdu.html

# (--with-ipmi)
SRC_IPMIPSU_PAGES = nut-ipmipsu.txt
if WITH_MANS
MAN_IPMIPSU_PAGES = nut-ipmipsu.8
endif

if WITH_IPMI
man8_MANS += $(MAN_IPMIPSU_PAGES)
endif

HTML_IPMIPSU_MANS = nut-ipmipsu.html

SRC_MACOSX_PAGES = macosx-ups.txt
if WITH_MANS
MAN_MACOSX_PAGES = macosx-ups.8
endif

if WITH_MACOSX
man8_MANS += $(MAN_MACOSX_PAGES)
endif

HTML_MACOSX_MANS = macosx-ups.html

SRC_MODBUS_PAGES = phoenixcontact_modbus.txt \
	generic_modbus.txt \
	huawei-ups2000.txt \
	socomec_jbus.txt   \
	adelsystem_cbi.txt
if WITH_MANS
MAN_MODBUS_PAGES = phoenixcontact_modbus.8 \
	generic_modbus.8 \
	huawei-ups2000.8 \
	socomec_jbus.8   \
	adelsystem_cbi.8
endif

if WITH_MODBUS
man8_MANS += $(MAN_MODBUS_PAGES)
endif

HTML_MODBUS_MANS = phoenixcontact_modbus.html \
	generic_modbus.html \
	huawei-ups2000.html \
	socomec_jbus.html   \
	adelsystem_cbi.html

SRC_LINUX_I2C_PAGES = asem.txt pijuice.txt
if WITH_MANS
MAN_LINUX_I2C_PAGES = asem.8 pijuice.8
endif

if WITH_LINUX_I2C
man8_MANS += $(MAN_LINUX_I2C_PAGES)
endif

HTML_LINUX_I2C_MANS = asem.html pijuice.html

# SOME_DRIVERS
endif

MAN_MANS =
if WITH_MANS
MAN_MANS += \
	$(MAN_CONF_PAGES) \
	$(MAN_CLIENT_PAGES) \
	$(MAN_TOOL_PAGES) \
	$(MAN5_CGI_PAGES) \
	$(MAN8_CGI_PAGES) \
	$(MAN1_DEV_PAGES) \
	$(MAN3_DEV_PAGES) \
	$(MAN_SERIAL_PAGES) \
	$(MAN_SNMP_PAGES) \
	$(MAN_USB_LIBUSB_PAGES) \
	$(MAN_SERIAL_USB_PAGES) \
	$(MAN_NETXML_PAGES) \
	$(MAN_POWERMAN_PAGES) \
	$(MAN_IPMIPSU_PAGES) \
	$(MAN_MACOSX_PAGES) \
	$(MAN_MODBUS_PAGES) \
	$(MAN_LINUX_I2C_PAGES)
endif

SRC_DRIVERS_PAGES = \
	$(SRC_SERIAL_PAGES) \
	$(SRC_SNMP_PAGES) \
	$(SRC_USB_LIBUSB_PAGES) \
	$(SRC_SERIAL_USB_PAGES) \
	$(SRC_NETXML_PAGES) \
	$(SRC_POWERMAN_PAGES) \
	$(SRC_IPMIPSU_PAGES) \
	$(SRC_MACOSX_PAGES) \
	$(SRC_MODBUS_PAGES) \
	$(SRC_LINUX_I2C_PAGES)

if SOME_DRIVERS
# The list above probably came up empty in this case, so make sure that
# the drivers requested by configure script are documented in the build;
# notably in the linkman-driver-names.txt file.
SRC_DRIVERS_PAGES += \
	$(DRIVER_MAN_LIST_PAGES)
endif

# distribute everything, even those not installed by default
# Note that 'dist' target requires AsciiDoc!
SRC_ALL_PAGES = \
	$(SRC_CONF_PAGES) \
	$(SRC_CLIENT_PAGES) \
	$(SRC_TOOL_PAGES) \
	$(SRC_CGI_PAGES) \
	$(SRC_DEV_PAGES) \
	$(SRC_DRIVERS_PAGES)

EXTRA_DIST = \
	$(SRC_ALL_PAGES) \
	$(MAN_MANS) \
	asciidoc.conf

if ! WITH_MANS
if ! SKIP_MANS
# Cause "make dist" to fail, unless caller (like the stack of distcheck-dmf)
# runs ./configure --with-doc=skip (or --with-doc=man=skip specifically)
EXTRA_DIST += dist
dist:
	@echo "ERROR: Manpage building was disabled by configure script, and these pages are required for our proper 'make dist'" >&2 ; false
endif
endif

# For builds done from dist'ed sources, there may be a conflict of timestamps
# between original *.txt files and pre-built manpages etc. leading to skipping
# of manpage re-generation even if that activity is possible and requested.
# Possibly a cleaner, but less portable, solution would be to touch the
# generated files to long ago. Current solution assumes good valid clocks :)
dist-hook:
	@echo "Fix up manpage source timestamps" && cd $(distdir) && touch $(SRC_ALL_PAGES)

HTML_MANS = \
	$(HTML_CONF_MANS) \
	$(HTML_CLIENT_MANS) \
	$(HTML_TOOL_MANS) \
	$(HTML_CGI_MANS) \
	$(HTML_DEV_MANS) \
	$(HTML_SERIAL_MANS) \
	$(HTML_SNMP_MANS) \
	$(HTML_USB_LIBUSB_MANS) \
	$(HTML_SERIAL_USB_MANS) \
	$(HTML_NETXML_MANS) \
	$(HTML_POWERMAN_MANS) \
	$(HTML_IPMIPSU_MANS) \
	$(HTML_MACOSX_MANS) \
	$(HTML_MODBUS_MANS) \
	$(HTML_LINUX_I2C_MANS)

# Note: target documents, except nutupsdrv.txt itself, start the
# list of drivers with `- linkman:nutupsdrv[8]` entry
# To regenerate these files, do `make distclean` first
LINKMAN_INCLUDE_GENERATED = linkman-driver-names.txt linkman-drivertool-names.txt
LINKMAN_INCLUDE_CONSUMERS = index.txt upsd.txt nutupsdrv.txt

linkman-driver-names.txt:
	@if test x"$(srcdir)" != x"$(builddir)" ; then \
	    if ! test -s "$(builddir)/$@" && test -s "$(srcdir)/$(@F)" ; then \
	        ln -fs "$(srcdir)/$(@F)" "$(builddir)/" ; \
	    fi ; \
	 fi
	@if test -s "$@" ; then exit 0 ; fi ; \
	 (LC_ALL=C; LANG=C; export LC_ALL LANG; \
	  for F in $(SRC_DRIVERS_PAGES) ; do echo "$$F" ; done \
	    | grep -vE '^nutupsdrv\.txt$$' \
	    | sort -n | uniq \
	    | sed 's,^\(.*\)\.txt$$,- linkman:\1[8],' ; \
	 ) > "$@"
	@if test ! -s "$@" ; then echo "- No NUT drivers were built" > "$@" ; fi

linkman-drivertool-names.txt:
	@if test x"$(srcdir)" != x"$(builddir)" ; then \
	    if ! test -s "$(builddir)/$@" && test -s "$(srcdir)/$(@F)" ; then \
	        ln -fs "$(srcdir)/$(@F)" "$(builddir)/" ; \
	    fi ; \
	 fi
	@if test -s "$@" ; then exit 0 ; fi ; \
	 (LC_ALL=C; LANG=C; export LC_ALL LANG; \
	  for F in $(SRC_DRIVERTOOL_PAGES) ; do echo "$$F" ; done \
	    | sort -n | uniq \
	    | sed 's,^\(.*\)\.txt$$,- linkman:\1[8],' ; \
	 ) > "$@"
	@if test ! -s "$@" ; then echo "- No NUT driver tools were built" > "$@" ; fi

# Dependencies are about particular filenames, since over time
# we might have several use-cases for LINKMAN_INCLUDE_GENERATED:
$(LINKMAN_INCLUDE_CONSUMERS): linkman-driver-names.txt linkman-drivertool-names.txt

# These files are generated when we build from git source so not tracked in
# git, and not part of tarball (to be in builddir) - so not in EXTRA_DIST.
DISTCLEANFILES = $(LINKMAN_INCLUDE_GENERATED)

all:

all-html html-man: $(HTML_MANS) index.html

# Have a way to build all man pages, not just those that fit currently
# configured drivers, daemons, developer aspect, etc.
all-man man-man: $(MAN_MANS)

if WITH_MANS
if ! SKIP_MANS
check-local: check-man
else
check-local: check-man-txt check-man-pages
	@echo "Man-page generation was SKIPPED per user request, so pregenerated pages were sanity-checked (if any)" >&2
endif
else
check-local: check-man-txt check-man-pages
	@echo "Man-page generation was not done, so pregenerated pages were sanity-checked (if any)" >&2
endif

check-man: check-man-txt check-man-pages check-html-man

# the "for" loops might better use $^ but it might be not portable
check-man-html: check-html-man

check-html-man: $(HTML_MANS)
	@FAILED=""; CHECKED=0; LANG=C; LC_ALL=C; export LANG; export LC_ALL; \
	for F in $(HTML_MANS) ; do \
	    CHECKED="`expr $$CHECKED + 1`"; \
	    test -s "$$F" && { file "$$F" | $(EGREP) -i '(XML|HTML.*document)' > /dev/null ; } || FAILED="$$FAILED $$F" ; \
	done; if test -n "$$FAILED" ; then \
	    echo "FAILED HTML-man sanity check for:$$FAILED" >&2 ; file $$FAILED >&2 ; exit 1; \
	fi; echo "PASSED HTML-man sanity check (checked $$CHECKED files)"; exit 0

# Note: many man-pages here have code samples and are mis-identified as C code
check-man-page: check-man-pages

# Man-pages may be pre-generated (srcdir), or re-built (builddir)
check-man-pages: $(MAN_MANS)
	@FAILED=""; CHECKED=0; LANG=C; LC_ALL=C; export LANG; export LC_ALL; \
	for F in $(MAN_MANS) ; do \
	    CHECKED="`expr $$CHECKED + 1`"; \
	    ( test -s "$(abs_srcdir)/$$F" && { file "$(abs_srcdir)/$$F" | $(EGREP) -i '(roff.* input|C source|ASCII text)' > /dev/null ; } ) || \
	    ( test -s "$(abs_builddir)/$$F" && { file "$(abs_builddir)/$$F" | $(EGREP) -i '(roff.* input|C source|ASCII text)' > /dev/null ; } ) || \
	    FAILED="$$FAILED $$F" ; \
	done; if test -n "$$FAILED" ; then \
	    echo "FAILED man-page sanity check for:$$FAILED" >&2 ; \
	    ( echo "SRCDIR:"; cd "$(abs_srcdir)/" && file $$FAILED ; \
	      echo "BUILDDIR:"; cd "$(abs_builddir)/" && file $$FAILED ; \
	    ) >&2 ; exit 1; \
	fi; echo "PASSED man-page sanity check (checked $$CHECKED files)"; exit 0

check-man-source: check-man-txt

# Note: (GNU) make can helpfully add VPATH to the short source filenames
# which we had listed above, so the "case" below handles two possibilities
check-man-txt: $(SRC_ALL_PAGES)
	@FAILED=""; CHECKED=0; LANG=C; LC_ALL=C; export LANG; export LC_ALL; \
	( cd $(abs_srcdir) ) || exit; \
	for F in $(SRC_ALL_PAGES) ; do \
	    CHECKED="`expr $$CHECKED + 1`"; \
	    case "$$F" in \
	        */*) ;; \
	        *) F="$(abs_srcdir)/$$F" ;; \
	    esac ; \
	    test -s "$$F" && { file "$$F" | $(EGREP) -i '(ASCII|UTF-8|Unicode|ISO-8859|English).* text' > /dev/null ; } || FAILED="$$FAILED $$F" ; \
	done; if test -n "$$FAILED" ; then \
	    echo "FAILED man-source sanity check for:$$FAILED" >&2 ; file $$FAILED >&2 ; exit 1; \
	fi; echo "PASSED man-source sanity check (checked $$CHECKED files)"; exit 0

CLEANFILES = *-spellchecked

SUFFIXES = .txt .html .1 .3 .5 .8

# For builds with allowed installation of prebuild man pages, check that
# they exist in sources (make would pull them automatically as a fallback
# from failed lookup in build products). For builds that require rebuild
# of man pages, abort with error if build product is missing.
if DOC_INSTALL_DISTED_MANS
SRC_PREBUILT_CLAUSE=|| [ -r "$(srcdir)/`basename $@`" ]
else
SRC_PREBUILT_CLAUSE=
endif

if HAVE_ASCIIDOC

CLEANFILES += *.1 *.3 *.5 *.8 *.xml *.html *.pdf

# Working around a2x not friendly to parallelized runs.
# See more details in the main NUT docs/Makefile.am
DOCBUILD_BEGIN = { \
    if test -n "$${A2X_OUTDIR}" && test "$${A2X_OUTDIR}" != '.' ; then \
        rm -rf "./$${A2X_OUTDIR}" || true ; \
        test -d "$@" && rm -rf "$@" || true ; \
        mkdir -p "./$${A2X_OUTDIR}" || exit ; \
        for F in $(LINKMAN_INCLUDE_GENERATED) ; do \
            if [ -s "./$$F" ] ; then ln -f -s "../../$$F" "./$${A2X_OUTDIR}/" ; else \
            if [ -s "$(abs_srcdir)/$$F" ] ; then ln -f -s "$(abs_srcdir)/$$F" "./$${A2X_OUTDIR}/" ; fi ; fi ; \
        done ; \
    else A2X_OUTDIR='.' ; fi; \
    if test -s "${builddir}/docbook-xsl.css" \
    && test -r "${builddir}/docbook-xsl.css" \
    && ! test -w "${builddir}/docbook-xsl.css" \
    ; then chmod u+w "${builddir}/docbook-xsl.css" ; fi ; \
    chmod -R u+w "./$${A2X_OUTDIR}" || true ; \
    if test x"$(srcdir)" != x"$(builddir)" ; then \
        if ! test -s "$(builddir)/$<" && test -s "$(srcdir)/`basename $<`" ; then \
            ln -fs "$(srcdir)/`basename $<`" "$(builddir)/" ; \
        fi ; \
    fi ; \
    A2X_VERBOSE="$(ASCIIDOC_VERBOSE)"; if [ "$(V)" = 1 ]; then A2X_VERBOSE="--verbose"; fi; \
}

# Note that documents with sub-pages (see LIBNUTCLIENT_*_DEPS above)
# may generate multiple files in one go... so we move "*" and hope
# for no required hidden files (or would have to `find` them all).
DOCBUILD_END = { \
    if test -n "$${A2X_OUTDIR}" && test "$${A2X_OUTDIR}" != '.' ; then \
        chmod -R u+w "./$${A2X_OUTDIR}" || true ; \
        test -d "$@" && rm -rf "$@" || true ; \
        for F in $(LINKMAN_INCLUDE_GENERATED) ; do \
            rm -f "./$${A2X_OUTDIR}/$$F" || true ; \
        done ; \
        mv -f "./$${A2X_OUTDIR}/$(@F)" ./ || exit ; \
        mv -f "./$${A2X_OUTDIR}/"*.* ./ 2>/dev/null || true ; \
        rm -rf "./$${A2X_OUTDIR}" ; \
    fi ; \
}

### Regarding absolute paths in attributes below: by default asciidoc
### resolves include paths relative to the main document, so while we
### see the relative builddir as "." in the makefile, for included
### data it would mean the source directory where the .txt resides.
.txt.html:
	@A2X_OUTDIR="tmp/man-html.$(@F).$$$$" ; \
	 echo "  DOC-MAN-HTML Generating $@"; \
	 $(DOCBUILD_BEGIN) ; RES=0; \
	 $(ASCIIDOC) --backend=xhtml11 $${A2X_VERBOSE} \
		--attribute localdate="`TZ=UTC date +%Y-%m-%d`" \
		--attribute localtime="`TZ=UTC date +%H:%M:%S`" \
		--attribute nutversion="@PACKAGE_VERSION@" \
		--attribute srcdir="$(abs_srcdir)" \
		--attribute builddir="$(abs_builddir)" \
		-o "$${A2X_OUTDIR}/$(@F)" $< || RES=$$? ; \
	 $(DOCBUILD_END) ; exit $$RES

### Prior to Asciidoc ~8.6.8, the --destination-dir flag didn't seem to affect the location of the intermediate .xml file.
### This parameter is currently required; see docs/Makefile.am for more detail.
A2X_MANPAGE_OPTS = --doctype manpage --format manpage $${A2X_VERBOSE} \
	--xsltproc-opts="--nonet" \
	--attribute mansource="Network UPS Tools" \
	--attribute manversion="@PACKAGE_VERSION@" \
	--attribute manmanual="NUT Manual" \
	--attribute srcdir="$(abs_srcdir)" \
	--attribute builddir="$(abs_builddir)" \
	--destination-dir="$${A2X_OUTDIR}"

.txt.1:
	@A2X_OUTDIR="tmp/man1.$(@F).$$$$" ; \
	 echo "  DOC-MAN  Generating $@"; \
	 $(DOCBUILD_BEGIN) ; RES=0; \
	 $(A2X) $(A2X_MANPAGE_OPTS) $< || RES=$$? ; \
	 $(DOCBUILD_END) ; exit $$RES

.txt.3:
	@A2X_OUTDIR="tmp/man3.$(@F).$$$$" ; \
	 echo "  DOC-MAN  Generating $@"; \
	 $(DOCBUILD_BEGIN) ; RES=0; \
	 $(A2X) $(A2X_MANPAGE_OPTS) $< || RES=$$? ; \
	 $(DOCBUILD_END) ; exit $$RES

.txt.5:
	@A2X_OUTDIR="tmp/man5.$(@F).$$$$" ; \
	 echo "  DOC-MAN  Generating $@"; \
	 $(DOCBUILD_BEGIN) ; RES=0; \
	 $(A2X) $(A2X_MANPAGE_OPTS) $< || RES=$$? ; \
	 $(DOCBUILD_END) ; exit $$RES

.txt.8:
	@A2X_OUTDIR="tmp/man8.$(@F).$$$$" ; \
	 echo "  DOC-MAN  Generating $@"; \
	 $(DOCBUILD_BEGIN) ; RES=0; \
	 $(A2X) $(A2X_MANPAGE_OPTS) $< || RES=$$? ; \
	 $(DOCBUILD_END) ; exit $$RES

else !HAVE_ASCIIDOC

.txt.html:
	@if [ -r "$@" ] $(SRC_PREBUILT_CLAUSE); then \
		echo "Not (re)building $@ manual page, since 'asciidoc', 'xmllint' or 'xsltproc' were not found." ; \
	else \
		echo "Could not find prebuilt $@ manual page." ; \
		echo "If you are building from Git, do you have all of the asciidoc/a2x tools installed?"; \
		exit 1; \
	fi

.txt.1:
	@if [ -r "$@" ] $(SRC_PREBUILT_CLAUSE); then \
		echo "Not (re)building $@ manual page, since 'asciidoc', 'xmllint' or 'xsltproc' were not found." ; \
	else \
		echo "Could not find prebuilt $@ manual page." ; \
		echo "If you are building from Git, do you have all of the asciidoc/a2x tools installed?"; \
		exit 1; \
	fi

.txt.3:
	@if [ -r "$@" ] $(SRC_PREBUILT_CLAUSE); then \
		echo "Not (re)building $@ manual page, since 'asciidoc', 'xmllint' or 'xsltproc' were not found." ; \
	else \
		echo "Could not find prebuilt $@ manual page." ; \
		echo "If you are building from Git, do you have all of the asciidoc/a2x tools installed?"; \
		exit 1; \
	fi

.txt.5:
	@if [ -r "$@" ] $(SRC_PREBUILT_CLAUSE); then \
		echo "Not (re)building $@ manual page, since 'asciidoc', 'xmllint' or 'xsltproc' were not found." ; \
	else \
		echo "Could not find prebuilt $@ manual page." ; \
		echo "If you are building from Git, do you have all of the asciidoc/a2x tools installed?"; \
		exit 1; \
	fi

.txt.8:
	@if [ -r "$@" ] $(SRC_PREBUILT_CLAUSE); then \
		echo "Not (re)building $@ manual page, since 'asciidoc', 'xmllint' or 'xsltproc' were not found." ; \
	else \
		echo "Could not find prebuilt $@ manual page." ; \
		echo "If you are building from Git, do you have all of the asciidoc/a2x tools installed?"; \
		exit 1; \
	fi

endif !HAVE_ASCIIDOC

# NOTE: Due to portability, we do not use a GNU percent-wildcard extension:
#%-spellchecked: % Makefile.am $(top_srcdir)/docs/Makefile.am $(abs_srcdir)/$(NUT_SPELL_DICT)
#	$(MAKE) -s -f $(top_builddir)/docs/Makefile SPELLCHECK_SRC_ONE="$<" SPELLCHECK_DIR="$(srcdir)" $@

# NOTE: Portable suffix rules do not allow prerequisites, so we shim them here
# by a wildcard target in case the make implementation can put the two together.
*.txt-spellchecked: Makefile.am $(abs_top_srcdir)/docs/Makefile.am $(abs_srcdir)/$(NUT_SPELL_DICT)
.txt.txt-spellchecked:
	$(MAKE) -s -f $(top_builddir)/docs/Makefile SPELLCHECK_SRC_ONE="$<" SPELLCHECK_DIR="$(srcdir)" $@

spellcheck spellcheck-interactive spellcheck-sortdict:
	$(MAKE) -f $(top_builddir)/docs/Makefile SPELLCHECK_SRC="$(SRC_ALL_PAGES)" SPELLCHECK_DIR="$(srcdir)" $@

MAINTAINERCLEANFILES = Makefile.in .dirstamp

clean-local:
	rm -rf tmp
