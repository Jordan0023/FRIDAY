# Firmware Audit: WNR3500V1 / WNR3500_Firmware_Version_1.0.29__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500v1/WNR3500%20Firmware%20Version%201.0.29%20(North%20America).zip
- Local path: known_firmware/firmware/WNR3500V1/WNR3500_Firmware_Version_1.0.29__North_America_.zip
- SHA-256: `16a3564b9a1d26c6e768d4c259894a6ec8696df89f8f65219f7a07bf8765fd4a`
- Size: 4092368 bytes
- Version: 0.29__North_America_
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

- binwalk -eM --directory known_firmware/extracted/16a3564b9a1d26c6 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/16a3564b9a1d26c6/_WNR3500_Firmware_Version_1.0.29__North_America_.zip.extracted/_WNR3500-V1.0.29_8.0.29NA.chk.extracted/squashfs-root/etc/wsc/hostapd.eap_user -> /tmp/wsc/hostapd.eap_user; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
