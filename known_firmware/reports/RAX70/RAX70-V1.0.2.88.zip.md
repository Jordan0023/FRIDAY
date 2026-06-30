# Firmware Audit: RAX70 / RAX70-V1.0.2.88.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX70/RAX70-V1.0.2.88.zip
- Local path: known_firmware/firmware/RAX70/RAX70-V1.0.2.88.zip
- SHA-256: `b288034606396d9c271688837b9e4177f873027bee3598e9c8dbc731452272e6`
- Size: 65675443 bytes
- Version: 1.0.2.88
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b288034606396d9c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
