# Firmware Audit: TP-Link Deco BE75 / Deco_BE75_V1_1.0.6_240725.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202408/20240826/Deco BE75_V1_1.0.6_240725.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE75/Deco_BE75_V1_1.0.6_240725.zip
- SHA-256: `a14dc20d0b170326ab9cfa9f0f6c5b89e5f550cca84c1f95ebd7aaadcd897e50`
- Size: 37592724 bytes
- Version: V1.6_1.0.6 Build 20240725
- Release date: 2024-08-26

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `sShD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a14dc20d0b170326 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
