# Firmware Audit: TP-Link Deco BE11000 / Deco_BE11000_V2.6_1.3.2_26040912.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202605/20260514/Deco BE11000_V2.6_1.3.2_26040912.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE11000/Deco_BE11000_V2.6_1.3.2_26040912.zip
- SHA-256: `d73f1f0e2d2045c606e766c20e0d53da04f54a7556691893ced3f63766c1dd74`
- Size: 47994208 bytes
- Version: V2.6_1.3.2 Build 26040912
- Release date: 2026-05-14

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d73f1f0e2d2045c6 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
