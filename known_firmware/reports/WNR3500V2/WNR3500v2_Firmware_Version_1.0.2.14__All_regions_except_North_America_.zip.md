# Firmware Audit: WNR3500V2 / WNR3500v2_Firmware_Version_1.0.2.14__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500V2/WNR3500v2%20Firmware%20Version%201.0.2.14%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WNR3500V2/WNR3500v2_Firmware_Version_1.0.2.14__All_regions_except_North_America_.zip
- SHA-256: `95e7fcbd020061a404606045087c46b82130a7c4b7551e90b7cf82fdce56cbcf`
- Size: 3445107 bytes
- Version: 0.2.14__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWD`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/95e7fcbd020061a4 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/95e7fcbd020061a4/_WNR3500v2_Firmware_Version_1.0.2.14__All_regions_except_North_America_.zip.extracted/_WNR3500v2-V1.0.2.14_24.0.74.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
