# Firmware Audit: RAX41 / RAX41-V1.0.17.142.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX41/RAX41-V1.0.17.142.zip
- Local path: known_firmware/firmware/RAX41/RAX41-V1.0.17.142.zip
- SHA-256: `067bdf69599c82882455e73ad8a117ade8995a3213d0ff8420e1e7da497ee2c3`
- Size: 81328181 bytes
- Version: 1.0.17.142
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/067bdf69599c8288 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
