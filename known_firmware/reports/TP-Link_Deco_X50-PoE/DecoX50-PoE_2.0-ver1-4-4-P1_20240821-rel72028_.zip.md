# Firmware Audit: TP-Link Deco X50-PoE / DecoX50-PoE_2.0-ver1-4-4-P1_20240821-rel72028_.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202411/20241129/DecoX50-PoE_2.0-ver1-4-4-P1[20240821-rel72028].zip
- Local path: known_firmware/firmware/TP-Link_Deco_X50-PoE/DecoX50-PoE_2.0-ver1-4-4-P1_20240821-rel72028_.zip
- SHA-256: `949191a28e47323ecad271851f865a975c2df8087dd16b5e4d3e8f90cf63f907`
- Size: 27920973 bytes
- Version: V2.6_1.4.4 Build 20240821
- Release date: 2024-11-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `EvaL, System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/949191a28e47323e exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
