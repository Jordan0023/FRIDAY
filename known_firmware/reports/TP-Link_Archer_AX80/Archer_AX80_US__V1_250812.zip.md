# Firmware Audit: TP-Link Archer AX80 / Archer_AX80_US__V1_250812.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202510/20251030/Archer AX80(US)_V1_250812.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX80/Archer_AX80_US__V1_250812.zip
- SHA-256: `60fd0d9cc66d3d446071fb6dfe440a13c4b39aaeefe9606d90540a518505484a`
- Size: 36873290 bytes
- Version: V1.6_1.3.2 Build 20250812
- Release date: 2025-10-30

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/60fd0d9cc66d3d44 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
