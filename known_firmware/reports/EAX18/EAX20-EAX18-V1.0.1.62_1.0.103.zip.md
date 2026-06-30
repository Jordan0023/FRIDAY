# Firmware Audit: EAX18 / EAX20-EAX18-V1.0.1.62_1.0.103.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX18/EAX20-EAX18-V1.0.1.62_1.0.103.zip
- Local path: known_firmware/firmware/EAX18/EAX20-EAX18-V1.0.1.62_1.0.103.zip
- SHA-256: `c5bedd46f58382e03b2134062cd24a2ff3de875dd0b8f2ca1a5744a8e34cff39`
- Size: 33134859 bytes
- Version: 1.0.1.62_1.0.103
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c5bedd46f58382e0 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
