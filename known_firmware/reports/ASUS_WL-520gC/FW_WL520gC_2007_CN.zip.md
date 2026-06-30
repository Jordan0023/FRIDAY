# Firmware Audit: ASUS WL-520gC / FW_WL520gC_2007_CN.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GC/FW_WL520gC_2007_CN.zip
- Local path: known_firmware/firmware/ASUS_WL-520gC/FW_WL520gC_2007_CN.zip
- SHA-256: `878ebf97176651574d03c0d059ade23c42d3d6c25fee5393570b485648acaee3`
- Size: 1894644 bytes
- Version: 2.0.0.7
- Release date: 2007/09/27

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/878ebf9717665157 exited 0: WARNING: Extractor.execute failed to run external extractor 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'': [Errno 2] No such file or directory: 'cramfsswap', 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
