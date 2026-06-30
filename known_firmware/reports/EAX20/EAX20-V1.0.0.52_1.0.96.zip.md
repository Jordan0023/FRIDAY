# Firmware Audit: EAX20 / EAX20-V1.0.0.52_1.0.96.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX20/EAX20-V1.0.0.52_1.0.96.zip
- Local path: known_firmware/firmware/EAX20/EAX20-V1.0.0.52_1.0.96.zip
- SHA-256: `6546bc9682b6600e44aa14e28f0c3d119bac0973dc3b82504bac56c36c772923`
- Size: 34647859 bytes
- Version: 1.0.0.52_1.0.96
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6546bc9682b6600e exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
