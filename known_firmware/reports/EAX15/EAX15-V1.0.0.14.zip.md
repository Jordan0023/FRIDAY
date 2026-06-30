# Firmware Audit: EAX15 / EAX15-V1.0.0.14.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX15/EAX15-V1.0.0.14.zip
- Local path: known_firmware/firmware/EAX15/EAX15-V1.0.0.14.zip
- SHA-256: `e7ae818da9de9e438d41b085bf499f094380c5e903b16c5dd474668c70be8c67`
- Size: 50988234 bytes
- Version: 1.0.0.14
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e7ae818da9de9e43 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
