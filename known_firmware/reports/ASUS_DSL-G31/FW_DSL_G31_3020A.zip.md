# Firmware Audit: ASUS DSL-G31 / FW_DSL_G31_3020A.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-G31/FW_DSL_G31_3020A.zip
- Local path: known_firmware/firmware/ASUS_DSL-G31/FW_DSL_G31_3020A.zip
- SHA-256: `da0a2c7dd2e13caf07db03986502ba671f72852511dd7b6ee34c07ac2697452e`
- Size: 3563679 bytes
- Version: 3.0.2.0.A
- Release date: 2010/03/18

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/da0a2c7dd2e13caf exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
