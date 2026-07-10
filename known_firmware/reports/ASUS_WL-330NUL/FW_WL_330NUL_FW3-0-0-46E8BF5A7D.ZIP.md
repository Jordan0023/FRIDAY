# Firmware Audit: ASUS WL-330NUL / FW_WL_330NUL_FW3-0-0-46E8BF5A7D.ZIP

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-330NUL/FW_WL_330NUL_FW3-0-0-46E8BF5A7D.ZIP
- Local path: known_firmware/firmware/ASUS_WL-330NUL/FW_WL_330NUL_FW3-0-0-46E8BF5A7D.ZIP
- SHA-256: `cb4b000246c925747f1261fdbd4324359596ed6f2954f58f30089e778eb116b1`
- Size: 10230965 bytes
- Version: 3.0.0.46
- Release date: 2016/06/20

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

#### `upgrade.cgi`

- Score: 24
- Evidence level: L2
- Source: string:www/supervisor.asp
- Parameters: AddForApproved_div, AddForBlocked_div, AddProfileButton, Add_profile_div, ApplyAddProfile, ApplyConnProfile, ApplyEditProfile, ApplyModeButton, ApplyProfileButton, Apply_ProConnect_div, ApproveUsers, BackMacClone
- Matched risk keywords: upgrade
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `apply.cgi`

- Score: 20
- Evidence level: L2
- Source: string:www/Main_AdmStatus_Content.asp
- Parameters: 0_guestuser, 0_guestuser_, 0_guestuser_count, 1_guestuser, 1_guestuser_, 1_guestuser_count, 2_guestuser, 2_guestuser_, 2_guestuser_count, Disconnect_btn, SystemCmd, access_code
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `reinit.cgi`

- Score: 20
- Evidence level: L2
- Source: string:www/super_setting.js
- Parameters: 0_guestuser, 0_guestuser_, 0_guestuser_count, 1_guestuser, 1_guestuser_, 1_guestuser_count, 2_guestuser, 2_guestuser_, 2_guestuser_count, AddForApproved_div, AddForBlocked_div, AddProfileButton
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `userControl.cgi`

- Score: 20
- Evidence level: L2
- Source: string:www/super_setting.js
- Parameters: 0_guestuser, 0_guestuser_, 0_guestuser_count, 1_guestuser, 1_guestuser_, 1_guestuser_count, 2_guestuser, 2_guestuser_, 2_guestuser_count, AddForApproved_div, AddForBlocked_div, AddProfileButton
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `vpnupload.cgi`

- Score: 16
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: vpn, upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `upload.cgi`

- Score: 12
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `logout.cgi`

- Score: 11
- Evidence level: L2
- Source: string:www/super_setting.js
- Parameters: 0_guestuser, 0_guestuser_, 0_guestuser_count, 1_guestuser, 1_guestuser_, 1_guestuser_count, 2_guestuser, 2_guestuser_, 2_guestuser_count, Disconnect_btn, access_code, addprofile_div
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `password.cgi`

- Score: 11
- Evidence level: L2
- Source: string:www/super_setting.js
- Parameters: 0_guestuser, 0_guestuser_, 0_guestuser_count, 1_guestuser, 1_guestuser_, 1_guestuser_count, 2_guestuser, 2_guestuser_, 2_guestuser_count, Disconnect_btn, access_code, addprofile_div
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `restart_sys.cgi`

- Score: 11
- Evidence level: L2
- Source: string:www/super_setting.js
- Parameters: 0_guestuser, 0_guestuser_, 0_guestuser_count, 1_guestuser, 1_guestuser_, 1_guestuser_count, 2_guestuser, 2_guestuser_, 2_guestuser_count, Disconnect_btn, access_code, addprofile_div
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `syslog.cgi`

- Score: 11
- Evidence level: L2
- Source: string:www/super_setting.js
- Parameters: 0_guestuser, 0_guestuser_, 0_guestuser_count, 1_guestuser, 1_guestuser_, 1_guestuser_count, 2_guestuser, 2_guestuser_, 2_guestuser_count, Disconnect_btn, access_code, addprofile_div
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `wlanProfile.cgi`

- Score: 11
- Evidence level: L2
- Source: string:www/super_setting.js
- Parameters: 0_guestuser, 0_guestuser_, 0_guestuser_count, 1_guestuser, 1_guestuser_, 1_guestuser_count, 2_guestuser, 2_guestuser_, 2_guestuser_count, Disconnect_btn, access_code, addprofile_div
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `applyapp.cgi`

- Score: 8
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `change_lang.cgi`

- Score: 8
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `dsllog.cgi`

- Score: 8
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `findasus.cgi`

- Score: 8
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `ftpServerTree.cgi`

- Score: 8
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `guestpasswd.cgi`

- Score: 8
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `guestpasswd.cgi.cgi`

- Score: 8
- Evidence level: L2
- Source: string:www/web_setting.js
- Parameters: 0_guestuser_, 0_guestuser_count, do_process_span, unapprov_user
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `update.cgi`

- Score: 8
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `utilityRequest.cgi`

- Score: 8
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `utilitylogin.cgi`

- Score: 8
- Evidence level: L2
- Source: string:bin/httpd
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

### Sink Summary

- exec: 389
- file_write: 753
- popen: 109
- system: 823
- unsafe_copy: 372

### Config Writer Leads

- `ATE: /etc/dnsmasq.conf`
- `ATE: /tmp/udhcpd.conf`
- `ATE: /var/spool/cron/crontabs`
- `ATE: firewall`
- `ATE: iptables`
- `ATE: iptables -t mangle -A PREROUTING -m mac --mac-source %s -j MARK --set-mark 99`
- `ATE: iptables -t mangle -D PREROUTING -m mac --mac-source %s -j MARK --set-mark 99`
- `ATE: iptables -t nat -D VSERVER -j DNAT --to %s`
- `ATE: iptables -t nat -I VSERVER 1 -j DNAT --to %s`
- `ATE: iptables-restore`
- `ATE: start_firewall`
- `BR.js: var JS_DHCP2="A configuração do servidor DHCP não corresponde ao endereço IP do firewall da rede sem fio. Você gostaria de mudar automaticamente ?";`
- `CZ.js: var JS_DHCP2="Nastavení DHCP serveru nesouhlasí se stávající IP adresou ve firewallu. Chcete ji změnit automaticky?";`
- `DE.js: var JS_DHCP2="Die Einstellungen des DHCP-Servers stimmen nicht mit der aktuellen IP-Adresse der Wireless-Firewall überein. Mochten Sie dies automatisch andern l`
- `EN.js: var JS_DHCP2="The setting of DHCP server does not match current IP address of Wireless Firewall. Would you like to change it automatically?";`
- `ES.js: var JS_DHCP2="La configuración del servidor DHCP no coincide con la dirección IP actual del firewall inalámbrico. ¿Desea cambiarla automáticamente?";`
- `MS.js: var JS_DHCP2="Seting pelayan DHCP tidak sepadan dengan alamat IP semasa bagi Firewall Wayarles. Adakah anda mahu mengubahnya secara automatik?";`
- `add_multi_routes: /etc/dnsmasq.conf`
- `add_multi_routes: /tmp/udhcpd.conf`
- `add_multi_routes: /var/spool/cron/crontabs`
- `add_multi_routes: firewall`
- `add_multi_routes: iptables`
- `add_multi_routes: iptables -t mangle -A PREROUTING -m mac --mac-source %s -j MARK --set-mark 99`
- `add_multi_routes: iptables -t mangle -D PREROUTING -m mac --mac-source %s -j MARK --set-mark 99`
- `add_multi_routes: iptables -t nat -D VSERVER -j DNAT --to %s`
- `add_multi_routes: iptables -t nat -I VSERVER 1 -j DNAT --to %s`
- `add_multi_routes: iptables-restore`
- `add_multi_routes: start_firewall`
- `auto_macclone: /etc/dnsmasq.conf`
- `auto_macclone: /tmp/udhcpd.conf`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_WL-330NUL/FW_WL_330NUL_FW3-0-0-46E8BF5A7D.ZIP.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/cb4b000246c92574

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
