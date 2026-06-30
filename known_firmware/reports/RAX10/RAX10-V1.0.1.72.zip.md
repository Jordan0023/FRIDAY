# Firmware Audit: RAX10 / RAX10-V1.0.1.72.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.1.72.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.1.72.zip
- SHA-256: `57ca9feeb0551992442d51c554c97c49d46026f01d570292ee07ea6520f1ed91`
- Size: 61078007 bytes
- Version: 1.0.1.72
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/57ca9feeb0551992 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
