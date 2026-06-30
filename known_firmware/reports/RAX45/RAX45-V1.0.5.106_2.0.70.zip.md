# Firmware Audit: RAX45 / RAX45-V1.0.5.106_2.0.70.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX45/RAX45-V1.0.5.106_2.0.70.zip
- Local path: known_firmware/firmware/RAX45/RAX45-V1.0.5.106_2.0.70.zip
- SHA-256: `1355aefe11b16f378a48426d0718b56b09b8ee0547bf4d21203837b9b6c1c94d`
- Size: 75894284 bytes
- Version: 1.0.5.106_2.0.70
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1355aefe11b16f37 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
