# Firmware Audit: TP-Link Deco BE25 / Deco_BE25_V1_1.1.7_260114.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202602/20260202/Deco BE25_V1_1.1.7_260114.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE25/Deco_BE25_V1_1.1.7_260114.zip
- SHA-256: `534934bf100522d15c6504ea23f9ddcb8b6322e807cff525d3c26834b4edc8eb`
- Size: 44555138 bytes
- Version: V1.6_1.1.7 Build 20260114
- Release date: 2026-02-02

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/534934bf100522d1 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
