# Firmware Audit: WNR2000V3 / WNR2000v3_Firmware_Version_1.1.1.58.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000V3/WNR2000v3%20Firmware%20Version%201.1.1.58.zip
- Local path: known_firmware/firmware/WNR2000V3/WNR2000v3_Firmware_Version_1.1.1.58.zip
- SHA-256: `d5fae1f2658bb2a3ac097dbd1785ff1a2ce4b034ca34fdead03e2c447017d637`
- Size: 3441641 bytes
- Version: 1.1.58
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d5fae1f2658bb2a3 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
