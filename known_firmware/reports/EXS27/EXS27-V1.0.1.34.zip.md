# Firmware Audit: EXS27 / EXS27-V1.0.1.34.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EXS27/EXS27-V1.0.1.34.zip
- Local path: known_firmware/firmware/EXS27/EXS27-V1.0.1.34.zip
- SHA-256: `a1db77f35622c58ffd992a59926e607ba5a22690ca2e51be8a6be84d0aebd32e`
- Size: 36273969 bytes
- Version: 1.0.1.34
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a1db77f35622c58f exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
