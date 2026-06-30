# Firmware Audit: RAX10 / RAX10-V1.0.15.146.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.15.146.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.15.146.zip
- SHA-256: `b134b12b6693f44accc84f40e3ee2a48a92c5103da563898ceb891b12f8a9a26`
- Size: 53919825 bytes
- Version: 1.0.15.146
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b134b12b6693f44a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
