# Firmware Audit: EXS25 / EXS25-V1.0.0.32.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EXS25/EXS25-V1.0.0.32.zip
- Local path: known_firmware/firmware/EXS25/EXS25-V1.0.0.32.zip
- SHA-256: `de5440098088810bbf15e42aa1eb600f67773af8dfd572231e7545d6859241e8`
- Size: 35749637 bytes
- Version: 1.0.0.32
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/de5440098088810b exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
