# Firmware Audit: RAX45 / RAX45-V1.0.4.100_2.0.64.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX45/RAX45-V1.0.4.100_2.0.64.zip
- Local path: known_firmware/firmware/RAX45/RAX45-V1.0.4.100_2.0.64.zip
- SHA-256: `167232e1415e55bd1891d4b66a0ae2862b1516acde949fec7d2c6bb389123c9b`
- Size: 74003215 bytes
- Version: 1.0.4.100_2.0.64
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/167232e1415e55bd exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
