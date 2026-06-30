# Firmware Audit: WNDRMACV2 / WNDRMACv2-V1.0.0.16.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDRMACV2/WNDRMACv2-V1.0.0.16.zip
- Local path: known_firmware/firmware/WNDRMACV2/WNDRMACv2-V1.0.0.16.zip
- SHA-256: `69ad64ce588b16fd91d57d64d89a4db60d9141abd5c1908c5c2668600e69e64e`
- Size: 11154908 bytes
- Version: 1.0.0.16
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/69ad64ce588b16fd exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
