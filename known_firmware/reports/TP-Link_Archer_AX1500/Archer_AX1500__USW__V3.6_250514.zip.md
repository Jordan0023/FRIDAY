# Firmware Audit: TP-Link Archer AX1500 / Archer_AX1500__USW__V3.6_250514.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251105/Archer AX1500_(USW)_V3.6_250514.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX1500/Archer_AX1500__USW__V3.6_250514.zip
- SHA-256: `d42cbb0d99f89070785144bf45f88af70fdedaff12f52ad954603a55d91a8fee`
- Size: 23410509 bytes
- Version: V3.6_1.1.0 Build 20250514
- Release date: 2025-11-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d42cbb0d99f89070 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
