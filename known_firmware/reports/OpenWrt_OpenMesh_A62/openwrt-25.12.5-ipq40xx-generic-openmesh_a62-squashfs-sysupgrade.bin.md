# Firmware Audit: OpenWrt OpenMesh A62 / openwrt-25.12.5-ipq40xx-generic-openmesh_a62-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-openmesh_a62-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_OpenMesh_A62/openwrt-25.12.5-ipq40xx-generic-openmesh_a62-squashfs-sysupgrade.bin
- SHA-256: `9b4cc4ecc7b1428f00d50ec703917ede1bd3b40af1713915502ecec73a67d973`
- Size: 8725023 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9b4cc4ecc7b1428f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9b4cc4ecc7b1428f/_openwrt-25.12.5-ipq40xx-generic-openmesh_a62-squashfs-sysupgrade.bin.extracted/sysupgrade-openmesh_a62/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
