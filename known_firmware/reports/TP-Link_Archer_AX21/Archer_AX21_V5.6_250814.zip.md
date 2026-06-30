# Firmware Audit: TP-Link Archer AX21 / Archer_AX21_V5.6_250814.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202509/20250905/Archer AX21_V5.6_250814.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX21/Archer_AX21_V5.6_250814.zip
- SHA-256: `298622ae18be01ea84ecdc6fa303cd2e884303368e4b366b3003a6c5fa311b89`
- Size: 28088698 bytes
- Version: V5.60_1.1.2 Build 20250814
- Release date: 2025-09-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/298622ae18be01ea exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
