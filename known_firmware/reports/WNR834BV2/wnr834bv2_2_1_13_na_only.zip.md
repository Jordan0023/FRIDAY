# Firmware Audit: WNR834BV2 / wnr834bv2_2_1_13_na_only.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR834BV2/wnr834bv2_2_1_13_na_only.zip
- Local path: known_firmware/firmware/WNR834BV2/wnr834bv2_2_1_13_na_only.zip
- SHA-256: `d0b67ab104e3762ddce71e3d8f3e6e86f2769fa383e8c05bbf3e903968cb4c9c`
- Size: 3522206 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d0b67ab104e3762d exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/d0b67ab104e3762d/_wnr834bv2_2_1_13_na_only.zip.extracted/wnr834bv2_2_1_13_na_only/_wnr834bv2_2_1_13_na_only.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
