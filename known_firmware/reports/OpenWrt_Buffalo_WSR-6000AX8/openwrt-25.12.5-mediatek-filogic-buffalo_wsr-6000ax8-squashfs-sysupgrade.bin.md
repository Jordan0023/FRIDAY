# Firmware Audit: OpenWrt Buffalo WSR-6000AX8 / openwrt-25.12.5-mediatek-filogic-buffalo_wsr-6000ax8-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-buffalo_wsr-6000ax8-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Buffalo_WSR-6000AX8/openwrt-25.12.5-mediatek-filogic-buffalo_wsr-6000ax8-squashfs-sysupgrade.bin
- SHA-256: `5a1b7864c9ad58635fcf031b5673dbe66130c118a55a346913e4204bbdb985e9`
- Size: 9881878 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5a1b7864c9ad5863 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5a1b7864c9ad5863/_openwrt-25.12.5-mediatek-filogic-buffalo_wsr-6000ax8-squashfs-sysupgrade.bin.extracted/sysupgrade-buffalo_wsr-6000ax8/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
