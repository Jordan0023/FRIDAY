# Firmware Audit: RAX15 / RAX15-V1.0.2.82_2.0.52.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX15/RAX15-V1.0.2.82_2.0.52.zip
- Local path: known_firmware/firmware/RAX15/RAX15-V1.0.2.82_2.0.52.zip
- SHA-256: `a4b6944cfc27389844c2cfd925edfa7ab94939e642630361bf215c5cff8707b6`
- Size: 67445147 bytes
- Version: 1.0.2.82_2.0.52
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a4b6944cfc273898 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
