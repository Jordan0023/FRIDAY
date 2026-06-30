# Firmware Audit: TP-Link Deco X90 / Deco_X90_V1_1.2.7_20240719.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202408/20240823/Deco_X90_V1_1.2.7_20240719.zip
- Local path: known_firmware/firmware/TP-Link_Deco_X90/Deco_X90_V1_1.2.7_20240719.zip
- SHA-256: `4a40fecab08fc9167af190b59e337e865819066ea7a3437bdc630a4dc5cd76ee`
- Size: 30862679 bytes
- Version: V1.6_1.2.7 Build 20240719
- Release date: 2024-08-23

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4a40fecab08fc916 stopped: extraction exceeded 2048 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
