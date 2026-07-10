# Firmware Audit: OpenWrt OpenMesh A42 / openwrt-25.12.5-ipq40xx-generic-openmesh_a42-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-openmesh_a42-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_OpenMesh_A42/openwrt-25.12.5-ipq40xx-generic-openmesh_a42-squashfs-sysupgrade.bin
- SHA-256: `3ab5761f07aca49f9b1e35047c97a0119ab6f1680ae3af193eb334c75d407843`
- Size: 8264223 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3ab5761f07aca49f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3ab5761f07aca49f/_openwrt-25.12.5-ipq40xx-generic-openmesh_a42-squashfs-sysupgrade.bin.extracted/sysupgrade-openmesh_a42/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
