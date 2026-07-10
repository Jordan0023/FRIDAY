# Firmware Audit: OpenWrt ipTIME AX7800M-6E / openwrt-25.12.5-mediatek-filogic-iptime_ax7800m-6e-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-iptime_ax7800m-6e-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ipTIME_AX7800M-6E/openwrt-25.12.5-mediatek-filogic-iptime_ax7800m-6e-squashfs-sysupgrade.bin
- SHA-256: `cfd42af760bb753e71d3983c7b73ce3540876843aedac00842d8c0e8017c127e`
- Size: 10629394 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cfd42af760bb753e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/cfd42af760bb753e/_openwrt-25.12.5-mediatek-filogic-iptime_ax7800m-6e-squashfs-sysupgrade.bin.extracted/sysupgrade-iptime_ax7800m-6e/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
