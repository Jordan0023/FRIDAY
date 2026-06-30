# Firmware Audit: TP-Link Deco XE70 Pro / Deco_XE70Pro_V3_1.2.9_20231225.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202401/20240111/Deco_XE70Pro_V3_1.2.9_20231225.zip
- Local path: known_firmware/firmware/TP-Link_Deco_XE70_Pro/Deco_XE70Pro_V3_1.2.9_20231225.zip
- SHA-256: `7d683b246190ac7475481b2b10cb0f91dba9bf8457f790301882f6d61839e875`
- Size: 26439975 bytes
- Version: V3.6_1.2.9 Build 20231225
- Release date: 2024-01-11

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7d683b246190ac74 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
