# Firmware Audit: ASUS WL-AM604g / FW_WL_AM604g_3022A.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-AM604g/FW_WL_AM604g_3022A.zip
- Local path: known_firmware/firmware/ASUS_WL-AM604g/FW_WL_AM604g_3022A.zip
- SHA-256: `403f2980953e553fe251b4a283e874e1cd77472c325b5b0d3d9946d03fd9bb6a`
- Size: 3564417 bytes
- Version: 3.0.2.2A
- Release date: 2010/04/28

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/403f2980953e553f exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
