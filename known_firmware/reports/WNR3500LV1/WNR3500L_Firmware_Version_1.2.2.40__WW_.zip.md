# Firmware Audit: WNR3500LV1 / WNR3500L_Firmware_Version_1.2.2.40__WW_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500LV1/WNR3500L%20Firmware%20Version%201.2.2.40%20(WW).zip
- Local path: known_firmware/firmware/WNR3500LV1/WNR3500L_Firmware_Version_1.2.2.40__WW_.zip
- SHA-256: `80e4c1f4ea53e3589dfa2a25926fc9c28d2ddad5f3ae8af8ab04f23cfe2097da`
- Size: 5395414 bytes
- Version: 2.2.40__WW_
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

- binwalk -eM --directory known_firmware/extracted/80e4c1f4ea53e358 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
