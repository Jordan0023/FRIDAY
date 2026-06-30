# Firmware Audit: EAX16 / EAX16_v1.0.0.24.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX16/EAX16_v1.0.0.24.zip
- Local path: known_firmware/firmware/EAX16/EAX16_v1.0.0.24.zip
- SHA-256: `0a2e1d85f067f359d6d9df44be814a262cda9ae7f62872cb8cecf2c9a2cfcd29`
- Size: 28862965 bytes
- Version: 0.0.24
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0a2e1d85f067f359 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
