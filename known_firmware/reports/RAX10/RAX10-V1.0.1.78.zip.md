# Firmware Audit: RAX10 / RAX10-V1.0.1.78.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.1.78.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.1.78.zip
- SHA-256: `f68591735b9e9c267d940fb22ee9159d2789f7ebf84558a213ff67dc3fd2bb7d`
- Size: 60971429 bytes
- Version: 1.0.1.78
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f68591735b9e9c26 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
