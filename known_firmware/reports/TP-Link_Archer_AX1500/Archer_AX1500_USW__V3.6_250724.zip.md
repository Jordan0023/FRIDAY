# Firmware Audit: TP-Link Archer AX1500 / Archer_AX1500_USW__V3.6_250724.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202509/20250905/Archer AX1500(USW)_V3.6_250724.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX1500/Archer_AX1500_USW__V3.6_250724.zip
- SHA-256: `fc72a68b7c659df5efeddd66372ee2c5de93fd29664056d612886bceb728d4d2`
- Size: 24811856 bytes
- Version: V3.60_1.2.1 Build 20250724
- Release date: 2025-09-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fc72a68b7c659df5 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
