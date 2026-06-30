# Firmware Audit: RAX10 / RAX10-V1.0.14.134.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.14.134.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.14.134.zip
- SHA-256: `f7db0ae12f264fc3c161ffe1e82aa0707d262570218326df96f6b21b2a8131eb`
- Size: 53913463 bytes
- Version: 1.0.14.134
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f7db0ae12f264fc3 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
