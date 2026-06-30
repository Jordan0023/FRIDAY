# Firmware Audit: ASUS WL-500gP V2 / FW_WL500gpv2_3044_TW.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-500gPV2/FW_WL500gpv2_3044_TW.zip
- Local path: known_firmware/firmware/ASUS_WL-500gP_V2/FW_WL500gpv2_3044_TW.zip
- SHA-256: `eeae5a79fb7c2752f7b8259300e12fdd43d9ac5d4e77aa34a7052d5e6df76d02`
- Size: 6811325 bytes
- Version: 3.0.4.4
- Release date: 2010/03/23

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `/bin/sh, SYSTEM, System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/eeae5a79fb7c2752 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/eeae5a79fb7c2752/_FW_WL500gpv2_3044_TW.zip.extracted/_WL500gpv2_3.0.4.4_TW.trx.extracted/squashfs-root/usr/local/samba/lib/lowcase.dat -> /tmp/lowcase.dat; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
