# Firmware Audit: ASUS DSL-N13 / FW_DSL_N13_1151A.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N13/FW_DSL_N13_1151A.zip
- Local path: known_firmware/firmware/ASUS_DSL-N13/FW_DSL_N13_1151A.zip
- SHA-256: `ad5b4381c61af1e7d3aa77871f34e03fbfe958e52606c3e799790d6954481903`
- Size: 3568025 bytes
- Version: 1.1.5.1A
- Release date: 2010/07/23

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ad5b4381c61af1e7 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
