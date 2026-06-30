# Firmware Audit: WNR3500V1 / WNR3500_Firmware_Version_1.0.22__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500v1/WNR3500%20Firmware%20Version%201.0.22%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WNR3500V1/WNR3500_Firmware_Version_1.0.22__All_regions_except_North_America_.zip
- SHA-256: `3c0d595a1170b728c90aa87551880e171da88514c8c982371993a538b3e526e0`
- Size: 4067775 bytes
- Version: 0.22__All_regions_except_North_America_
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

- binwalk -eM --directory known_firmware/extracted/3c0d595a1170b728 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/3c0d595a1170b728/_WNR3500_Firmware_Version_1.0.22__All_regions_except_North_America_.zip.extracted/_WNR3500-V1.0.22_6.0.22.chk.extracted/squashfs-root/etc/wsc/hostapd.eap_user -> /tmp/wsc/hostapd.eap_user; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
