# Firmware Audit: TP-Link Deco BE95 / Deco_BE95_V1_1.0.20_240601.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202407/20240730/Deco BE95_V1_1.0.20_240601.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE95/Deco_BE95_V1_1.0.20_240601.zip
- SHA-256: `9d704de864ff1f9d1c7b015fe6545738447da0841b9302579e4f141a718466ba`
- Size: 37374358 bytes
- Version: V1.6_1.0.20 Build 20240601
- Release date: 2024-07-30

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `sShD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, BoA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9d704de864ff1f9d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
