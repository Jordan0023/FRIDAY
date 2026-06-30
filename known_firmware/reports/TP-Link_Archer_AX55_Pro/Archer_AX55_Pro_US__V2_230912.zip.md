# Firmware Audit: TP-Link Archer AX55 Pro / Archer_AX55_Pro_US__V2_230912.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202310/20231011/Archer AX55 Pro(US)_V2_230912.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX55_Pro/Archer_AX55_Pro_US__V2_230912.zip
- SHA-256: `312a8efbb93803e0a48cc7cee036f3bc71cf33f06dc1ad932a963c1c6a0cd63e`
- Size: 29117342 bytes
- Version: V2.6_1.0.3 Build 20230912
- Release date: 2023-10-11

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eval, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/312a8efbb93803e0 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
