# Firmware Audit: TP-Link Deco BE65-Outdoor / Deco_BE65-Outdoor_V1.6_1.0.0_250325.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202508/20250807/Deco BE65-Outdoor_V1.6_1.0.0_250325.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE65-Outdoor/Deco_BE65-Outdoor_V1.6_1.0.0_250325.zip
- SHA-256: `de79afeb247dbec9d93f8cc882fc3219f9ac6ce22a798bf90e3685e4e76bba4e`
- Size: 46321606 bytes
- Version: V1.60_1.0.0 Build 20250325
- Release date: 2025-08-07

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, bOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/de79afeb247dbec9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
