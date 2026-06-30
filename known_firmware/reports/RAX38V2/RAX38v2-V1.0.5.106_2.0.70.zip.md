# Firmware Audit: RAX38V2 / RAX38v2-V1.0.5.106_2.0.70.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX38v2/RAX38v2-V1.0.5.106_2.0.70.zip
- Local path: known_firmware/firmware/RAX38V2/RAX38v2-V1.0.5.106_2.0.70.zip
- SHA-256: `d5d7f9c49f2cddc608aa40e80d33c5c2eecad1c5da7212e533765433f4fe91f6`
- Size: 75894292 bytes
- Version: 1.0.5.106_2.0.70
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d5d7f9c49f2cddc6 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
