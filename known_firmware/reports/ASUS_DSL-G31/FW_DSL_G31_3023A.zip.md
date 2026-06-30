# Firmware Audit: ASUS DSL-G31 / FW_DSL_G31_3023A.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-G31/FW_DSL_G31_3023A.zip
- Local path: known_firmware/firmware/ASUS_DSL-G31/FW_DSL_G31_3023A.zip
- SHA-256: `6d6800301be428ef01695beda10041bf9db0573683c7c84852850bc4921a187c`
- Size: 3571937 bytes
- Version: 3.0.2.3A
- Release date: 2010/06/22

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6d6800301be428ef exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
