# Firmware Audit: TP-Link Archer AX5400 Pro / Archer_AX5400_Pro_US__V1_250814.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251107/Archer AX5400 Pro(US)_V1_250814.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX5400_Pro/Archer_AX5400_Pro_US__V1_250814.zip
- SHA-256: `cdf20591bce86cc80da044ba21865dfe521cf79f411e8efed4e6ff319587e8b4`
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

- binwalk -eM --directory known_firmware/extracted/cdf20591bce86cc8 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
