# Firmware Audit: TP-Link Archer AX72 Pro / Archer_AX72_Pro_US__V1_250814.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251107/Archer AX72 Pro(US)_V1_250814.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX72_Pro/Archer_AX72_Pro_US__V1_250814.zip
- SHA-256: `1622b372f81470d2da53ebf0da63d892d36bc5ec53d780e724ce56b2dc1fd7cd`
- Size: 39080894 bytes
- Version: V1.6_1.4.2 Build 20250814
- Release date: 2025-11-07

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `pWd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1622b372f81470d2 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
