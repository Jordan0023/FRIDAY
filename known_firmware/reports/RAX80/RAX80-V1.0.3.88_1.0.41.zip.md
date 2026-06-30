# Firmware Audit: RAX80 / RAX80-V1.0.3.88_1.0.41.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX80/RAX80-V1.0.3.88_1.0.41.zip
- Local path: known_firmware/firmware/RAX80/RAX80-V1.0.3.88_1.0.41.zip
- SHA-256: `96546da5451916ea51b02a7e5217a10b630d3067320d95af4eba72fe82ae3cca`
- Size: 67524223 bytes
- Version: 1.0.3.88_1.0.41
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/96546da5451916ea exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
