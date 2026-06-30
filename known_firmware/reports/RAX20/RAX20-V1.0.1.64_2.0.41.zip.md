# Firmware Audit: RAX20 / RAX20-V1.0.1.64_2.0.41.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.1.64_2.0.41.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.1.64_2.0.41.zip
- SHA-256: `8f5d59cc40cac3d61be6148f4301a004b9b558662dbe718aae18312e09ef88d6`
- Size: 63613097 bytes
- Version: 1.0.1.64_2.0.41
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8f5d59cc40cac3d6 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
