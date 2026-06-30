# Firmware Audit: ASUS DSL-N55U Annex B / Rescue_DSL_N55U_3004374159_Annex_B.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N55U_B1/Rescue_DSL_N55U_3004374159_Annex_B.zip
- Local path: known_firmware/firmware/ASUS_DSL-N55U_Annex_B/Rescue_DSL_N55U_3004374159_Annex_B.zip
- SHA-256: `1c7ab6ae1aab3494b8c3c250c1f2eb5387808dffcaa6b0c09cdcda11bb726123`
- Size: 8050394 bytes
- Version: 3.0.0.4.374_159
- Release date: 2013/08/26

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1c7ab6ae1aab3494 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
