# Firmware Audit: RAX15 / RAX15-V1.0.1.58_2.0.31.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX15/RAX15-V1.0.1.58_2.0.31.zip
- Local path: known_firmware/firmware/RAX15/RAX15-V1.0.1.58_2.0.31.zip
- SHA-256: `926c5f5a94df0a1ba8f16197f893531b8945904fb0c65fae56fb7cdb74bf48b3`
- Size: 61783956 bytes
- Version: 1.0.1.58_2.0.31
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/926c5f5a94df0a1b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
