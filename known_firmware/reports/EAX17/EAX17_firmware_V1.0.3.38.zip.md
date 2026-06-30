# Firmware Audit: EAX17 / EAX17_firmware_V1.0.3.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX17/EAX17_firmware_V1.0.3.38.zip
- Local path: known_firmware/firmware/EAX17/EAX17_firmware_V1.0.3.38.zip
- SHA-256: `aa630d1502d4be0057c8cffcd81cbc451cb29fbad777f894af36f2f929a03929`
- Size: 29450311 bytes
- Version: 0.3.38
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, bOA, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/aa630d1502d4be00 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
