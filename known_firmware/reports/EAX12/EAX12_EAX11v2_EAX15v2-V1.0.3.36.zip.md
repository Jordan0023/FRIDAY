# Firmware Audit: EAX12 / EAX12_EAX11v2_EAX15v2-V1.0.3.36.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX12/EAX12_EAX11v2_EAX15v2-V1.0.3.36.zip
- Local path: known_firmware/firmware/EAX12/EAX12_EAX11v2_EAX15v2-V1.0.3.36.zip
- SHA-256: `331d99830059c4ac2d1ea782d8de085c063bb50628425c3302f7fe05b9ce0c1e`
- Size: 14554501 bytes
- Version: 1.0.3.36
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/331d99830059c4ac exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
