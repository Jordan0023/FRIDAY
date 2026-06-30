# Firmware Audit: RAX50 / RAX50-V1.0.2.10_2.0.26.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.2.10_2.0.26.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.2.10_2.0.26.zip
- SHA-256: `d026d840ca486cd50bf6d819b5768b70b600acf341de39ddfcf3f328fde02b36`
- Size: 65747571 bytes
- Version: 1.0.2.10_2.0.26
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d026d840ca486cd5 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
