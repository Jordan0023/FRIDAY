# Firmware Audit: TP-Link Archer Air R5 / Archer_Air_R5_US__V1_230922.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202403/20240319/Archer Air R5(US)_V1_230922.zip
- Local path: known_firmware/firmware/TP-Link_Archer_Air_R5/Archer_Air_R5_US__V1_230922.zip
- SHA-256: `265778725ff3ff5f8909c55677ed07077c37652c60c6caaac16dcd2ee05ca4cd`
- Size: 28637878 bytes
- Version: V1.6_1.1.4 Build 20230922
- Release date: 2024-03-19

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `SshD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/265778725ff3ff5f exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
