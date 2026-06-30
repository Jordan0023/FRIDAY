# Firmware Audit: ASUS DSL-G31 / FW_DSL_G31_3013A.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-G31/FW_DSL_G31_3013A.zip
- Local path: known_firmware/firmware/ASUS_DSL-G31/FW_DSL_G31_3013A.zip
- SHA-256: `86d27095ede7d30fc38365cdc6970c574af74065dc6c8f4125a38ad4d11f1440`
- Size: 3761668 bytes
- Version: 3.0.1.3A
- Release date: 2009/07/28

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/86d27095ede7d30f exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
