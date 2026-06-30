# Firmware Audit: ASUS RT-AC66U B1 / RT-AC66U_B1_3.0.0.4_385_20433-g3f7796b.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-AC66U_B1/RT-AC66U_B1_3.0.0.4_385_20433-g3f7796b.zip
- Local path: known_firmware/firmware/ASUS_RT-AC66U_B1/RT-AC66U_B1_3.0.0.4_385_20433-g3f7796b.zip
- SHA-256: `8b8c057bbcdf012fb053338a3dd957ec72b9c83fef62ef0f84215b7cd1f34af4`
- Size: 38531290 bytes
- Version: 3.0.0.4.385.20433
- Release date: 2020/04/14

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, bOA, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8b8c057bbcdf012f exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/8b8c057bbcdf012f/_RT-AC66U_B1_3.0.0.4_385_20433-g3f7796b.zip.extracted/_RT-AC66U_B1_3.0.0.4_385_20433-g3f7796b.trx.extracted/squashfs-root/usr/share/share -> /tmp/share; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
