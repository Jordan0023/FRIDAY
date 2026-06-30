# Firmware Audit: ASUS RT-N13U / FW_RT_N13U_1020_APAC.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N13U/FW_RT_N13U_1020_APAC.zip
- Local path: known_firmware/firmware/ASUS_RT-N13U/FW_RT_N13U_1020_APAC.zip
- SHA-256: `d74592057a45de209100de2269c4ec653e9be0c06e0e5a85e40696c89ba5f0e0`
- Size: 3864379 bytes
- Version: 1.0.2.0_APAC
- Release date: 2010/01/22

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, Secret, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `SShD, inetd, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `HTTPD, cgi-bin, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `/bin/ash, /bin/sh, SYSTEM, System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

### Outdated crypto/library markers

Old OpenSSL/BusyBox versions may contain known CVEs and should be mapped to package versions.

Evidence: `BusyBox v1.12`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d74592057a45de20 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
