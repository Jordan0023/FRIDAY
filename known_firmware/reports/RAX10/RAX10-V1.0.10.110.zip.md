# Firmware Audit: RAX10 / RAX10-V1.0.10.110.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.10.110.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.10.110.zip
- SHA-256: `eefd619763f3deabc88d4d34a4c2187b8d88dab95670c2874f815cf06a23d73e`
- Size: 53486110 bytes
- Version: 1.0.10.110
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/eefd619763f3deab exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
