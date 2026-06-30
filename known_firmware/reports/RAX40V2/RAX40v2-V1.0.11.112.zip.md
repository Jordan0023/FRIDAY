# Firmware Audit: RAX40V2 / RAX40v2-V1.0.11.112.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX40v2/RAX40v2-V1.0.11.112.zip
- Local path: known_firmware/firmware/RAX40V2/RAX40v2-V1.0.11.112.zip
- SHA-256: `8dffe8f0b274cca490c9f391c8cb9c64a027b30ef0a71ec130ca8208a7e5bbe4`
- Size: 75405036 bytes
- Version: 1.0.11.112
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8dffe8f0b274cca4 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
