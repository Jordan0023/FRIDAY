# Firmware Audit: ASUS DSL-N12E_C1 / FW_DSL_N12E_C1_1078.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12E_C1/FW_DSL_N12E_C1_1078.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12E_C1/FW_DSL_N12E_C1_1078.zip
- SHA-256: `9c30ffd2c749bae8a465511550ec0d20b8adfa55d3edf452047067d9404633a3`
- Size: 7627156 bytes
- Version: 1.0.7.8
- Release date: 2015/02/03

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9c30ffd2c749bae8 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
