# Firmware Audit: ASUS WL-520gC / FW_WL520gc_2008_TW.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GC/FW_WL520gc_2008_TW.zip
- Local path: known_firmware/firmware/ASUS_WL-520gC/FW_WL520gc_2008_TW.zip
- SHA-256: `33c46554fbff0a3192fa463373d34979a85434d07b7dda82c27e6a39b55b2e9d`
- Size: 1872480 bytes
- Version: 2.0.0.8
- Release date: 2008/01/22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/33c46554fbff0a31 exited 0: WARNING: Extractor.execute failed to run external extractor 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'': [Errno 2] No such file or directory: 'cramfsswap', 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
