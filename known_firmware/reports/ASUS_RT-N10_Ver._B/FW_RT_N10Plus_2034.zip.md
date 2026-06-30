# Firmware Audit: ASUS RT-N10 Ver. B / FW_RT_N10Plus_2034.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N10+/FW_RT_N10Plus_2034.zip
- Local path: known_firmware/firmware/ASUS_RT-N10_Ver._B/FW_RT_N10Plus_2034.zip
- SHA-256: `cfe96ae5f3e00fa4ab59998e7b23584d6914dd2d71aa26495792461a23952218`
- Size: 3866584 bytes
- Version: 2.0.3.4
- Release date: 2014/08/05

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, Secret, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, HTTPD, cgi-bin, httpd`

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

- binwalk -eM --directory known_firmware/extracted/cfe96ae5f3e00fa4 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
