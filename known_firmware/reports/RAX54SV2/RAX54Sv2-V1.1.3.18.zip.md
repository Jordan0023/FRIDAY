# Firmware Audit: RAX54SV2 / RAX54Sv2-V1.1.3.18.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX54S/RAX54Sv2-V1.1.3.18.zip
- Local path: known_firmware/firmware/RAX54SV2/RAX54Sv2-V1.1.3.18.zip
- SHA-256: `291cadfea4e3ada006ef252db3a976f5a934552b5f720d95e40d38a412883755`
- Size: 81245764 bytes
- Version: 1.1.3.18
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/291cadfea4e3ada0 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
