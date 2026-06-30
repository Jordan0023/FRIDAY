# Firmware Audit: TP-Link Deco M9 Plus / Deco_M9_Plus_en_1.6.4_Build_20240718.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202408/20240822/Deco M9 Plus_en_1.6.4 Build 20240718.zip
- Local path: known_firmware/firmware/TP-Link_Deco_M9_Plus/Deco_M9_Plus_en_1.6.4_Build_20240718.zip
- SHA-256: `342777d09e9df5c50030f8a3ddba8cf63bb19862ca7a2aa2acaf2f37efc2e750`
- Size: 22257396 bytes
- Version: V2_1.6.4 Build 20240718
- Release date: 2024-08-22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/342777d09e9df5c5 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
