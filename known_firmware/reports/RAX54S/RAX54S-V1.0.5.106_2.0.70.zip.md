# Firmware Audit: RAX54S / RAX54S-V1.0.5.106_2.0.70.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX54S/RAX54S-V1.0.5.106_2.0.70.zip
- Local path: known_firmware/firmware/RAX54S/RAX54S-V1.0.5.106_2.0.70.zip
- SHA-256: `028a2c83e7d8111ceb78b70131f5f26079fc3580f1b0ba9d0c97edb6a0208b68`
- Size: 75894270 bytes
- Version: 1.0.5.106_2.0.70
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/028a2c83e7d8111c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
