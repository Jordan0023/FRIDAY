# Firmware Audit: TP-Link Deco X20-Outdoor / X50-Outdoor_X20-Outdoor_HB6300-Outdoor_WM9000-Outdoor-SP1-up-ver1-2-8-P1_20240914-rel35513_.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202412/20241217/X50-Outdoor_X20-Outdoor_HB6300-Outdoor_WM9000-Outdoor-SP1-up-ver1-2-8-P1[20240914-rel35513].zip
- Local path: known_firmware/firmware/TP-Link_Deco_X20-Outdoor/X50-Outdoor_X20-Outdoor_HB6300-Outdoor_WM9000-Outdoor-SP1-up-ver1-2-8-P1_20240914-rel35513_.zip
- SHA-256: `115409ec7424b3b3619051b5c6aed9bdc1b0ce1aef0b38c86b001576e3f00f60`
- Size: 31639926 bytes
- Version: V1.6_1.2.8 Build 20240914
- Release date: 2024-12-17

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/115409ec7424b3b3 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
