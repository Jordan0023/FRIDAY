# Firmware Audit: RAX75 / RAX75-V1.0.10.140.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.10.140.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.10.140.zip
- SHA-256: `fd261e006fae48929221c7e3347405601ffb956e6c571330091427db490dcd72`
- Size: 73506885 bytes
- Version: 1.0.10.140
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fd261e006fae4892 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
