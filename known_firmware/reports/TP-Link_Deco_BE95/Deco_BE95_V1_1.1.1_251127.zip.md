# Firmware Audit: TP-Link Deco BE95 / Deco_BE95_V1_1.1.1_251127.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202512/20251223/Deco BE95_V1_1.1.1_251127.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE95/Deco_BE95_V1_1.1.1_251127.zip
- SHA-256: `d0e7dd1a26d29eb8982bc0970f86fde37da9b17abc968528c690a3a073f29c62`
- Size: 38739338 bytes
- Version: V1.6_1.1.1 Build 20251127
- Release date: 2025-12-23

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d0e7dd1a26d29eb8 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
