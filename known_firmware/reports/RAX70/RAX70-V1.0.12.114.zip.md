# Firmware Audit: RAX70 / RAX70-V1.0.12.114.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX70/RAX70-V1.0.12.114.zip
- Local path: known_firmware/firmware/RAX70/RAX70-V1.0.12.114.zip
- SHA-256: `922f348e5f8f227c8704d7dc0e76e9f37b80f85e0241cccbf13436b322e83d25`
- Size: 65187067 bytes
- Version: 1.0.12.114
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/922f348e5f8f227c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
