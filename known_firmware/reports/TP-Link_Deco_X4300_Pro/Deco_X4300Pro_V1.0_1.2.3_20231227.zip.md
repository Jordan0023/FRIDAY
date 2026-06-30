# Firmware Audit: TP-Link Deco X4300 Pro / Deco_X4300Pro_V1.0_1.2.3_20231227.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202401/20240130/Deco_X4300Pro_V1.0_1.2.3_20231227.zip
- Local path: known_firmware/firmware/TP-Link_Deco_X4300_Pro/Deco_X4300Pro_V1.0_1.2.3_20231227.zip
- SHA-256: `4ec5f91db713cd68c53d80ea6804c3a3e943d04a92111c47bdaddcaa92004784`
- Size: 25595103 bytes
- Version: V1.6_1.2.3 Build 20231227
- Release date: 2024-01-30

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, bOA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4ec5f91db713cd68 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
