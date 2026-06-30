# Firmware Audit: RAX40V2 / RAX40v2_V1.0.2.82_2.0.50.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX40v2/RAX40v2_V1.0.2.82_2.0.50.zip
- Local path: known_firmware/firmware/RAX40V2/RAX40v2_V1.0.2.82_2.0.50.zip
- SHA-256: `a3a6807e84c1dea85df712906f6c58373789dca45b884a9ddd66d638ab3c8edd`
- Size: 70834687 bytes
- Version: 0.2.82_2.0.50
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a3a6807e84c1dea8 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
