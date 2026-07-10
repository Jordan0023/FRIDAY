# Firmware Audit: ASUS RT-N14UHP / FW_RT_N14UHP_30043808287WOWIMAX.ZIP

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N14UHP/FW_RT_N14UHP_30043808287WOWIMAX.ZIP
- Local path: known_firmware/firmware/ASUS_RT-N14UHP/FW_RT_N14UHP_30043808287WOWIMAX.ZIP
- SHA-256: `3c94e695e96b71fa82d7b1494fb04b5df6442de321da8d54058c884d840e25f0`
- Size: 15397640 bytes
- Version: 3.0.0.4.380.8287_nowimax
- Release date: 2018/05/31

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWd`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

#### `upgrade.cgi`

- Score: 24
- Evidence level: L2
- Source: string:www/Advanced_FirmwareUpgrade_Content.asp
- Parameters: FormTitle, Loading, LoadingBar, TopBanner, action_mode, action_script, action_wait, apply, auto_upgrade_setting, beta_firmware_path, beta_firmware_path_span, check_states
- Matched risk keywords: upgrade
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upload.cgi`

- Score: 24
- Evidence level: L2
- Source: string:www/Advanced_SettingBackup_Content.asp
- Parameters: AreaHint, FormTitle, Loading, LoadingBar, ModelPid_img, Productdesc_1, Productdesc_2, Productdesc_3, Productdesc_4, QISFeature, QISmain, QISmain_m
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `Advanced_VPN_OpenVPN.asp`

- Score: 23
- Evidence level: L2
- Source: string:www/Advanced_VPN_PPTP.asp
- Parameters: FormTitle, Loading, PPTP_setting, TopBanner, VPNServer_enable, VPNServer_mode, _pptpd_clients_end, _pptpd_clients_start, action_mode, action_script, action_wait, current_page
- Matched risk keywords: vpn, openvpn
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `apply.cgi`

- Score: 20
- Evidence level: L2
- Source: string:www/Main_DHCPStatus_Content.asp
- Parameters: 2g_radio_hint, 2g_title, 5g_2_radio_hint, 5g_2_title, 5g_radio_hint, 5g_title, ClientList_Block_PC, DMDesc, DMUtilityLink, DM_mask, DM_mask_floder, DNS1
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `deleteOfflineClient.cgi`

- Score: 20
- Evidence level: L2
- Source: string:www/client_function.js
- Parameters: JSON.stringify, New, _profile, action_mode, action_script, action_wait, all_expander, cardUploadIcon, cardUploadIcons_table, card_canvas_user_icon, card_changeIconTitle, card_client_confirm
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `qis/QIS_internet_vpn.htm`

- Score: 19
- Evidence level: L2
- Source: string:www/qis/QIS_internet_ip.htm
- Parameters: DNSDiv, QISmain, QISmain_m, WANIPDiv, action_mode, action_script, action_wait, current_page, dhcp_info_radio, dhcp_info_radio_m, dns_info_radio, dns_info_radio_m
- Matched risk keywords: vpn
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `Advanced_WANPort_Content.asp`

- Score: 18
- Evidence level: L2
- Source: string:www/RU.dict
- Parameters: DNS1, DNS2, LanProto, RemoteAP, RemoteAPtd, WANIP, act_form, action_mode, action_script, action_wait, ap_table, connectionType
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `Advanced_WAN_Content.asp`

- Score: 18
- Evidence level: L2
- Source: string:www/RU.dict
- Parameters: DNS1, DNS2, FAQ_input, LanProto, RemoteAP, RemoteAPtd, WANIP, _variable, act_form, action_mode, action_script, action_wait
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `device-map/wan_action.asp`

- Score: 18
- Evidence level: L2
- Source: string:www/device-map/internet.asp
- Parameters: DNS1, DNS2, LanProto, RemoteAP, RemoteAPtd, WANIP, act_form, action_mode, action_script, action_wait, ap_table, connectionType
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `images/New_ui/networkmap/USB2.png`

- Score: 18
- Evidence level: L2
- Source: string:www/index.asp
- Parameters: Loading, MULTIFILTER_ALL, MULTIFILTER_DEVICENAME, MULTIFILTER_ENABLE, MULTIFILTER_MAC, MULTIFILTER_MACFILTER_DAYTIME, NM_connect_status, NM_connect_title, NM_shift, NM_table, NM_table_div, SmartConnectName
- Matched risk keywords: usb
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `images/New_ui/networkmap/USB3.png`

- Score: 18
- Evidence level: L2
- Source: string:www/index.asp
- Parameters: Loading, MULTIFILTER_ALL, MULTIFILTER_DEVICENAME, MULTIFILTER_ENABLE, MULTIFILTER_MAC, MULTIFILTER_MACFILTER_DAYTIME, NM_connect_status, NM_connect_title, NM_shift, NM_table, NM_table_div, SmartConnectName
- Matched risk keywords: usb
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `images/New_ui/networkmap/line_dualwan.png`

- Score: 18
- Evidence level: L2
- Source: string:www/index.asp
- Parameters: Loading, MULTIFILTER_ALL, MULTIFILTER_DEVICENAME, MULTIFILTER_ENABLE, MULTIFILTER_MAC, MULTIFILTER_MACFILTER_DAYTIME, NM_connect_status, NM_connect_title, NM_shift, NM_table, NM_table_div, SmartConnectName
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `vpnupload.cgi`

- Score: 16
- Evidence level: L2
- Source: string:usr/sbin/httpds
- Parameters: none discovered
- Matched risk keywords: vpn, upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `images/RT-AC66U_V2/WANunplug_usb.png`

- Score: 15
- Evidence level: L2
- Source: string:www/qis/QIS_welcome.htm
- Parameters: AreaHint, ModelPid_img, Productdesc_1, Productdesc_2, Productdesc_3, Productdesc_4, QISFeature, QISmain, QISmain_m, btn_next_step, current_page, desc_td
- Matched risk keywords: wan, usb
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `images/WANunplug_usb.png`

- Score: 15
- Evidence level: L2
- Source: string:www/qis/QIS_welcome.htm
- Parameters: AreaHint, ModelPid_img, Productdesc_1, Productdesc_2, Productdesc_3, Productdesc_4, QISFeature, QISmain, QISmain_m, btn_next_step, current_page, desc_td
- Matched risk keywords: wan, usb
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `login.cgi`

- Score: 14
- Evidence level: L2
- Source: string:www/Main_Login.asp
- Parameters: action_mode, action_script, action_wait, current_page, dmRedirection, error_status_field, form, group_id, hidden_frame, login_authorization, login_filed, login_passwd
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `images/RT-AC66U_V2/WANunplug_eth.png`

- Score: 12
- Evidence level: L2
- Source: string:www/qis/QIS_welcome.htm
- Parameters: AreaHint, ModelPid_img, Productdesc_1, Productdesc_2, Productdesc_3, Productdesc_4, QISFeature, QISmain, QISmain_m, btn_next_step, current_page, desc_td
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `images/WANunplug.png`

- Score: 12
- Evidence level: L2
- Source: string:www/qis/QIS_welcome.htm
- Parameters: AreaHint, ModelPid_img, Productdesc_1, Productdesc_2, Productdesc_3, Productdesc_4, QISFeature, QISmain, QISmain_m, btn_next_step, current_page, desc_td
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `images/WANunplug_eth.png`

- Score: 12
- Evidence level: L2
- Source: string:www/qis/QIS_welcome.htm
- Parameters: AreaHint, ModelPid_img, Productdesc_1, Productdesc_2, Productdesc_3, Productdesc_4, QISFeature, QISmain, QISmain_m, btn_next_step, current_page, desc_td
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `update.cgi`

- Score: 11
- Evidence level: L2
- Source: string:www/Main_TrafficMonitor_last24.asp
- Parameters: FormTitle, Loading, TopBanner, TriggerList, action_mode, action_script, action_wait, avg1, avg2, avg4, avg6, avg8
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `QIS_default.cgi`

- Score: 8
- Evidence level: L2
- Source: string:www/Restarting.asp
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `appGet.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpds
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `appGet_image_path.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpds
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `applyapp.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpds
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `change_lang.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpds
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `check_Auth.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpds
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `dsllog.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpds
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `findasus.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpds
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `ftpServerTree.cgi`

- Score: 8
- Evidence level: L2
- Source: string:usr/sbin/httpds
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

### Sink Summary

- exec: 1292
- file_write: 2995
- popen: 309
- system: 2116
- unsafe_copy: 588

### Config Writer Leads

- `3ginfo.sh: cat /tmp/udhcpd.conf`
- `3ginfo.sh: echo "udhcpd.conf >"`
- `ATE: /var/spool/cron/crontabs`
- `ATE: firewall`
- `ATE: iptables_chk_mac`
- `ATE: remove_iptables_rules`
- `ATE: start_firewall`
- `Advanced_BasicFirewall_Content.asp: <input type="hidden" name="action_script" value="restart_firewall">`
- `Advanced_BasicFirewall_Content.asp: <input type="hidden" name="current_page" value="Advanced_BasicFirewall_Content.asp">`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="0" name="fw_dos_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'fw_dos_x', '0')" <% nvram_match("fw_dos`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="0" name="fw_enable_x" onClick="return change_common_radio(this, 'FirewallConfig', 'fw_enable_x', '0')" <% nvram_match("fw_enable_x", `
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="0" name="misc_ping_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'misc_ping_x', '0')" <% nvram_match("`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="1" name="fw_dos_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'fw_dos_x', '1')" <% nvram_match("fw_dos`
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="1" name="fw_enable_x" onClick="return change_common_radio(this, 'FirewallConfig', 'fw_enable_x', '1')" <% nvram_match("fw_enable_x", `
- `Advanced_BasicFirewall_Content.asp: <input type="radio" value="1" name="misc_ping_x" class="input" onClick="return change_common_radio(this, 'FirewallConfig', 'misc_ping_x', '1')" <% nvram_match("`
- `Advanced_BasicFirewall_Content.asp: change_firewall(firewall_enable);`
- `Advanced_BasicFirewall_Content.asp: var firewall_enable = '<% nvram_get("fw_enable_x"); %>';`
- `Advanced_Exposed_Content.asp: <input type="hidden" name="action_script" value="restart_firewall">`
- `Advanced_Feedback.asp: <input type="hidden" name="PM_attach_iptables" value="">`
- `Advanced_Feedback.asp: <span id="attach_iptables_span" style="color:#FFFFFF;"><input type="checkbox" class="input" name="attach_iptables" id="attach_iptables_id"><label for="attach_ip`
- `Advanced_Feedback.asp: desclist.push(["<#212#>","Firewall"]); //20`
- `Advanced_Feedback.asp: document.form.PM_attach_iptables.value = 0;`
- `Advanced_Feedback.asp: document.form.PM_attach_iptables.value = 1;`
- `Advanced_Feedback.asp: document.form.attach_iptables.checked = false;`
- `Advanced_Feedback.asp: document.form.attach_iptables.disabled = "";`
- `Advanced_Feedback.asp: document.form.attach_iptables.disabled = "true";`
- `Advanced_Feedback.asp: document.getElementById("attach_iptables_span").style.display = "none";`
- `Advanced_Feedback.asp: if(document.form.attach_iptables.checked == true)`
- `Advanced_Feedback.asp: url_group.push(["Firewall", "KeywordFilter", "URLFilter"]);`
- `Advanced_Firewall_Content.asp: <input type="hidden" name="action_script" value="restart_firewall">`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_RT-N14UHP/FW_RT_N14UHP_30043808287WOWIMAX.ZIP.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/3c94e695e96b71fa

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
