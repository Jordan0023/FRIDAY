# Firmware Audit: RAX43 / RAX43-V1.0.2.72_2.0.45.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX43/RAX43-V1.0.2.72_2.0.45.zip
- Local path: known_firmware/firmware/RAX43/RAX43-V1.0.2.72_2.0.45.zip
- SHA-256: `dbad75eccb6e0eb69be9b18a1e0648e52e77c082d774138d36d1f3833c821c0c`
- Size: 68683143 bytes
- Version: 1.0.2.72_2.0.45
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dbad75eccb6e0eb6 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
