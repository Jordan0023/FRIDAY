# Firmware Audit: OpenWrt AVM FRITZ!Repeater 1200 / openwrt-25.12.5-ipq40xx-generic-avm_fritzrepeater-1200-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-avm_fritzrepeater-1200-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_AVM_FRITZ_Repeater_1200/openwrt-25.12.5-ipq40xx-generic-avm_fritzrepeater-1200-squashfs-sysupgrade.bin
- SHA-256: `7cbd8a6bbfb7d0a00686b9f0d30357a757fc157780176e1c727a58605a338842`
- Size: 8182333 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7cbd8a6bbfb7d0a0 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7cbd8a6bbfb7d0a0/_openwrt-25.12.5-ipq40xx-generic-avm_fritzrepeater-1200-squashfs-sysupgrade.bin.extracted/sysupgrade-avm_fritzrepeater-1200/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
