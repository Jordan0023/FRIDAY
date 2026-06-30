# Firmware Audit: TP-Link Archer C54 / Archer_C54_US__V1_210830.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202201/20220107/Archer C54(US)_V1_210830.zip
- Local path: known_firmware/firmware/TP-Link_Archer_C54/Archer_C54_US__V1_210830.zip
- SHA-256: `01acbe242a0ecb154c5b3e80c5e1e1ca68c94bad0ac27bb1ae1c5b6670795ff8`
- Size: 2901387 bytes
- Version: unknown
- Release date: 2022-01-07

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----, -----BEGIN RSA PRIVATE KEY-----`

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PASSWORD, PWD, password, pwd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, eval, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/01acbe242a0ecb15 exited 0: WARNING: Extractor.execute failed to run external extractor 'unstuff '%e'': [Errno 2] No such file or directory: 'unstuff', 'unstuff '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
