# Firmware Audit: RAX78 / RAX78-V1.0.5.108.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX78/RAX78-V1.0.5.108.zip
- Local path: known_firmware/firmware/RAX78/RAX78-V1.0.5.108.zip
- SHA-256: `25c916079c5edf6b9a1b01ce9efd80a350d2a3bbe9b3629f40e8f89271ed4bbd`
- Size: 63622656 bytes
- Version: 1.0.5.108
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/25c916079c5edf6b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
