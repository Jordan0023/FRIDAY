# Firmware Audit: ASUS WL-500gP V2 / FW_WL500gpv2_3038_TW.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-500gPV2/FW_WL500gpv2_3038_TW.zip
- Local path: known_firmware/firmware/ASUS_WL-500gP_V2/FW_WL500gpv2_3038_TW.zip
- SHA-256: `6e5e1a65990cbc47d564c03ccc1f67febc54213ba08c71b7a4ef73812269d678`
- Size: 7050426 bytes
- Version: 3.0.3.8
- Release date: 2009/05/11

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

- binwalk -eM --directory known_firmware/extracted/6e5e1a65990cbc47 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/6e5e1a65990cbc47/_FW_WL500gpv2_3038_TW.zip.extracted/_WL500gpv2_3.0.3.8_TW.trx.extracted/squashfs-root/usr/local/samba/lib/lowcase.dat -> /tmp/lowcase.dat; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
