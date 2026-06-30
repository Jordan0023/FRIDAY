# Firmware Audit: TP-Link Deco XE200 / Deco_XE200_V1_1.2.4_230627.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202308/20230818/Deco XE200_V1_1.2.4_230627.zip
- Local path: known_firmware/firmware/TP-Link_Deco_XE200/Deco_XE200_V1_1.2.4_230627.zip
- SHA-256: `6a294114c671688527c5faec11f6b053808ab2b284addfe275bee78b51657e1a`
- Size: 32099217 bytes
- Version: V1.6_1.2.4 Build 20230627
- Release date: 2023-08-18

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, bOA, bOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6a294114c6716885 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
