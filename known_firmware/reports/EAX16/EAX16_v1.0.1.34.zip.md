# Firmware Audit: EAX16 / EAX16_v1.0.1.34.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX16/EAX16_v1.0.1.34.zip
- Local path: known_firmware/firmware/EAX16/EAX16_v1.0.1.34.zip
- SHA-256: `53960a74e44742868f4073b89e38f33ba6926291e74b4627339b5dd597d086db`
- Size: 29440021 bytes
- Version: 0.1.34
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/53960a74e4474286 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
