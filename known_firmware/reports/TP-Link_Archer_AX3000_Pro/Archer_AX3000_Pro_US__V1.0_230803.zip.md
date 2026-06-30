# Firmware Audit: TP-Link Archer AX3000 Pro / Archer_AX3000_Pro_US__V1.0_230803.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202403/20240307/Archer AX3000 Pro(US)_V1.0_230803.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX3000_Pro/Archer_AX3000_Pro_US__V1.0_230803.zip
- SHA-256: `bd5c9353f871ae0b1b4527eea66a7b14feaca91988efe7ef2ee23513220160c2`
- Size: 34789754 bytes
- Version: V1.6_1.2.2 Build 20230803
- Release date: 2024-03-07

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bd5c9353f871ae0b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
