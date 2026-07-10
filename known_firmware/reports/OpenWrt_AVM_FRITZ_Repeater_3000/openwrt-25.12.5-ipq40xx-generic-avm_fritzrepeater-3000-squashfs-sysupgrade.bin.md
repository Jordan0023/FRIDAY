# Firmware Audit: OpenWrt AVM FRITZ!Repeater 3000 / openwrt-25.12.5-ipq40xx-generic-avm_fritzrepeater-3000-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-avm_fritzrepeater-3000-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_AVM_FRITZ_Repeater_3000/openwrt-25.12.5-ipq40xx-generic-avm_fritzrepeater-3000-squashfs-sysupgrade.bin
- SHA-256: `323080ccb13eecb1322fac5f46734ebd44998f75b2bad2b989791d0db321c4d8`
- Size: 8632893 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/323080ccb13eecb1 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/323080ccb13eecb1/_openwrt-25.12.5-ipq40xx-generic-avm_fritzrepeater-3000-squashfs-sysupgrade.bin.extracted/sysupgrade-avm_fritzrepeater-3000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
