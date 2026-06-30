# Firmware Audit: EAX16 / EAX16_v1.0.2.28.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX16/EAX16_v1.0.2.28.zip
- Local path: known_firmware/firmware/EAX16/EAX16_v1.0.2.28.zip
- SHA-256: `199c1e78d3bca3aa62239f8affbfabe40c0b6f918e4c5f1860437f74becb4631`
- Size: 28868703 bytes
- Version: 0.2.28
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/199c1e78d3bca3aa exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
