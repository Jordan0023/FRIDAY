# Firmware Audit: TP-Link Deco BE5000 / Deco_BE5000_V1_1.1.0_250718.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251107/Deco_BE5000_V1_1.1.0_250718.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE5000/Deco_BE5000_V1_1.1.0_250718.zip
- SHA-256: `9abcce63a688c153807f46e3b0124fe3b6e7394c6455cd0496d586935d7bb6a0`
- Size: 44052544 bytes
- Version: V1.6_1.1.0 Build 20250718
- Release date: 2025-11-07

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9abcce63a688c153 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
