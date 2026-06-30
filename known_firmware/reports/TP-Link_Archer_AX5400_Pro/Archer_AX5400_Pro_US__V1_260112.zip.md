# Firmware Audit: TP-Link Archer AX5400 Pro / Archer_AX5400_Pro_US__V1_260112.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202604/20260414/Archer AX5400 Pro(US)_V1_260112.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX5400_Pro/Archer_AX5400_Pro_US__V1_260112.zip
- SHA-256: `e8df46bb6a579ef1afe6ef0dad4966542de2c5836ec128d401ecc734976efa77`
- Size: 40716015 bytes
- Version: V1.6_1.4.6 Build 20260112
- Release date: 2026-04-14

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e8df46bb6a579ef1 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
