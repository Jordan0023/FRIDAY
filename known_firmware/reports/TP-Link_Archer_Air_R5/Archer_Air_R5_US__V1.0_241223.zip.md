# Firmware Audit: TP-Link Archer Air R5 / Archer_Air_R5_US__V1.0_241223.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202504/20250401/Archer Air R5(US)_V1.0_241223.zip
- Local path: known_firmware/firmware/TP-Link_Archer_Air_R5/Archer_Air_R5_US__V1.0_241223.zip
- SHA-256: `ee64055d95b9f034bee98d708713709b1f69a370c2bc5a2c3e0571b5238b3828`
- Size: 28746530 bytes
- Version: V1.6_1.1.7 Build 20241223
- Release date: 2025-04-01

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `ssHD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, bOA, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ee64055d95b9f034 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
