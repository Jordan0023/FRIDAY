# Firmware Audit: RAX41V2 / RAX41v2-V1.1.3.18.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX41/RAX41v2-V1.1.3.18.zip
- Local path: known_firmware/firmware/RAX41V2/RAX41v2-V1.1.3.18.zip
- SHA-256: `a25d5ada2a46cf641e782741e0de228e13cf2c85116c5ad642efacf56e2d44be`
- Size: 81245689 bytes
- Version: 1.1.3.18
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a25d5ada2a46cf64 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
