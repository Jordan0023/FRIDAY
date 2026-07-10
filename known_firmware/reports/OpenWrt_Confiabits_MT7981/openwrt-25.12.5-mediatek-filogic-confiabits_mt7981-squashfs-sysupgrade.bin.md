# Firmware Audit: OpenWrt Confiabits MT7981 / openwrt-25.12.5-mediatek-filogic-confiabits_mt7981-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-confiabits_mt7981-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Confiabits_MT7981/openwrt-25.12.5-mediatek-filogic-confiabits_mt7981-squashfs-sysupgrade.bin
- SHA-256: `2228cdac38a7bf5634e382797f97545469acc8369f4d5adfa1f4b3bcf49ea002`
- Size: 9554241 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2228cdac38a7bf56 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2228cdac38a7bf56/_openwrt-25.12.5-mediatek-filogic-confiabits_mt7981-squashfs-sysupgrade.bin.extracted/sysupgrade-confiabits_mt7981/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
