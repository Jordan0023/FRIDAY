# Firmware Audit: TP-Link Archer AX1800 / Archer_AX1800_USW__V5.6_250814.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202509/20250905/Archer AX1800(USW)_V5.6_250814.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX1800/Archer_AX1800_USW__V5.6_250814.zip
- SHA-256: `eb48e5e849de5d85423ae43f31584a22e24eeba045aa13c71872468412259be1`
- Size: 28088702 bytes
- Version: V5.60_1.1.2 Build 20250814
- Release date: 2025-09-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/eb48e5e849de5d85 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
