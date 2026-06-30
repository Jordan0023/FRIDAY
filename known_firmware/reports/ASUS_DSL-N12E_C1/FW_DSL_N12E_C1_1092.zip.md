# Firmware Audit: ASUS DSL-N12E_C1 / FW_DSL_N12E_C1_1092.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12E_C1/FW_DSL_N12E_C1_1092.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12E_C1/FW_DSL_N12E_C1_1092.zip
- SHA-256: `cf50b67c03952b74e2fdbc22981e09a263c66a678b5f99f4aad7d6e12ff0c7d4`
- Size: 7589152 bytes
- Version: 1.0.9.2
- Release date: 2015/04/22

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cf50b67c03952b74 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
