# Firmware Audit: RAX9 / RAX9-V1.0.3.32.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX9/RAX9-V1.0.3.32.zip
- Local path: known_firmware/firmware/RAX9/RAX9-V1.0.3.32.zip
- SHA-256: `0d20c9b101b197d3bacc1d8d8749db1716208984cd21432c6d98dca50c5c051d`
- Size: 22788329 bytes
- Version: 1.0.3.32
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

- `network/switch.sh`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `sbin/ip`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `en/howto_openvpn.aspx`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=15
- `index.php/access-server/docs/admin-guides-sp-859543150/howto-desktop-client-configuration/495-connecting-to-openvpn-access-server-using-the-connect-client-on-mac.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=15
- `lib/ddns/dynamic_dns_functions.sh`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=13
- `config/landev`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `etc/config/fstab`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `lanSetup.lua`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `network/swl`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `sbin/quagga.init`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `state/dhcpconfigchanged`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `upper/etc/config/fstab`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `wireless/l1profile.dat`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `xagent/certs/ca-bundle-mega.crt`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `xagent/genie_handler`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `zebra/ripd.conf`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `zebra/zebra.conf`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `config/ddns`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L2; score=11
- `init.d/ddns`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L2; score=11
- `log/ddns`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L2; score=11
- `run/ddns`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L2; score=11
- `FW_forward.htm`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `SrnhLecUIw4OGEfhefwVVdCx/CVxY3UzHCMrr1zZ7Ud3YA47Dx7SwNxk`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `fw/cfu_notify`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=10
- `sbin/ntpd`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=10
- `sbin/ntpd-hotplug`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=10
- `self/ns/net`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `share/libubox/jshn.sh`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=10
- `share/zoneinfo`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=10
- `hotplug.d/iface/95-ddns`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=8

### Non-HTTP Service Surface

- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/1095C94`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/10A3CF8`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/11C67B2`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/12256DD`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/122F4D0`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/12576BE`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/126FFFA`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/12AA44F`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/1301048`; evidence=service marker present
- `dhcpd` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/46CC1F`; evidence=service marker present
- `dhcpd` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/BC780F`; evidence=service marker present; local sinks: exec, file_write, popen
- `dnsmasq` (udp/tcp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/46CC1F`; evidence=service marker present
- `mesh` (unknown, lan/wireless): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/A82AFA`; evidence=service marker present
- `mesh` (unknown, lan/wireless): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/B98E7A`; evidence=service marker present
- `mesh` (unknown, lan/wireless): auth=device, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/RAX9-V1.0.3.32_Release_Notes.htm`; evidence=service marker present
- `telnetd` (tcp, lan): auth=unknown, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/3BE609`; evidence=service marker present; local sinks: file_write, system
- `telnetd` (tcp, lan): auth=unknown, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/46CC1F`; evidence=service marker present
- `udhcpd` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/46CC1F`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/102D855`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/10A3CF8`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/11AC9DA`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/11CD561`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/11FBBCB`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/12256DD`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/122F4D0`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/1232570`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/12576BE`; evidence=service marker present; local sinks: file_write
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/1290B64`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/12AA44F`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/12B118C`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/12E8E4B`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/13405F4`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/1363564`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX9-V1.0.3.32.zip.extracted/FFB54C`; evidence=service marker present
- `ftpd` (tcp, lan): auth=unknown, risk=medium; source=`_RAX9-V1.0.3.32.zip.extracted/46CC1F`; evidence=service marker present
- `dropbear` (tcp, lan): auth=required, risk=low; source=`_RAX9-V1.0.3.32.zip.extracted/46CC1F`; evidence=service marker present

### Sink Summary

- exec: 6
- file_write: 67
- popen: 2
- system: 20
- unsafe_copy: 46

### Config Writer Leads

- `10A3CF8: ch adres (NAT) ani firewallem.</p></p>",`
- `10A3CF8: firewall s`
- `10A3CF8: nou firewall. Pakety mezi porty v`
- `10A3CF8: ny firewall.</p><p>Klikn`
- `11AC9DA: "AWN029" : "Firewallregler for udg`
- `11AC9DA: "AWN030" : "Firewallregler for indg`
- `11AC9DA: ben) en meget mindre sikker firewall, da den tillader n`
- `11AC9DA: ende trafik. Valgmuligheden Secured (Sikker) giver en sikret firewall til at beskytte pc&apos;erne p`
- `121C203: "firewall001" : "`
- `121C203: "firewall002" : "`
- `121C203: "firewall003" : "`
- `121C203: "firewall004" : "`
- `121C203: "firewall005" : "`
- `121C203: "firewall006" : "`
- `121C203: "firewall007" : "`
- `121C203: "firewall008" : "`
- `121C203: "firewall009" : "`
- `121C203: "firewall010" : "`
- `121C203: "firewall011" : "`
- `121C203: "firewall012" : "VPN-PPTP(TCP:1723)",`
- `121C203: "firewall013" : "VPN-L2TP(UDP:1701)",`
- `121C203: "firewall014" : "REXEC(TCP:514)",`
- `121C203: "firewall015" : "RLOGIN(TCP:513)",`
- `121C203: "firewall016" : "RTELNET(TCP:107)",`
- `121C203: "firewall017" : "RTSP(TCP/UDP:554)",`
- `121C203: "firewall018" : "SFTP(TCP:115)",`
- `121C203: "firewall019" : "SMTP(TCP:25)",`
- `121C203: "firewall020" : "SNMP(TCP/UDP:161)",`
- `121C203: "firewall021" : "SNMP-TRAPS(TCP/UDP:162)",`
- `121C203: "firewall022" : "SQL-NET(TCP:1521)",`

### Handler-level Correlated Flows

- `_RAX9-V1.0.3.32.zip.extracted/725511`: L3-correlated, score 51; sources=getenv, ubus; sinks=command_execution, file_write, unsafe_memory
- `_RAX9-V1.0.3.32.zip.extracted/3BE609`: L3-correlated, score 43; sources=ubus; sinks=command_execution, file_write
- `_RAX9-V1.0.3.32.zip.extracted/818A86`: L2-co-located, score 33; sources=getenv; sinks=file_write, unsafe_memory
- `_RAX9-V1.0.3.32.zip.extracted/8B8549`: L2-co-located, score 33; sources=getenv; sinks=file_write, unsafe_memory
- `_RAX9-V1.0.3.32.zip.extracted/4FCEFB`: L3-correlated, score 30; sources=ubus; sinks=unsafe_memory
- `_RAX9-V1.0.3.32.zip.extracted/C313CB`: L2-co-located, score 28; sources=getenv; sinks=file_write

### Ghidra Function-local Evidence

- `5CCE02:FUN_00010d0c` at `00010d0c`: route `/*`, sink `unsafe_copy`
- `5CCE02:FUN_00010d0c` at `00010d0c`: route `/ipv4/ip_tunnel.c`, sink `unsafe_copy`
- `725511:_ftext` at `004012a0`: route `/proc/swaps`, sink `file_write`
- `725511:_ftext` at `004012a0`: route `/proc/swaps`, sink `memory_operation`
- `725511:_ftext` at `004012a0`: route `/mnt/%s`, sink `file_write`
- `725511:_ftext` at `004012a0`: route `/mnt/%s`, sink `memory_operation`
- `725511:_ftext` at `004012a0`: route `/dev/%s`, sink `file_write`
- `725511:_ftext` at `004012a0`: route `/dev/%s`, sink `memory_operation`
- `725511:_ftext` at `004012a0`: route `/tmp/jffs_cfg`, sink `file_write`
- `725511:_ftext` at `004012a0`: route `/tmp/jffs_cfg`, sink `memory_operation`
- `725511:_ftext` at `004012a0`: route `/tmp/overlay`, sink `file_write`
- `725511:_ftext` at `004012a0`: route `/tmp/overlay`, sink `memory_operation`
- `725511:_ftext` at `004012a0`: route `/*`, sink `file_write`
- `725511:_ftext` at `004012a0`: route `/*`, sink `memory_operation`
- `725511:FUN_00401ff8` at `00401ff8`: route `/proc/swaps`, sink `file_write`
- `725511:FUN_00401ff8` at `00401ff8`: route `/*`, sink `file_write`
- `725511:FUN_004022b4` at `004022b4`: route `/proc/self/mountinfo`, sink `file_write`
- `725511:FUN_00402734` at `00402734`: route `/usr/sbin/dosfsck`, sink `exec`
- `725511:FUN_00402734` at `00402734`: route `/usr/sbin/fsck.f2fs`, sink `exec`
- `725511:FUN_00402734` at `00402734`: route `/usr/sbin/e2fsck`, sink `exec`
- `725511:FUN_00402734` at `00402734`: route `/*`, sink `exec`
- `725511:FUN_004028a8` at `004028a8`: route `/dev/null`, sink `file_write`
- `725511:FUN_00402914` at `00402914`: route `/sbin/mount.%s`, sink `exec`
- `725511:FUN_00402914` at `00402914`: route `/*`, sink `exec`
- `725511:FUN_00402bac` at `00402bac`: route `/*`, sink `unsafe_copy`
- `725511:FUN_00402bac` at `00402bac`: route `/*`, sink `unsafe_copy`
- `725511:FUN_004032f4` at `004032f4`: route `/proc/mtd`, sink `file_write`
- `725511:FUN_004032f4` at `004032f4`: route `/dev/mtdblock%s`, sink `file_write`
- `725511:FUN_004033d0` at `004033d0`: route `/dev`, sink `file_write`
- `725511:FUN_004033d0` at `004033d0`: route `/dev/%s`, sink `file_write`

### Runtime Profile

- Vendor profile: generic
- Web stack: not identified
- State backends: not identified
- Architectures: mipsel
- Executables/scripts discovered: 38

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: none identified
- Listener candidates: none identified
- Runtime requirements discovered: 0
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 291
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

Structured zero-day triage JSON: `known_firmware/reports/RAX9/RAX9-V1.0.3.32.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0d20c9b101b197d3 stopped: extraction exceeded 768 MB: WARNING: Extractor.execute failed to run external extractor 'unstuff '%e'': [Errno 2] No such file or directory: 'unstuff', 'unstuff '%e'' might not be installed correctly

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX9_0d20c9b1 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- Ghidra emitted 54 function-local route/sink evidence records.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
