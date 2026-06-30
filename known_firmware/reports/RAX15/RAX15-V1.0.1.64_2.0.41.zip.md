# Firmware Audit: RAX15 / RAX15-V1.0.1.64_2.0.41.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX15/RAX15-V1.0.1.64_2.0.41.zip
- Local path: known_firmware/firmware/RAX15/RAX15-V1.0.1.64_2.0.41.zip
- SHA-256: `2879a5ae5f710af14d284c75d9af55c0efe5fa0dd15feee69f12f2efc11ae024`
- Size: 63613099 bytes
- Version: 1.0.1.64_2.0.41
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2879a5ae5f710af1 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
