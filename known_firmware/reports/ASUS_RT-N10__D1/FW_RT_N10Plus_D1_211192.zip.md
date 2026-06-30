# Firmware Audit: ASUS RT-N10+ D1 / FW_RT_N10Plus_D1_211192.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N10+_D1/FW_RT_N10Plus_D1_211192.zip
- Local path: known_firmware/firmware/ASUS_RT-N10__D1/FW_RT_N10Plus_D1_211192.zip
- SHA-256: `bba8e7726908fe89b2368c443684395f0ac80bf2be4dcc1a2f3b784d8ce9cc4b`
- Size: 3762204 bytes
- Version: 2.1.1.1.92
- Release date: 2015/01/22

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bba8e7726908fe89 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
