# Firmware Audit: EAX16 / EAX16_v1.0.4.40.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX16/EAX16_v1.0.4.40.zip
- Local path: known_firmware/firmware/EAX16/EAX16_v1.0.4.40.zip
- SHA-256: `b95f4937fe8bcdbca5c73a06f29617dd81223c684138f80f7ed53e457bdb41f4`
- Size: 29347863 bytes
- Version: 0.4.40
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b95f4937fe8bcdbc exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
