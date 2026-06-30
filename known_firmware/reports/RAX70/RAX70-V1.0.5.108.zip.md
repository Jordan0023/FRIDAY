# Firmware Audit: RAX70 / RAX70-V1.0.5.108.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX70/RAX70-V1.0.5.108.zip
- Local path: known_firmware/firmware/RAX70/RAX70-V1.0.5.108.zip
- SHA-256: `cb1843a425d427c8a95649c4fb68a18774dece81c1926e9e157e6e489a277d7d`
- Size: 63622756 bytes
- Version: 1.0.5.108
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cb1843a425d427c8 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
