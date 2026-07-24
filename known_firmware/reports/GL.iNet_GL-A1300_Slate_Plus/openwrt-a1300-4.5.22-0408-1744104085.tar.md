# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.5.22-0408-1744104085.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.5.22-0408-1744104085.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.22-0408-1744104085.tar
- SHA-256: `ef25c2803d1b0e727748c3aeeb5c4aa950066fedfa18cb171ca3f4f0180cf5bd`
- Size: 45865618 bytes
- Version: 4.5.22
- Release date: 2025-04-08 17:20:43

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boA`

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
- `openvpn/scripts/ovpnclient-down`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=18
- `backup/installed_packages.txt`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `self/ns`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `sys/kernel/hostname`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `sys/net/ipv6/conf`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `cgi-bin/cgi-upload`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=16
- `kernel/debug/hnat/hnat_setting`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=16
- `kernel/debug/mtk-eth/reset`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=16
- `upgrade/platform.sh`: deprioritized: authentication boundary is unknown; cannot qualify as unauthenticated; auth=unknown; evidence=L2; score=16
- `class/leds/gl`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `config/nas`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `etc/openvpn/cert/dh1024.pem`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=15
- `init.d/gl_nas_sys`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `netifd/netifd-proto.sh`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `openvpn/cert/dh1024.pem`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=15
- `ppp/ip-up.d`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `run/wgclient-route-update_done`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `share/nftables.d/chain-pre/forward/02-edg.nft`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `share/nftables.d/chain-pre/input/02-edg.nft`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `wireguard/scripts/wgclient-route-update.sh`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `kernel/debug/usb/devices`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=14
- `run/ovpnclient-ovpnclient.pid`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=14
- `lib/gl_ddns/dynamic_dns_updater.sh`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=13
- `run/mwan3/iface_state/modem_0001_4`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=13
- `share/dnscrypt-proxy/dnscrypt-resolvers.csv`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=13
- `share/dnsmasq/trust-anchors.conf`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=13

### Non-HTTP Service Surface

- `cloud` (tcp, outbound): auth=device, risk=high; source=`etc/board.d/02_network`; evidence=service marker present; local sinks: system
- `cloud` (tcp, outbound): auth=device, risk=high; source=`etc/hotplug.d/firmware/11-ath10k-caldata`; evidence=service marker present; local sinks: system
- `cloud` (tcp, outbound): auth=device, risk=high; source=`etc/hotplug.d/iface/99-gl-cloud`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`etc/init.d/gl-cloud`; evidence=service marker present; local sinks: system
- `cloud` (tcp, outbound): auth=device, risk=high; source=`lib/functions/gl_util.sh`; evidence=service marker present; local sinks: system
- `cloud` (tcp, outbound): auth=device, risk=high; source=`lib/upgrade/dualboot_datachk.sh`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`lib/upgrade/platform.sh`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/cloud`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/dns`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/netmode`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/rtty`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/s2s.so`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/system`; evidence=service marker present; local sinks: system
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/vpn-policy`; evidence=service marker present; local sinks: system
- `cloud` (tcp, outbound): auth=device, risk=high; source=`usr/lib/oui-httpd/rpc/wifi`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/fonts/element-icons.732389de.ttf`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.de.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.en.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.es.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.it.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.ja.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.zh-cn.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-cloud.zh-tw.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.de.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.en.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-ipv6.es.json`; evidence=service marker present
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
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-parentalcontrol.de.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-parentalcontrol.en.json`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`www/i18n/gl-sdk4-ui-parentalcontrol.it.json`; evidence=service marker present

### Sink Summary

- exec: 31
- file_write: 243
- popen: 3
- system: 212
- unsafe_copy: 86

### Config Writer Leads

- `01-user: /etc/openvpn.user \`
- `01-user: [ -e "/etc/openvpn.user" ] && {`
- `20-firewall: /etc/init.d/firewall enabled || exit 0`
- `20-firewall: logger -t firewall "Reloading firewall due to $ACTION of $INTERFACE ($DEVICE)"`
- `21-vpnpolicy: #update_firewall`
- `21-vpnpolicy: reload_domain_firewall`
- `21-vpnpolicy: reload_mac_firewall`
- `21-vpnpolicy: set_vlan_firewall`
- `82_merge_mtk_sdk: local enable=$(uci -q get firewall.@defaults[0].flow_offloading_hw)`
- `82_merge_mtk_sdk: uci commit firewall`
- `82_merge_mtk_sdk: uci delete firewall.@defaults[0].flow_offloading`
- `82_merge_mtk_sdk: uci delete firewall.@defaults[0].flow_offloading_hw`
- `82_merge_mtk_sdk: uci set firewall.@defaults[0].flow_offloading='1'`
- `82_merge_mtk_sdk: uci set firewall.@defaults[0].flow_offloading_hw='1'`
- `97-tor: /etc/init.d/firewall reload`
- `97-tor: uci set firewall.tor_allow_http.src_dip="$new_ip"`
- `97-tor: uci set firewall.tor_allow_http.src_ip="$new_ip/$mask"`
- `97-tor: uci set firewall.tor_allow_ssh.src_dip="$new_ip"`
- `97-tor: uci set firewall.tor_allow_ssh.src_ip="$new_ip/$mask"`
- `adguardhome: /etc/init.d/firewall reload`
- `adguardhome: uci commit 'firewall'`
- `adguardhome: uci delete firewall.adguard_home`
- `adguardhome: uci delete firewall.adguard_home_guest`
- `adguardhome: uci set firewall.adguard_home.dest='lan'`
- `adguardhome: uci set firewall.adguard_home.dest_port='3053'`
- `adguardhome: uci set firewall.adguard_home.name="Adguard Home"`
- `adguardhome: uci set firewall.adguard_home.proto='tcpudp'`
- `adguardhome: uci set firewall.adguard_home.src='lan'`
- `adguardhome: uci set firewall.adguard_home.src_dport='53'`
- `adguardhome: uci set firewall.adguard_home='redirect'`

### Handler-level Correlated Flows

- `sbin/procd`: L3-correlated, score 56; sources=getenv, ubus; sinks=auth, command_execution, file_write, unsafe_memory
- `etc/init.d/dnsmasq`: L3-correlated, score 51; sources=ubus, uci_get; sinks=auth, command_execution, unsafe_memory
- `sbin/rpcd`: L3-correlated, score 51; sources=getenv, ubus; sinks=auth, file_write, unsafe_memory
- `sbin/netifd`: L3-correlated, score 48; sources=ubus; sinks=auth, file_write, unsafe_memory
- `sbin/fw3`: L3-correlated, score 46; sources=getenv, ubus; sinks=file_write, unsafe_memory
- `sbin/init`: L3-correlated, score 44; sources=getenv; sinks=command_execution, file_write, unsafe_memory
- `lib/functions/gl_util.sh`: L3-correlated, score 43; sources=ubus; sinks=command_execution, file_write
- `lib/netifd/hostapd.sh`: L3-correlated, score 43; sources=ubus; sinks=auth, file_write
- `lib/netifd/proto/directip.sh`: L3-correlated, score 43; sources=ubus; sinks=auth, command_execution
- `lib/netifd/proto/ncm.sh`: L3-correlated, score 43; sources=ubus; sinks=auth, command_execution
- `lib/netifd/proto/qcm.sh`: L3-correlated, score 43; sources=ubus; sinks=auth, command_execution
- `lib/netifd/proto/qmi.sh`: L3-correlated, score 43; sources=ubus; sinks=auth, command_execution
- `sbin/block`: L3-correlated, score 43; sources=getenv; sinks=file_write, unsafe_memory
- `sbin/sysupgrade`: L3-correlated, score 43; sources=ubus; sinks=command_execution, file_write
- `usr/lib/oui-httpd/rpc/netmode`: L3-correlated, score 43; sources=ubus; sinks=auth, file_write
- `usr/lib/oui-httpd/rpc/system`: L3-correlated, score 43; sources=ubus; sinks=auth, command_execution
- `usr/libexec/cgi-io`: L3-correlated, score 43; sources=CONTENT_LENGTH, getenv; sinks=auth, file_write, unsafe_memory
- `etc/init.d/gl_s2s`: L3-correlated, score 38; sources=ubus; sinks=command_execution
- `etc/init.d/gl_timer`: L3-correlated, score 38; sources=uci_get; sinks=command_execution
- `etc/init.d/stubby`: L3-correlated, score 38; sources=uci_get; sinks=command_execution

### Ghidra Function-local Evidence

- `rpcd:FUN_00013954` at `00013954`: route `/*`, sink `file_write`
- `rpcd:FUN_00013954` at `00013954`: route `/*`, sink `unsafe_copy`
- `rpcd:FUN_00015468` at `00015468`: route `/*`, sink `file_write`
- `rpcd:FUN_000155cc` at `000155cc`: route `/*`, sink `file_write`
- `rpcd:FUN_00015e30` at `00015e30`: route `/*`, sink `file_write`
- `rpcd:FUN_00018918` at `00018918`: route `/*`, sink `file_write`
- `rpcd:FUN_00018918` at `00018918`: route `/*`, sink `file_write`
- `rpcd:FUN_00018918` at `00018918`: route `/*`, sink `exec`
- `rpcd:FUN_00018da4` at `00018da4`: route `/*`, sink `file_write`
- `rpcd:FUN_00018da4` at `00018da4`: route `/*`, sink `exec`
- `rpcd:FUN_0001977c` at `0001977c`: route `/*`, sink `file_write`
- `rpcd:FUN_0001977c` at `0001977c`: route `/*`, sink `exec`
- `ubusd:FUN_000111e8` at `000111e8`: route `/*`, sink `file_write`
- `ubusd:FUN_00012a64` at `00012a64`: route `/*`, sink `unsafe_copy`
- `ubusd:FUN_00012a64` at `00012a64`: route `/*`, sink `memory_operation`
- `cgi-fcgi:FUN_0001118c` at `0001118c`: route `/*`, sink `file_write`
- `cgi-fcgi:FUN_0001118c` at `0001118c`: route `/*`, sink `unsafe_copy`

### Runtime Profile

- Vendor profile: openwrt
- Web stack: nginx
- State backends: dbus, ubus, uci
- Architectures: arm, script
- Executables/scripts discovered: 1002

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: etc/init.d/adguardhome, etc/init.d/avahi-daemon, etc/init.d/boot, etc/init.d/bootcount, etc/init.d/carrier-monitor, etc/init.d/cron, etc/init.d/dbus, etc/init.d/disk_manage
- Listener candidates: etc/init.d/dnsmasq, etc/init.d/nginx, usr/sbin/dnsmasq, usr/sbin/nginx
- Runtime requirements discovered: 43
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

Structured zero-day triage JSON: `known_firmware/reports/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.22-0408-1744104085.tar.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ef25c2803d1b0e72 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ef25c2803d1b0e72/_openwrt-a1300-4.5.22-0408-1744104085.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-A1300_Slate_Plus_ef25c280 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-A1300_Slate_Plus_ef25c280 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-A1300_Slate_Plus_ef25c280 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-A1300_Slate_Plus_ef25c280 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-A1300_Slate_Plus_ef25c280 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- Ghidra emitted 17 function-local route/sink evidence records.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
