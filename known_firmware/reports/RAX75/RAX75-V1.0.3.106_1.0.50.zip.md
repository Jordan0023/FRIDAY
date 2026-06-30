# Firmware Audit: RAX75 / RAX75-V1.0.3.106_1.0.50.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.3.106_1.0.50.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.3.106_1.0.50.zip
- SHA-256: `28eef3996270a36d1fef89d41d5287e645b7d587558d4d517e921ffd4222c484`
- Size: 79180250 bytes
- Version: 1.0.3.106_1.0.50
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/28eef3996270a36d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
