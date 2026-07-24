# Firmware Audit: TP-Link Archer C54 / Archer_C54_US__V1_230608.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202309/20230908/Archer C54(US)_V1_230608.zip
- Local path: known_firmware/firmware/TP-Link_Archer_C54/Archer_C54_US__V1_230608.zip
- SHA-256: `14424b87ee63f1df422fc94765d911f07468e531a6b267cf798dcb565c5a1844`
- Size: 2954889 bytes
- Version: V1.6_1.12.20 Build 230608
- Release date: 2025-12-15

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----, -----BEGIN EC PRIVATE KEY-----, -----BEGIN RSA PRIVATE KEY-----`

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PASSWORD, PWD, Password, password, pwd`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `INETD, inetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, eval, system`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

- `12/2030`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `1999/xhtml`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `404.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `BAUwAwEB/zAdBgNVHQ4EFgQUxu2iBRTsef5iNnsADVhM`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `Catalog/Pages`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `ExtGState/BM/Normal/CA`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `ExtGState/BM/Normal/ca`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `Filter/FlateDecode/Length`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `FlateDecode/Length`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `Group/S/Transparency/CS/DeviceRGB`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `ObjStm/N`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `Page/Parent`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `Pages/Count`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `S/StructParents`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `TR/xhtml1/DTD/xhtml1-transitional.dtd`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `Text/ImageB/ImageC/ImageI`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `WUujXjlIDgxIvyZZCYiXO3dle2/MEvpmZk6JQIDAQABo1EwTzALBgNVHQ8E`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `c/c-50`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `default/img/Loading.gif`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `default/img/logo-icon.png`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `easymesh/product-list`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `fail.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `flashing.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `index.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `mjDm3ELbygZRIp9WEDOZCJ/zawXo`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `ru/easymesh/product-list`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `support/download`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `advanced/network/ddnsAdv/ddnsAdvDnydns/models.js`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L2; score=4
- `advanced/network/ddnsAdv/ddnsAdvNoip/models.js`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L2; score=4
- `advanced/network/ddnsAdv/ddnsAdvTplink/models.js`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L2; score=4

### Non-HTTP Service Surface

- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/16CD50`; evidence=service marker present; local sinks: exec
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1799CB`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/17E463`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1AAC53`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1AFEF2`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1B83B8`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1C053E`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1C7C4A`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1CF020`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1D62CE`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1DD257`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1E493A`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1EBDBC`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1F345B`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/1F96DD`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/20041F`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/2071E3`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/20E940`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/21980F`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/224841`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/228A34`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/235589`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/23BCE1`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/241B71`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/247B79`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/24EFCF`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/253813`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/259FEE`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/260E0F`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/266EC5`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/_16CD50.extracted/20BA04.sit`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/_16CD50.extracted/20BA16.sit`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/_16CD50.extracted/2B7008.zlib`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/_1799CB.extracted/1C9EFF.sit`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/_1799CB.extracted/1C9F11.sit`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/_1799CB.extracted/275503.zlib`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/_17E463.extracted/18C63E.sit`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/_17E463.extracted/18C650.sit`; evidence=service marker present; local sinks: exec, file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/_17E463.extracted/237C42.zlib`; evidence=service marker present; local sinks: file_write
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_C54_US__V1_230608.zip.extracted/_c54v1-IMG0-up-boot-128B_2023-06-09_14.00.59.bin.extracted/_1AAC53.extracted/155076.sit`; evidence=service marker present; local sinks: exec, file_write

### Sink Summary

- exec: 673
- file_write: 553
- popen: 0
- system: 0
- unsafe_copy: 0

### Config Writer Leads

- `10299A.sit: ",CHECKING_INTERNET:"Checking internet connection...",ENJOY_APP:"Enjoy network management at your fingertips with the Tether app.",NO_INTERNET:"No Internet Conn`
- `10299A.sit: ",FIREWALL:"`
- `10299A.sit: ",FIREWALL_INTRO:"`
- `10299A.sit: ",FIREWALL_LAN:"`
- `10299A.sit: ",FIREWALL_SPI:"SPI`
- `10299A.sit: ",FIREWALL_WAN:"`
- `10299A.sit: "},$.su.CHAR.FIREWALL={FIREWALL:"`
- `10299A.sit: s system time.",CURRENT_TIME:"Current Time",HOUR_TIME:"24-Hour Time",SET_TIME:"Set Time",DATE:"Date",MANUAL:"Manually",GET_GMT:"Get from Internet",GET_DEVICE:"G`
- `1029AC.sit: ",CHECKING_INTERNET:"Checking internet connection...",ENJOY_APP:"Enjoy network management at your fingertips with the Tether app.",NO_INTERNET:"No Internet Conn`
- `1029AC.sit: ",FIREWALL:"`
- `1029AC.sit: ",FIREWALL_INTRO:"`
- `1029AC.sit: ",FIREWALL_LAN:"`
- `1029AC.sit: ",FIREWALL_SPI:"SPI`
- `1029AC.sit: ",FIREWALL_WAN:"`
- `1029AC.sit: "},$.su.CHAR.FIREWALL={FIREWALL:"`
- `1029AC.sit: s system time.",CURRENT_TIME:"Current Time",HOUR_TIME:"24-Hour Time",SET_TIME:"Set Time",DATE:"Date",MANUAL:"Manually",GET_GMT:"Get from Internet",GET_DEVICE:"G`
- `10B867.zlib: !function(V){V.su=V.su||{},V.su.encrypt=function(t,r,e){for(var n=e=e||"yLwVl0zKqws7LgKPRQ84Mdt708T1qQ3Ha7xv3H7NyU84p21BriUWBU43odz3iP4rBL3cD02KZciXTysVXiV8ngg6`
- `10B867.zlib: !function(n){function e(e){this.settings=n.extend({},{locale:"en_US",DEFAULT_LAN_TYPE:"en_US",URL_JS:"./locale/%LAN_TYPE%/lan.js",URL_CSS:"./locale/%LAN_TYPE%/l`
- `10B867.zlib: </scpd>!function(u){u.su.moduleManager.define("mapRouter",{services:["device","ajax","moduleRouter","timer","device"],models:["lanAdvLanModel","wirelessMapModel`
- `10B867.zlib: FIREWALL`
- `10B867.zlib: SPI_FIREWALL`
- `127AE9.zlib: !function(V){V.su=V.su||{},V.su.encrypt=function(t,r,e){for(var n=e=e||"yLwVl0zKqws7LgKPRQ84Mdt708T1qQ3Ha7xv3H7NyU84p21BriUWBU43odz3iP4rBL3cD02KZciXTysVXiV8ngg6`
- `127AE9.zlib: !function(n){function e(e){this.settings=n.extend({},{locale:"en_US",DEFAULT_LAN_TYPE:"en_US",URL_JS:"./locale/%LAN_TYPE%/lan.js",URL_CSS:"./locale/%LAN_TYPE%/l`
- `127AE9.zlib: </scpd>!function(u){u.su.moduleManager.define("mapRouter",{services:["device","ajax","moduleRouter","timer","device"],models:["lanAdvLanModel","wirelessMapModel`
- `127AE9.zlib: FIREWALL`
- `127AE9.zlib: SPI_FIREWALL`
- `12B728.sit: ",CHECKING_INTERNET:"Checking internet connection...",ENJOY_APP:"Enjoy network management at your fingertips with the Tether app.",NO_INTERNET:"No Internet Conn`
- `12B728.sit: ",FIREWALL:"`
- `12B728.sit: ",FIREWALL_INTRO:"`
- `12B728.sit: ",FIREWALL_LAN:"`

### Handler-level Correlated Flows

No source and dangerous sink were co-located in the same sampled handler or binary.

### Ghidra Function-local Evidence

No function-local route/sink pairs were emitted by Ghidra.

### Runtime Profile

- Vendor profile: tp-link
- Web stack: not identified
- State backends: not identified
- Architectures: not identified
- Executables/scripts discovered: 0

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: none identified
- Listener candidates: none identified
- Runtime requirements discovered: 0
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 392
- Archive validation cases: 7

### Confirmation Policy

- confirmed_label_requires: L5
- confirmed_zero_day_requires: ['L5 reproducible security effect with fault/sink attribution', 'novel reproducible pre-authentication exploitation path with no remote administrator session required', 'LAN or WAN network reachability without credentials', 'impact is remote code execution or a reliable input-specific denial of service', 'denial of service reproduces from attacker input and is not generic resource exhaustion', 'documented, dated public-prior-art search', 'no matching public disclosure or publicly available fix at the recorded discovery time']
- authenticated_admin_disposition: confirmed vulnerability, but not a confirmed zero-day
- vendor_contact_required: False
- private_duplicate_caveat: public novelty does not exclude an unknown private or embargoed duplicate
- L3: route-specific attacker parameter reaches the sink
- L4: authentication/validation boundary and trigger are proven
- L5: reproducible security effect with fault/sink attribution
- forbidden_shortcut: route string and dangerous symbol merely co-located in a binary
- impactful_hunt_scope: unauthenticated LAN/WAN RCE or reliable input-specific denial of service

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- Only routes with a plausible low-privilege boundary and route-local sink evidence are promoted. Global firmware sink counts never raise route evidence.
- Authentication labels inferred from strings are hypotheses until dispatcher control flow or a live request confirms them.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/TP-Link_Archer_C54/Archer_C54_US__V1_230608.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/14424b87ee63f1df exited 0: WARNING: Extractor.execute failed to run external extractor 'unstuff '%e'': [Errno 2] No such file or directory: 'unstuff', 'unstuff '%e'' might not be installed correctly

## Decompiler Notes

- No ELF binaries found for Ghidra import.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
