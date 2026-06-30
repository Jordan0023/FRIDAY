# Firmware Audit: WNR2000V3 / WNR2000v3_Firmware_Version_1.1.2.2.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000v3/WNR2000v3_Firmware_Version_1.1.2.2.zip
- Local path: known_firmware/firmware/WNR2000V3/WNR2000v3_Firmware_Version_1.1.2.2.zip
- SHA-256: `0f7cfe1df5a6c67333a81b2b8a025e1b3d147851ba14bc8da8f809075d1d3d42`
- Size: 3448136 bytes
- Version: 1.2.2
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0f7cfe1df5a6c673 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
