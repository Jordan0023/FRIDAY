# Firmware Audit: ASUS WL-520gC / FW_WL520gC_2007_TW.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GC/FW_WL520gC_2007_TW.zip
- Local path: known_firmware/firmware/ASUS_WL-520gC/FW_WL520gC_2007_TW.zip
- SHA-256: `aef48ded92b434e7449dc9b0bd000cc52a43dffbc18aa0d24a3ea30bddb985fe`
- Size: 1879863 bytes
- Version: 2.0.0.7
- Release date: 2007/09/27

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/aef48ded92b434e7 exited 0: WARNING: Extractor.execute failed to run external extractor 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'': [Errno 2] No such file or directory: 'cramfsswap', 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
