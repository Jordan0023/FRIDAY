# Firmware Audit: WNR3500LV1 / WNR3500L_Firmware_Version_1.0.2.26__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500Lv1/WNR3500L%20Firmware%20Version%201.0.2.26%20(North%20America).zip
- Local path: known_firmware/firmware/WNR3500LV1/WNR3500L_Firmware_Version_1.0.2.26__North_America_.zip
- SHA-256: `805b2bd7ffc140a5f71de68846aa60858b050fa6077db9810154fc62fb8e9c81`
- Size: 5252378 bytes
- Version: 0.2.26__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWD, password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/805b2bd7ffc140a5 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/805b2bd7ffc140a5/_WNR3500L_Firmware_Version_1.0.2.26__North_America_.zip.extracted/_WNR3500L-V1.0.2.26_30.0.98NA.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
