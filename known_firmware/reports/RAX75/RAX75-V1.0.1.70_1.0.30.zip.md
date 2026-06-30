# Firmware Audit: RAX75 / RAX75-V1.0.1.70_1.0.30.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.1.70_1.0.30.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.1.70_1.0.30.zip
- SHA-256: `60ab9a57aef69e7c9ce89ed91ac87107c436d6fcdbbb8dbd850a3ac8a38eb973`
- Size: 50597011 bytes
- Version: 1.0.1.70_1.0.30
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOA, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/60ab9a57aef69e7c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
