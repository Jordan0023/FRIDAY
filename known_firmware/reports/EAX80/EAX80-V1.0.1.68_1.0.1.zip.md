# Firmware Audit: EAX80 / EAX80-V1.0.1.68_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX80/EAX80-V1.0.1.68_1.0.1.zip
- Local path: known_firmware/firmware/EAX80/EAX80-V1.0.1.68_1.0.1.zip
- SHA-256: `c1e4e9f5c09c4cb63bf954b2e699ba9cb93dd8c1d9c43b4cac2642ba2316aa31`
- Size: 34064793 bytes
- Version: 1.0.1.68_1.0.1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c1e4e9f5c09c4cb6 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
