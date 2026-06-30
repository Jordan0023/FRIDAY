# Firmware Audit: TP-Link Archer AXE95 / Archer_AXE95_US__V1_231228.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202401/20240119/Archer AXE95(US)_V1_231228.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AXE95/Archer_AXE95_US__V1_231228.zip
- SHA-256: `16059b029b9d0e88c6164fc703cd8dd81dedfd3f1d3c50c79aac5d60350e68e1`
- Size: 43781545 bytes
- Version: V1.6_1.1.5 Build 20231228
- Release date: 2024-01-19

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOA, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/16059b029b9d0e88 exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
