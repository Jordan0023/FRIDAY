# Firmware Audit: TP-Link Deco BE25 / Deco_BE25_V1_1.1.0_250718.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202510/20251020/Deco BE25_V1_1.1.0_250718.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE25/Deco_BE25_V1_1.1.0_250718.zip
- SHA-256: `df31177e8651616179dc3c030cf4f8f0c7beda78c434064498e9b67036d1fae1`
- Size: 43932320 bytes
- Version: V1.6_1.1.0 Build 20250718
- Release date: 2025-10-20

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, bOA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/df31177e86516161 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
