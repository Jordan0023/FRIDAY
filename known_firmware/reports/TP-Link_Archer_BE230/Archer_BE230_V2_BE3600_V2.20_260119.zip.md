# Firmware Audit: TP-Link Archer BE230 / Archer_BE230_V2_BE3600_V2.20_260119.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202605/20260513/Archer_BE230_V2_BE3600_V2.20_260119.zip
- Local path: known_firmware/firmware/TP-Link_Archer_BE230/Archer_BE230_V2_BE3600_V2.20_260119.zip
- SHA-256: `eadf82eef089b6792c6347827493afcc9e90515ea1fcff90d6fa0984022bc2e8`
- Size: 46786411 bytes
- Version: V2.6_1.1.4 Build 20260119
- Release date: 2026-05-13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/eadf82eef089b679 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
