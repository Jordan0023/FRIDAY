# Firmware Audit: EAX12 / EAX12_EAX11v2_EAX15v2-V1.0.2.32.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX12/EAX12_EAX11v2_EAX15v2-V1.0.2.32.zip
- Local path: known_firmware/firmware/EAX12/EAX12_EAX11v2_EAX15v2-V1.0.2.32.zip
- SHA-256: `f0d0a2f2997415fdaa05192fffd35322f16ee25e7c3a05f2d39a3dd32805fb4c`
- Size: 14943703 bytes
- Version: 1.0.2.32
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f0d0a2f2997415fd exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
