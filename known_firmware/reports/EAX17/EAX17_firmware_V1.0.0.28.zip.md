# Firmware Audit: EAX17 / EAX17_firmware_V1.0.0.28.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX17/EAX17_firmware_V1.0.0.28.zip
- Local path: known_firmware/firmware/EAX17/EAX17_firmware_V1.0.0.28.zip
- SHA-256: `4a6d18d468b69fcd8fdb332cbcaabb5a9434fad3a76630ce0f2be2c875d07b39`
- Size: 28835734 bytes
- Version: 0.0.28
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4a6d18d468b69fcd exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
