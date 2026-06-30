# Firmware Audit: TP-Link Deco BE85 / Deco_BE85_V2_1.2.0_250724.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202509/20250901/Deco BE85_V2_1.2.0_250724.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE85/Deco_BE85_V2_1.2.0_250724.zip
- SHA-256: `9546e2633450fb84110b341bbed88ef18ccd004b066269f61228c001777c452d`
- Size: 36830411 bytes
- Version: V2.60_1.2.0 Build 20250724
- Release date: 2025-09-01

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9546e2633450fb84 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
