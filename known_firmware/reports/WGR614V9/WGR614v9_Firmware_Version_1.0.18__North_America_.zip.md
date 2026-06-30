# Firmware Audit: WGR614V9 / WGR614v9_Firmware_Version_1.0.18__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V9/WGR614v9%20Firmware%20Version%201.0.18%20(North%20America).zip
- Local path: known_firmware/firmware/WGR614V9/WGR614v9_Firmware_Version_1.0.18__North_America_.zip
- SHA-256: `29e66e9e0cede6437a342ce865657a82878143f63f89d868e6949107869e9393`
- Size: 1901168 bytes
- Version: 0.18__North_America_
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

- binwalk -eM --directory known_firmware/extracted/29e66e9e0cede643 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/29e66e9e0cede643/_WGR614v9_Firmware_Version_1.0.18__North_America_.zip.extracted/_WGR614v9-V1.0.18_8.0.9NA.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
