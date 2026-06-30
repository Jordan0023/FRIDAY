# Firmware Audit: JWNR2000V1 / JWNR2000_Firmware_Version_1.0.0.7__Korea_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/JWNR2000v1/JWNR2000%20Firmware%20Version%201.0.0.7%20(Korea).zip
- Local path: known_firmware/firmware/JWNR2000V1/JWNR2000_Firmware_Version_1.0.0.7__Korea_.zip
- SHA-256: `80f222d5e6024c8d3b8027c21526299ee9253b37fedc9983fed30829e27daea0`
- Size: 2145847 bytes
- Version: 0.0.7__Korea_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/80f222d5e6024c8d exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
