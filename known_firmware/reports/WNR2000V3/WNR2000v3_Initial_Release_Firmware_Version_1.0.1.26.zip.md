# Firmware Audit: WNR2000V3 / WNR2000v3_Initial_Release_Firmware_Version_1.0.1.26.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000V3/WNR2000v3%20Initial%20Release%20Firmware%20Version%201.0.1.26.zip
- Local path: known_firmware/firmware/WNR2000V3/WNR2000v3_Initial_Release_Firmware_Version_1.0.1.26.zip
- SHA-256: `6d77eb299d921205d9cb2733fbef331f20d6cb9bec35e5fbec5b750d223ded9f`
- Size: 3123861 bytes
- Version: 0.1.26
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6d77eb299d921205 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
