# Firmware Audit: RAX10 / RAX10-V1.0.1.68.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.1.68.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.1.68.zip
- SHA-256: `ef1135f6a992ed557222487129dcc00dccefcbc04fec1d5eedc41563f8b22852`
- Size: 61114062 bytes
- Version: 1.0.1.68
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ef1135f6a992ed55 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
