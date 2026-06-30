# Firmware Audit: WNR3500LV1 / WNR3500L_Firmware_Version_1.2.2.44__NA_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500LV1/WNR3500L%20Firmware%20Version%201.2.2.44%20(NA).zip
- Local path: known_firmware/firmware/WNR3500LV1/WNR3500L_Firmware_Version_1.2.2.44__NA_.zip
- SHA-256: `f8dc507f909e025b7a15330285830fdd8c22d067d5536798780f79cbd2ce01b4`
- Size: 5352366 bytes
- Version: 2.2.44__NA_
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f8dc507f909e025b exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
