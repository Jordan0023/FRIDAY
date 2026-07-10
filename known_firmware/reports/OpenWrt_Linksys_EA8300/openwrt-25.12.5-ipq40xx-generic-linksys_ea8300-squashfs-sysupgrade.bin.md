# Firmware Audit: OpenWrt Linksys EA8300 / openwrt-25.12.5-ipq40xx-generic-linksys_ea8300-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-linksys_ea8300-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_EA8300/openwrt-25.12.5-ipq40xx-generic-linksys_ea8300-squashfs-sysupgrade.bin
- SHA-256: `5abf63136ac45c1ad620ac6c45c7c1e65098501c575b573bdd67ff36885bb328`
- Size: 8449375 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5abf63136ac45c1a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5abf63136ac45c1a/_openwrt-25.12.5-ipq40xx-generic-linksys_ea8300-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_ea8300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
