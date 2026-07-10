# Firmware Audit: OpenWrt TP-Link RE6000XD / openwrt-25.12.5-mediatek-filogic-tplink_re6000xd-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-tplink_re6000xd-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_RE6000XD/openwrt-25.12.5-mediatek-filogic-tplink_re6000xd-squashfs-sysupgrade.bin
- SHA-256: `73abc2e7936f5e3a3ae445e03f1f7231b7edce168805e24f5c06acef8138438a`
- Size: 9881870 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/73abc2e7936f5e3a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/73abc2e7936f5e3a/_openwrt-25.12.5-mediatek-filogic-tplink_re6000xd-squashfs-sysupgrade.bin.extracted/sysupgrade-tplink_re6000xd/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
