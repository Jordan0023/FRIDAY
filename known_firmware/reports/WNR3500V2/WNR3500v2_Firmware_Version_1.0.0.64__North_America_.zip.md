# Firmware Audit: WNR3500V2 / WNR3500v2_Firmware_Version_1.0.0.64__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500V2/WNR3500v2%20Firmware%20Version%201.0.0.64%20(North%20America).zip
- Local path: known_firmware/firmware/WNR3500V2/WNR3500v2_Firmware_Version_1.0.0.64__North_America_.zip
- SHA-256: `01eef982fb194cb7e5f113b507d0e878e7abb197c91342bdd789336031d0d596`
- Size: 3286836 bytes
- Version: 0.0.64__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWD, password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/01eef982fb194cb7 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/01eef982fb194cb7/_WNR3500v2_Firmware_Version_1.0.0.64__North_America_.zip.extracted/_WNR3500v2-V1.0.0.64_11.0.51NA.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
