# Firmware Audit: TP-Link Archer BE700 Pro / Archer_BE700_Pro_US__V1.6_241115.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202412/20241202/Archer BE700 Pro(US)_V1.6_241115.zip
- Local path: known_firmware/firmware/TP-Link_Archer_BE700_Pro/Archer_BE700_Pro_US__V1.6_241115.zip
- SHA-256: `8ca87e93b2d4d67fd3e1ab1e2ff9b6ef87e3cb10856aab4e903ef58cf9c841d2`
- Size: 50583527 bytes
- Version: V1.6_1.1.1 Build 20241115
- Release date: 2024-12-02

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8ca87e93b2d4d67f exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
