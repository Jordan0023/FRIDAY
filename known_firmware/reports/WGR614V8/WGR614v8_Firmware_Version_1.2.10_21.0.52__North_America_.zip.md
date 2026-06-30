# Firmware Audit: WGR614V8 / WGR614v8_Firmware_Version_1.2.10_21.0.52__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V8/WGR614v8%20Firmware%20Version%201.2.10_21.0.52%20(North%20America).zip
- Local path: known_firmware/firmware/WGR614V8/WGR614v8_Firmware_Version_1.2.10_21.0.52__North_America_.zip
- SHA-256: `68f5dd7fb714f78fe93d7e78b81f36078dd0e69d980dc20252ec5307e3b003b7`
- Size: 3561646 bytes
- Version: 2.10_21.0.52__North_America_
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

- binwalk -eM --directory known_firmware/extracted/68f5dd7fb714f78f exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/68f5dd7fb714f78f/_WGR614v8_Firmware_Version_1.2.10_21.0.52__North_America_.zip.extracted/_WGR614v8-V1.2.10_21.0.52NA.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
