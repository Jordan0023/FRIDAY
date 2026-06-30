# Firmware Audit: WNR2000V2 / WNR2000v2_Firmware_Version_1.0.0.35_29.0.47__WW_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000V2/WNR2000v2%20Firmware%20Version%201.0.0.35_29.0.47%20(WW).zip
- Local path: known_firmware/firmware/WNR2000V2/WNR2000v2_Firmware_Version_1.0.0.35_29.0.47__WW_.zip
- SHA-256: `ebc38bba20f5e1d6a8e7ee8f4e3b66db25593cbed26eb60db421022d7be86f72`
- Size: 3433048 bytes
- Version: 0.0.35_29.0.47__WW_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWD, password`

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

- binwalk -eM --directory known_firmware/extracted/ebc38bba20f5e1d6 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/ebc38bba20f5e1d6/_WNR2000v2_Firmware_Version_1.0.0.35_29.0.47__WW_.zip.extracted/WNR2000v2 Firmware Version 1.0.0.35_29.0.47 (WW)/_WNR2000v2-V1.0.0.35_29.0.47.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
