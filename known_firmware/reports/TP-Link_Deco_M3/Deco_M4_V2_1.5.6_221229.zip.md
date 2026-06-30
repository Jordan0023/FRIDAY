# Firmware Audit: TP-Link Deco M3 / Deco_M4_V2_1.5.6_221229.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202302/20230201/Deco_M4_V2_1.5.6_221229.zip
- Local path: known_firmware/firmware/TP-Link_Deco_M3/Deco_M4_V2_1.5.6_221229.zip
- SHA-256: `e67b063b1edc69f59fe12a57d66a39ad274eaf4042f8ee26420857e78481e83c`
- Size: 12489538 bytes
- Version: V2_1.5.6 Build 20221229
- Release date: 2023-02-01

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e67b063b1edc69f5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e67b063b1edc69f5/_Deco_M4_V2_1.5.6_221229.zip.extracted/_M4R 2.0_en_1.5.6 Build 20221229 Rel. 72252_US_EU_AU_JP_EG_up.bin.extracted/squashfs-root/usr/sbin/rmmod -> /usr/sbin/kmodloader; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
