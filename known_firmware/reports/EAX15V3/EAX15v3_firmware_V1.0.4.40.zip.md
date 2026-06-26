# Firmware Audit: EAX15V3 / EAX15v3_firmware_V1.0.4.40.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX15v3/EAX15v3_firmware_V1.0.4.40.zip
- Local path: known_firmware/firmware/EAX15V3/EAX15v3_firmware_V1.0.4.40.zip
- SHA-256: `ba883003ed327b2dca348ea1b9f9284bfc509a4aed4d53029c7fa3994f3e65d7`
- Size: 29347883 bytes
- Version: 0.4.40
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boa`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/ba883003ed327b2d

## Decompiler Notes

- No ELF binaries found for Ghidra import.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
