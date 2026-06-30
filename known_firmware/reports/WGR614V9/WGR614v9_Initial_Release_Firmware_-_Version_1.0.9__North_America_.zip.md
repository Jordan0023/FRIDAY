# Firmware Audit: WGR614V9 / WGR614v9_Initial_Release_Firmware_-_Version_1.0.9__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V9/WGR614v9%20Initial%20Release%20Firmware%20-%20Version%201.0.9%20(North%20America).zip
- Local path: known_firmware/firmware/WGR614V9/WGR614v9_Initial_Release_Firmware_-_Version_1.0.9__North_America_.zip
- SHA-256: `3be0b7b0b55e8e4fc4a130139d17994d99e864b5b6ec68be3d2c2ceb2247f323`
- Size: 1893580 bytes
- Version: 0.9__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3be0b7b0b55e8e4f exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/3be0b7b0b55e8e4f/_WGR614v9_Initial_Release_Firmware_-_Version_1.0.9__North_America_.zip.extracted/_wgr614v9_1_0_9_1_0_1_na.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
