# Firmware Audit: ASUS RT-AC51U / FW_RT-AC51U_3.0.0.4_380_8539.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-AC51U/FW_RT-AC51U_3.0.0.4_380_8539.zip
- Local path: known_firmware/firmware/ASUS_RT-AC51U/FW_RT-AC51U_3.0.0.4_380_8539.zip
- SHA-256: `10ab117cf76c5c4eb0a10505ee9a32c99ba58d1e1a3c3523ba052bf46ff5e3d1`
- Size: 14758166 bytes
- Version: 3.0.0.4.380.8539
- Release date: 2019/11/06

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/10ab117cf76c5c4e exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/10ab117cf76c5c4e/_FW_RT-AC51U_3.0.0.4_380_8539.zip.extracted/_RT-AC51U_3.0.0.4_380_8539-gea47e5f.trx.extracted/squashfs-root/usr/local/share -> /tmp/share; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
