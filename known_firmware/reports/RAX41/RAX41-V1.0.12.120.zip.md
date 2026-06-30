# Firmware Audit: RAX41 / RAX41-V1.0.12.120.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX41/RAX41-V1.0.12.120.zip
- Local path: known_firmware/firmware/RAX41/RAX41-V1.0.12.120.zip
- SHA-256: `1762d5c7845ddd7be66d7732ca28c6752e15559c5bd621298f288630ad1f8425`
- Size: 82214842 bytes
- Version: 1.0.12.120
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1762d5c7845ddd7b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
