# Firmware Audit: WGT624V4 / WGT624v4_-_Firmware_Version_2.0.13_2.0.15.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGT624V4/WGT624v4%20-%20Firmware%20Version%202.0.13_2.0.15.zip
- Local path: known_firmware/firmware/WGT624V4/WGT624v4_-_Firmware_Version_2.0.13_2.0.15.zip
- SHA-256: `4c58d2fd211cb68ad08fc9be5f50ee94ba650b21516a9a44ec62932e4712b2c8`
- Size: 2605075 bytes
- Version: 0.13_2.0.15
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4c58d2fd211cb68a exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/4c58d2fd211cb68a/_WGT624v4_-_Firmware_Version_2.0.13_2.0.15.zip.extracted/_WGT624v4-V2.0.13_2.0.15NA.chk.extracted/squashfs-root/etc/wlan/wlanconfig.0 -> /tmp/wlanconfig.0; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
