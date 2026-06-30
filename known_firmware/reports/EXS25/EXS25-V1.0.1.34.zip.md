# Firmware Audit: EXS25 / EXS25-V1.0.1.34.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EXS25/EXS25-V1.0.1.34.zip
- Local path: known_firmware/firmware/EXS25/EXS25-V1.0.1.34.zip
- SHA-256: `44d8bbed150c5cb31f5cf2acec11695288c006baacd475c39297f6911e132b33`
- Size: 36273969 bytes
- Version: 1.0.1.34
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/44d8bbed150c5cb3 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
