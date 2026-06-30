# Firmware Audit: TP-Link Deco BE85 / Deco_BE85_V2_1.1.1_241023.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202411/20241106/Deco BE85_V2_1.1.1_241023.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE85/Deco_BE85_V2_1.1.1_241023.zip
- SHA-256: `3d18b915a0e5185d9313100b16d0d86670c0a88d2c02829469961b4ed0f4c351`
- Size: 37154851 bytes
- Version: V2.6_1.1.1 Build 20241023
- Release date: 2024-11-06

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3d18b915a0e5185d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
