# Firmware Audit: RAX50 / RAX50-V1.0.0.30_2.0.20.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.0.30_2.0.20.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.0.30_2.0.20.zip
- SHA-256: `f74f9b4ff5f48def6abd246590a5af62aa41ec3bc28da9193fe9a252e7c7496f`
- Size: 55726431 bytes
- Version: 1.0.0.30_2.0.20
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f74f9b4ff5f48def exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
