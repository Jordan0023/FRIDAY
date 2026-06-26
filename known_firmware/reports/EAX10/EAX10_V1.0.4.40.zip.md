# Firmware Audit: EAX10 / EAX10_V1.0.4.40.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX10/EAX10_V1.0.4.40.zip
- Local path: known_firmware/firmware/EAX10/EAX10_V1.0.4.40.zip
- SHA-256: `0a92dcd4da9cfe3b4fe19d5ac659507b7cafabe78b7b91b9d03ddef400fb93e7`
- Size: 29347907 bytes
- Version: 0.4.40
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boa`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/0a92dcd4da9cfe3b

## Decompiler Notes

- No ELF binaries found for Ghidra import.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
