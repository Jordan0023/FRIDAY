# Firmware Audit: RAX80 / RAX80-V1.0.5.132_1.0.69.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX80/RAX80-V1.0.5.132_1.0.69.zip
- Local path: known_firmware/firmware/RAX80/RAX80-V1.0.5.132_1.0.69.zip
- SHA-256: `4f9ecfb45f6b68e935abc1edf3b83ef807419d7ec5e58e516c7345868faf2fbc`
- Size: 74005662 bytes
- Version: 1.0.5.132_1.0.69
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4f9ecfb45f6b68e9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
