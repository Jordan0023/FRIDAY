# Firmware Audit: TP-Link Archer BE3200 / Archer_BE3200_USW__V1_250328.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202505/20250509/Archer BE3200(USW)_V1_250328.zip
- Local path: known_firmware/firmware/TP-Link_Archer_BE3200/Archer_BE3200_USW__V1_250328.zip
- SHA-256: `312170bb603d4d239bf295a61803af466e76ec6cc9bf4be36d127d512b2cd033`
- Size: 50792450 bytes
- Version: V1.6_1.0.2 Build 20250328
- Release date: 2025-05-09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `EVAL`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/312170bb603d4d23 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
