# Firmware Audit: ASUS DSL-N12E_C1 / FW_DSL_N12E_C1_1104.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12E_C1/FW_DSL_N12E_C1_1104.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12E_C1/FW_DSL_N12E_C1_1104.zip
- SHA-256: `aab2443cd1094da1c55e81f5ada7e871a02b5865e38295f061ced32617183458`
- Size: 7690303 bytes
- Version: 1.1.0.4
- Release date: 2015/11/04

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/aab2443cd1094da1 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
