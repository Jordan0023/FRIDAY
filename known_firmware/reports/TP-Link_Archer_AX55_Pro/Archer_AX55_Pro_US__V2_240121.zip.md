# Firmware Audit: TP-Link Archer AX55 Pro / Archer_AX55_Pro_US__V2_240121.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202402/20240221/Archer AX55 Pro(US)_V2_240121.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX55_Pro/Archer_AX55_Pro_US__V2_240121.zip
- SHA-256: `3d2bb247e6ae754ecb81d855a5a57251844fb800d24287dc14611746430e070e`
- Size: 29176102 bytes
- Version: V2.6_1.0.5 Build 20240121
- Release date: 2024-02-21

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3d2bb247e6ae754e exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
