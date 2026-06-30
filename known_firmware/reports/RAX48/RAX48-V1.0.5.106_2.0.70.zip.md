# Firmware Audit: RAX48 / RAX48-V1.0.5.106_2.0.70.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX48/RAX48-V1.0.5.106_2.0.70.zip
- Local path: known_firmware/firmware/RAX48/RAX48-V1.0.5.106_2.0.70.zip
- SHA-256: `6a22493794ff6fef058da13298ef955d469c16794b99da0682ab32972862839f`
- Size: 75894285 bytes
- Version: 1.0.5.106_2.0.70
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6a22493794ff6fef exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
