# Firmware Audit: ASUS WL-500gP V2 / FW_WL500gpv2_3044_TW.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-500gPV2/FW_WL500gpv2_3044_TW.zip
- Local path: known_firmware/firmware/ASUS_WL-500gP_V2/FW_WL500gpv2_3044_TW.zip
- SHA-256: `eeae5a79fb7c2752f7b8259300e12fdd43d9ac5d4e77aa34a7052d5e6df76d02`
- Size: 6811325 bytes
- Version: 3.0.4.4
- Release date: 2010/03/23

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `/bin/sh, SYSTEM, System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

#### `apply.cgi`

- Score: 20
- Evidence level: L2
- Source: string:www/Main_DHCPStatus_Content.asp
- Parameters: Loading, LoadingBar, PPPConnection_x_WANAction_button, PPPConnection_x_WANAction_button1, PrinterStatus_x_PrinterAction2_button, PrinterStatus_x_PrinterAction_button, SystemCmd, TopBanner, action, action1, action2, action_mode
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

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
- Parameters: DNS1, DNS2, WANIP, connectbutton, connectionType, connectstatus, gateway
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `device-map/wan_action.asp`

- Score: 18
- Evidence level: L2
- Source: string:www/device-map/HSDPA.asp
- Parameters: DNS1, DNS2, WANIP, action_mode, connectbutton, connectedtime, connectionType, connectstatus, current_page, form, gateway, group_id
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `images/WANunplug.gif`

- Score: 15
- Evidence level: L2
- Source: string:www/qis/QIS_detect.htm
- Parameters: AParea, DETECT_TITLE, action_mode, action_script, current_page, detectForm, detect_frame, flag, fresharea, next_page, preferred_lang, prev_page
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `syslog.cgi`

- Score: 14
- Evidence level: L2
- Source: string:www/Main_LogStatus_Content.asp
- Parameters: Loading, TopBanner, action_mode, action_script, boot_days, boot_hours, boot_minutes, boot_seconds, current_page, firmver, first_time, footer
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

#### `webcam.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

### Sink Summary

- exec: 219
- file_write: 723
- popen: 0
- system: 591
- unsafe_copy: 362

### Config Writer Leads

- `Advanced_ACL_Content.asp: <a class="hintstyle" href="javascript:void(0);" onClick="openHint(18,1);"><#FirewallConfig_MFMethod_itemname#></a>`
- `Advanced_ACL_Content.asp: <option class="content_input_fd" value="allow" <% nvram_match_x("DeviceSecurity11a","wl_macmode", "allow","selected"); %>><#FirewallConfig_MFMethod_item1#></opt`
- `Advanced_ACL_Content.asp: <option class="content_input_fd" value="deny" <% nvram_match_x("DeviceSecurity11a","wl_macmode", "deny","selected"); %>><#FirewallConfig_MFMethod_item2#></optio`
- `Advanced_ACL_Content.asp: <th align="right"><#FirewallConfig_MFList_groupitemname#></th>`
- `Advanced_ACL_Content.asp: <th width="30%"><#FirewallConfig_MFhwaddr_itemname#>`
- `Advanced_ACL_Content.asp: if(confirm("<#FirewallConfig_MFList_accept_hint1#>")){`
- `Advanced_ACL_Content.asp: var wl_macnum_x = '<% nvram_get_x("FirewallConfig", "wl_macnum_x"); %>';`
- `Advanced_BasicFirewall_Content.asp: <input type="hidden" name="current_page" value="Advanced_BasicFirewall_Content.asp">`
- `Advanced_BasicFirewall_Content.asp: <input type="hidden" name="sid_list" value="FirewallConfig;">`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="0" name="fw_dos_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'fw_dos_x', '0')" <% nvram_match_x("Fire`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="0" name="fw_enable_x"  onClick="return change_common_radio(this, 'FirewallConfig', 'fw_enable_x', '0')" <% nvram_match_x("FirewallCon`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="0" name="misc_http_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'misc_http_x', '0')" <% nvram_match_x`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="0" name="misc_lpr_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'misc_lpr_x', '0')" <% nvram_match_x("`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="0" name="misc_ping_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'misc_ping_x', '0')" <% nvram_match_x`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="1" name="fw_dos_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'fw_dos_x', '1')" <% nvram_match_x("Fire`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="1" name="misc_http_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'misc_http_x', '1')" <% nvram_match_x`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="1" name="misc_lpr_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'misc_lpr_x', '1')" <% nvram_match_x("`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="1" name="misc_ping_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'misc_ping_x', '1')" <% nvram_match_x`
- `Advanced_BasicFirewall_Content.asp: <option value="accept" <% nvram_match_x("FirewallConfig","fw_log_x", "accept","selected"); %>>Accepted</option>`
- `Advanced_BasicFirewall_Content.asp: <option value="both" <% nvram_match_x("FirewallConfig","fw_log_x", "both","selected"); %>>Both</option>`
- `Advanced_BasicFirewall_Content.asp: <option value="drop" <% nvram_match_x("FirewallConfig","fw_log_x", "drop","selected"); %>>Dropped</option>`
- `Advanced_BasicFirewall_Content.asp: <option value="none" <% nvram_match_x("FirewallConfig","fw_log_x", "none","selected"); %>>None</option>`
- `Advanced_BasicFirewall_Content.asp: <select name="fw_log_x" class="input" onchange="return change_common(this, 'FirewallConfig', 'fw_log_x')">`
- `Advanced_BasicFirewall_Content.asp: <td bgcolor="#FFFFFF"><#FirewallConfig_display2_sectiondesc#></td>`
- `Advanced_BasicFirewall_Content.asp: <td width="300"><input type="radio" value="1" name="fw_enable_x"  onClick="return change_common_radio(this, 'FirewallConfig', 'fw_enable_x', '1')" <% nvram_matc`
- `Advanced_BasicFirewall_Content.asp: <td><input type="text" maxlength="5" size="5" name="misc_httpport_x" class="input" value="<% nvram_get_x("FirewallConfig", "misc_httpport_x"); %>" onkeypress="r`
- `Advanced_BasicFirewall_Content.asp: <th align="right"><#FirewallConfig_DoSEnable_itemname#></th>`
- `Advanced_BasicFirewall_Content.asp: <th align="right"><a class="hintstyle" href="javascript:void(0);" onClick="openHint(8,1);"><#FirewallConfig_WanLanLog_itemname#></a></th>`
- `Advanced_BasicFirewall_Content.asp: <th align="right"><a class="hintstyle" href="javascript:void(0);" onClick="openHint(8,2);"><#FirewallConfig_x_WanWebEnable_itemname#></a></th>`
- `Advanced_BasicFirewall_Content.asp: <th align="right"><a class="hintstyle" href="javascript:void(0);" onClick="openHint(8,3);"><#FirewallConfig_x_WanWebPort_itemname#></a></th>`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_WL-500gP_V2/FW_WL500gpv2_3044_TW.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/eeae5a79fb7c2752

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
