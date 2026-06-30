# Firmware Audit: WNDRMACV2 / WNDRMACv2_Firmware_Version_1.0.0.9_-_BETA.zip

- Source URL: https://www.downloads.netgear.com/files/WNDRMACv2/WNDRMACv2%20Firmware%20Version%201.0.0.9%20-%20BETA.zip
- Local path: known_firmware/firmware/WNDRMACV2/WNDRMACv2_Firmware_Version_1.0.0.9_-_BETA.zip
- SHA-256: `7d50e4378d6f869520523afc162993f6c77eae2b296e4124145d1ecbcdc8382f`
- Size: 2202444 bytes
- Version: 0.0.9_-_BETA
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7d50e4378d6f8695 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
