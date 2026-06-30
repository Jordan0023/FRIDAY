# Firmware Audit: TP-Link Archer AX5400 Pro / Archer_AX5400_Pro_US__V1_250928.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251105/Archer AX5400 Pro(US)_V1_250928.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX5400_Pro/Archer_AX5400_Pro_US__V1_250928.zip
- SHA-256: `14cdf9dc3db7ecece12de7b957755496dd764d61f6dfdcc0b8f73a7edbd48dc8`
- Size: 41658382 bytes
- Version: V1.6_1.4.5 Build 20250928
- Release date: 2025-11-08

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/14cdf9dc3db7ecec exited 0: WARNING: Extractor.execute failed to run external extractor 'unstuff '%e'': [Errno 2] No such file or directory: 'unstuff', 'unstuff '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
