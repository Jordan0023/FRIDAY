# Firmware Audit: EAX15V3 / EAX15v3_firmware_V1.0.0.20.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX15v3/EAX15v3_firmware_V1.0.0.20.zip
- Local path: known_firmware/firmware/EAX15V3/EAX15v3_firmware_V1.0.0.20.zip
- SHA-256: `4d666092ee301b9471ac1227e89e4e76a0b37017d26ef21046c204937078bb0c`
- Size: 28815068 bytes
- Version: 0.0.20
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4d666092ee301b94 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
