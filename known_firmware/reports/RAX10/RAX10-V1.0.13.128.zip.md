# Firmware Audit: RAX10 / RAX10-V1.0.13.128.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.13.128.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.13.128.zip
- SHA-256: `1ad126a567e6cf724a15637d1830e09bf44df2f49653b1234be1b3ef6b332ac4`
- Size: 53107988 bytes
- Version: 1.0.13.128
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1ad126a567e6cf72 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
