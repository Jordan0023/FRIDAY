# Firmware Audit: TP-Link Deco WB10800 / Deco_WB10800_V2.6_1.1.0_250718.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251105/Deco WB10800_V2.6_1.1.0_250718.zip
- Local path: known_firmware/firmware/TP-Link_Deco_WB10800/Deco_WB10800_V2.6_1.1.0_250718.zip
- SHA-256: `e2e385847b7b480b93dc48530985b09919a743e5925c1822d20bdde1fc8d4277`
- Size: 38753061 bytes
- Version: V2.6_1.1.0 Build 20250718
- Release date: 2025-11-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e2e385847b7b480b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
