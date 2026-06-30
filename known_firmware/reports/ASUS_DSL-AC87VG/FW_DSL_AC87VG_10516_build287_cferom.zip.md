# Firmware Audit: ASUS DSL-AC87VG / FW_DSL_AC87VG_10516_build287_cferom.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-AC87VG/FW_DSL_AC87VG_10516_build287_cferom.zip
- Local path: known_firmware/firmware/ASUS_DSL-AC87VG/FW_DSL_AC87VG_10516_build287_cferom.zip
- SHA-256: `2e8a1cc962c39781deee6119a397293014462461ce193a7280949fe326b1ee8b`
- Size: 48157971 bytes
- Version: 1.05.16_build287
- Release date: 2018/07/30

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `EVAl`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2e8a1cc962c39781 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
