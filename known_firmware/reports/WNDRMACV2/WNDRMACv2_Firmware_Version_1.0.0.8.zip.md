# Firmware Audit: WNDRMACV2 / WNDRMACv2_Firmware_Version_1.0.0.8.zip

- Source URL: https://www.downloads.netgear.com/files/WNDRMACv2/WNDRMACv2%20Firmware%20Version%201.0.0.8.zip
- Local path: known_firmware/firmware/WNDRMACV2/WNDRMACv2_Firmware_Version_1.0.0.8.zip
- SHA-256: `38f1d473e612ebd9c3b3e0bb90bfe08dda26b8282943367b349cf5609784e4b6`
- Size: 10756161 bytes
- Version: 0.0.8
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/38f1d473e612ebd9 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
