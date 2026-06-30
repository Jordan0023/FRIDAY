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

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/14424b87ee63f1df exited 0: WARNING: Extractor.execute failed to run external extractor 'unstuff '%e'': [Errno 2] No such file or directory: 'unstuff', 'unstuff '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
