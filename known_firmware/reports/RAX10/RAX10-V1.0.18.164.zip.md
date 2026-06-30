# Firmware Audit: RAX10 / RAX10-V1.0.18.164.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.18.164.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.18.164.zip
- SHA-256: `d2137ac59429a601f747d0eae34405687bdbeafd4af10bfd916e1d1f32353827`
- Size: 56443654 bytes
- Version: 1.0.18.164
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d2137ac59429a601 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
