# Firmware Audit: RAX20 / RAX20-V1.0.2.82_2.0.52.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.2.82_2.0.52.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.2.82_2.0.52.zip
- SHA-256: `77e918774c0d2a34ff28f686f1a127ee0c5f01c219addae8f69aaa61fced802c`
- Size: 67445147 bytes
- Version: 1.0.2.82_2.0.52
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/77e918774c0d2a34 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
