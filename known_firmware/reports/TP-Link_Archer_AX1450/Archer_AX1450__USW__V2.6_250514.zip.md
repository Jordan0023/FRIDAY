# Firmware Audit: TP-Link Archer AX1450 / Archer_AX1450__USW__V2.6_250514.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251105/Archer AX1450_(USW)_V2.6_250514.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX1450/Archer_AX1450__USW__V2.6_250514.zip
- SHA-256: `dcd96fc09af5399d4d82462d3fcce53718ee2dba1640a27b07f64727994437c5`
- Size: 23410509 bytes
- Version: V2.6_1.1.0 Build 20250514
- Release date: 2025-11-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dcd96fc09af5399d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
