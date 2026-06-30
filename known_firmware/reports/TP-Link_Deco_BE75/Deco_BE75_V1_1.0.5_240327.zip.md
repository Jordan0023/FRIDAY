# Firmware Audit: TP-Link Deco BE75 / Deco_BE75_V1_1.0.5_240327.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202406/20240627/Deco BE75_V1_1.0.5_240327.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE75/Deco_BE75_V1_1.0.5_240327.zip
- SHA-256: `0e8600e0c633227cde22478fe6d7a8884b28005ff00dcd66901d9ff93bf58a0b`
- Size: 37489181 bytes
- Version: V1.6_1.0.5 Build 20240327
- Release date: 2024-06-27

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0e8600e0c633227c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
