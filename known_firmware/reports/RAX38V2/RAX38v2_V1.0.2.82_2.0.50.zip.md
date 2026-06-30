# Firmware Audit: RAX38V2 / RAX38v2_V1.0.2.82_2.0.50.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX38v2/RAX38v2_V1.0.2.82_2.0.50.zip
- Local path: known_firmware/firmware/RAX38V2/RAX38v2_V1.0.2.82_2.0.50.zip
- SHA-256: `2fcd748e4d1721ebc79d0af64ef776984e14fd12bdc41d492eb7a864d2b2876e`
- Size: 70834688 bytes
- Version: 0.2.82_2.0.50
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2fcd748e4d1721eb exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
