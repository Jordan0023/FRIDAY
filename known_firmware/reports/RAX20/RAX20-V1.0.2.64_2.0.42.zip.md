# Firmware Audit: RAX20 / RAX20-V1.0.2.64_2.0.42.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.2.64_2.0.42.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.2.64_2.0.42.zip
- SHA-256: `5dc7f783149630ac916fdb4e0ca6be270f7fddeb7951e924aec4412beee734a0`
- Size: 63595730 bytes
- Version: 1.0.2.64_2.0.42
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5dc7f783149630ac exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
