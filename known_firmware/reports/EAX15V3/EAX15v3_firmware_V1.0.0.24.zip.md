# Firmware Audit: EAX15V3 / EAX15v3_firmware_V1.0.0.24.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX15v3/EAX15v3_firmware_V1.0.0.24.zip
- Local path: known_firmware/firmware/EAX15V3/EAX15v3_firmware_V1.0.0.24.zip
- SHA-256: `ef48480acd11cf14ef7a4158c303a4053cdb8052efb9271f410f2c971c189e1a`
- Size: 28825413 bytes
- Version: 0.0.24
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ef48480acd11cf14 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
