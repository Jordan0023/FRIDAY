# Firmware Audit: ASUS WL-AM602 / FW_WL_AM602_RU_1001.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-AM602/FW_WL_AM602_RU_1001.zip
- Local path: known_firmware/firmware/ASUS_WL-AM602/FW_WL_AM602_RU_1001.zip
- SHA-256: `35d903e87a6a751760aff18086f08c594ebfa94e63e6565184882840c4c0377e`
- Size: 1851295 bytes
- Version: 1.0.0.1
- Release date: 2009/11/06

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/35d903e87a6a7517 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
