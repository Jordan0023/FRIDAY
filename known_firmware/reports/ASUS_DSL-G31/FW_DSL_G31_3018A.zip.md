# Firmware Audit: ASUS DSL-G31 / FW_DSL_G31_3018A.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-G31/FW_DSL_G31_3018A.zip
- Local path: known_firmware/firmware/ASUS_DSL-G31/FW_DSL_G31_3018A.zip
- SHA-256: `7a7ba8ab7860900bcc36f3f7ec951a3a35a06f85f8e45f4c253531effb95a6b1`
- Size: 3530100 bytes
- Version: 3.0.1.8A
- Release date: 2010/01/06

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7a7ba8ab7860900b exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
