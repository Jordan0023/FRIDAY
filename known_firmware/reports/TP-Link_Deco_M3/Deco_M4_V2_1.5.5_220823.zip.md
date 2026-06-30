# Firmware Audit: TP-Link Deco M3 / Deco_M4_V2_1.5.5_220823.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202209/20220915/Deco_M4_V2_1.5.5_220823.zip
- Local path: known_firmware/firmware/TP-Link_Deco_M3/Deco_M4_V2_1.5.5_220823.zip
- SHA-256: `f31f651f636c67b62febb20a9f5ebf638b6bf33ee92ca49d63425f873059aba5`
- Size: 12467720 bytes
- Version: V2_1.5.5 Build 20220823
- Release date: 2022-09-15

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f31f651f636c67b6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f31f651f636c67b6/_Deco_M4_V2_1.5.5_220823.zip.extracted/_M4R 2.0_en_1.5.5 Build 20220823 Rel. 41353_EG_US_EU_AU_JP_up.bin.extracted/squashfs-root/usr/sbin/rmmod -> /usr/sbin/kmodloader; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
