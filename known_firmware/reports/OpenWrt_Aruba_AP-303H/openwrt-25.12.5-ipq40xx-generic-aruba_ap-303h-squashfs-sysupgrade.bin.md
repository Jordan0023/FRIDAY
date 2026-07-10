# Firmware Audit: OpenWrt Aruba AP-303H / openwrt-25.12.5-ipq40xx-generic-aruba_ap-303h-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-aruba_ap-303h-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Aruba_AP-303H/openwrt-25.12.5-ipq40xx-generic-aruba_ap-303h-squashfs-sysupgrade.bin
- SHA-256: `9a2bd78624ffa661f971bbe4213debec24673739e3be3fbb32de0359b0419e7f`
- Size: 8192546 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9a2bd78624ffa661 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9a2bd78624ffa661/_openwrt-25.12.5-ipq40xx-generic-aruba_ap-303h-squashfs-sysupgrade.bin.extracted/sysupgrade-aruba_ap-303h/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
