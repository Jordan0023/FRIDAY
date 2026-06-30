# Firmware Audit: WNDRMACV2 / WNDRMACv2-V1.0.0.20.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDRMACV2/WNDRMACv2-V1.0.0.20.zip
- Local path: known_firmware/firmware/WNDRMACV2/WNDRMACv2-V1.0.0.20.zip
- SHA-256: `ca414b8c57ef4121fd694c438a374806dffbc871973d1c507ca003c8de16cf90`
- Size: 11156200 bytes
- Version: 1.0.0.20
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, bOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ca414b8c57ef4121 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
