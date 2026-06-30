# Firmware Audit: ASUS DSL-N12E_C1 / FW_DSL_N12E_C1_1099.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12E_C1/FW_DSL_N12E_C1_1099.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12E_C1/FW_DSL_N12E_C1_1099.zip
- SHA-256: `b1816f26264a4c82b6590591f548e7e936b5be1148a0de2c1bd16b5403df37bd`
- Size: 7670607 bytes
- Version: 1.0.9.9
- Release date: 2015/08/11

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b1816f26264a4c82 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
