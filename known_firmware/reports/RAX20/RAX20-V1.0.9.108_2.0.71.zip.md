# Firmware Audit: RAX20 / RAX20-V1.0.9.108_2.0.71.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.9.108_2.0.71.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.9.108_2.0.71.zip
- SHA-256: `1e30cf2f820afbc88f9985376c94d7e16c77fd85228fbf385b1efa60263cf8d6`
- Size: 76351148 bytes
- Version: 1.0.9.108_2.0.71
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1e30cf2f820afbc8 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
