# Firmware Audit: TP-Link Deco BE95 / Deco_BE95_V1_1.1.0_241217.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202501/20250109/Deco BE95_V1_1.1.0_241217.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE95/Deco_BE95_V1_1.1.0_241217.zip
- SHA-256: `44d68cadcdba85c6b0d5ad0c6f2081c512cc77bcb7fad2d815a09bd0c27e7a71`
- Size: 38605081 bytes
- Version: V1.6_1.1.0 Build 20241217
- Release date: 2025-01-09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/44d68cadcdba85c6 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
