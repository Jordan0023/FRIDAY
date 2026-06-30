# Firmware Audit: ASUS DSL-N12HP / FW_DSL_N12HP_10016.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12HP/FW_DSL_N12HP_10016.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12HP/FW_DSL_N12HP_10016.zip
- SHA-256: `9fe114405176f5bdf895a21a028fa443339da9a2b859e7fb1d208482e5453792`
- Size: 7672977 bytes
- Version: 1.0.0.16
- Release date: 2016/10/14

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

- binwalk -eM --directory known_firmware/extracted/9fe114405176f5bd exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
