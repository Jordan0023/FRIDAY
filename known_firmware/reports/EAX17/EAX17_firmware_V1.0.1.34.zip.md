# Firmware Audit: EAX17 / EAX17_firmware_V1.0.1.34.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX17/EAX17_firmware_V1.0.1.34.zip
- Local path: known_firmware/firmware/EAX17/EAX17_firmware_V1.0.1.34.zip
- SHA-256: `932f47c4e07d0e7a200979411ebed266a10cd18eaf3ffc94c1624f0f1c19ba79`
- Size: 29440046 bytes
- Version: 0.1.34
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/932f47c4e07d0e7a exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
