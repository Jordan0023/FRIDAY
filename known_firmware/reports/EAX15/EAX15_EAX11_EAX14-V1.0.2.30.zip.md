# Firmware Audit: EAX15 / EAX15_EAX11_EAX14-V1.0.2.30.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX15/EAX15_EAX11_EAX14-V1.0.2.30.zip
- Local path: known_firmware/firmware/EAX15/EAX15_EAX11_EAX14-V1.0.2.30.zip
- SHA-256: `bfb50e6ac1bc9e63ca513033f8131c132df762bf1f3d703f824ea615660778ae`
- Size: 50726152 bytes
- Version: 1.0.2.30
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `EVal`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bfb50e6ac1bc9e63 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
