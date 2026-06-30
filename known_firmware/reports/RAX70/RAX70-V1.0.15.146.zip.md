# Firmware Audit: RAX70 / RAX70-V1.0.15.146.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX70/RAX70-V1.0.15.146.zip
- Local path: known_firmware/firmware/RAX70/RAX70-V1.0.15.146.zip
- SHA-256: `3405b1f2e2c05dfdeda72a6d301271c205e1234afa0d20b3bc08b506bb3c9124`
- Size: 67580500 bytes
- Version: 1.0.15.146
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3405b1f2e2c05dfd exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
