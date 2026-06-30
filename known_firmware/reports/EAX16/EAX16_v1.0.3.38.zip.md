# Firmware Audit: EAX16 / EAX16_v1.0.3.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX16/EAX16_v1.0.3.38.zip
- Local path: known_firmware/firmware/EAX16/EAX16_v1.0.3.38.zip
- SHA-256: `a47ef6376116ef9ba9b393ee53e3555f22d82a213d2afe47ffe72667b4eed655`
- Size: 29450292 bytes
- Version: 0.3.38
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, bOA, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a47ef6376116ef9b exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
