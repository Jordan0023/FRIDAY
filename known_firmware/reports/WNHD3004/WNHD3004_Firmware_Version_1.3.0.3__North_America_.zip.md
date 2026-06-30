# Firmware Audit: WNHD3004 / WNHD3004_Firmware_Version_1.3.0.3__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNHD3004/WNHD3004%20Firmware%20Version%201.3.0.3%20(North%20America).zip
- Local path: known_firmware/firmware/WNHD3004/WNHD3004_Firmware_Version_1.3.0.3__North_America_.zip
- SHA-256: `c680d9ce8e94f434e97e94cf9ec1e460670decec3d8be3ac174949e0b09a7005`
- Size: 4419131 bytes
- Version: 3.0.3__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

### Outdated crypto/library markers

Old OpenSSL/BusyBox versions may contain known CVEs and should be mapped to package versions.

Evidence: `BusyBox v1.10, OpenSSL 0.`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c680d9ce8e94f434 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/c680d9ce8e94f434/_WNHD3004_Firmware_Version_1.3.0.3__North_America_.zip.extracted/_WNHD3004_V1.3.0.3NA.bin.extracted/squashfs-root/www_sta/md5 -> /etc/md5; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
