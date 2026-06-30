# Firmware Audit: RAX20 / RAX20-V1.0.4.100_2.0.64.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.4.100_2.0.64.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.4.100_2.0.64.zip
- SHA-256: `65b4308c7d503925a29f8b95ab10a543c846f5e92b2fd8a3fcd05800b9a070ce`
- Size: 74012313 bytes
- Version: 1.0.4.100_2.0.64
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/65b4308c7d503925 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
