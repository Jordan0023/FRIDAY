# Firmware Audit: OpenWrt Crisis Innovation Lab MeshPoint.One / openwrt-25.12.5-ipq40xx-generic-cilab_meshpoint-one-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-cilab_meshpoint-one-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Crisis_Innovation_Lab_MeshPoint.One/openwrt-25.12.5-ipq40xx-generic-cilab_meshpoint-one-squashfs-sysupgrade.bin
- SHA-256: `31e172cfa5102b9c5dfc79f54ea6a9f03cd256af4bc352850e0610bbfd3ee788`
- Size: 9554484 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/31e172cfa5102b9c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/31e172cfa5102b9c/_openwrt-25.12.5-ipq40xx-generic-cilab_meshpoint-one-squashfs-sysupgrade.bin.extracted/sysupgrade-cilab_meshpoint-one/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
