# Firmware Audit: RAX75 / RAX75-V1.0.5.126_1.0.65.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.5.126_1.0.65.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.5.126_1.0.65.zip
- SHA-256: `91cd465e03696df9d5bb98f3def3d3510670e4af8bd885137060ba606cbfde87`
- Size: 77677548 bytes
- Version: 1.0.5.126_1.0.65
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/91cd465e03696df9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
