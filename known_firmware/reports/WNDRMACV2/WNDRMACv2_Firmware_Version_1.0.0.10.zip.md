# Firmware Audit: WNDRMACV2 / WNDRMACv2_Firmware_Version_1.0.0.10.zip

- Source URL: https://www.downloads.netgear.com/files/WNDRMACv2/WNDRMACv2%20Firmware%20Version%201.0.0.10.zip
- Local path: known_firmware/firmware/WNDRMACV2/WNDRMACv2_Firmware_Version_1.0.0.10.zip
- SHA-256: `a17b301b1b0a50ffa9a6a4318a7b0eb4005a4c9e25dcc0b343ed4672cb6f2ba8`
- Size: 10872550 bytes
- Version: 0.0.10
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a17b301b1b0a50ff exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
