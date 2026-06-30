# Firmware Audit: TP-Link Deco WB7200 / Deco_WB7200_V1.6_1.1.0_250718.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251105/Deco WB7200_V1.6_1.1.0_250718.zip
- Local path: known_firmware/firmware/TP-Link_Deco_WB7200/Deco_WB7200_V1.6_1.1.0_250718.zip
- SHA-256: `be8eff5eac1b4e4635665f262bbbb4ae71d5517af70f4f72b66f36cda0bc38ce`
- Size: 38753061 bytes
- Version: V1.6_1.1.0 Build 20250718
- Release date: 2025-11-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/be8eff5eac1b4e46 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
