# Firmware Audit: RAX80 / RAX80-V1.0.3.106_1.0.50.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX80/RAX80-V1.0.3.106_1.0.50.zip
- Local path: known_firmware/firmware/RAX80/RAX80-V1.0.3.106_1.0.50.zip
- SHA-256: `dfa72b37192090876486c9e89321733b78dcecee2210f2fc817a84503839daeb`
- Size: 79180250 bytes
- Version: 1.0.3.106_1.0.50
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dfa72b3719209087 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
