# Firmware Audit: RAX78 / RAX78-V1.0.15.146.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX78/RAX78-V1.0.15.146.zip
- Local path: known_firmware/firmware/RAX78/RAX78-V1.0.15.146.zip
- SHA-256: `5856a9df83c89b99a7d9fe3ea6fd07f33b60bfcd649a0a9f9102c8bfb16ba99e`
- Size: 67580597 bytes
- Version: 1.0.15.146
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5856a9df83c89b99 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
