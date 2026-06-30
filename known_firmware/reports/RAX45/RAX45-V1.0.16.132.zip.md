# Firmware Audit: RAX45 / RAX45-V1.0.16.132.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX45/RAX45-V1.0.16.132.zip
- Local path: known_firmware/firmware/RAX45/RAX45-V1.0.16.132.zip
- SHA-256: `030a60734fc6ce6f79fa1dfb47d7f8ad30da349ac9d89390038f7f0616b27bf8`
- Size: 84548122 bytes
- Version: 1.0.16.132
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/030a60734fc6ce6f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
