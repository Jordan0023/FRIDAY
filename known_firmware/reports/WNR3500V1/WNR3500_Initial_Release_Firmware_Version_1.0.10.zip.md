# Firmware Audit: WNR3500V1 / WNR3500_Initial_Release_Firmware_Version_1.0.10.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500v1/WNR3500%20Initial%20Release%20Firmware%20Version%201.0.10.zip
- Local path: known_firmware/firmware/WNR3500V1/WNR3500_Initial_Release_Firmware_Version_1.0.10.zip
- SHA-256: `fba13e515efb8c76575f9078773d6b56b0a35e83603e10c85cacc7f647a9871a`
- Size: 3859161 bytes
- Version: 0.10
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

- binwalk -eM --directory known_firmware/extracted/fba13e515efb8c76 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/fba13e515efb8c76/_WNR3500_Initial_Release_Firmware_Version_1.0.10.zip.extracted/_wnr3500_1_0_10_1_0_10_na.chk.extracted/squashfs-root/etc/wsc/hostapd.eap_user -> /tmp/wsc/hostapd.eap_user; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
