# Firmware Audit: EXS18 / EXS18-V1.0.1.34.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EXS18/EXS18-V1.0.1.34.zip
- Local path: known_firmware/firmware/EXS18/EXS18-V1.0.1.34.zip
- SHA-256: `16710aede4948c9a4244551a46ed3fd64a0b69f2bf4c13d7c2265ebdeff117e2`
- Size: 36273971 bytes
- Version: 1.0.1.34
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/16710aede4948c9a exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
