# Firmware Audit: ASUS WL-300g / WL300g_firmware_1937_EN.rar

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-300g/WL300g_firmware_1937_EN.rar
- Local path: known_firmware/firmware/ASUS_WL-300g/WL300g_firmware_1937_EN.rar
- SHA-256: `d7bf369b3ea91d710fa8728e6f1d17acbe8e897ca4b67403c74c3175958fb5d4`
- Size: 3541954 bytes
- Version: 1.9.3.7
- Release date: 2007/04/26

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d7bf369b3ea91d71 exited 0: WARNING: Extractor.execute failed to run external extractor 'unrar -x '%e'': [Errno 2] No such file or directory: 'unrar', 'unrar -x '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
