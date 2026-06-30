# Firmware Audit: EAX18 / EAX20-EAX18-V1.0.0.52_1.0.96.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX18/EAX20-EAX18-V1.0.0.52_1.0.96.zip
- Local path: known_firmware/firmware/EAX18/EAX20-EAX18-V1.0.0.52_1.0.96.zip
- SHA-256: `fe570eaf7d4cf55f5df2ffbece024ab5fc499c44a2fad399c544d8277db8c3ea`
- Size: 34647863 bytes
- Version: 1.0.0.52_1.0.96
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fe570eaf7d4cf55f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
