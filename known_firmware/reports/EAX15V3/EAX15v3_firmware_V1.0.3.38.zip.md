# Firmware Audit: EAX15V3 / EAX15v3_firmware_V1.0.3.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX15v3/EAX15v3_firmware_V1.0.3.38.zip
- Local path: known_firmware/firmware/EAX15V3/EAX15v3_firmware_V1.0.3.38.zip
- SHA-256: `ed9130b0bf364602f4dade2ea9575b3dc56cf902f2dc96007e96afea4b600141`
- Size: 29450340 bytes
- Version: 0.3.38
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, bOA, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ed9130b0bf364602 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
