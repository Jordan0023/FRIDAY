# Firmware Audit: TP-Link Deco M3 / Deco_M4_V2_1.5.4_220113.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202202/20220214/Deco_M4_V2_1.5.4_220113.zip
- Local path: known_firmware/firmware/TP-Link_Deco_M3/Deco_M4_V2_1.5.4_220113.zip
- SHA-256: `4b1ca88faccd2b39952a8eaf8b0bae0e145c8bd9944ff3a625df1c8159e2c55d`
- Size: 12510670 bytes
- Version: V2_1.5.4
- Release date: 2022-02-14

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4b1ca88faccd2b39 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/4b1ca88faccd2b39/_Deco_M4_V2_1.5.4_220113.zip.extracted/_M4R 2.0_en_1.5.4 Build 20220113 Rel. 38349_US_EU_AU_JP_up.bin.extracted/squashfs-root/usr/sbin/rmmod -> /usr/sbin/kmodloader; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
