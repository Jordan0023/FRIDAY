# Firmware Audit: TP-Link Deco P9 / Deco_P9_1.1.5_20231229.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202402/20240205/Deco_P9_1.1.5_20231229.zip
- Local path: known_firmware/firmware/TP-Link_Deco_P9/Deco_P9_1.1.5_20231229.zip
- SHA-256: `7c23c7a36b083377a767eaf3f1017d97d436899c86bbe72abbecb6ae94073c89`
- Size: 12555330 bytes
- Version: V2.6_1.1.5 Build 20231229
- Release date: 2024-02-05

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7c23c7a36b083377 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7c23c7a36b083377/_Deco_P9_1.1.5_20231229.zip.extracted/_P9 2.0_en_1.1.5 Build 20231229 Rel. 36756_US_EU_AU_JP_up.bin.extracted/squashfs-root/usr/sbin/rmmod -> /usr/sbin/kmodloader; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
