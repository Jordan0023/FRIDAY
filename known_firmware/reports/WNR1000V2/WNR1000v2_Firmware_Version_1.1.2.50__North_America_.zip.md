# Firmware Audit: WNR1000V2 / WNR1000v2_Firmware_Version_1.1.2.50__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR1000v2/WNR1000v2%20Firmware%20Version%201.1.2.50%20(North%20America).zip
- Local path: known_firmware/firmware/WNR1000V2/WNR1000v2_Firmware_Version_1.1.2.50__North_America_.zip
- SHA-256: `f0af71a497613c66ff0deeb03bc8bece16f4ad33c1ddaa9d9bf1b098e6d0e333`
- Size: 3469296 bytes
- Version: 1.2.50__North_America_
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f0af71a497613c66 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
