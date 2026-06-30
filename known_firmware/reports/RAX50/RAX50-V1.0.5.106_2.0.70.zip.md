# Firmware Audit: RAX50 / RAX50-V1.0.5.106_2.0.70.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.5.106_2.0.70.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.5.106_2.0.70.zip
- SHA-256: `df0c8ce0f5c49555fefe7f89f6b7c961191976a87fde70bb9b69082bf5cec166`
- Size: 75894283 bytes
- Version: 1.0.5.106_2.0.70
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/df0c8ce0f5c49555 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
