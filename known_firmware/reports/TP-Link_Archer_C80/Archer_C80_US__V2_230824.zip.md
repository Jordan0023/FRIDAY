# Firmware Audit: TP-Link Archer C80 / Archer_C80_US__V2_230824.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202310/20231030/Archer C80(US)_V2_230824.zip
- Local path: known_firmware/firmware/TP-Link_Archer_C80/Archer_C80_US__V2_230824.zip
- SHA-256: `9836efb7da5672fe1fd94b77b90bf24b5b090a26200f756b2aab5f5026f7cd57`
- Size: 3904858 bytes
- Version: V2.6_1.13.2 Build 230824
- Release date: 2023-10-30

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----, -----BEGIN RSA PRIVATE KEY-----`

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PASSWORD, PWD, password, pwd, token`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, HTTPD, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9836efb7da5672fe exited 0: WARNING: Extractor.execute failed to run external extractor 'unstuff '%e'': [Errno 2] No such file or directory: 'unstuff', 'unstuff '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
