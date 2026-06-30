# Firmware Audit: RAX20 / RAX20-V1.0.1.58_2.0.31.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.1.58_2.0.31.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.1.58_2.0.31.zip
- SHA-256: `e9775a92b9708494f63b23a0400a38fb452c19c80fe8e5067f92c26a1342f016`
- Size: 61783954 bytes
- Version: 1.0.1.58_2.0.31
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e9775a92b9708494 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
