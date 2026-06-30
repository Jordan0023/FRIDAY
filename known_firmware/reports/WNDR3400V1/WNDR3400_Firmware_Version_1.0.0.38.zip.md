# Firmware Audit: WNDR3400V1 / WNDR3400_Firmware_Version_1.0.0.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR3400V1/WNDR3400%20Firmware%20Version%201.0.0.38.zip
- Local path: known_firmware/firmware/WNDR3400V1/WNDR3400_Firmware_Version_1.0.0.38.zip
- SHA-256: `a20f03a10716a700a1cf0d85f2b42b9e884869cb49aafacb89ce580d00869526`
- Size: 4509339 bytes
- Version: 0.0.38
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a20f03a10716a700 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
