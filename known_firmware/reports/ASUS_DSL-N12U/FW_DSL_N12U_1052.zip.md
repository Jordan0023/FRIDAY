# Firmware Audit: ASUS DSL-N12U / FW_DSL_N12U_1052.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12U/FW_DSL_N12U_1052.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12U/FW_DSL_N12U_1052.zip
- SHA-256: `1a0935f8186cd7df8fcfb038f0e74f5e229e5aed5ef784fab6b458450e136b69`
- Size: 3986428 bytes
- Version: 1.0.5.2
- Release date: 2015/01/12

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PASSWORD, Password, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, HTTPD, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `/bin/ash, /bin/sh, SYSTEM, System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

### Outdated crypto/library markers

Old OpenSSL/BusyBox versions may contain known CVEs and should be mapped to package versions.

Evidence: `BusyBox v1.12`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

#### `Advanced_Eth_WAN_Content.asp`

- Score: 18
- Evidence level: L2
- Source: string:www/Advanced_DualWan_Route_Config.asp
- Parameters: GWStatic, GWStaticList_Block, Loading, TopBanner, action_mode, action_script, adslSyncSts, adslsync, button, case_3g_wan, case_dsl, case_eth_wan
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `Advanced_WAN_Content.asp`

- Score: 18
- Evidence level: L2
- Source: string:www/RU.dict
- Parameters: Adv_setting, DSLWANList_s, Dev3G, EVDO_on, Loading, TopBanner, action_mode, action_mode_edit, action_script, adslSyncSts, adslsync, backup_wan_conn
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `DSL_WAN_Content.asp`

- Score: 18
- Evidence level: L2
- Source: string:www/Edit_Advanced_DSL_WAN_Config.asp
- Parameters: DSLWANList_s, Loading, TopBanner, action_mode, action_mode_edit, action_script, current_page, dsl_DHCPClient_0, dsl_dns1_0, dsl_dns2_0, dsl_dnsenable_0, dsl_encap_0
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `detectWAN.js`

- Score: 18
- Evidence level: L2
- Source: string:www/device-map/internet.asp
- Parameters: DNS1, DNS2, Router_domore, WANIP, WPSForm, action_mode, action_script, all_related_wep, all_wep_key, applySecurity, apply_tr, connectbtn_show
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `device-map/wan_action.asp`

- Score: 18
- Evidence level: L2
- Source: string:www/device-map/internet.asp
- Parameters: DNS1, DNS2, Router_domore, WANIP, WPSForm, action_mode, action_script, all_related_wep, all_wep_key, applySecurity, apply_tr, connectbtn_show
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `apply.cgi`

- Score: 17
- Evidence level: L2
- Source: string:www/Main_DHCPStatus_Content.asp
- Parameters: Loading, LoadingBar, SystemCmd, TopBanner, WLANConfig11b_WirelessCtrl_button, WLANConfig11b_WirelessCtrl_button1, action, action1, action2, action_mode, action_mode2, action_script
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `3ginfo.cgi`

- Score: 14
- Evidence level: L2
- Source: string:www/Main_LogStatus_Content.asp
- Parameters: Loading, TopBanner, action_mode, action_mode2, action_script, boot_days, boot_hours, boot_minutes, boot_seconds, btn_3ginfo, current_page, firmver
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `adsllog.cgi`

- Score: 14
- Evidence level: L2
- Source: string:www/Main_AdslStatus_Content.asp
- Parameters: Loading, TopBanner, action_mode, action_mode2, action_script, current_page, firmver, first_time, footer, form, form2, group_id
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `syslog.cgi`

- Score: 14
- Evidence level: L2
- Source: string:www/Main_LogStatus_Content.asp
- Parameters: Loading, TopBanner, action_mode, action_mode2, action_script, boot_days, boot_hours, boot_minutes, boot_seconds, btn_3ginfo, current_page, firmver
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upgrade.cgi`

- Score: 12
- Evidence level: L2
- Source: string:www/Advanced_FirmwareUpgrade_Content.asp
- Parameters: Loading, LoadingBar, TopBanner, action_mode, button, current_page, file, firmver, footer, form, help_td, helpicon
- Matched risk keywords: upgrade
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upload.cgi`

- Score: 12
- Evidence level: L2
- Source: string:www/Advanced_SettingBackup_Content.asp
- Parameters: Loading, LoadingBar, TopBanner, action1, action2, action_mode, current_page, dr_sweet_advise, drword, file, firmver, footer
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `images/WANunplug.gif`

- Score: 9
- Evidence level: L2
- Source: string:www/qis/QIS_detect.htm
- Parameters: CheckLink, DETECT_TITLE, DetectFail, Detecting, LinkDown, action_mode, current_page, detectForm, detect_frame, flag, next_page, preferred_lang
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `change_lang.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpd
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

- exec: 479
- file_write: 2519
- popen: 5
- system: 1233
- unsafe_copy: 556

### Config Writer Leads

- `3g.sh: iptables --append FORWARD --in-interface br0 -j ACCEPT`
- `3g.sh: iptables --table nat --append POSTROUTING --out-interface eth0 -j MASQUERADE`
- `3ginfo.sh: cat /tmp/udhcpd.conf`
- `3ginfo.sh: echo "udhcpd.conf >"`
- `AR.dict: FirewallConfig_DoSEnable_itemdesc=`
- `AR.dict: FirewallConfig_DoSEnable_itemname=`
- `AR.dict: FirewallConfig_FirewallEnable_itemdesc=`
- `AR.dict: FirewallConfig_FirewallEnable_itemname=`
- `AR.dict: FirewallConfig_LWFilterList_groupitemdesc=`
- `AR.dict: FirewallConfig_LWFilterList_widzarddesc=`
- `AR.dict: FirewallConfig_LanWanActiveDate_itemdesc=`
- `AR.dict: FirewallConfig_LanWanActiveDate_itemname=`
- `AR.dict: FirewallConfig_LanWanActiveTime_itemdesc=`
- `AR.dict: FirewallConfig_LanWanActiveTime_itemname=`
- `AR.dict: FirewallConfig_LanWanDefaultAct_itemdesc=`
- `AR.dict: FirewallConfig_LanWanDefaultAct_itemname=`
- `AR.dict: FirewallConfig_LanWanDstIP_itemname=`
- `AR.dict: FirewallConfig_LanWanDstPort_itemname=`
- `AR.dict: FirewallConfig_LanWanFirewallEnable_itemdesc=`
- `AR.dict: FirewallConfig_LanWanFirewallEnable_itemname=`
- `AR.dict: FirewallConfig_LanWanICMP_itemdesc=`
- `AR.dict: FirewallConfig_LanWanICMP_itemname=`
- `AR.dict: FirewallConfig_LanWanProFlag_itemname=`
- `AR.dict: FirewallConfig_LanWanSrcIP_itemname=`
- `AR.dict: FirewallConfig_LanWanSrcPort_itemname=`
- `AR.dict: FirewallConfig_MFList_accept_hint1=`
- `AR.dict: FirewallConfig_MFList_groupitemname=`
- `AR.dict: FirewallConfig_MFMethod_item1=`
- `AR.dict: FirewallConfig_MFMethod_item2=`
- `AR.dict: FirewallConfig_MFMethod_itemdesc=`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_DSL-N12U/FW_DSL_N12U_1052.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/1a0935f8186cd7df

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
