# Firmware Audit: RAX75 / RAX75-V1.0.3.98_1.0.46.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.3.98_1.0.46.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.3.98_1.0.46.zip
- SHA-256: `b848bdc32f676fcdc5180f045dec2026c53aea22829abaad56e92c65c36ecd97`
- Size: 75197079 bytes
- Version: 1.0.3.98_1.0.46
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b848bdc32f676fcd exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
