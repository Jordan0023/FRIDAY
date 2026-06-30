# Firmware Audit: ASUS WL-500gP V2 / FW_WL500gpv2_3042_TW.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-500gPV2/FW_WL500gpv2_3042_TW.zip
- Local path: known_firmware/firmware/ASUS_WL-500gP_V2/FW_WL500gpv2_3042_TW.zip
- SHA-256: `1cf7b9c1f058857e0ce73704d4edf7ba001bbbbd52786618f87d85c029b3a439`
- Size: 6934793 bytes
- Version: 3.0.4.2
- Release date: 2009/08/21

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `/bin/sh, SYSTEM, System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1cf7b9c1f058857e exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/1cf7b9c1f058857e/_FW_WL500gpv2_3042_TW.zip.extracted/_WL500gpv2_3.0.4.2_TW.trx.extracted/squashfs-root/usr/local/samba/lib/lowcase.dat -> /tmp/lowcase.dat; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
