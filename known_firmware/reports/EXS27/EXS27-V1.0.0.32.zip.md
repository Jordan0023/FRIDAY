# Firmware Audit: EXS27 / EXS27-V1.0.0.32.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EXS27/EXS27-V1.0.0.32.zip
- Local path: known_firmware/firmware/EXS27/EXS27-V1.0.0.32.zip
- SHA-256: `bb3a4a64c8ceea2279b954aa9c9e70bed2931fa700abb321cd72b5d4f0e7801c`
- Size: 35749580 bytes
- Version: 1.0.0.32
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bb3a4a64c8ceea22 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
