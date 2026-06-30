# Firmware Audit: RAX50V2 / RAX50v2-V1.1.4.28.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50v2-V1.1.4.28.zip
- Local path: known_firmware/firmware/RAX50V2/RAX50v2-V1.1.4.28.zip
- SHA-256: `e861cbf42f6216ac48b1bcd2fac1a1c7d71e952a6db37f352304fe705a6f6feb`
- Size: 84776173 bytes
- Version: 1.1.4.28
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e861cbf42f6216ac exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
