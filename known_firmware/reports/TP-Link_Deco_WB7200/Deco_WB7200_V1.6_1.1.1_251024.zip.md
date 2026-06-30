# Firmware Audit: TP-Link Deco WB7200 / Deco_WB7200_V1.6_1.1.1_251024.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202601/20260116/Deco WB7200_V1.6_1.1.1_251024.zip
- Local path: known_firmware/firmware/TP-Link_Deco_WB7200/Deco_WB7200_V1.6_1.1.1_251024.zip
- SHA-256: `6fa12d8cd74c7b03da28903bb002b30cc2b22c9c4e736259fd8ba798650c879c`
- Size: 39039646 bytes
- Version: V1.6_1.1.1 Build 20251024
- Release date: 2026-01-16

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6fa12d8cd74c7b03 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
