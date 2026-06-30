# Firmware Audit: EXS18 / EXS18-V1.0.0.32.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EXS18/EXS18-V1.0.0.32.zip
- Local path: known_firmware/firmware/EXS18/EXS18-V1.0.0.32.zip
- SHA-256: `7f5a26638a5c1afddb44e5719a13812fbe0559cdbcef07b649d045a4913684b7`
- Size: 35749588 bytes
- Version: 1.0.0.32
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7f5a26638a5c1afd exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
