# Firmware Audit: ASUS RT-G32 / FW_RTG32_3014_EN.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-G32/FW_RTG32_3014_EN.zip
- Local path: known_firmware/firmware/ASUS_RT-G32/FW_RTG32_3014_EN.zip
- SHA-256: `ecdf6288d6c0444a3465bd826eda5f05ee1169d9470441ff938596cded7c40a6`
- Size: 2424874 bytes
- Version: 3.0.1.4
- Release date: 2009/02/20

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ecdf6288d6c0444a exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
