# Firmware Audit: RAX20 / RAX20-V1.0.10.110_2.0.72.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.10.110_2.0.72.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.10.110_2.0.72.zip
- SHA-256: `2262ce82a8163ffbee7c49948d59457bcad7de6143131e22a1a5ecbcd9ea5287`
- Size: 76349368 bytes
- Version: 1.0.10.110_2.0.72
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2262ce82a8163ffb exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
