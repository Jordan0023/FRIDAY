# Firmware Audit: RAX50 / RAX50-V1.0.2.66_2.0.42.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.2.66_2.0.42.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.2.66_2.0.42.zip
- SHA-256: `d01b84bf207a0c7b5190519d8e172ea76e63910d995810cdac35b4bc60782b4d`
- Size: 67470142 bytes
- Version: 1.0.2.66_2.0.42
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d01b84bf207a0c7b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
