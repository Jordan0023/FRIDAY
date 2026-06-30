# Firmware Audit: RAX48 / RAX48-V1.0.3.96_2.0.59.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX48/RAX48-V1.0.3.96_2.0.59.zip
- Local path: known_firmware/firmware/RAX48/RAX48-V1.0.3.96_2.0.59.zip
- SHA-256: `6abf7443a6a6cde2a8fd991b489e2a3d05dc7cebc9f7b17a2e6050e72efdb140`
- Size: 73781627 bytes
- Version: 1.0.3.96_2.0.59
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6abf7443a6a6cde2 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
