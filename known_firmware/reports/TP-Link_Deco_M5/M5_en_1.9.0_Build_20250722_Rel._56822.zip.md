# Firmware Audit: TP-Link Deco M5 / M5_en_1.9.0_Build_20250722_Rel._56822.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202509/20250911/M5 en_1.9.0 Build 20250722 Rel. 56822.zip
- Local path: known_firmware/firmware/TP-Link_Deco_M5/M5_en_1.9.0_Build_20250722_Rel._56822.zip
- SHA-256: `9133fdeacb472378a7c648d621991f2c70c3587c10a505e8c377cb1c497283b4`
- Size: 16593618 bytes
- Version: V3.80_1.9.0 Build 20250722
- Release date: 2025-09-11

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `pWD`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9133fdeacb472378 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9133fdeacb472378/_M5_en_1.9.0_Build_20250722_Rel._56822.zip.extracted/M5 en_1.9.0 Build 20250722 Rel. 56822/_M5 en_1.9.0 Build 20250722 Rel. 56822_US_EU_JP_AU_CA_TW_B4_ID_UK_SW_EG_up.bin.extracted/squashfs-root-0/usr/sbin/rmmod -> /usr/sbin/kmodloader; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
