# Firmware Audit: TP-Link Deco BE77 / Deco_BE77_V1_1.0.2_251024.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202512/20251218/Deco BE77_V1_1.0.2_251024.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE77/Deco_BE77_V1_1.0.2_251024.zip
- SHA-256: `33aceac6fe437bd77163b9d7453771038b1bb363673ee7ba68c4c246cb97c2d1`
- Size: 49567364 bytes
- Version: V1.6_1.0.2 Build 20251024
- Release date: 2025-12-18

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/33aceac6fe437bd7 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
