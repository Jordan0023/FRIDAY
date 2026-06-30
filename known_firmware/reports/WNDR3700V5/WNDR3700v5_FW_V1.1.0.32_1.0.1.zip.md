# Firmware Audit: WNDR3700V5 / WNDR3700v5_FW_V1.1.0.32_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR3700V5/WNDR3700v5_FW_V1.1.0.32_1.0.1.zip
- Local path: known_firmware/firmware/WNDR3700V5/WNDR3700v5_FW_V1.1.0.32_1.0.1.zip
- SHA-256: `02b657a85e4a1955cbedf89bf2f4cbe3f6076bf5b5553ea2d15928043dd5fc60`
- Size: 13845787 bytes
- Version: 1.0.32_1.0.1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/02b657a85e4a1955 exited 0: WARNING: Extractor.execute failed to run external extractor 'jar xvf '%e'': [Errno 2] No such file or directory: 'jar', 'jar xvf '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
