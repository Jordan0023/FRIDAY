# Firmware Audit: WNDR3700V2 / WNDR3700v2_Firmware_Version_1.0.0.6.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR3700V2/WNDR3700v2%20Firmware%20Version%201.0.0.6.zip
- Local path: known_firmware/firmware/WNDR3700V2/WNDR3700v2_Firmware_Version_1.0.0.6.zip
- SHA-256: `1bf82b0e821c7a34d61d71fb1c6969cc2f7385e8d10b4f639d0f48133c679e14`
- Size: 6841571 bytes
- Version: 0.0.6
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1bf82b0e821c7a34 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
