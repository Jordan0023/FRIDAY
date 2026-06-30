# Firmware Audit: RAX50 / RAX50-V1.0.2.64_2.0.41.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.2.64_2.0.41.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.2.64_2.0.41.zip
- SHA-256: `0718ab43300dd5dd3dcb010438fe2a43942155d2e8a5c992713a29d9e01e87dd`
- Size: 65574341 bytes
- Version: 1.0.2.64_2.0.41
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0718ab43300dd5dd exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
