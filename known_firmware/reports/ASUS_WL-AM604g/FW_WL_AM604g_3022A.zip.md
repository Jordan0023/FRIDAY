# Firmware Audit: ASUS WL-AM604g / FW_WL_AM604g_3022A.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-AM604g/FW_WL_AM604g_3022A.zip
- Local path: known_firmware/firmware/ASUS_WL-AM604g/FW_WL_AM604g_3022A.zip
- SHA-256: `403f2980953e553fe251b4a283e874e1cd77472c325b5b0d3d9946d03fd9bb6a`
- Size: 3564417 bytes
- Version: 3.0.2.2A
- Release date: 2010/04/28

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, Secret, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd, sshd, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

### Outdated crypto/library markers

Old OpenSSL/BusyBox versions may contain known CVEs and should be mapped to package versions.

Evidence: `BusyBox v1.00`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

#### `QIS_ntwksum2.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/qis/QIS_mercfg.html
- Parameters: CityList, City_tr, CountryList, ISP, ISPList, ISP_tr, Service, Service_tr, action_mode, atmVci, atmVpi, cbVlan
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `enblservice.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/pppoe.html
- Parameters: enblOnDemand, enblPppIpAddress, form, nextButton, pppAuthMethod, pppInfo, pppInfo2, pppIpAddressInfo, pppIpAddressInfo2, pppIpExtension, pppLocalIpAddress, pppMtu
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `enblwl.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/mercfg.html
- Parameters: cbVlan, defaultGateway, dns, dnsPrimary, dnsSecondary, enblOnDemand, enblPppIpAddress, encSel, enetWan, form, gw, gwAddr
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `natcfg2.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/mercfg.html
- Parameters: defaultGateway, dns, dnsPrimary, dnsSecondary, gw, gwAddr, gwIfc, wan, wanIf, wanIpAddress, wanSubnetMask
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `pppauthinfo.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/pppoe.html
- Parameters: enblOnDemand, enblPppIpAddress, form, nextButton, pppAuthMethod, pppInfo, pppInfo2, pppIpAddressInfo, pppIpAddressInfo2, pppIpExtension, pppLocalIpAddress, pppMtu
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `Advanced_WAN_Content.asp`

- Score: 18
- Evidence level: L2
- Source: string:webs/error_page.htm
- Parameters: Adv_setting, Clients_table, LoadingBar, ParentalControlList_s, action_mode, action_script, alert_block, applyClient, applyFrame, blockedClients_table, case1, case2
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `detectWAN.js`

- Score: 18
- Evidence level: L2
- Source: string:webs/device-map/internet.asp
- Parameters: DNS1, DNS2, Internet_domore, Renew_Btn, WANIP, action_mode, action_script, applyFrame, connectionType, connectstatus, current_page, form
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `wancfg.cmd`

- Score: 15
- Evidence level: L2
- Source: string:webs/Advanced_WAN_Content.asp
- Parameters: Loading, TopBanner, action_mode, action_script, current_page, firmver, first_time, footer, form, group_id, help_td, helpicon
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `wancfg.html`

- Score: 15
- Evidence level: L2
- Source: string:webs/Advanced_WAN_Content.asp
- Parameters: Loading, TopBanner, action_mode, action_script, current_page, firmver, first_time, footer, form, group_id, help_td, helpicon
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `adslcfg.cgi`

- Score: 14
- Evidence level: L2
- Source: string:webs/adslcfg.html
- Parameters: Loading, TopBanner, action_mode, action_script, adslBitswap, adslMod, adslPair, adslSra, button, current_page, firmver, first_time
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `apply.cgi`

- Score: 14
- Evidence level: L2
- Source: string:webs/Main_IPTStatus_Content.asp
- Parameters: Loading, TopBanner, action, action_mode, action_script, current_page, firmver, first_time, footer, form, group_id, help_td
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `stat_wanreset.htm`

- Score: 12
- Evidence level: L2
- Source: string:webs/Statistics_LAN_WAN.asp
- Parameters: LAN_Statistics_Block, Loading, TopBanner, WAN_Statistics_Block, action, action_mode, action_script, button, current_page, firmver, first_time, footer
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upgrade.cgi`

- Score: 12
- Evidence level: L2
- Source: string:webs/Advanced_FirmwareUpgrade_Content.asp
- Parameters: Loading, LoadingBar, TopBanner, action_mode, button, current_page, file, firmver, footer, form, help_td, helpicon
- Matched risk keywords: upgrade
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upload.cgi`

- Score: 12
- Evidence level: L2
- Source: string:webs/Advanced_SettingBackup_Content.asp
- Parameters: Loading, LoadingBar, TopBanner, action1, action2, action_mode, backupform, current_page, file, firmver, footer, form
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `QIS_pppoe.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/qis/QIS_manual_setting.htm
- Parameters: CityList, City_tr, CountryList, ISP, ISPList, ISP_tr, Service, Service_tr, action_mode, atmVci, atmVpi, cbVlan
- Matched risk keywords: pppoe
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `pppoe.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/ntwkprtcl.html
- Parameters: cbVlan, encSel, enetWan, form, ntwkPrtcl, vlanEnblInfo, vlanIdInfo, vlanIdText
- Matched risk keywords: pppoe
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `wancfg_add.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/ntwksum2.html
- Parameters: btnSave
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `wancfg_remove.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/wancfg.html
- Parameters: WAN_table, form, rml
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `images/WANunplug.gif`

- Score: 9
- Evidence level: L2
- Source: string:webs/qis/QIS_detect.htm
- Parameters: CheckLink, DETECT_TITLE, DetectFail, Detecting, LinkDown, action_mode, current_page, detectForm, detect_frame, flag, next_page, preferred_lang
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `QIS_IPTV.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/qis/QIS_ntwksum2.html
- Parameters: btnSave
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `QIS_ipoacfg.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/qis/QIS_ntwkprtcl.html
- Parameters: cbVlan, encSel, enetWan, form, nextButton, ntwkPrtcl, vlanEnblInfo, vlanIdInfo, vlanIdText
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `QIS_mercfg.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/qis/QIS_manual_setting.htm
- Parameters: CityList, City_tr, CountryList, ISP, ISPList, ISP_tr, Service, Service_tr, action_mode, atmVci, atmVpi, cbVlan
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `QIS_ntwkprtcl.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/qis/QIS_manual_setting.htm
- Parameters: CityList, City_tr, CountryList, ISP, ISPList, ISP_tr, Service, Service_tr, action_mode, atmVci, atmVpi, city
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `QIS_reboot.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/qis/QIS_ntwksum2.html
- Parameters: btnSave
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `enblbridge.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/ntwkprtcl.html
- Parameters: cbVlan, encSel, enetWan, form, ntwkPrtcl, vlanEnblInfo, vlanIdInfo, vlanIdText
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `ipoacfg.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/ntwkprtcl.html
- Parameters: cbVlan, encSel, enetWan, form, ntwkPrtcl, vlanEnblInfo, vlanIdInfo, vlanIdText
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfg.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/enblservice.html
- Parameters: enblFirewall, enblIgmp, enblNat, enblService, form, serviceName
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfgbr.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/enblservice.html
- Parameters: enblIgmp, enblService, form, serviceName
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `mercfg.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/ntwkprtcl.html
- Parameters: cbVlan, encSel, enetWan, form, ntwkPrtcl, vlanEnblInfo, vlanIdInfo, vlanIdText
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `ntwkprtcl.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/enblbridge.html
- Parameters: Form1, atmVci, atmVpi, category_1, category_2, category_3, enblService, form, maximumBurst, peakCell, serviceCategory, serviceName
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

### Sink Summary

- exec: 424
- file_write: 411
- popen: 2
- system: 973
- unsafe_copy: 226

### Config Writer Leads

- `Advanced_ACL_Content.asp: <a class="hintstyle" href="javascript:void(0);" onClick="openHint(18,1);"><#FirewallConfig_MFMethod_itemname#></a>`
- `Advanced_ACL_Content.asp: <option class="content_input_fd" value="allow" <% nvram_match_x("DeviceSecurity11a","wl_macmode", "allow","selected"); %>><#FirewallConfig_MFMethod_item1#></opt`
- `Advanced_ACL_Content.asp: <option class="content_input_fd" value="deny" <% nvram_match_x("DeviceSecurity11a","wl_macmode", "deny","selected"); %>><#FirewallConfig_MFMethod_item2#></optio`
- `Advanced_ACL_Content.asp: <th align="right"><#FirewallConfig_MFList_groupitemname#></th>`
- `Advanced_ACL_Content.asp: <th width="30%"><#FirewallConfig_MFhwaddr_itemname#>`
- `Advanced_ACL_Content.asp: if(confirm("<#FirewallConfig_MFList_accept_hint1#>")){`
- `Advanced_ACL_Content.asp: var wl_macnum_x = '<% nvram_get_x("FirewallConfig", "wl_macnum_x"); %>';`
- `Advanced_Firewall_Content.asp: <input type="hidden" name="current_page" value="Advanced_Firewall_Content.asp">`
- `Advanced_Firewall_Content.asp: <input type="hidden" name="filter_lw_num_x_0" value="<% nvram_get_x("FirewallConfig", "filter_lw_num_x"); %>" readonly="1">`
- `Advanced_Firewall_Content.asp: <input type="hidden" name="sid_list" value="FirewallConfig;">`
- `Advanced_Firewall_Content.asp: <td bgcolor="#FFFFFF"><#FirewallConfig_display_sectiondesc#></td>`
- `Advanced_Firewall_Content.asp: <td colspan="2" id="LWFilterList"><#FirewallConfig_LWFilterList_groupitemdesc#></td>`
- `Advanced_Firewall_Content.asp: <th width="35%"><#FirewallConfig_LanWanFltName_itemname#>:</th>`
- `Advanced_Firewall_Content.asp: <th><#FirewallConfig_LWFilterList_widzarddesc#></th>`
- `Advanced_Firewall_Content.asp: <th><#FirewallConfig_LanWanDstIP_itemname#>:</th>`
- `Advanced_Firewall_Content.asp: <th><#FirewallConfig_LanWanDstPort_itemname#>:</th>`
- `Advanced_Firewall_Content.asp: <th><#FirewallConfig_LanWanProFlag_itemname#>:</th>`
- `Advanced_Firewall_Content.asp: <th><#FirewallConfig_LanWanSrcIP_itemname#>:</th>`
- `Advanced_Firewall_Content.asp: <th><#FirewallConfig_LanWanSrcPort_itemname#>:</th>`
- `Advanced_Firewall_Content.asp: code +="<th style='text-align:center;'><#FirewallConfig_LanWanDstIP_itemname#></th>";`
- `Advanced_Firewall_Content.asp: code +="<th style='text-align:center;'><#FirewallConfig_LanWanSrcIP_itemname#></th>";`
- `Advanced_Firewall_Content.asp: code +='<th colspan="2" style="text-align:center;"><#FirewallConfig_LanWanProFlag_itemname#></th>';`
- `Advanced_Firewall_Content.asp: code +='<th style="text-align:center;"><#FirewallConfig_LanWanDstPort_itemname#></th>';`
- `Advanced_Firewall_Content.asp: code +='<th style="text-align:center;"><#FirewallConfig_LanWanFltName_itemname#></th>';`
- `Advanced_Firewall_Content.asp: code +='<th style="text-align:center;"><#FirewallConfig_LanWanSrcPort_itemname#></th>';`
- `Advanced_Firewall_Content.asp: var LWFilterList = [<% get_nvram_list("FirewallConfig", "LWFilterList"); %>];`
- `Advanced_ParentalControl_Content.asp: <input type="hidden" name="pc_num_x" value="<% nvram_get_x("FirewallConfig", "pc_num_x"); %>" readonly="1">`
- `Advanced_ParentalControl_Content.asp: <input type="hidden" name="sid_list" value="FirewallConfig;">`
- `Advanced_ParentalControl_Content.asp: alert("<#FirewallConfig_URLActiveTime_itemhint#>");`
- `Advanced_ParentalControl_Content.asp: alert("<#FirewallConfig_URLActiveTime_itemhint2#>")`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_WL-AM604g/FW_WL_AM604g_3022A.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/403f2980953e553f

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
