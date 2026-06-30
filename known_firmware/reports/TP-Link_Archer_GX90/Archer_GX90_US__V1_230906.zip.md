# Firmware Audit: TP-Link Archer GX90 / Archer_GX90_US__V1_230906.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202309/20230925/Archer GX90(US)_V1_230906.zip
- Local path: known_firmware/firmware/TP-Link_Archer_GX90/Archer_GX90_US__V1_230906.zip
- SHA-256: `f4b0f87e1d5a5dd4b5c421e2df7722c34ab256d9e6a0a5a9b823711f0d1ba745`
- Size: 45846211 bytes
- Version: V1.6_1.1.3 Build 20230906
- Release date: 2023-09-25

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `EVAL`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f4b0f87e1d5a5dd4 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
