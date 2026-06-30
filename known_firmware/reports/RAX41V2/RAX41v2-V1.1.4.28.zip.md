# Firmware Audit: RAX41V2 / RAX41v2-V1.1.4.28.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX41/RAX41v2-V1.1.4.28.zip
- Local path: known_firmware/firmware/RAX41V2/RAX41v2-V1.1.4.28.zip
- SHA-256: `404de697d9d7ac3baf82710e63e86154f67a8c2177022cdd6a026c6cd2df160d`
- Size: 84776175 bytes
- Version: 1.1.4.28
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/404de697d9d7ac3b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
