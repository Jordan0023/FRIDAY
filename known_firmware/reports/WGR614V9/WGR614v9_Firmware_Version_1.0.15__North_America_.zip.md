# Firmware Audit: WGR614V9 / WGR614v9_Firmware_Version_1.0.15__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V9/WGR614v9%20Firmware%20Version%201.0.15%20(North%20America).zip
- Local path: known_firmware/firmware/WGR614V9/WGR614v9_Firmware_Version_1.0.15__North_America_.zip
- SHA-256: `64e2222b85d4a148041db4072938b974b8d3b1f1aa180dcf8b310f83156f2581`
- Size: 1914136 bytes
- Version: 0.15__North_America_
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

- binwalk -eM --directory known_firmware/extracted/64e2222b85d4a148 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/64e2222b85d4a148/_WGR614v9_Firmware_Version_1.0.15__North_America_.zip.extracted/_wgr614v9_1_0_15_4_0_3_na_only.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
