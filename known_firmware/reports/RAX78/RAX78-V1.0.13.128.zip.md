# Firmware Audit: RAX78 / RAX78-V1.0.13.128.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX78/RAX78-V1.0.13.128.zip
- Local path: known_firmware/firmware/RAX78/RAX78-V1.0.13.128.zip
- SHA-256: `c01a3394cf18505e89466104b4aedb5f384fb5fc1829019e42c68ed243159465`
- Size: 66755084 bytes
- Version: 1.0.13.128
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c01a3394cf18505e exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
