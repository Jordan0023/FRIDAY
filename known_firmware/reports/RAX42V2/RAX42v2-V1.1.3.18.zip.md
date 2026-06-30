# Firmware Audit: RAX42V2 / RAX42v2-V1.1.3.18.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX42/RAX42v2-V1.1.3.18.zip
- Local path: known_firmware/firmware/RAX42V2/RAX42v2-V1.1.3.18.zip
- SHA-256: `f8bfa2eb9ee345fdd1cb7c635ba11f89ecd20265db0cb5fa7731d24af6188cc7`
- Size: 81245689 bytes
- Version: 1.1.3.18
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f8bfa2eb9ee345fd exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
