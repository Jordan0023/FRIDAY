# Firmware Audit: OpenWrt Edgecore EAP111 / openwrt-25.12.5-mediatek-filogic-edgecore_eap111-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-edgecore_eap111-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Edgecore_EAP111/openwrt-25.12.5-mediatek-filogic-edgecore_eap111-squashfs-sysupgrade.bin
- SHA-256: `5783498288f202801d9d588b9859aa5130234dc4dc577f357d549f50c75c6669`
- Size: 9390350 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5783498288f20280 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5783498288f20280/_openwrt-25.12.5-mediatek-filogic-edgecore_eap111-squashfs-sysupgrade.bin.extracted/sysupgrade-edgecore_eap111/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
