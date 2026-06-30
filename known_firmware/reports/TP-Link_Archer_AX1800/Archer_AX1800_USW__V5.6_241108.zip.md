# Firmware Audit: TP-Link Archer AX1800 / Archer_AX1800_USW__V5.6_241108.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202412/20241205/Archer AX1800(USW)_V5.6_241108.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX1800/Archer_AX1800_USW__V5.6_241108.zip
- SHA-256: `3acbe45ad5488c7c41625c3e056b95a34b660c0f105b008440232a10c3d5e14e`
- Size: 24436879 bytes
- Version: V5.6_1.0.1 Build 20241108
- Release date: 2024-12-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3acbe45ad5488c7c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
