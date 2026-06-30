# Firmware Audit: TP-Link Deco BE65 Pro / Deco_BE65_Pro_V1_1.1.3_250403.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202505/20250506/Deco BE65 Pro_V1_1.1.3_250403.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE65_Pro/Deco_BE65_Pro_V1_1.1.3_250403.zip
- SHA-256: `9b7bab775a2a5e93ef64d2cebd27860f9436e0c11a745effc6ad16a4d6f496b0`
- Size: 45700425 bytes
- Version: V1.6_1.1.3 Build 20250403
- Release date: 2025-05-06

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9b7bab775a2a5e93 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
