# Firmware Audit: GL.iNet GL-AR300M16 Shadow / openwrt-ar300m16-4.3.27-0514-1747192506.bin

- Source URL: https://fw.gl-inet.com/firmware/ar300m/release4/openwrt-ar300m16-4.3.27-0514-1747192506.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M16_Shadow/openwrt-ar300m16-4.3.27-0514-1747192506.bin
- SHA-256: `4ab5fc68dbafde7fc8450baa664102b3603983264bed13576d7ade1edb2ca864`
- Size: 15598342 bytes
- Version: 4.3.27
- Release date: 2025-05-14 11:14:32

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcat, strcpy`

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
- `containers/ubus`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `devices/virtual/net`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `run/ubus`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `self/ns`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `sys/kernel/hostname`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `sys/net/ipv6/conf`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `cgi-bin/cgi-upload`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=16
- `kernel/debug/hnat/hnat_setting`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=16
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
- `sbin/dnscrypt-proxy`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `share/nftables.d/chain-pre/forward/02-edg.nft`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15

### Non-HTTP Service Surface

- `cloud` (tcp, outbound): auth=device, risk=high; source=`etc/hotplug.d/iface/99-gl-cloud`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`etc/init.d/gl-cloud`; evidence=service marker present; local sinks: system
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
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.ko.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.zh-cn.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.zh-tw.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.de.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.en.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.es.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.it.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.ja.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.ko.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.zh-cn.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-logview.zh-tw.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-vpndashboard.de.json`; evidence=service marker present

### Sink Summary

- exec: 36
- file_write: 232
- popen: 0
- system: 196
- unsafe_copy: 82

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
- `cron: ln -s /etc/crontabs /var/spool/cron/ 2>/dev/null`
- `cron: procd_set_param command "$PROG" -f -c /etc/crontabs -l "${loglevel:-5}"`
- `cron: procd_set_param file "$crontab"`
- `crontab.js: 'use strict';'require view';'require fs';'require ui';var isReadonlyView=!L.hasViewPermission()||null;return view.extend({load:function(){return L.resolveDefaul`
- `custom.js: 'use strict';'require view';'require fs';'require ui';return view.extend({load:function(){return L.resolveDefault(fs.read('/etc/firewall.user'),'');},handleSave`

### Handler-level Correlated Flows

- `sbin/procd`: L3-correlated, score 56; sources=getenv, ubus; sinks=auth, command_execution, file_write, unsafe_memory
- `etc/init.d/dnsmasq`: L3-correlated, score 51; sources=ubus, uci_get; sinks=auth, command_execution, unsafe_memory
- `sbin/rpcd`: L3-correlated, score 51; sources=getenv, ubus; sinks=auth, file_write, unsafe_memory
- `sbin/ujail`: L3-correlated, score 51; sources=getenv, ubus; sinks=auth, file_write, unsafe_memory
- `sbin/netifd`: L3-correlated, score 48; sources=ubus; sinks=auth, file_write, unsafe_memory
- `sbin/init`: L3-correlated, score 44; sources=getenv; sinks=command_execution, file_write, unsafe_memory
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
- `etc/init.d/gl_timer`: L3-correlated, score 38; sources=uci_get; sinks=command_execution
- `etc/init.d/stubby`: L3-correlated, score 38; sources=uci_get; sinks=command_execution
- `etc/init.d/sysntpd`: L3-correlated, score 38; sources=ubus; sinks=command_execution

### Ghidra Function-local Evidence

No function-local route/sink pairs were emitted by Ghidra.

### Runtime Profile

- Vendor profile: openwrt
- Web stack: nginx
- State backends: ubus, uci
- Architectures: mips, script
- Executables/scripts discovered: 744

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: etc/init.d/boot, etc/init.d/bootcount, etc/init.d/carrier-monitor, etc/init.d/cron, etc/init.d/dnscrypt-proxy, etc/init.d/dnsmasq, etc/init.d/done, etc/init.d/dropbear
- Listener candidates: etc/init.d/dnsmasq, etc/init.d/nginx, usr/sbin/dnsmasq, usr/sbin/nginx
- Runtime requirements discovered: 36
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

Structured zero-day triage JSON: `known_firmware/reports/GL.iNet_GL-AR300M16_Shadow/openwrt-ar300m16-4.3.27-0514-1747192506.bin.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/4ab5fc68dbafde7f

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-AR300M16_Shadow_4ab5fc68 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-AR300M16_Shadow_4ab5fc68 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-AR300M16_Shadow_4ab5fc68 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-AR300M16_Shadow_4ab5fc68 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-AR300M16_Shadow_4ab5fc68 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
