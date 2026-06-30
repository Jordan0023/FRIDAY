# Firmware Audit: ASUS WL-320gE / WL320gE_firmware_1980.rar

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-320gE/WL320gE_firmware_1980.rar
- Local path: known_firmware/firmware/ASUS_WL-320gE/WL320gE_firmware_1980.rar
- SHA-256: `5ce28acdabc17e59c55b6d5d78d0bfa849bf0be6f67eb68a557908d927b33ed1`
- Size: 3428831 bytes
- Version: 1.9.8.0
- Release date: 2007/08/24

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5ce28acdabc17e59 exited 0: WARNING: Extractor.execute failed to run external extractor 'unrar -x '%e'': [Errno 2] No such file or directory: 'unrar', 'unrar -x '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
