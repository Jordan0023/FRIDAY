# Firmware Audit: EAX12 / EAX12_EAX11v2_EAX15v2-V1.0.3.34.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX12/EAX12_EAX11v2_EAX15v2-V1.0.3.34.zip
- Local path: known_firmware/firmware/EAX12/EAX12_EAX11v2_EAX15v2-V1.0.3.34.zip
- SHA-256: `03001adfb96c6fbf197fed91e6d3f7a11dccaa5425de214a78bc0dd3fc513145`
- Size: 14943704 bytes
- Version: 1.0.3.34
- Release date: unknown

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `ssHd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/03001adfb96c6fbf exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
