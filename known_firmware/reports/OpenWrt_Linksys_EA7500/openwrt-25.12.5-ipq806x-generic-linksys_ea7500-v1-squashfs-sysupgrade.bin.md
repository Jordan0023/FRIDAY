# Firmware Audit: OpenWrt Linksys EA7500 / openwrt-25.12.5-ipq806x-generic-linksys_ea7500-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-linksys_ea7500-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_EA7500/openwrt-25.12.5-ipq806x-generic-linksys_ea7500-v1-squashfs-sysupgrade.bin
- SHA-256: `fce82a513c4804983106f29868ca108139785b8a6364f2adaca8d70cf8ac0f8c`
- Size: 8202798 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fce82a513c480498 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fce82a513c480498/_openwrt-25.12.5-ipq806x-generic-linksys_ea7500-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_ea7500-v1/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
