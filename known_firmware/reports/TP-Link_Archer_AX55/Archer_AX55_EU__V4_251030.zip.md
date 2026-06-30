# Firmware Audit: TP-Link Archer AX55 / Archer_AX55_EU__V4_251030.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202510/20251030/Archer AX55(EU)_V4_251030.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX55/Archer_AX55_EU__V4_251030.zip
- SHA-256: `63aef3f1a541dda9996cb3ea4845e4cdd931af9859b215c0ed420025d6df1826`
- Size: 37377400 bytes
- Version: unknown
- Release date: 2026-01-16

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/63aef3f1a541dda9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
