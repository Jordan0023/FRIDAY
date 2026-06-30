# Firmware Audit: EAX15V3 / EAX15v3_firmware_V1.0.1.34.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX15v3/EAX15v3_firmware_V1.0.1.34.zip
- Local path: known_firmware/firmware/EAX15V3/EAX15v3_firmware_V1.0.1.34.zip
- SHA-256: `9337126c20363c78603a0cd0d4d85fbbdf2c44419d01d9316aa181fd86a68ec3`
- Size: 29440115 bytes
- Version: 0.1.34
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9337126c20363c78 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
