# Firmware Audit: TP-Link Archer AX3000 Pro / Archer_AX3000_Pro_US__V1_240426.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202407/20240722/Archer AX3000 Pro(US)_V1_240426.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX3000_Pro/Archer_AX3000_Pro_US__V1_240426.zip
- SHA-256: `d7161da72131e6aa81531cf7e959e36ebd554f39ca9f63a4056a44a6386dcf6c`
- Size: 35446850 bytes
- Version: V1.6_1.3.1 Build 20240426
- Release date: 2024-07-22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d7161da72131e6aa exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
