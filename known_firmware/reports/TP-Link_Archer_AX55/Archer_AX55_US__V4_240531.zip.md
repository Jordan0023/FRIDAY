# Firmware Audit: TP-Link Archer AX55 / Archer_AX55_US__V4_240531.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202407/20240715/Archer AX55(US)_V4_240531.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX55/Archer_AX55_US__V4_240531.zip
- SHA-256: `057acbd2637686c19bbcf89ecc3b49dfb1d6b766bb1a4d1e61e4a7a2a1f4fc2c`
- Size: 37138061 bytes
- Version: V4.6_1.1.1 Build 20240531
- Release date: 2024-07-15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/057acbd2637686c1 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
