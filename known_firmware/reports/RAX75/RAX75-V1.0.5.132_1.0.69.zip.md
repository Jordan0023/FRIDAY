# Firmware Audit: RAX75 / RAX75-V1.0.5.132_1.0.69.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.5.132_1.0.69.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.5.132_1.0.69.zip
- SHA-256: `225da6d30438f23ca6aa611ee938db01ceb875d2bd35f85d795e06f2da6a45c0`
- Size: 74005667 bytes
- Version: 1.0.5.132_1.0.69
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/225da6d30438f23c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
