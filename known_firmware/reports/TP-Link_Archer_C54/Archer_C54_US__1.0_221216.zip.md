# Firmware Audit: TP-Link Archer C54 / Archer_C54_US__1.0_221216.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202302/20230207/Archer C54(US)_1.0_221216.zip
- Local path: known_firmware/firmware/TP-Link_Archer_C54/Archer_C54_US__1.0_221216.zip
- SHA-256: `d8a5000279fd245e3332029b887fcc1675b31bfca4ee7644ab7bb8697118ff51`
- Size: 2724924 bytes
- Version: V1.6_1.12.0 Build 221216
- Release date: 2023-02-07

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

- binwalk -eM --directory known_firmware/extracted/d8a5000279fd245e exited 0: WARNING: Extractor.execute failed to run external extractor 'unstuff '%e'': [Errno 2] No such file or directory: 'unstuff', 'unstuff '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
