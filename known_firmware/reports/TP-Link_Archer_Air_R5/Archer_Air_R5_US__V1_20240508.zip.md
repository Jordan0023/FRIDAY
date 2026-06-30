# Firmware Audit: TP-Link Archer Air R5 / Archer_Air_R5_US__V1_20240508.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202406/20240625/Archer Air R5(US)_V1_20240508.zip
- Local path: known_firmware/firmware/TP-Link_Archer_Air_R5/Archer_Air_R5_US__V1_20240508.zip
- SHA-256: `fc8b95001d7e7e0dbc7f02418ef2e4db6bf2d62d93d1514468c5263c8803844a`
- Size: 28637892 bytes
- Version: V1.6_1.1.6 Build 20240508
- Release date: 2024-06-25

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fc8b95001d7e7e0d exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
