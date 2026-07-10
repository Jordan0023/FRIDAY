# Firmware Audit: ASUS RT-N10+ D1 / FW_RT_N10Plus_D1_211192.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N10+_D1/FW_RT_N10Plus_D1_211192.zip
- Local path: known_firmware/firmware/ASUS_RT-N10__D1/FW_RT_N10Plus_D1_211192.zip
- SHA-256: `bba8e7726908fe89b2368c443684395f0ac80bf2be4dcc1a2f3b784d8ce9cc4b`
- Size: 3762204 bytes
- Version: 2.1.1.1.92
- Release date: 2015/01/22

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

#### `qis/QIS_internet_vpn.htm`

- Score: 19
- Evidence level: L2
- Source: string:www/qis/QIS_internet_ip.htm
- Parameters: action_mode, current_page, dhcp_info_radio, dns_info_radio, dns_info_title, dns_sec, flag, form, heartbeat_server, ifVPNfield, lan_ipaddr, lan_netmask
- Matched risk keywords: vpn
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `detectWAN.js`

- Score: 18
- Evidence level: L2
- Source: string:www/device-map/internet.asp
- Parameters: DNS1, DNS2, WANIP, connectbutton_link, connectbutton_nolink, connectionType, connectstatus, domore, gateway, internetForm, wan_status
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `device-map/wan_action.asp`

- Score: 18
- Evidence level: L2
- Source: string:www/device-map/internet.asp
- Parameters: DNS1, DNS2, WANIP, connectbutton_link, connectbutton_nolink, connectionType, connectstatus, domore, gateway, internetForm, wan_status
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `qis/QIS_detectWAN.htm`

- Score: 18
- Evidence level: L2
- Source: string:www/QIS_wizard.htm
- Parameters: Loading, QKform, action_mode, action_script, contentM, current_page, dr_sweet_advise, drword, flag, hiddenMask, http_passwd, http_username
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `apply.cgi`

- Score: 17
- Evidence level: L2
- Source: string:www/Main_DHCPStatus_Content.asp
- Parameters: Loading, LoadingBar, SystemCmd, TopBanner, action, action1, action2, action_mode, action_script, boot_days, boot_hours, boot_minutes
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `syslog.cgi`

- Score: 14
- Evidence level: L2
- Source: string:www/Main_LogStatus_Content.asp
- Parameters: Loading, TopBanner, action_mode, action_script, boot_days, boot_hours, boot_minutes, boot_seconds, current_page, firmver, first_time, footer
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `images/WANunplug.gif`

- Score: 12
- Evidence level: L2
- Source: string:www/qis/QIS_detect.htm
- Parameters: AParea, DETECT_TITLE, action_mode, current_page, detectForm, flag, fresharea, img_obj1, img_obj2, img_obj3, img_obj4, next_page
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upgrade.cgi`

- Score: 12
- Evidence level: L2
- Source: string:www/Advanced_FirmwareUpgrade_Content.asp
- Parameters: Loading, LoadingBar, TopBanner, action_mode, button, current_page, dr_sweet_advise, drword, file, firmver, footer, form
- Matched risk keywords: upgrade
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upload.cgi`

- Score: 12
- Evidence level: L2
- Source: string:www/Advanced_SettingBackup_Content.asp
- Parameters: Loading, LoadingBar, TopBanner, action1, action2, action_mode, current_page, dr_sweet_advise, drword, file, firmver, footer
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `Advanced_StorageSelectFolder_Content.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `change_lang.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `tzopanel.cgi`

- Score: 8
- Evidence level: L2
- Source: string:www/general.js
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `webcam.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

### Sink Summary

- exec: 386
- file_write: 1002
- popen: 0
- system: 1118
- unsafe_copy: 420

### Config Writer Leads

- `ATE_Get_BootLoaderVersion: /tmp/udhcpd.conf`
- `ATE_Get_BootLoaderVersion: [rc] iptables-restore mangle_rules-01`
- `ATE_Get_BootLoaderVersion: [rc] iptables-restore mangle_rules-02`
- `ATE_Get_BootLoaderVersion: [rc] restarting IPTABLES firewall.`
- `ATE_Get_BootLoaderVersion: [rc] restarting firewall.`
- `ATE_Get_BootLoaderVersion: clean_iptables`
- `ATE_Get_BootLoaderVersion: echo 0 > /proc/sys/net/bridge/bridge-nf-call-iptables &`
- `ATE_Get_BootLoaderVersion: iptables -F`
- `ATE_Get_BootLoaderVersion: iptables -X`
- `ATE_Get_BootLoaderVersion: iptables -Z`
- `ATE_Get_BootLoaderVersion: iptables -t nat -A PREROUTING -d ! %s/%s -p tcp --dport 80 -j DNAT --to-destination %s:18017`
- `ATE_Get_BootLoaderVersion: iptables -t nat -A PREROUTING -p udp --dport 53 -j DNAT --to-destination %s:18018`
- `ATE_Get_BootLoaderVersion: iptables -t nat -A PREROUTING -p udp --dport 53 -j DNAT --to-destination %s:55`
- `ATE_Get_BootLoaderVersion: iptables -t nat -F`
- `ATE_Get_BootLoaderVersion: iptables -t nat -X`
- `ATE_Get_BootLoaderVersion: iptables -t nat -Z`
- `ATE_Get_BootLoaderVersion: iptables-restore`
- `ATE_Get_BootLoaderVersion: rc restarting IPTABLES firewall.`
- `ATE_Get_BootLoaderVersion: rc restarting firewall.`
- `ATE_Get_BootLoaderVersion: restart_firewall`
- `ATE_Get_BootLoaderVersion: start_firewall`
- `ATE_Get_BootLoaderVersion: start_firewall_ex`
- `ATE_Get_BootLoaderVersion: udhcpd /tmp/udhcpd.conf &`
- `ATE_Get_CCode_2G: /tmp/udhcpd.conf`
- `ATE_Get_CCode_2G: [rc] iptables-restore mangle_rules-01`
- `ATE_Get_CCode_2G: [rc] iptables-restore mangle_rules-02`
- `ATE_Get_CCode_2G: [rc] restarting IPTABLES firewall.`
- `ATE_Get_CCode_2G: [rc] restarting firewall.`
- `ATE_Get_CCode_2G: clean_iptables`
- `ATE_Get_CCode_2G: echo 0 > /proc/sys/net/bridge/bridge-nf-call-iptables &`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_RT-N10__D1/FW_RT_N10Plus_D1_211192.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/bba8e7726908fe89

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
