# Firmware Audit: TP-Link Archer BE230 / Archer_BE230_US__V2_260212.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202604/20260429/Archer BE230(US)_V2_260212.zip
- Local path: known_firmware/firmware/TP-Link_Archer_BE230/Archer_BE230_US__V2_260212.zip
- SHA-256: `941ee111d22d85af3330cf62b79ee13eeda4480a50a19168828aa367006e0312`
- Size: 50112879 bytes
- Version: V2.6_1.3.2 Build 20260212
- Release date: 2026-04-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/941ee111d22d85af exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
