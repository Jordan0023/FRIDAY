# Firmware Audit: WN3100RPV2 / WN3100RPv2-FW_V1.0.0.14.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WN3100RPv2/WN3100RPv2-FW_V1.0.0.14.zip
- Local path: known_firmware/firmware/WN3100RPV2/WN3100RPv2-FW_V1.0.0.14.zip
- SHA-256: `88d257e98511dbc84cb6025561918d735b6a75b2b6893d142571f6bd2cf7c038`
- Size: 3570865 bytes
- Version: 0.0.14
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `passwd, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/88d257e98511dbc8 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/88d257e98511dbc8/_WN3100RPv2-FW_V1.0.0.14.zip.extracted/_WN3100RPv2-V1.0.0.14.img.extracted/squashfs-root/etc/fstab -> /tmp/fstab; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
