# Firmware Audit: ASUS WL-AM602 / FW_WL_AM602_RU_1001.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-AM602/FW_WL_AM602_RU_1001.zip
- Local path: known_firmware/firmware/ASUS_WL-AM602/FW_WL_AM602_RU_1001.zip
- SHA-256: `35d903e87a6a751760aff18086f08c594ebfa94e63e6565184882840c4c0377e`
- Size: 1851295 bytes
- Version: 1.0.0.1
- Release date: 2009/11/06

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd, sshd, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

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

#### `dnscfg.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/dnscfg.html
- Parameters: dnsInfo, dnsPrimary, dnsSecondary, enableAuto
- Matched risk keywords: dns
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `enblservice.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/pppoe.html
- Parameters: defaultGateway, divPppToBridge, enblMacClone, enblOnDemand, enblPppIpAddress, enblsendlcp, gw, gwRadio, idacname, idservicename, macClone, pppACName
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `natcfg2.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/wancfg.html
- Parameters: defaultGateway, divPppToBridge, dns, dnsPrimary, dnsSecondary, enblMacClone, enblOnDemand, enblPppIpAddress, enblsendlcp, gw, gwRadio, idacname
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `ntwksum2.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/enblservice.html
- Parameters: Table1, Text1, Text2, dhcpEthEnd, dhcpEthStart, dhcpInfo, dhcpLeasedTime, dhcpSrvAddr, dhcpSrvType, enblFirewall, enblIgmp, enblLan2
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `pppauthinfo.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/pppoe.html
- Parameters: defaultGateway, divPppToBridge, enblMacClone, enblOnDemand, enblPppIpAddress, enblsendlcp, gw, gwRadio, idacname, idservicename, macClone, pppACName
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfg.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/enblservice.html
- Parameters: enblFirewall, enblIgmp, enblNat, enblService, hideIP, hideNatIP, natIP, natType, serviceName
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfg2.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/lancfg2.html
- Parameters: chkIgmpSnp, chkUpnp, dhcpEthEnd, dhcpEthStart, dhcpInfo, dhcpLeasedTime, dhcpSrvAddr, dhcpSrvType, enblLan2, ethIpAddress, ethSubnetMask, igmpMode
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfg2Reset.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/lancfg2.html
- Parameters: chkIgmpSnp, chkUpnp, dhcpEthEnd, dhcpEthStart, dhcpInfo, dhcpLeasedTime, dhcpSrvAddr, dhcpSrvType, enblLan2, ethIpAddress, ethSubnetMask, igmpMode
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfgbr.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/enblservice.html
- Parameters: enblFirewall, enblIgmp, enblNat, enblService, hideIP, hideNatIP, natIP, natType, serviceName
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `logintro.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/logconfig.html
- Parameters: emailAddress, emailPassword, emailSendEach, emailSendFull, emailSendSched, emailSendType, emailSmtpAddress, emailUseSsl, emailUsername, fwlEmailInfo, fwlEmailSched, levelDisplay
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `wlsetup.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/lancfg.html
- Parameters: Table1, Text1, Text2, dhcpEthEnd, dhcpEthStart, dhcpInfo, dhcpLeasedTime, dhcpSrvAddr, dhcpSrvType, enblLan2, ethIpAddress, ethSubnetMask
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upload.cgi`

- Score: 15
- Evidence level: L2
- Source: string:webs/uploadinfo.html
- Parameters: back, filename, frmUpload, status, uiStatus
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `uploadsettings.cgi`

- Score: 15
- Evidence level: L2
- Source: string:webs/updatesettings.html
- Parameters: filename, frmUpdate
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `algcfg.cgi`

- Score: 14
- Evidence level: L2
- Source: string:webs/algcfg.html
- Parameters: Siproxd, sipproxdInfo
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `diagpppoe.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/diag.html
- Parameters: none discovered
- Matched risk keywords: pppoe
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `pppoe.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/ntwkprtcl.html
- Parameters: cbVlan, encInfo, encSel, enetWan, ntwkPrtcl, vlanEnblInfo, vlanIdInfo, vlanIdText
- Matched risk keywords: pppoe
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `snmpconfig.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/snmpconfig.html
- Parameters: rocommunity, rwcommunity, status, sysContact, sysLocation, sysName, trapIp
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `wancfg.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/ntwkprtcl.html
- Parameters: cbVlan, encInfo, encSel, enetWan, ntwkPrtcl, vlanEnblInfo, vlanIdInfo, vlanIdText
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `adslcfg.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/adslcfg.html
- Parameters: adslBitswap, adslMod, adslPair, adslSra
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `autoscan.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/vpivci.html
- Parameters: atmVci, atmVpi, enblAutoScan, enblQos, qosInfo, vccInfo
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `autoscancancel.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/autoscan.html
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `autoscanerr.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/vpivci.html
- Parameters: atmVci, atmVpi, enblAutoScan, enblQos, qosInfo, vccInfo
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `diag.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/diagipow.html
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `diagbr.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/diag.html
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `diagipow.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/diag.html
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `diagmer.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/diag.html
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `diagpppoa.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/diag.html
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `enblbridge.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/ntwkprtcl.html
- Parameters: cbVlan, encInfo, encSel, enetWan, ntwkPrtcl, vlanEnblInfo, vlanIdInfo, vlanIdText
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `ipoacfg.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/ntwkprtcl.html
- Parameters: cbVlan, encInfo, encSel, enetWan, ntwkPrtcl, vlanEnblInfo, vlanIdInfo, vlanIdText
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `natSession.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/natSession.html
- Parameters: sessionNum
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

### Sink Summary

- exec: 296
- file_write: 467
- popen: 0
- system: 783
- unsafe_copy: 152

### Config Writer Leads

- `[: iptables -t filter -F`
- `[: iptables -t nat -F`
- `[: iptables -t nat -L -n > /var/nat_redirect`
- `bftpd: iptables -t filter -F`
- `bftpd: iptables -t nat -F`
- `bftpd: iptables -t nat -L -n > /var/nat_redirect`
- `busybox: iptables -t filter -F`
- `busybox: iptables -t nat -F`
- `busybox: iptables -t nat -L -n > /var/nat_redirect`
- `cat: iptables -t filter -F`
- `cat: iptables -t nat -F`
- `cat: iptables -t nat -L -n > /var/nat_redirect`
- `cfm: /bin/iptables`
- `cfm: /etc/udhcpd.conf`
- `cfm: <font color='red'>ICMP services of WAN side can only be disabled when the firewall is enable.<br><br>`
- `cfm: BcmDb_isFirewallEnabled`
- `cfm: BcmDb_isInterfaceFirewallEnabled`
- `cfm: By default, all incoming IP traffic from WAN is blocked when the firewall is enabled, but some IP traffic can be <b><font color='green'>ACCEPTED</font></b> by s`
- `cfm: Some applications require that specific ports in the Router's firewall be opened for access by the remote parties. Port Trigger dynamically opens up the 'Open P`
- `cfm: _ZN10SecCfgMngr12loadIpTablesEv`
- `cfm: _ZN10SecCfgMngr16doFirewallPolicyEPc`
- `cfm: _ZN10SecCfgMngr19glbIpTablesIsLoadedE`
- `cfm: _ZN11SecFltInTbl11runiptablesEPcS0_cS0_S0_S0_S0_S0_`
- `cfm: _ZN12SecVrtSrvTbl11runiptablesEcPcS0_S0_S0_S0_S0_`
- `cfm: buildIpTables`
- `cfm: cgiGetEnblFirewallForWeb`
- `cfm: enblFirewall`
- `cfm: firewall`
- `cfm: iptables -%c FORWARD %c -i %s -d %s -j ACCEPT`
- `cfm: iptables -%c FORWARD -i %s %s %s %s %s -j DROP`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_WL-AM602/FW_WL_AM602_RU_1001.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/35d903e87a6a7517

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
