# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release10326-0408-1744078505.tar

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release10326-0408-1744078505.tar
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release10326-0408-1744078505.tar
- SHA-256: `edf1ba09412592e0a76ba46e04f8787947bf84ea313c9a93c6bc828105b022b7`
- Size: 21607310 bytes
- Version: 4.3.26
- Release date: 2025-04-08 10:14:29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

- `L.env.cgi`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=22
- `sbin/chat`: rejected: route is not correlated with a dangerous sink; auth=none; evidence=L0; score=20
- `run/ovpnclient`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=19
- `run/ovpnclient-up_done`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=19
- `gl-hw-info/wan`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=18
- `mwan3_rule_/S`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=18
- `mwan3rtmon/ipv6`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=18
- `openvpn/scripts/ovpnclient-down`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=18
- `run/mwan3`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=18
- `backup/installed_packages.txt`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `cgi-bin/get_simslot_info`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `cgi-bin/handshake`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `containers/ubus`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `devices/virtual/net`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `run/ubus`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `self/ns`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `sys/kernel/hostname`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `sys/net/ipv6/conf`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `cgi-bin/cgi-upload`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=16
- `kernel/debug/ecm/gl_front_end_ipv6_stop`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=16
- `upgrade/platform.sh`: deprioritized: authentication boundary is unknown; cannot qualify as unauthenticated; auth=unknown; evidence=L2; score=16
- `class/leds/gl`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `doc/html/rfc2782`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `etc/openvpn/cert/dh1024.pem`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=15
- `init.d/dnscrypt-proxy`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `netifd/netifd-proto.sh`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `openvpn/cert/dh1024.pem`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=15
- `ppp/ip-up.d`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `resolv.conf.d/resolv.conf.auto`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `run/wgclient-route-update_done`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15

### Non-HTTP Service Surface

- `cloud` (tcp, outbound): auth=device, risk=high; source=`etc/hotplug.d/iface/99-gl-cloud`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`etc/init.d/gl-cloud`; evidence=service marker present; local sinks: system
- `cloud` (tcp, outbound): auth=device, risk=high; source=`etc/init.d/gl_mqtt`; evidence=service marker present; local sinks: system
- `cloud` (tcp, outbound): auth=device, risk=high; source=`etc/init.d/gl_s2s`; evidence=service marker present; local sinks: system
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/cloud`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/dns`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/netmode`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/rtty`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/s2s.so`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/system`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/vpn-policy`; evidence=service marker present; local sinks: system
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/wifi`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/fonts/element-icons.732389de.ttf`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.de.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.en.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.es.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.fr.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.it.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.ja.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.ko.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.ru.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.zh-cn.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.zh-tw.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.de.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.en.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.es.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.fr.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.it.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.ja.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.zh-cn.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.zh-tw.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.de.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.en.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.es.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.it.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.ja.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.zh-cn.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.zh-tw.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-vpndashboard.de.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-vpndashboard.en.json`; evidence=service marker present; local sinks: file_write

### Sink Summary

- exec: 36
- file_write: 259
- popen: 2
- system: 206
- unsafe_copy: 88

### Config Writer Leads

- `01-user: /etc/openvpn.user \`
- `01-user: [ -e "/etc/openvpn.user" ] && {`
- `15-mwan3: mwan3_create_iface_iptables $INTERFACE $DEVICE`
- `15-mwan3: mwan3_set_connected_iptables`
- `15-mwan3: mwan3_set_general_iptables`
- `15-mwan3: mwan3_set_policies_iptables`
- `20-firewall: /etc/init.d/firewall enabled || exit 0`
- `20-firewall: logger -t firewall "Reloading firewall due to $ACTION of $INTERFACE ($DEVICE)"`
- `21-vpnpolicy: #update_firewall`
- `21-vpnpolicy: reload_domain_firewall`
- `21-vpnpolicy: reload_mac_firewall`
- `21-vpnpolicy: set_vlan_firewall`
- `97-tor: /etc/init.d/firewall reload`
- `97-tor: uci set firewall.tor_allow_http.src_dip="$new_ip"`
- `97-tor: uci set firewall.tor_allow_http.src_ip="$new_ip/$mask"`
- `97-tor: uci set firewall.tor_allow_ssh.src_dip="$new_ip"`
- `97-tor: uci set firewall.tor_allow_ssh.src_ip="$new_ip/$mask"`
- `br_netfilter.ko: 5Bridge firewalling registered`
- `br_netfilter.ko: bridge-nf-call-iptables`
- `busybox: /etc/crontabs/`
- `cable.so: /etc/init.d/firewall reload`
- `cable.so: firewall`
- `cable.so: firewall.@zone`
- `cable.so: firewall.@zone[1].network`
- `clients: /etc/init.d/firewall`
- `cloud: /usr/lib/oui-httpd/rpc/firewall`
- `cloud: firewall`
- `cloud: firewall_mod`
- `cron: [ -z "$(ls /etc/crontabs/)" ] && return 1`
- `cron: for crontab in /etc/crontabs/*; do`

### Handler-level Correlated Flows

- `sbin/procd`: L3-correlated, score 56; sources=getenv, ubus; sinks=auth, command_execution, file_write, unsafe_memory
- `usr/sbin/uhttpd`: L3-correlated, score 55; sources=CONTENT_LENGTH, HTTP_COOKIE, QUERY_STRING, UBUS, ubus; sinks=auth, file_write, unsafe_memory
- `etc/init.d/dnsmasq`: L3-correlated, score 51; sources=ubus, uci_get; sinks=auth, command_execution, unsafe_memory
- `sbin/rpcd`: L3-correlated, score 51; sources=getenv, ubus; sinks=auth, file_write, unsafe_memory
- `sbin/ujail`: L3-correlated, score 51; sources=getenv, ubus; sinks=auth, file_write, unsafe_memory
- `sbin/netifd`: L3-correlated, score 48; sources=ubus; sinks=auth, file_write, unsafe_memory
- `sbin/init`: L3-correlated, score 44; sources=getenv; sinks=command_execution, file_write, unsafe_memory
- `etc/config/uhttpd`: L3-correlated, score 43; sources=ubus; sinks=auth, file_write
- `etc/init.d/uhttpd`: L3-correlated, score 43; sources=uci_get; sinks=auth, command_execution
- `lib/functions/gl_util.sh`: L3-correlated, score 43; sources=ubus; sinks=command_execution, file_write
- `lib/netifd/hostapd.sh`: L3-correlated, score 43; sources=ubus; sinks=auth, file_write
- `lib/netifd/proto/directip.sh`: L3-correlated, score 43; sources=ubus; sinks=auth, command_execution
- `lib/netifd/proto/ncm.sh`: L3-correlated, score 43; sources=ubus; sinks=auth, command_execution
- `lib/netifd/proto/qcm.sh`: L3-correlated, score 43; sources=ubus; sinks=auth, command_execution
- `lib/netifd/proto/qmi.sh`: L3-correlated, score 43; sources=ubus; sinks=auth, command_execution
- `lib/upgrade/stage2`: L3-correlated, score 43; sources=ubus; sinks=command_execution, file_write
- `sbin/block`: L3-correlated, score 43; sources=getenv; sinks=file_write, unsafe_memory
- `sbin/sysupgrade`: L3-correlated, score 43; sources=ubus; sinks=command_execution, file_write
- `usr/libexec/cgi-io`: L3-correlated, score 43; sources=CONTENT_LENGTH, getenv; sinks=auth, file_write, unsafe_memory
- `etc/init.d/gl_s2s`: L3-correlated, score 38; sources=ubus; sinks=command_execution

### Ghidra Function-local Evidence

No function-local route/sink pairs were emitted by Ghidra.

### Runtime Profile

- Vendor profile: openwrt
- Web stack: nginx, uhttpd
- State backends: ubus, uci
- Architectures: mips, script
- Executables/scripts discovered: 806

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: etc/init.d/boot, etc/init.d/bootcount, etc/init.d/carrier-monitor, etc/init.d/cron, etc/init.d/dnscrypt-proxy, etc/init.d/dnsmasq, etc/init.d/done, etc/init.d/dropbear
- Listener candidates: etc/config/uhttpd, etc/init.d/dnsmasq, etc/init.d/nginx, etc/init.d/uhttpd, lib/upgrade/keep.d/uhttpd, usr/sbin/dnsmasq, usr/sbin/nginx, usr/sbin/uhttpd
- Runtime requirements discovered: 39
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 500
- Archive validation cases: 7

### Confirmation Policy

- confirmed_label_requires: L5
- confirmed_zero_day_requires: ['L5 reproducible security effect with fault/sink attribution', 'novel reproducible pre-authentication exploitation path with no remote administrator session required', 'LAN or WAN network reachability without credentials', 'impact is remote code execution or a reliable input-specific denial of service', 'denial of service reproduces from attacker input and is not generic resource exhaustion', 'documented, dated public-prior-art search', 'no matching public disclosure or publicly available fix at the recorded discovery time']
- authenticated_admin_disposition: confirmed vulnerability, but not a confirmed zero-day
- vendor_contact_required: False
- private_duplicate_caveat: public novelty does not exclude an unknown private or embargoed duplicate
- L3: route-specific attacker parameter reaches the sink
- L4: authentication/validation boundary and trigger are proven
- L5: reproducible security effect with fault/sink attribution
- forbidden_shortcut: route string and dangerous symbol merely co-located in a binary
- impactful_hunt_scope: unauthenticated LAN/WAN RCE or reliable input-specific denial of service

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- Only routes with a plausible low-privilege boundary and route-local sink evidence are promoted. Global firmware sink counts never raise route evidence.
- Authentication labels inferred from strings are hypotheses until dispatcher control flow or a live request confirms them.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release10326-0408-1744078505.tar.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/edf1ba09412592e0 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/edf1ba09412592e0/_openwrt-e750-4.0-release10326-0408-1744078505.tar.extracted/sysupgrade-glinet_gl-e750/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-E750_GL-E750V2_Mudi_edf1ba09 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-E750_GL-E750V2_Mudi_edf1ba09 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-E750_GL-E750V2_Mudi_edf1ba09 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-E750_GL-E750V2_Mudi_edf1ba09 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-E750_GL-E750V2_Mudi_edf1ba09 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
