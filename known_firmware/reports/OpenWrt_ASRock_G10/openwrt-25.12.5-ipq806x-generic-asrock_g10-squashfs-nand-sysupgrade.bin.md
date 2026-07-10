# Firmware Audit: OpenWrt ASRock G10 / openwrt-25.12.5-ipq806x-generic-asrock_g10-squashfs-nand-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-asrock_g10-squashfs-nand-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASRock_G10/openwrt-25.12.5-ipq806x-generic-asrock_g10-squashfs-nand-sysupgrade.bin
- SHA-256: `58ab3678cb8393e8547726e5b06c7cf00315316938e64c9b90a9f63e43ed8374`
- Size: 9728537 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/58ab3678cb8393e8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/58ab3678cb8393e8/_openwrt-25.12.5-ipq806x-generic-asrock_g10-squashfs-nand-sysupgrade.bin.extracted/sysupgrade-asrock_g10/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
