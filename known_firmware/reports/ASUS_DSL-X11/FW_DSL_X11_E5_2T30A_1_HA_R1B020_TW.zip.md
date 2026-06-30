# Firmware Audit: ASUS DSL-X11 / FW_DSL_X11_E5_2T30A_1_HA_R1B020_TW.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-X11/FW_DSL_X11_E5_2T30A_1_HA_R1B020_TW.zip
- Local path: known_firmware/firmware/ASUS_DSL-X11/FW_DSL_X11_E5_2T30A_1_HA_R1B020_TW.zip
- SHA-256: `3faa46ada3ca8ee96a38b1d95b3f3da2258a4cac86783e56d4d5b3eb8eecd3e2`
- Size: 1856522 bytes
- Version: E5.2T30A-1-HA-R1B020-TW
- Release date: 2011/09/15

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3faa46ada3ca8ee9 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
