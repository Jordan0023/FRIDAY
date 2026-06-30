# Firmware Audit: EAX15 / EAX15_EAX11_EAX14-V1.0.3.34.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX15/EAX15_EAX11_EAX14-V1.0.3.34.zip
- Local path: known_firmware/firmware/EAX15/EAX15_EAX11_EAX14-V1.0.3.34.zip
- SHA-256: `02b0e851355d472cad2918cfaa5e26d895fb912400f919a1da95a2eceab722fb`
- Size: 41944353 bytes
- Version: 1.0.3.34
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, bOA, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/02b0e851355d472c exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
