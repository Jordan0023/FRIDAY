# Firmware Audit: RAX10 / RAX10-V1.0.2.88.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.2.88.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.2.88.zip
- SHA-256: `82d749b5840ec5378c2fb254bb6267a9f8f01e6ac5d858ff06549dcdf5686a34`
- Size: 53952443 bytes
- Version: 1.0.2.88
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/82d749b5840ec537 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
