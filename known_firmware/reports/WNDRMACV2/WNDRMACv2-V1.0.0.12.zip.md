# Firmware Audit: WNDRMACV2 / WNDRMACv2-V1.0.0.12.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDRMACV2/WNDRMACv2-V1.0.0.12.zip
- Local path: known_firmware/firmware/WNDRMACV2/WNDRMACv2-V1.0.0.12.zip
- SHA-256: `ce4ef2f202c74567dcb621f697cea01d73a23a455e813913a85a9d4082abebb7`
- Size: 10873792 bytes
- Version: 1.0.0.12
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ce4ef2f202c74567 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
