# Firmware Audit: TP-Link Archer BE700 Pro / Archer_BE700_Pro_US__V1.6_240730.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202408/20240829/Archer BE700 Pro(US)_V1.6_240730.zip
- Local path: known_firmware/firmware/TP-Link_Archer_BE700_Pro/Archer_BE700_Pro_US__V1.6_240730.zip
- SHA-256: `876dedfaed4d5eac531ae45274458c78d59bc2a45c0fbabea270384feac7927e`
- Size: 50538139 bytes
- Version: V1.6_1.1.0 Build 20240730
- Release date: 2024-08-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/876dedfaed4d5eac exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
