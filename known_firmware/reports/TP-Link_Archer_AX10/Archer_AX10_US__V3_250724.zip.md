# Firmware Audit: TP-Link Archer AX10 / Archer_AX10_US__V3_250724.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202509/20250905/Archer AX10(US)_V3_250724.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX10/Archer_AX10_US__V3_250724.zip
- SHA-256: `0dfe2a75564a1224f4868f5b052fba0f1a22310303d785f0a9c163f1b033cf82`
- Size: 24811852 bytes
- Version: V3.60_1.2.1 Build 20250724
- Release date: 2025-09-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0dfe2a75564a1224 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
