# Firmware Audit: TP-Link Archer AXE300 / Archer_AXE300_US__V1_241115.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202412/20241205/Archer AXE300(US)_V1_241115.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AXE300/Archer_AXE300_US__V1_241115.zip
- SHA-256: `731258d44b1743b805fe82b2d08ce66e3c0243946caf8c6f69afb24c60c95e71`
- Size: 47676212 bytes
- Version: V1.6_1.0.11 Build 20241115
- Release date: 2024-12-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/731258d44b1743b8 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
