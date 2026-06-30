# Firmware Audit: WNR3500V2 / WNR3500v2_Firmware_Version_1.0.2.10__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500V2/WNR3500v2%20Firmware%20Version%201.0.2.10%20(North%20America).zip
- Local path: known_firmware/firmware/WNR3500V2/WNR3500v2_Firmware_Version_1.0.2.10__North_America_.zip
- SHA-256: `3eed08e0647d5dc3e7cdb7e33306add740bbc6a7c19ee792319adc7f392ee25a`
- Size: 3418835 bytes
- Version: 0.2.10__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3eed08e0647d5dc3 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/3eed08e0647d5dc3/_WNR3500v2_Firmware_Version_1.0.2.10__North_America_.zip.extracted/_WNR3500v2-V1.0.2.10_23.0.70NA.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
