# Firmware Audit: ASUS DSL-N12U / FW_DSL_N12U_1052.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12U/FW_DSL_N12U_1052.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12U/FW_DSL_N12U_1052.zip
- SHA-256: `1a0935f8186cd7df8fcfb038f0e74f5e229e5aed5ef784fab6b458450e136b69`
- Size: 3986428 bytes
- Version: 1.0.5.2
- Release date: 2015/01/12

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PASSWORD, Password, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, HTTPD, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `/bin/ash, /bin/sh, SYSTEM, System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

### Outdated crypto/library markers

Old OpenSSL/BusyBox versions may contain known CVEs and should be mapped to package versions.

Evidence: `BusyBox v1.12`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1a0935f8186cd7df exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
