# Firmware Audit: ASUS DSL-X11 / FW_DSL_X11_E5_2T30A_1_HA_R1B020_TW.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-X11/FW_DSL_X11_E5_2T30A_1_HA_R1B020_TW.zip
- Local path: known_firmware/firmware/ASUS_DSL-X11/FW_DSL_X11_E5_2T30A_1_HA_R1B020_TW.zip
- SHA-256: `3faa46ada3ca8ee96a38b1d95b3f3da2258a4cac86783e56d4d5b3eb8eecd3e2`
- Size: 1856522 bytes
- Version: E5.2T30A-1-HA-R1B020-TW
- Release date: 2011/09/15

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

#### `dhcpbind.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/addbindmac.html
- Parameters: IPbutton, abc, btnReturn, btnSave, chkIgmpSnp, chkUpnp, dhcpEthEnd, dhcpEthStart, dhcpInfo, dhcpLeasedTime, dhcpSrvAddr, dhcpSrvType
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

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
- Parameters: authErrorRetry, divPppToBridge, enblFullcone, enblOnDemand, enblPppDebug, enblPppIpAddress, pppAuthErrorInfo, pppAuthMethod, pppInfo, pppIpAddressInfo, pppIpExtension, pppLocalIpAddress
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfg2.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/lancfg2.html
- Parameters: IPbutton, chkIgmpSnp, chkUpnp, dhcpEthEnd, dhcpEthStart, dhcpInfo, dhcpLeasedTime, dhcpSrvAddr, dhcpSrvType, dhcpSubnetMask, dnsDomainName, dnsHostName
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfg2Reset.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/lancfg2.html
- Parameters: IPbutton, chkIgmpSnp, chkUpnp, dhcpEthEnd, dhcpEthStart, dhcpInfo, dhcpLeasedTime, dhcpSrvAddr, dhcpSrvType, dhcpSubnetMask, dnsDomainName, dnsHostName
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `natcfg2.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/wancfg.html
- Parameters: defaultGateway, dns, dnsPrimary, dnsSecondary, gw, gwAddr, gwIfc, wan, wanIf, wanIpAddress, wanSubnetMask
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `pppauthinfo.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/pppoe.html
- Parameters: authErrorRetry, divPppToBridge, enblFullcone, enblOnDemand, enblPppDebug, enblPppIpAddress, pppAuthErrorInfo, pppAuthMethod, pppInfo, pppIpAddressInfo, pppIpExtension, pppLocalIpAddress
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `ntwksum2.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/enblservice.html
- Parameters: Table1, Text1, Text2, dhcpEthEnd, dhcpEthStart, dhcpInfo, dhcpLeasedTime, dhcpSrvAddr, dhcpSrvType, dhcpSubnetMask, enblFirewall, enblFullcone
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `wlsetup.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/lancfg.html
- Parameters: Table1, Text1, Text2, dhcpEthEnd, dhcpEthStart, dhcpInfo, dhcpLeasedTime, dhcpSrvAddr, dhcpSrvType, dhcpSubnetMask, enblLan2, ethIpAddress
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `upload.cgi`

- Score: 15
- Evidence level: L2
- Source: string:webs/uploadinfo.html
- Parameters: filename
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `uploadsettings.cgi`

- Score: 15
- Evidence level: L2
- Source: string:webs/updatesettings.html
- Parameters: filename
- Matched risk keywords: upload
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `algcfg.cgi`

- Score: 14
- Evidence level: L2
- Source: string:webs/algcfg.html
- Parameters: Siproxd, sipproxdInfo
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `rebootinfo.cgi`

- Score: 14
- Evidence level: L2
- Source: string:webs/resetrouter.html
- Parameters: IPbutton, btnSave, ftpAdminEnbl, ftpAdminPswd, ftpAdminPswdCfm, ftpAnonymousEnbl, ftpAnonymousPswd, ftpAnonymousPswdCfm, ftpSrvEnbl, ftpStrikeEnbl, ftpUserEnbl, ftpUserPswd
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `usbftpd.cgi`

- Score: 14
- Evidence level: L2
- Source: string:webs/usbftpd.html
- Parameters: ftpAdminEnbl, ftpAdminPswd, ftpAdminPswdCfm, ftpAnonymousEnbl, ftpAnonymousPswd, ftpAnonymousPswdCfm, ftpSrvEnbl, ftpStrikeEnbl, ftpUserEnbl, ftpUserPswd, ftpUserPswdCfm, ftpWanEnbl
- Matched risk keywords: usb
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

#### `diagpppoe.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/diag.html
- Parameters: none discovered
- Matched risk keywords: pppoe
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `logintro.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/logconfig.html
- Parameters: levelDisplay, levelLog, logAddr, logMode, logPort, srvInfo, status
- Matched risk keywords: none
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

#### `adslcfgc.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/adslcfgc.html
- Parameters: adsBitmap, adslMod, adslPair
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `autoscan.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/vpivci.html
- Parameters: atmVci, atmVpi, enblQos, portId, qosInfo, vccInfo
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
- Parameters: atmVci, atmVpi, enblQos, portId, qosInfo, vccInfo
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `diag.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/diagpppoe.html
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

### Sink Summary

- exec: 382
- file_write: 379
- popen: 0
- system: 948
- unsafe_copy: 181

### Config Writer Leads

- `[: iptables -A FORWARD -p ALL -j DMZFWD`
- `[: iptables -A FORWARD -p ALL -j IPFLTINFWD`
- `[: iptables -A FORWARD -p ALL -j IPFLTOUTFWD`
- `[: iptables -A FORWARD -p ALL -j VSFWD`
- `[: iptables -A INPUT -p ALL -j IPFLTIN`
- `[: iptables -A INPUT -p ALL -j RAIN`
- `[: iptables -A INPUT -p ALL -j REIN`
- `[: iptables -F`
- `[: iptables -t filter -F`
- `[: iptables -t filter -N DMZFWD`
- `[: iptables -t filter -N IPFLTIN`
- `[: iptables -t filter -N IPFLTINFWD`
- `[: iptables -t filter -N IPFLTOUTFWD`
- `[: iptables -t filter -N RAIN`
- `[: iptables -t filter -N REIN`
- `[: iptables -t filter -N VSFWD`
- `[: iptables -t filter -X`
- `[: iptables -t filter -X DMZFWD 2>/dev/null`
- `[: iptables -t filter -X IPFLTIN 2>/dev/null`
- `[: iptables -t filter -X IPFLTINFWD 2>/dev/null`
- `[: iptables -t filter -X IPFLTOUTFWD 2>/dev/null`
- `[: iptables -t filter -X RAIN 2>/dev/null`
- `[: iptables -t filter -X REIN 2>/dev/null`
- `[: iptables -t filter -X VSFWD 2>/dev/null`
- `[: iptables -t mangle -F`
- `[: iptables -t nat -A PREROUTING -p ALL -j DMZPRE`
- `[: iptables -t nat -A PREROUTING -p ALL -j RAPRE`
- `[: iptables -t nat -A PREROUTING -p ALL -j REPRE`
- `[: iptables -t nat -A PREROUTING -p ALL -j VSPRE`
- `[: iptables -t nat -F`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_DSL-X11/FW_DSL_X11_E5_2T30A_1_HA_R1B020_TW.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/3faa46ada3ca8ee9

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
