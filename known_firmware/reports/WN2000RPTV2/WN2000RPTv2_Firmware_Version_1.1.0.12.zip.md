# Firmware Audit: WN2000RPTV2 / WN2000RPTv2_Firmware_Version_1.1.0.12.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WN2000RPTv2/WN2000RPTv2%20Firmware%20Version%201.1.0.12.zip
- Local path: known_firmware/firmware/WN2000RPTV2/WN2000RPTv2_Firmware_Version_1.1.0.12.zip
- SHA-256: `9516738d79c9131beb487e637f7b614bd091977ff300d4455e5f558bedaa490c`
- Size: 2916993 bytes
- Version: 1.0.12
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9516738d79c9131b exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
