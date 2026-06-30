# Firmware Audit: RAX75 / RAX75-V1.0.1.64_1.0.27.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.1.64_1.0.27.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.1.64_1.0.27.zip
- SHA-256: `3a1d0b78c6b43c3a99c740991921bfe544d407c285c7bb47040fda8c5ae199ea`
- Size: 50583672 bytes
- Version: 1.0.1.64_1.0.27
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3a1d0b78c6b43c3a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
