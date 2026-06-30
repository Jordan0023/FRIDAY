# Firmware Audit: EAX15V3 / EAX15v3_firmware_V1.0.2.36.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX15v3/EAX15v3_firmware_V1.0.2.36.zip
- Local path: known_firmware/firmware/EAX15V3/EAX15v3_firmware_V1.0.2.36.zip
- SHA-256: `a261ca03204134809e600f80e6b93e7e0a63c427ac99c78105dc7fd2aad0f24b`
- Size: 29450317 bytes
- Version: 0.2.36
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a261ca0320413480 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
