# Firmware Audit: RAX48 / RAX48-V1.0.16.132.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX48/RAX48-V1.0.16.132.zip
- Local path: known_firmware/firmware/RAX48/RAX48-V1.0.16.132.zip
- SHA-256: `6166b80d003d147db32aa89eb01681735ac0b95e39247eaa98bdc7bc790a2d2a`
- Size: 84548126 bytes
- Version: 1.0.16.132
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6166b80d003d147d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
