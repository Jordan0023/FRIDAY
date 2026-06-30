# Firmware Audit: WNR3500V1 / WNR3500_Firmware_Version_1.0.36__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500v1/WNR3500%20Firmware%20Version%201.0.36%20(North%20America).zip
- Local path: known_firmware/firmware/WNR3500V1/WNR3500_Firmware_Version_1.0.36__North_America_.zip
- SHA-256: `f57848dcb8fd031979d6912824242fc656e42fbff7e930d4c30c60f74aaf3209`
- Size: 4083876 bytes
- Version: 0.36__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f57848dcb8fd0319 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/f57848dcb8fd0319/_WNR3500_Firmware_Version_1.0.36__North_America_.zip.extracted/_WNR3500-V1.0.36_8.0.36NA.chk.extracted/squashfs-root/etc/wsc/hostapd.eap_user -> /tmp/wsc/hostapd.eap_user; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
