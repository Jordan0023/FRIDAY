# Firmware Audit: WNR3500LV1 / WNR3500L_Firmware_Version_1.0.2.50__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500Lv1/WNR3500L%20Firmware%20Version%201.0.2.50%20(North%20America).zip
- Local path: known_firmware/firmware/WNR3500LV1/WNR3500L_Firmware_Version_1.0.2.50__North_America_.zip
- SHA-256: `9cec15c28ad4f4a66c0d08efbc21971c992e0b623306451c9378bf275a5aef86`
- Size: 5269197 bytes
- Version: 0.2.50__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWD, password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9cec15c28ad4f4a6 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/9cec15c28ad4f4a6/_WNR3500L_Firmware_Version_1.0.2.50__North_America_.zip.extracted/_WNR3500L-V1.0.2.50_31.1.25NA.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
