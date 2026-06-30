# Firmware Audit: WNDR4500 / WNDR4500_Firmware_Version_1.0.0.50.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR4500/WNDR4500%20Firmware%20Version%201.0.0.50.zip
- Local path: known_firmware/firmware/WNDR4500/WNDR4500_Firmware_Version_1.0.0.50.zip
- SHA-256: `44b29c0647722f80352dc0a92d89e3a28d16ed4e9a25f5ee4825a68a69bf7c4c`
- Size: 8103618 bytes
- Version: 0.0.50
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/44b29c0647722f80 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
