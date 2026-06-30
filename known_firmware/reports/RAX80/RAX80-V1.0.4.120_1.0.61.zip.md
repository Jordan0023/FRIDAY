# Firmware Audit: RAX80 / RAX80-V1.0.4.120_1.0.61.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX80/RAX80-V1.0.4.120_1.0.61.zip
- Local path: known_firmware/firmware/RAX80/RAX80-V1.0.4.120_1.0.61.zip
- SHA-256: `50b066a890db82cbbde518f117bcb36a71114bf104fc88db00bac87782a30362`
- Size: 78863825 bytes
- Version: 1.0.4.120_1.0.61
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/50b066a890db82cb exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
