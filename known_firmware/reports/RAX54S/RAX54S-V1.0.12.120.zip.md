# Firmware Audit: RAX54S / RAX54S-V1.0.12.120.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX54S/RAX54S-V1.0.12.120.zip
- Local path: known_firmware/firmware/RAX54S/RAX54S-V1.0.12.120.zip
- SHA-256: `d6cfb360a223995317f4439c46723197073abefa5ee6841f8634d9f4778848ee`
- Size: 82214850 bytes
- Version: 1.0.12.120
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d6cfb360a2239953 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
