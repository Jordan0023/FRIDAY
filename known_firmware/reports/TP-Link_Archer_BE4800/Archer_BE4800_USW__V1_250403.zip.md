# Firmware Audit: TP-Link Archer BE4800 / Archer_BE4800_USW__V1_250403.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202505/20250509/Archer BE4800(USW)_V1_250403.zip
- Local path: known_firmware/firmware/TP-Link_Archer_BE4800/Archer_BE4800_USW__V1_250403.zip
- SHA-256: `47e071ea115358f7cddd054e586fe5a4a51668a85f0194e0f9cef8f244f0033c`
- Size: 41198096 bytes
- Version: V1.6_1.0.4 Build 20250403
- Release date: 2025-05-09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/47e071ea115358f7 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
