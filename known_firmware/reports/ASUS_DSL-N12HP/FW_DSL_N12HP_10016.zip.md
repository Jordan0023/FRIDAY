# Firmware Audit: ASUS DSL-N12HP / FW_DSL_N12HP_10016.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12HP/FW_DSL_N12HP_10016.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12HP/FW_DSL_N12HP_10016.zip
- SHA-256: `9fe114405176f5bdf895a21a028fa443339da9a2b859e7fb1d208482e5453792`
- Size: 7672977 bytes
- Version: 1.0.0.16
- Release date: 2016/10/14

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

#### `uploadwapicert.cgi`

- Score: 24
- Evidence level: L2
- Source: string:webs/cgi-bin/wlsecurity.html
- Parameters: FormTitle, Loading, NetReauth, Preauth, TopBanner, addEnBtn, apcertfilename, ascertfilename, divCert, divWscAPMode, divWscAddClient, divWscAddClient_pcb
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `cgi-bin/Advanced_WANPort_Content.asp`

- Score: 23
- Evidence level: L2
- Source: string:webs/cgi-bin/device-map/internet_dual.asp
- Parameters: DNS1, DNS2, LanProto, RemoteAP, RemoteAPtd, WANIP, action_mode, action_script, action_wait, ap_table, connectionType, current_page
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `dnscfg.cgi`

- Score: 23
- Evidence level: L2
- Source: string:webs/cgi-bin/dnscfg.html
- Parameters: BR, CN, CZ, DA, DE, EN, ES, FAQ_input, FI, FR, FormTitle, IT
- Matched risk keywords: dns
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `ifcgateway.cgi`

- Score: 23
- Evidence level: L2
- Source: string:webs/cgi-bin/natcfg2.html
- Parameters: BR, CN, CZ, CurrentPcMac, DA, DE, Dhcp6cAddr, Dhcp6cForRapidCommit, Dhcp6cPd, EN, ES, FAQ_input
- Matched risk keywords: gateway
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `cgi-bin/Advanced_DSL_Content.asp`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/device-map/internet_dual.asp
- Parameters: DNS1, DNS2, LanProto, RemoteAP, RemoteAPtd, WANIP, action_mode, action_script, action_wait, ap_table, connectionType, current_page
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `cgi-bin/Advanced_Modem_Content.asp`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/device-map/internet_dual.asp
- Parameters: DNS1, DNS2, LanProto, RemoteAP, RemoteAPtd, WANIP, action_mode, action_script, action_wait, ap_table, connectionType, current_page
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `cgi-bin/device-map/internet.asp`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/device-map/internet.asp
- Parameters: DipConnFlag, Dipflag, DvInfo_Form, DvInfo_PVC, IPv6PrivacyAddrsSupportedFlag, Saveflag, div_wanDNS, div_wanGateway, div_wanIP, div_wanType, pvcFlag, releaseIP
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `cgi-bin/device-map/router.asp`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/device-map/router.asp
- Parameters: BUTTON, CountryChange, LANIP, MAC, PINCode, SwapRAM_graph_table, WLnetworkmap, action_mode, action_script, action_wait, apply_tr, cpu
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `cgi-bin/index2.asp`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/qis/QIS_finish.asp
- Parameters: Bridged_IP_LLC, Bridged_IP_VC, Bridged_Only_LLC, Bridged_Only_VC, PPPAuthen, PPPoA_LLC, PPPoA_VC, PPPoE_LLC, PPPoE_VC, QIS_Flag, Routed_IP_LLC, Routed_IP_VC
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `cgi-bin/start_apply.asp`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/aidisk/Aidisk-3.asp
- Parameters: DDNSName, action_mode, action_script, action_wait, alert_block, alert_str, asusddns_tos_agreement, button_descrition, c1, c2, check_asus_ddns, current_page
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfg2.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/lancfg2.html
- Parameters: BR, CN, CZ, DA, DE, EN, ES, FAQ_input, FI, FR, FormTitle, IT
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfg2Reset.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/lancfg2.html
- Parameters: BR, CN, CZ, DA, DE, EN, ES, FAQ_input, FI, FR, FormTitle, IT
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfg2get.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/lancfg2.html
- Parameters: BR, CN, CZ, DA, DE, EN, ES, FAQ_input, FI, FR, FormTitle, IT
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `natcfg2.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/wancfg.html
- Parameters: BR, CN, CZ, DA, DE, EN, ES, FAQ_input, FI, FR, FormTitle, IT
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `ntwksum2.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/natcfg2.html
- Parameters: BR, CN, CZ, CurrentPcMac, DA, DE, Dhcp6cAddr, Dhcp6cForRapidCommit, Dhcp6cPd, EN, ES, FAQ_input
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `quickmanual_wireless.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/cgi-bin/quickmanual_ppp_temp.html
- Parameters: FormTitle, Loading, TopBanner, dhcp_info_radio, dnsPrimary, dnsSecondary, dns_info_radio, dns_info_title, dns_sec, dsltmp_cfg_pppoe_passwd, dsltmp_cfg_pppoe_username, footer
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `device-map/wan_action.asp`

- Score: 18
- Evidence level: L2
- Source: string:webs/cgi-bin/device-map/internet_dual.asp
- Parameters: DNS1, DNS2, LanProto, RemoteAP, RemoteAPtd, WANIP, action_mode, action_script, action_wait, ap_table, connectionType, current_page
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upload.cgi`

- Score: 18
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: BR, CN, CZ, DA, DE, EN, ES, FAQ_input, FI, FR, IT, JP
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `uploaddefaultsettings.cgi`

- Score: 18
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: MAC_num, filename, skip_option, user_ssid
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `cgi-bin/Feedback_Info.asp`

- Score: 17
- Evidence level: L2
- Source: string:webs/cgi-bin/Advanced_DSL_Feedback.asp
- Parameters: FormTitle, Loading, PM_attach_cfgfile, PM_attach_iptables, PM_attach_syslog, TopBanner, action_mode, action_script, action_wait, adv_adsl, attach_cfgfile, attach_iptables
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `cgi-bin/ParentalControl.asp`

- Score: 17
- Evidence level: L2
- Source: string:webs/cgi-bin/ParentalControl.asp
- Parameters: ClientList_Block_PC, FormTitle, LWFilterList, Loading, MULTIFILTER_ALL, MULTIFILTER_DEVICENAME, MULTIFILTER_ENABLE, MULTIFILTER_LANTOWAN_DESC, MULTIFILTER_LANTOWAN_ENABLE, MULTIFILTER_LANTOWAN_PORT, MULTIFILTER_LANTOWAN_PROTO, MULTIFILTER_MAC
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `omcisystem.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/omcisystem.html
- Parameters: chkAll, chkAllPath, chkCmf, chkFile, chkFlow, chkHwPath, chkMcast, chkModel, chkOmci, chkRule, chkSwPath, chkVlan
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `pppoe.cgi`

- Score: 17
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: BR, CN, CZ, DA, DE, EN, ES, FAQ_input, FI, FR, IT, JP
- Matched risk keywords: pppoe
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `quickmanual_br_temp.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/cgi-bin/quickmanual.html
- Parameters: CountryList, FormTitle, ISP, ISPList, ISPSVC_value, ISP_tr, ISP_value, Loading, TopBanner, action_mode, action_script, action_wait
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `quickmanual_ipoa_temp.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/cgi-bin/quickmanual.html
- Parameters: CountryList, FormTitle, ISP, ISPList, ISPSVC_value, ISP_tr, ISP_value, Loading, TopBanner, action_mode, action_script, action_wait
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `quickmanual_ipoe_temp.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/cgi-bin/quickmanual.html
- Parameters: CountryList, FormTitle, ISP, ISPList, ISPSVC_value, ISP_tr, ISP_value, Loading, TopBanner, action_mode, action_script, action_wait
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `quickmanual_ppp_temp.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/cgi-bin/quickmanual.html
- Parameters: CountryList, FormTitle, ISP, ISPList, ISPSVC_value, ISP_tr, ISP_value, Loading, TopBanner, action_mode, action_script, action_wait
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `cgi-bin/upload.cgi`

- Score: 15
- Evidence level: L2
- Source: string:webs/cgi-bin/upload.html
- Parameters: FormTitle, Loading, TopBanner, configchange, filename, footer, hidden_frame, mainMenu, subMenu, tabMenu, uploadform
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `cgi-bin/uploadsettings.cgi`

- Score: 15
- Evidence level: L2
- Source: string:webs/cgi-bin/setting_top.html
- Parameters: FormTitle, Loading, TopBanner, filename, footer, hidden_frame, mainMenu, subMenu, tabMenu, uploadform
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `uploadinfo.cgi`

- Score: 15
- Evidence level: L2
- Source: string:webs/state.js
- Parameters: BR, CN, CZ, DA, DE, EN, ES, FAQ_input, FI, FR, IT, JP
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

### Sink Summary

- exec: 289
- file_write: 1582
- popen: 79
- system: 727
- unsafe_copy: 280

### Config Writer Leads

- `Advanced_DSL_Feedback.asp: <input type="checkbox" class="input" name="attach_iptables"><#ejGetLangStr(FEEDBACK_0006)#>`
- `Advanced_DSL_Feedback.asp: <input type="hidden" name="PM_attach_iptables" value="0">`
- `Advanced_DSL_Feedback.asp: document.adv_adsl.PM_attach_iptables.value = 0;`
- `Advanced_DSL_Feedback.asp: document.adv_adsl.PM_attach_iptables.value = 1;`
- `Advanced_DSL_Feedback.asp: if(document.adv_adsl.attach_iptables.checked == true)`
- `EN.dict: ACCCNTR_0035=Notice: If you enable firewall , you still need to add incoming filter rule for those service.`
- `EN.dict: ACCCNTR_0048=Notice: If you enable firewall , you still need to add incoming filter rule for those service.`
- `EN.dict: ROUTING_0050=WAN Interfaces (Configured in Routing mode and with firewall enabled) and LAN Interfaces Select one or more WAN/LAN interfaces displayed below to a`
- `EN.dict: SETUPLAN_0010=Enable LAN side firewall`
- `EN.dict: SETUPLAN_0022=Enable LAN side firewall`
- `EN.dict: SETUPLAN_0118=Firewall`
- `EN.dict: SETUPLAN_0168=Some applications require that specific ports in the Router's firewall be opened for access by the remote parties. Port Trigger dynamically opens `
- `EN.dict: SETUPLAN_0178=Some applications such as games, video conferencing, remote access applications and others require that specific ports in the Router's firewall be`
- `EN.dict: SETUPLAN_0254=When the firewall is enabled on a WAN or LAN interface, all incoming IP traffic is BLOCKED. However, some IP traffic can be ACCEPTED by setting up`
- `EN.dict: SETUPLAN_0268=WAN Interfaces (Configured in Routing mode and with firewall enabled) and LAN Interfaces`
- `EN.dict: SETUPWANNEXT_0018=Enable Firewall`
- `EN.dict: SETUPWANNEXT_0055=Firewall:`
- `EN.dict: SETUPWANNEXT_0079=Enable Firewall`
- `EN.dict: SETUPWAN_0010=Firewall`
- `EN.dict: STATSWAN_0010=Firewall`
- `EN.dict: WANSTS_Firewall=Firewall`
- `ParentalControl.asp: <input type="hidden" name="action_script" value="restart_firewall">`
- `dhcpc: /etc/udhcpd.conf`
- `dhcpd: /etc/udhcpd.conf`
- `dumpsysinfo.sh: echo "###### iptables -t filter -L ######"`
- `dumpsysinfo.sh: echo "###### iptables -t mangle -L ######"`
- `dumpsysinfo.sh: echo "###### iptables -t nat -L ######"`
- `dumpsysinfo.sh: iptables -t filter -L`
- `dumpsysinfo.sh: iptables -t mangle -L`
- `dumpsysinfo.sh: iptables -t nat -L`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_DSL-N12HP/FW_DSL_N12HP_10016.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/9fe114405176f5bd

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
