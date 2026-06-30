# Firmware Audit: RAX43V2 / RAX43v2-V1.1.3.18.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX43/RAX43v2-V1.1.3.18.zip
- Local path: known_firmware/firmware/RAX43V2/RAX43v2-V1.1.3.18.zip
- SHA-256: `a6cd36cc6a05d8e92fa00eac16e4e21852539ba48ca63ec050d2535a55e5e97c`
- Size: 81245688 bytes
- Version: 1.1.3.18
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a6cd36cc6a05d8e9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
