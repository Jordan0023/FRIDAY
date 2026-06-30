# Firmware Audit: TP-Link Archer AC1900 / Archer_AC1900_USW__V2.6_240430.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202407/20240711/Archer AC1900(USW)_V2.6_240430.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AC1900/Archer_AC1900_USW__V2.6_240430.zip
- SHA-256: `54592b203735e67618ff854cdfd685e4da6f8da1b7dcd2e9e94fb8820be0123b`
- Size: 3961094 bytes
- Version: V2.6_1.13.6 Build 240430
- Release date: 2024-07-11

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----, -----BEGIN RSA PRIVATE KEY-----`

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PASSWORD, PWD, password, pwd, token`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, HTTPD, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/54592b203735e676 exited 0: WARNING: Extractor.execute failed to run external extractor 'unstuff '%e'': [Errno 2] No such file or directory: 'unstuff', 'unstuff '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
