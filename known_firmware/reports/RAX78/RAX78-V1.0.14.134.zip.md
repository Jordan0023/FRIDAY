# Firmware Audit: RAX78 / RAX78-V1.0.14.134.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX78/RAX78-V1.0.14.134.zip
- Local path: known_firmware/firmware/RAX78/RAX78-V1.0.14.134.zip
- SHA-256: `fbe73c7df401157ab6d6ee7949285455a22eafda5fc8e108455c16082a8a05cd`
- Size: 67574483 bytes
- Version: 1.0.14.134
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fbe73c7df401157a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
