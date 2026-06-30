# Firmware Audit: RAX49S / RAX49-V1.1.4.28.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX49S/RAX49-V1.1.4.28.zip
- Local path: known_firmware/firmware/RAX49S/RAX49-V1.1.4.28.zip
- SHA-256: `8b87b77ab47edf494194969ee9834a117b7a8f1df2fafdd84d99665ba10f55c4`
- Size: 84776169 bytes
- Version: 1.1.4.28
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8b87b77ab47edf49 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
