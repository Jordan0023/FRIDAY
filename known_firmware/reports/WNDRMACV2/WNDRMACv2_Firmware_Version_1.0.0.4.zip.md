# Firmware Audit: WNDRMACV2 / WNDRMACv2_Firmware_Version_1.0.0.4.zip

- Source URL: https://www.downloads.netgear.com/files/WNDRMACv2/WNDRMACv2%20Firmware%20Version%201.0.0.4.zip
- Local path: known_firmware/firmware/WNDRMACV2/WNDRMACv2_Firmware_Version_1.0.0.4.zip
- SHA-256: `48be516daa0088c89a79bf76c639e0ad28a65c8883e9ac67e56bf34e742a86d4`
- Size: 10455422 bytes
- Version: 0.0.4
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/48be516daa0088c8 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
