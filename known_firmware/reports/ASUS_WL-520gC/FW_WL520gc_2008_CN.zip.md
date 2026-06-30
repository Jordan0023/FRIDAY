# Firmware Audit: ASUS WL-520gC / FW_WL520gc_2008_CN.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GC/FW_WL520gc_2008_CN.zip
- Local path: known_firmware/firmware/ASUS_WL-520gC/FW_WL520gc_2008_CN.zip
- SHA-256: `4cce770592ff5b488a2e505c4b0c736e3d0c8143fc01666834363b2f58d99b39`
- Size: 1887268 bytes
- Version: 2.0.0.8
- Release date: 2008/01/22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4cce770592ff5b48 exited 0: WARNING: Extractor.execute failed to run external extractor 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'': [Errno 2] No such file or directory: 'cramfsswap', 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
