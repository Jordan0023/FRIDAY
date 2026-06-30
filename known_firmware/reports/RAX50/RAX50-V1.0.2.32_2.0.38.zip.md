# Firmware Audit: RAX50 / RAX50-V1.0.2.32_2.0.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.2.32_2.0.38.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.2.32_2.0.38.zip
- SHA-256: `639c04540a77630c2db785e59f248291f3f5de6a18373ea768ee9b515e3866a3`
- Size: 65567198 bytes
- Version: 1.0.2.32_2.0.38
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/639c04540a77630c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
