# Firmware Audit: WNR2000V3 / WNR2000v3_Release_Firmware_Version_1.1.1.72.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000v3/WNR2000v3_Release_Firmware_Version_1.1.1.72.zip
- Local path: known_firmware/firmware/WNR2000V3/WNR2000v3_Release_Firmware_Version_1.1.1.72.zip
- SHA-256: `e377fe5f6ac7fb422f535f76a6f2fbd1c3af60517dd86a858b09275b021dbf9f`
- Size: 3440423 bytes
- Version: 1.1.72
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e377fe5f6ac7fb42 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
