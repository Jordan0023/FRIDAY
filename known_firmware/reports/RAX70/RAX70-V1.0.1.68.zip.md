# Firmware Audit: RAX70 / RAX70-V1.0.1.68.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX70/RAX70-V1.0.1.68.zip
- Local path: known_firmware/firmware/RAX70/RAX70-V1.0.1.68.zip
- SHA-256: `d546813086377968d0e763d8e9362e16108097c702de7485346b0dccb4bbd340`
- Size: 72887195 bytes
- Version: 1.0.1.68
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d546813086377968 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
