# Firmware Audit: TP-Link Archer AX3000 Pro / Archer_AX3000_Pro_US__V1.0_231103.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202403/20240307/Archer AX3000 Pro(US)_V1.0_231103.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX3000_Pro/Archer_AX3000_Pro_US__V1.0_231103.zip
- SHA-256: `a3a38fd308aae59680e4a6cac3f9640aa96ef848dd253f5139c59463f5b91bbd`
- Size: 34795001 bytes
- Version: V1.6_1.2.3 Build 20231103
- Release date: 2024-03-07

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a3a38fd308aae596 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
