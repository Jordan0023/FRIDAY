# Firmware Audit: TP-Link Deco BE65 Pro / Deco_BE65_Pro_V1_1.2.0_250718.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202512/20251210/Deco BE65 Pro_V1_1.2.0_250718.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE65_Pro/Deco_BE65_Pro_V1_1.2.0_250718.zip
- SHA-256: `be5ac4fc169050c1d3e238f78110bfbe5e006d57013a8a88b0809950ddaf236f`
- Size: 44352783 bytes
- Version: V1.6_1.2.0 Build 20250718
- Release date: 2025-12-10

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/be5ac4fc169050c1 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
