# Firmware Audit: WNR3500LV1 / WNR3500L_Initial_Release_Firmware_Version_1.0.0.86__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500Lv1/WNR3500L%20Initial%20Release%20Firmware%20Version%201.0.0.86%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WNR3500LV1/WNR3500L_Initial_Release_Firmware_Version_1.0.0.86__All_regions_except_North_America_.zip
- SHA-256: `27c3caeb535e7975d0775481eb1a08bf87276b45a0931f3d4f834ba5a024774a`
- Size: 5423593 bytes
- Version: 0.0.86__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWD, password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/27c3caeb535e7975 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/27c3caeb535e7975/_WNR3500L_Initial_Release_Firmware_Version_1.0.0.86__All_regions_except_North_America_.zip.extracted/_WNR3500L-V1.0.0.86_13.0.75.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
