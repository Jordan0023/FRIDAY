# Firmware Audit: TP-Link Archer AXE95 / Archer_AXE95_US__V1_260511.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202606/20260624/Archer AXE95(US)_V1_260511.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AXE95/Archer_AXE95_US__V1_260511.zip
- SHA-256: `646c6928d14cc2003ffdcf63b85701a83788abf09ff38ae5dc265e0df7f760a7`
- Size: 49293223 bytes
- Version: V1.6_1.2.0 Build 20260511
- Release date: 2026-06-24

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/646c6928d14cc200 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
