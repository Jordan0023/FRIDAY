# Firmware Audit: EAX17 / EAX17_firmware_V1.0.4.40.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX17/EAX17_firmware_V1.0.4.40.zip
- Local path: known_firmware/firmware/EAX17/EAX17_firmware_V1.0.4.40.zip
- SHA-256: `4705221375ca0fa512d7cd893eb52525196c788276d9ddaba41c61fcacac318d`
- Size: 29347873 bytes
- Version: 0.4.40
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4705221375ca0fa5 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
