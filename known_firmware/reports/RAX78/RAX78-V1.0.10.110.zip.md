# Firmware Audit: RAX78 / RAX78-V1.0.10.110.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX78/RAX78-V1.0.10.110.zip
- Local path: known_firmware/firmware/RAX78/RAX78-V1.0.10.110.zip
- SHA-256: `b4d4676aee3619c827104c81a7aec1f9c068876a9905a434535a838cbbbf39d8`
- Size: 63624029 bytes
- Version: 1.0.10.110
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b4d4676aee3619c8 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
