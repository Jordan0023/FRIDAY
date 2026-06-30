# Firmware Audit: RAX48 / RAX48-V1.0.12.120.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX48/RAX48-V1.0.12.120.zip
- Local path: known_firmware/firmware/RAX48/RAX48-V1.0.12.120.zip
- SHA-256: `d3052783bfa74d446530741cff0e9461cd92e41f16c77025bc0e8903a792907b`
- Size: 82214846 bytes
- Version: 1.0.12.120
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d3052783bfa74d44 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
