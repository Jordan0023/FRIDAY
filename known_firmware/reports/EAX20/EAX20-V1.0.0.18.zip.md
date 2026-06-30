# Firmware Audit: EAX20 / EAX20-V1.0.0.18.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX20/EAX20-V1.0.0.18.zip
- Local path: known_firmware/firmware/EAX20/EAX20-V1.0.0.18.zip
- SHA-256: `4b3ea44c834b050b3714e1a7d4b8819a839428f404758be4a5fa561c829eb5f8`
- Size: 36466876 bytes
- Version: 1.0.0.18
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4b3ea44c834b050b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
