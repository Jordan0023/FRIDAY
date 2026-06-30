# Firmware Audit: EAX80 / EAX80-V1.0.1.62_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX80/EAX80-V1.0.1.62_1.0.1.zip
- Local path: known_firmware/firmware/EAX80/EAX80-V1.0.1.62_1.0.1.zip
- SHA-256: `331632fc2f3ec14a9164fb0149e870699c5379bb6f32f0232a04260eae4e1fe7`
- Size: 35396064 bytes
- Version: 1.0.1.62_1.0.1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, Boa, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/331632fc2f3ec14a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
