# Firmware Audit: TP-Link Deco X50-Outdoor / X50-Outdoor_X20-Outdoor_HB6300-Outdoor_WM9000-Outdoor-SP1-up-ver1-2-6-P1_20240723-rel10139_.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202409/20240918/X50-Outdoor_X20-Outdoor_HB6300-Outdoor_WM9000-Outdoor-SP1-up-ver1-2-6-P1[20240723-rel10139].zip
- Local path: known_firmware/firmware/TP-Link_Deco_X50-Outdoor/X50-Outdoor_X20-Outdoor_HB6300-Outdoor_WM9000-Outdoor-SP1-up-ver1-2-6-P1_20240723-rel10139_.zip
- SHA-256: `06d272f65a919aeb901078c1bd6e014f888d7ce709036bb7688409357878d3b4`
- Size: 31642195 bytes
- Version: V1.6_1.2.6 Build 20240723
- Release date: 2024-09-18

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/06d272f65a919aeb exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
