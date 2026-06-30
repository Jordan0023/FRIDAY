# Firmware Audit: TP-Link Archer GX90 / Archer_GX90_US__V1_240428.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202407/20240709/Archer GX90(US)_V1_240428.zip
- Local path: known_firmware/firmware/TP-Link_Archer_GX90/Archer_GX90_US__V1_240428.zip
- SHA-256: `201b0851daa71d48ea8f537a721486546c9994bedfa16cc41cb11dca3f89c95c`
- Size: 45962745 bytes
- Version: V1.6_1.1.5 Build 20240428
- Release date: 2024-07-09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/201b0851daa71d48 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
