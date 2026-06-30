# Firmware Audit: RAX50 / RAX50-V1.0.11.112.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.11.112.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.11.112.zip
- SHA-256: `360cb32372abd6da18dfe686e5ae2d38bb6953251f68c0a4b36beebeafdb9bc3`
- Size: 75405026 bytes
- Version: 1.0.11.112
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/360cb32372abd6da exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
