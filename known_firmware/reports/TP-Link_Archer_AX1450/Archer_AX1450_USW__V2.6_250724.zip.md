# Firmware Audit: TP-Link Archer AX1450 / Archer_AX1450_USW__V2.6_250724.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202509/20250905/Archer AX1450(USW)_V2.6_250724.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX1450/Archer_AX1450_USW__V2.6_250724.zip
- SHA-256: `61e78840d3e82caf07cedd592c57ebe2c42f816c65e230050007ac866e83a2e2`
- Size: 24811856 bytes
- Version: V2.60_1.2.1 Build 20250724
- Release date: 2025-09-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/61e78840d3e82caf exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
