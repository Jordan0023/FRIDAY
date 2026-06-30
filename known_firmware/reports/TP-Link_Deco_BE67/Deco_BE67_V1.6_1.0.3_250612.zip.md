# Firmware Audit: TP-Link Deco BE67 / Deco_BE67_V1.6_1.0.3_250612.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202506/20250624/Deco BE67_V1.6_1.0.3_250612.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE67/Deco_BE67_V1.6_1.0.3_250612.zip
- SHA-256: `af036a1e6054dc99b90494ba9ab64c58abf1070a8b1f77c2b7cc7b0ab8483965`
- Size: 49305290 bytes
- Version: V1.60_1.0.3 Build 20250612
- Release date: 2025-06-24

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, bOA, bOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/af036a1e6054dc99 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
