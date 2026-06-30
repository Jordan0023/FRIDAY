# Firmware Audit: ASUS WL-320gP / WL320gP_firmware_1980.rar

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-320gP/WL320gP_firmware_1980.rar
- Local path: known_firmware/firmware/ASUS_WL-320gP/WL320gP_firmware_1980.rar
- SHA-256: `63c167d8ba73a16716f0ba617c19b496d08d34243904df11d6bd14515ec33929`
- Size: 3428786 bytes
- Version: 1.9.8.0
- Release date: 2007/08/24

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/63c167d8ba73a167 exited 0: WARNING: Extractor.execute failed to run external extractor 'unrar -x '%e'': [Errno 2] No such file or directory: 'unrar', 'unrar -x '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
