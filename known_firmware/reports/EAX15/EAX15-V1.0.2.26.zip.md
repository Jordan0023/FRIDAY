# Firmware Audit: EAX15 / EAX15-V1.0.2.26.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX15/EAX15-V1.0.2.26.zip
- Local path: known_firmware/firmware/EAX15/EAX15-V1.0.2.26.zip
- SHA-256: `dbf458e78195823bead6c50eba39d697b228af9976db4d409d55ba96f2c65d96`
- Size: 51512528 bytes
- Version: 1.0.2.26
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dbf458e78195823b exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
