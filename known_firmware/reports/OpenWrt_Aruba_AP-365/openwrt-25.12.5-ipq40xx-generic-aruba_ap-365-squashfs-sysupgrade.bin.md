# Firmware Audit: OpenWrt Aruba AP-365 / openwrt-25.12.5-ipq40xx-generic-aruba_ap-365-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-aruba_ap-365-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Aruba_AP-365/openwrt-25.12.5-ipq40xx-generic-aruba_ap-365-squashfs-sysupgrade.bin
- SHA-256: `33a874309399e7d5cb74b74dc947a00963c8b6f1ba6d493caca25a6b28a39555`
- Size: 8192543 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/33a874309399e7d5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/33a874309399e7d5/_openwrt-25.12.5-ipq40xx-generic-aruba_ap-365-squashfs-sysupgrade.bin.extracted/sysupgrade-aruba_ap-365/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
