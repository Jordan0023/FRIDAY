# Firmware Audit: RAX43 / RAX43-V1.0.11.112.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX43/RAX43-V1.0.11.112.zip
- Local path: known_firmware/firmware/RAX43/RAX43-V1.0.11.112.zip
- SHA-256: `cae11fbd38c76d0e2a059be0237c071358930aad91dde36f505fa3ceb54145c2`
- Size: 75405026 bytes
- Version: 1.0.11.112
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cae11fbd38c76d0e exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
