# Firmware Audit: ASUS WL-566gM / WL566gM_1018_EN_TW_DE_CN_KR.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-566gM/WL566gM_1018_EN_TW_DE_CN_KR.zip
- Local path: known_firmware/firmware/ASUS_WL-566gM/WL566gM_1018_EN_TW_DE_CN_KR.zip
- SHA-256: `852cb1bbfdaafdfe7239ad32388b82756099a564a6b4826d62eb719f51079730`
- Size: 3587916 bytes
- Version: 1.0.1.8
- Release date: 2007/06/14

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, Secret, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boa, cgi-bin, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `/bin/sh, System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

### Outdated crypto/library markers

Old OpenSSL/BusyBox versions may contain known CVEs and should be mapped to package versions.

Evidence: `BusyBox v1.00, OpenSSL 0.`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

#### `apply.cgi`

- Score: 20
- Evidence level: L2
- Source: string:www/Main_DHCPStatus_Content.asp
- Parameters: ACLList, ACLList_s, Broadband, Confirm, Country, GWStatic, GWStatic_s, KnownApps, LANHostConfig_x_DDNSStatus_button, LWFilterList, LWFilterList_s, LWKnownApps
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `syslog.cgi`

- Score: 14
- Evidence level: L2
- Source: string:www/Main_LogStatus_Content.asp
- Parameters: action, action_mode, action_script, current_page, first_time, form, form1, form2, form3, group_id, modified, next_host
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upgrade.cgi`

- Score: 12
- Evidence level: L2
- Source: string:www/Advanced_FirmwareUpgrade_Content.asp
- Parameters: Mode, action_mode, button, current_page, file, form, next_page, overDiv, preferred_lang
- Matched risk keywords: upgrade
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upload.cgi`

- Score: 12
- Evidence level: L2
- Source: string:www/Advanced_SettingBackup_Content.asp
- Parameters: Mode, action_mode, current_page, file, next_page, overDiv, preferred_lang
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `change_lang.cgi`

- Score: 11
- Evidence level: L2
- Source: string:www/Title.asp
- Parameters: current_page, first_time, form, next_host, overDiv, preferred_lang, preferred_lang_menu, productid, wan_nat_x, wan_route_x
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `acllog.cgi`

- Score: 8
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `webcam.cgi`

- Score: 8
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

### Sink Summary

- exec: 1428
- file_write: 1935
- popen: 2
- system: 3321
- unsafe_copy: 293

### Config Writer Leads

- `Advanced_BasicFirewall_Content.asp: </td><td class="content_input_td"><input type="radio" value="1" name="fw_enable_x" class="content_input_fd" onClick="return change_common_radio(this, 'FirewallC`
- `Advanced_BasicFirewall_Content.asp: </td><td class="content_input_td"><input type="radio" value="1" name="fw_sipblock" class="content_input_fd" onClick="return change_common_radio(this, 'FirewallC`
- `Advanced_BasicFirewall_Content.asp: </td><td class="content_input_td"><input type="radio" value="1" name="misc_http_x" class="content_input_fd" onClick="return change_common_radio(this, 'FirewallC`
- `Advanced_BasicFirewall_Content.asp: </td><td class="content_input_td"><input type="radio" value="1" name="misc_ping_x" class="content_input_fd" onClick="return change_common_radio(this, 'FirewallC`
- `Advanced_BasicFirewall_Content.asp: </td><td class="content_input_td"><input type="text" maxlength="5" size="5" name="misc_httpport_x" class="content_input_fd" value="<% nvram_get_x("FirewallConfi`
- `Advanced_BasicFirewall_Content.asp: </td><td class="content_input_td"><select name="fw_log_x" class="content_input_fd" onChange="return change_common(this, 'FirewallConfig', 'fw_log_x')"><option c`
- `Advanced_BasicFirewall_Content.asp: <input type="hidden" name="current_page" value="Advanced_BasicFirewall_Content.asp"><input type="hidden" name="next_page" value="Advanced_Firewall_Content.asp">`
- `Advanced_BasicFirewall_Content.asp: <td class="content_desc_td" colspan="2"><#FirewallConfig_display2_sectiondesc#>`
- `Advanced_BasicFirewall_Content.asp: <td class="content_header_td" onMouseOver="return overlib('<#FirewallConfig_DoS_itemdesc#>', LEFT);" onMouseOut="return nd();"><#FirewallConfig_DoS_itemname#>`
- `Advanced_BasicFirewall_Content.asp: <td class="content_header_td" onMouseOver="return overlib('<#FirewallConfig_WanLanLog_itemdesc#>', LEFT);" onMouseOut="return nd();"><#FirewallConfig_WanLanLog_`
- `Advanced_BasicFirewall_Content.asp: <td class="content_header_td" onMouseOver="return overlib('<#FirewallConfig_x_WanPingEnable_itemdesc#>', LEFT);" onMouseOut="return nd();"><#FirewallConfig_x_Wa`
- `Advanced_BasicFirewall_Content.asp: <td class="content_header_td" onMouseOver="return overlib('<#FirewallConfig_x_WanWebEnable_itemdesc#>', LEFT);" onMouseOut="return nd();"><#FirewallConfig_x_Wan`
- `Advanced_BasicFirewall_Content.asp: <td class="content_header_td" onMouseOver="return overlib('<#FirewallConfig_x_WanWebPort_itemdesc#>', LEFT);" onMouseOut="return nd();"><#FirewallConfig_x_WanWe`
- `Advanced_BasicFirewall_Content.asp: <td class="content_header_td"><#FirewallConfig_FirewallEnable_itemname#>`
- `Advanced_FilterHelp_Widzard.asp: <b><#FirewallConfig_WanLanSrcIP_helpitem#></b> : <#FHELP_desc4#>`
- `Advanced_FilterHelp_Widzard.asp: <b><#FirewallConfig_WanLanSrcPort_itemname#></b> : <#FHELP_desc5#>`
- `Advanced_Firewall_Content.asp: <% nvram_get_table_x("FirewallConfig","LWFilterList"); %>`
- `Advanced_Firewall_Content.asp: </td><td class="content_input_td"><input type="hidden" maxlength="11" class="content_input_fd" size="11" name="filter_lw_time_x" value="<% nvram_get_x("Firewall`
- `Advanced_Firewall_Content.asp: </td><td class="content_input_td"><input type="hidden" maxlength="7" class="content_input_fd" size="7" name="filter_lw_date_x" value="<% nvram_get_x("FirewallCo`
- `Advanced_Firewall_Content.asp: </td><td class="content_input_td"><input type="radio" value="1" name="fw_lw_enable_x" class="content_input_fd" onClick="return change_common_radio(this, 'Firewa`
- `Advanced_Firewall_Content.asp: </td><td class="content_list_field_header_td" colspan=""><#FirewallConfig_LanWanDstPort_itemname#>`
- `Advanced_Firewall_Content.asp: </td><td class="content_list_field_header_td" colspan=""><#FirewallConfig_LanWanProFlag_itemname#>`
- `Advanced_Firewall_Content.asp: <input type="hidden" name="current_page" value="Advanced_Firewall_Content.asp"><input type="hidden" name="next_page" value="Advanced_URLFilter_Content.asp"><inp`
- `Advanced_Firewall_Content.asp: <input type="hidden" name="filter_lw_num_x_0" value="<% nvram_get_x("FirewallConfig", "filter_lw_num_x"); %>" readonly="1"></td><td width="10%">`
- `Advanced_Firewall_Content.asp: <td class="content_desc_td" colspan="2"><#FirewallConfig_display4_sectiondesc#>`
- `Advanced_Firewall_Content.asp: <td class="content_header_td" onMouseOver="return overlib('<#FirewallConfig_LanWanActiveDate_itemdesc#>', LEFT);" onMouseOut="return nd();"><#FirewallConfig_Lan`
- `Advanced_Firewall_Content.asp: <td class="content_header_td" onMouseOver="return overlib('<#FirewallConfig_LanWanActiveTime_itemdesc#>', LEFT);" onMouseOut="return nd();"><#FirewallConfig_Lan`
- `Advanced_Firewall_Content.asp: <td class="content_header_td"><#FirewallConfig_LanWanFirewallEnable_itemname#>`
- `Advanced_Firewall_Content.asp: <td class="content_list_header_td" width="60%" id="LWFilterList"><#FirewallConfig_LWFilterList_groupitemdesc#>`
- `Advanced_Firewall_Content.asp: <td class="content_section_header_td" colspan="2"><#FirewallConfig_LanWanFirewallEnable_sectionname#>`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_WL-566gM/WL566gM_1018_EN_TW_DE_CN_KR.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/852cb1bbfdaafdfe

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
