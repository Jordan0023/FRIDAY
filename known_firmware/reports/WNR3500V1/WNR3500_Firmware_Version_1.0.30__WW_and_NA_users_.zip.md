# Firmware Audit: WNR3500V1 / WNR3500_Firmware_Version_1.0.30__WW_and_NA_users_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500v1/WNR3500%20Firmware%20Version%201.0.30%20(WW%20and%20NA%20users).zip
- Local path: known_firmware/firmware/WNR3500V1/WNR3500_Firmware_Version_1.0.30__WW_and_NA_users_.zip
- SHA-256: `73fe351c42845f3fa0e252b879f2e94c3ed8227ef942dbb11f288082c77d9c97`
- Size: 4095177 bytes
- Version: 0.30__WW_and_NA_users_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/73fe351c42845f3f exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/73fe351c42845f3f/_WNR3500_Firmware_Version_1.0.30__WW_and_NA_users_.zip.extracted/_WNR3500-V1.0.30_8.0.30.chk.extracted/squashfs-root/etc/wsc/hostapd.eap_user -> /tmp/wsc/hostapd.eap_user; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
