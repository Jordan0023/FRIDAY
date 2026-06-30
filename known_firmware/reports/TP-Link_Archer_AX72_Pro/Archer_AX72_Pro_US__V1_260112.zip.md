# Firmware Audit: TP-Link Archer AX72 Pro / Archer_AX72_Pro_US__V1_260112.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202604/20260414/Archer AX72 Pro(US)_V1_260112.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX72_Pro/Archer_AX72_Pro_US__V1_260112.zip
- SHA-256: `ae833a7643030bec851a27fe5cb27f688ba210ab0570690d0a3754ac6c503bd2`
- Size: 40716011 bytes
- Version: V1.6_1.4.6 Build 20260112
- Release date: 2026-04-14

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ae833a7643030bec exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
