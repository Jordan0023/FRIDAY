# Firmware Audit: EAX20 / EAX20-V1.0.0.20_1.0.63.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX20/EAX20-V1.0.0.20_1.0.63.zip
- Local path: known_firmware/firmware/EAX20/EAX20-V1.0.0.20_1.0.63.zip
- SHA-256: `873f39b748389fc345bc7c37e11ad49a5a53b2b23e508dc4bf60b261673fedbe`
- Size: 36451074 bytes
- Version: 1.0.0.20_1.0.63
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/873f39b748389fc3 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
