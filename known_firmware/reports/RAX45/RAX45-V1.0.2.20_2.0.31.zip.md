# Firmware Audit: RAX45 / RAX45-V1.0.2.20_2.0.31.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX45/RAX45-V1.0.2.20_2.0.31.zip
- Local path: known_firmware/firmware/RAX45/RAX45-V1.0.2.20_2.0.31.zip
- SHA-256: `53faa0664c4d25336ace61e1f310999109f69abc927fe1702f53afedd6c93deb`
- Size: 65748778 bytes
- Version: 1.0.2.20_2.0.31
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/53faa0664c4d2533 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
