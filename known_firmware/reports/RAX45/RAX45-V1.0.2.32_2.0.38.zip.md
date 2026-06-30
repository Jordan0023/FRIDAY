# Firmware Audit: RAX45 / RAX45-V1.0.2.32_2.0.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX45/RAX45-V1.0.2.32_2.0.38.zip
- Local path: known_firmware/firmware/RAX45/RAX45-V1.0.2.32_2.0.38.zip
- SHA-256: `0816448a3c6e35c7a836361f6bb3649939efe4f2c03095942527b7b43d6797ad`
- Size: 65567197 bytes
- Version: 1.0.2.32_2.0.38
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0816448a3c6e35c7 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
