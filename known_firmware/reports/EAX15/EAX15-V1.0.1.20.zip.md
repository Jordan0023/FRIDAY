# Firmware Audit: EAX15 / EAX15-V1.0.1.20.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX15/EAX15-V1.0.1.20.zip
- Local path: known_firmware/firmware/EAX15/EAX15-V1.0.1.20.zip
- SHA-256: `2afa3786c06d548374d4bfa443f902fe90a9e035704579a02f6b6a2aeb737e5d`
- Size: 51250391 bytes
- Version: 1.0.1.20
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2afa3786c06d5483 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
