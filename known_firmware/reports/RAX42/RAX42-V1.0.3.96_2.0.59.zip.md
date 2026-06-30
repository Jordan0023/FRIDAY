# Firmware Audit: RAX42 / RAX42-V1.0.3.96_2.0.59.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX42/RAX42-V1.0.3.96_2.0.59.zip
- Local path: known_firmware/firmware/RAX42/RAX42-V1.0.3.96_2.0.59.zip
- SHA-256: `1aaa55f12ed1a2b4f184c47170a763cb493bc50d48379b3d15d381d9b3143cb2`
- Size: 73781620 bytes
- Version: 1.0.3.96_2.0.59
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1aaa55f12ed1a2b4 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
