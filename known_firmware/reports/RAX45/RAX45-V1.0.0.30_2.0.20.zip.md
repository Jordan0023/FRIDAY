# Firmware Audit: RAX45 / RAX45-V1.0.0.30_2.0.20.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX45/RAX45-V1.0.0.30_2.0.20.zip
- Local path: known_firmware/firmware/RAX45/RAX45-V1.0.0.30_2.0.20.zip
- SHA-256: `15cc97d2b12a42d5df2ebef50efa703fe51e8fd3556e0981fb454b96e09b4a50`
- Size: 55726432 bytes
- Version: 1.0.0.30_2.0.20
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/15cc97d2b12a42d5 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
