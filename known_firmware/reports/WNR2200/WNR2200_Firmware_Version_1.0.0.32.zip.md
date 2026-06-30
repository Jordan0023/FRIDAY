# Firmware Audit: WNR2200 / WNR2200_Firmware_Version_1.0.0.32.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2200/WNR2200%20Firmware%20Version%201.0.0.32.zip
- Local path: known_firmware/firmware/WNR2200/WNR2200_Firmware_Version_1.0.0.32.zip
- SHA-256: `c213b89e47cc0912546fd3d252462b244fde88768f9cbf13bb05dc69d406fc3c`
- Size: 4888913 bytes
- Version: 0.0.32
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c213b89e47cc0912 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
