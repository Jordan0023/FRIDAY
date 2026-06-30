# Firmware Audit: RAX43 / RAX43_V1.0.2.82_2.0.50.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX43/RAX43_V1.0.2.82_2.0.50.zip
- Local path: known_firmware/firmware/RAX43/RAX43_V1.0.2.82_2.0.50.zip
- SHA-256: `e28a5eb8ac3d5107c462f9e627cc14f24ea1f50e1b5662f51f9b3aa210b7a7dd`
- Size: 70834694 bytes
- Version: 0.2.82_2.0.50
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e28a5eb8ac3d5107 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
