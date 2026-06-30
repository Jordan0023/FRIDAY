# Firmware Audit: RAX50 / RAX50-V1.0.17.142.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.17.142.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.17.142.zip
- SHA-256: `3f27b4a7202d89d70156a5d187cf8ccfe0e28bcb7c0b24311e21181d25967272`
- Size: 81328182 bytes
- Version: 1.0.17.142
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3f27b4a7202d89d7 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
