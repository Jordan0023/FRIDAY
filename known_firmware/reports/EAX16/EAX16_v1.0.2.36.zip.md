# Firmware Audit: EAX16 / EAX16_v1.0.2.36.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX16/EAX16_v1.0.2.36.zip
- Local path: known_firmware/firmware/EAX16/EAX16_v1.0.2.36.zip
- SHA-256: `386abdc09c71c2222c75c6679601330bc10e560e3d5eff73a421ef3f4a626b81`
- Size: 29450287 bytes
- Version: 0.2.36
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/386abdc09c71c222 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
