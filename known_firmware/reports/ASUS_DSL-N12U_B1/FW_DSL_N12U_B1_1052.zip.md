# Firmware Audit: ASUS DSL-N12U B1 / FW_DSL_N12U_B1_1052.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12U_B1/FW_DSL_N12U_B1_1052.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12U_B1/FW_DSL_N12U_B1_1052.zip
- SHA-256: `ccfb3ae2669bbd2242c3eeef66e2a8b4a1be8d60e3d6b3c254dfb1f0ecdf642b`
- Size: 3986434 bytes
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

- binwalk -eM --directory known_firmware/extracted/ccfb3ae2669bbd22 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
