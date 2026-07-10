# Firmware Audit: ASUS DSL-N13 / FW_DSL_N13_1151A.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N13/FW_DSL_N13_1151A.zip
- Local path: known_firmware/firmware/ASUS_DSL-N13/FW_DSL_N13_1151A.zip
- SHA-256: `ad5b4381c61af1e7d3aa77871f34e03fbfe958e52606c3e799790d6954481903`
- Size: 3568025 bytes
- Version: 1.1.5.1A
- Release date: 2010/07/23

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----, -----BEGIN RSA PRIVATE KEY-----`

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password, token`

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

Evidence: `gets, sprintf, strcat, strcpy`

### Outdated crypto/library markers

Old OpenSSL/BusyBox versions may contain known CVEs and should be mapped to package versions.

Evidence: `BusyBox v1.00, OpenSSL 0.`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

#### `Q_enblwl.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/enblbridge.html
- Parameters: authErrorRetry, cbVlan, defaultGateway, divPppToBridge, dns, dnsPrimary, dnsSecondary, enblFullcone, enblOnDemand, enblPppDebug, enblPppIpAddress, enblService
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
- Source: string:webs/dhcp.html
- Parameters: chkIgmpSnp, chkUpnp, dhcpDns, dhcpEthEnd, dhcpEthStart, dhcpInfo, dhcpLeasedTime, dhcpSrvAddr, dhcpSrvType, dhcpSubnetMask, dnsDomainName, dnsHostName
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `lancfg2Reset.cgi`

- Score: 20
- Evidence level: L2
- Source: string:webs/dhcp.html
- Parameters: chkIgmpSnp, chkUpnp, dhcpDns, dhcpEthEnd, dhcpEthStart, dhcpInfo, dhcpLeasedTime, dhcpSrvAddr, dhcpSrvType, dhcpSubnetMask, dnsDomainName, dnsHostName
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

#### `BandwidthMan.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/bandwidth_management.html
- Parameters: GAME, GameOff, GameOn, INTERNET, InternetOff, InternetOn, Management, NO, SERVER, ServerOff, ServerOn, Submit
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `Q_vpivci.cgi`

- Score: 17
- Evidence level: L2
- Source: string:webs/Q_streamcfg.html
- Parameters: enblPppIpAddress, ppp, pppIpAddressInfo, pppLocalIpAddress, pppPassword, pppUserName
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
- Parameters: backup_progress_div, filename
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

#### `BandwidthAdv.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/bandwidth_advanced.html
- Parameters: AddBtn, Advanced, FTPServer, Fragment, RemoveBtn, SaveBtn, Submit, qos_dfragment_enable_w, qos_dfragment_size_w, qos_ip_w, qos_name_w, qos_port_w
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `diagpppoe.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/diag.html
- Parameters: none discovered
- Matched risk keywords: pppoe
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `ejectusb.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/ftpsvr.html
- Parameters: usb_ftpanonymous_x, usb_ftpenable_x, usb_ftpmax_x, usb_ftpport_x, usb_ftpstaytimeout_x, usb_ftpsuper_x, usb_ftptimeout_x, x_FIsAnonymous_link, x_FIsSuperuser_link
- Matched risk keywords: usb
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow; check daemon config injection and service restart behavior

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

#### `wancfg.cgi`

- Score: 11
- Evidence level: L2
- Source: string:webs/ntwkprtcl.html
- Parameters: cbVlan, encInfo, encSel, enetWan, ntwkPrtcl, vlanEnblInfo, vlanIdInfo, vlanIdText
- Matched risk keywords: wan
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `Q_linkstate.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/menuBcm.js
- Parameters: none discovered
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `Q_reboot.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/ntwksum2.html
- Parameters: btnSave
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `Q_russiastream.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/ntwksum2.html
- Parameters: btnSave
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `Q_streamcfg.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/Q_vpivci.html
- Parameters: China, Others, Russia, RussiaISP, all_isp, atmVci, atmVpi, country, isp, russia_isp, vccInfo, warning
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `adslcfg.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/adslcfg.html
- Parameters: adslBitswap, adslMod, adslPair, adslSra
- Matched risk keywords: none
- Next checks: map route to handler and auth gate; trace each risky parameter into command/file/memory sinks; prove or reject parameter-to-system/popen/exec flow

#### `diag.cgi`

- Score: 8
- Evidence level: L2
- Source: string:webs/diagipow.html
- Parameters: Connection, DiagDSL, DiagInternet, DiagWireless
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

### Sink Summary

- exec: 462
- file_write: 696
- popen: 0
- system: 1075
- unsafe_copy: 239

### Config Writer Leads

- `EN.dict: SCINFLT_desc3=WAN Interfaces (Configured in Routing mode and with firewall enabled only)`
- `EN.dict: SCPRTTRG_desc2=Some applications such as games, video conferencing, remote access applications and others require that specific ports in the Router's firewall b`
- `EN.dict: inflt_disc1=By default, all incoming IP traffic from the WAN is blocked when the firewall is enabled. However, some IP traffic can be`
- `EN.dict: natcfg2_enbfw=Enable Firewall`
- `EN.dict: prttrg_disc=Some applications require that specific ports in the Router's firewall be opened for access by the remote parties. Port Trigger dynamically opens up`
- `Q_detectresult.html: loc += '&enblFirewall=1&enblNat=1&enblIgmp=0&enblService=1&quickSetup=1';`
- `Q_detectresult.html: var loc = 'Q_enblwl.cgi?enblNat=1&enblFirewall=1&enblService=1';`
- `Q_streamcfg.html: loc += '&enblFirewall=1&enblNat=1&enblIgmp=0&enblService=1&quickSetup=1&pppMtu=1492';`
- `Q_streamcfg.html: var loc = 'Q_enblwl.cgi?enblNat=1&enblFirewall=1&enblService=1';`
- `[: iptables -F`
- `[: iptables -t filter -F`
- `[: iptables -t mangle -F`
- `[: iptables -t nat -F`
- `[: iptables -t nat -L > /var/nat_redirect`
- `asushotplug: /bin/iptables`
- `asushotplug: /etc/udhcpd.conf`
- `asushotplug: BcmDb_isFirewallEnabled`
- `asushotplug: BcmDb_isInterfaceFirewallEnabled`
- `asushotplug: _Z26BcmCfmSec_FltInRuniptablesPcS_cS_S_S_S_S_`
- `asushotplug: _ZN10SecCfgMngr12loadIpTablesEv`
- `asushotplug: _ZN10SecCfgMngr16doFirewallPolicyEPc`
- `asushotplug: _ZN10SecCfgMngr19glbIpTablesIsLoadedE`
- `asushotplug: _ZN11SecFltInTbl11runiptablesEPcS0_cS0_S0_S0_S0_S0_`
- `asushotplug: _ZN12SecVrtSrvTbl11runiptablesEcPcS0_S0_S0_S0_`
- `asushotplug: cgiGetEnblFirewallForWeb`
- `asushotplug: iptables`
- `asushotplug: iptables -%c FORWARD -i %s %s %s %s %s -j DROP`
- `asushotplug: iptables -%c FORWARD -i %s -p icmp %s %s -j DROP`
- `asushotplug: iptables -%c FORWARD -i %s -p tcp %s %s %s %s -j DROP`
- `asushotplug: iptables -%c FORWARD -i %s -p udp %s %s %s %s -j DROP`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_DSL-N13/FW_DSL_N13_1151A.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/ad5b4381c61af1e7

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
