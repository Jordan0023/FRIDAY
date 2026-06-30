# Firmware Audit: RAX38V2 / RAX38v2-V1.0.4.100_2.0.64.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX38v2/RAX38v2-V1.0.4.100_2.0.64.zip
- Local path: known_firmware/firmware/RAX38V2/RAX38v2-V1.0.4.100_2.0.64.zip
- SHA-256: `11e68bcd2ba52dc928ad5bdb4b75ace338155d11ec0be45ca4eaf5430f59a219`
- Size: 74003225 bytes
- Version: 1.0.4.100_2.0.64
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/11e68bcd2ba52dc9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
