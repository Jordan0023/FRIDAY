# Firmware Audit: ASUS RT-N13 / FW_RT_N13_2019_beta_RU.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N13/FW_RT_N13_2019_beta_RU.zip
- Local path: known_firmware/firmware/ASUS_RT-N13/FW_RT_N13_2019_beta_RU.zip
- SHA-256: `dd2b8cb7a9a93eb58b385058798b1d7f9e089d977e3b1c610b575403acdbb405`
- Size: 3284811 bytes
- Version: 2.0.1.9_beta
- Release date: 2009/12/15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dd2b8cb7a9a93eb5 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/dd2b8cb7a9a93eb5/_FW_RT_N13_2019_beta_RU.zip.extracted/_RT-N13_2.0.1.9_beta_RU.trx.extracted/_40.extracted/_ramdisk.extracted/squashfs-root/www/Settings.CFG -> /tmp/settings; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
