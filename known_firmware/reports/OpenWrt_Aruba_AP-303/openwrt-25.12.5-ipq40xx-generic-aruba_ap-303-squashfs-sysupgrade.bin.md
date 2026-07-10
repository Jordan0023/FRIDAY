# Firmware Audit: OpenWrt Aruba AP-303 / openwrt-25.12.5-ipq40xx-generic-aruba_ap-303-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-aruba_ap-303-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Aruba_AP-303/openwrt-25.12.5-ipq40xx-generic-aruba_ap-303-squashfs-sysupgrade.bin
- SHA-256: `6f41c0367ecdf97af1fe168c488ae4654cf4613fece905bf68010c06279e95fd`
- Size: 8192543 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6f41c0367ecdf97a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6f41c0367ecdf97a/_openwrt-25.12.5-ipq40xx-generic-aruba_ap-303-squashfs-sysupgrade.bin.extracted/sysupgrade-aruba_ap-303/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
