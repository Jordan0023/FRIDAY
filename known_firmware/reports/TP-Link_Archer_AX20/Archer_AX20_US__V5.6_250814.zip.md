# Firmware Audit: TP-Link Archer AX20 / Archer_AX20_US__V5.6_250814.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202509/20250905/Archer AX20(US)_V5.6_250814.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX20/Archer_AX20_US__V5.6_250814.zip
- SHA-256: `a3ed91fdcb3c17087d631fd0f2691b3248b917e321473f06253a1fdd8c0b4e4b`
- Size: 28088698 bytes
- Version: V5.60_1.1.2 Build 20250814
- Release date: 2025-09-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a3ed91fdcb3c1708 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
