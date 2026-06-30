# Firmware Audit: ASUS RT-N10 Ver. B / FW_RT_N10Plus_2028.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N10+/FW_RT_N10Plus_2028.zip
- Local path: known_firmware/firmware/ASUS_RT-N10_Ver._B/FW_RT_N10Plus_2028.zip
- SHA-256: `da52e79612d3f386e39b0fa16a377582c28683caa17710f49dbb9a33883107e2`
- Size: 3771014 bytes
- Version: 2.0.2.8
- Release date: 2011/11/08

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, Secret, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `telnetd`

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

- binwalk -eM --directory known_firmware/extracted/da52e79612d3f386 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
