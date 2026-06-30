# Firmware Audit: WNR612V2 / WNR612v2_Firmware_Version_1.0.0.2.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR612v2/WNR612v2%20Firmware%20Version%201.0.0.2.zip
- Local path: known_firmware/firmware/WNR612V2/WNR612v2_Firmware_Version_1.0.0.2.zip
- SHA-256: `75afda2b66686d38532756345fcd6943319e6e787d9e7195de725f60747d8309`
- Size: 3197946 bytes
- Version: 0.0.2
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/75afda2b66686d38 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
