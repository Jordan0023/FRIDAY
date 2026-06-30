# Firmware Audit: WNDRMACV1 / WNDRMAC_Firmware_Version_1.0.0.22.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDRMACv1/WNDRMAC%20Firmware%20Version%201.0.0.22.zip
- Local path: known_firmware/firmware/WNDRMACV1/WNDRMAC_Firmware_Version_1.0.0.22.zip
- SHA-256: `125aafeab2de36efe0dadc5efc664d7f3cb7ac887a96136b83ff6a199d885345`
- Size: 10870480 bytes
- Version: 0.0.22
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/125aafeab2de36ef exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
