# Firmware Audit: TP-Link Archer BE11000 Pro / Archer_BE11000_Pro_US__V1.6_251022.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251110/Archer BE700 Pro(US)_V1.6_251022.zip
- Local path: known_firmware/firmware/TP-Link_Archer_BE11000_Pro/Archer_BE11000_Pro_US__V1.6_251022.zip
- SHA-256: `0795cae638225029f1525f2d969a84c0ed6fc1591d594e2cac9aa26680f0c271`
- Size: 50602579 bytes
- Version: V1.6_1.1.2 Build 20251022
- Release date: 2025-11-13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0795cae638225029 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
