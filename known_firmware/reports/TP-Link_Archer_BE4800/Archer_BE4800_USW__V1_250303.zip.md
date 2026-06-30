# Firmware Audit: TP-Link Archer BE4800 / Archer_BE4800_USW__V1_250303.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202504/20250402/Archer BE4800(USW)_V1_250303.zip
- Local path: known_firmware/firmware/TP-Link_Archer_BE4800/Archer_BE4800_USW__V1_250303.zip
- SHA-256: `543d8bb220dbf9a20ccb7827070f53502a3141136eeeab9ff6b703fecfca5dec`
- Size: 41198096 bytes
- Version: V1.6_1.0.3 Build 20250303
- Release date: 2025-04-02

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/543d8bb220dbf9a2 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
