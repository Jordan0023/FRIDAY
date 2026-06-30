# Firmware Audit: ASUS DSL-N12E_C1 / FW_DSL_N12E_C1_1098.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12E_C1/FW_DSL_N12E_C1_1098.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12E_C1/FW_DSL_N12E_C1_1098.zip
- SHA-256: `6553f63d92ccf4e6a7674b67f2d9ebeb8458c87ff073e56d2e9532770e5934fb`
- Size: 7685694 bytes
- Version: 1.0.9.8
- Release date: 2015/07/23

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6553f63d92ccf4e6 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
