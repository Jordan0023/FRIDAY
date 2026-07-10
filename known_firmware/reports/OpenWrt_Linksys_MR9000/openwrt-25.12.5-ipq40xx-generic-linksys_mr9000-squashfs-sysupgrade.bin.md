# Firmware Audit: OpenWrt Linksys MR9000 / openwrt-25.12.5-ipq40xx-generic-linksys_mr9000-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-linksys_mr9000-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_MR9000/openwrt-25.12.5-ipq40xx-generic-linksys_mr9000-squashfs-sysupgrade.bin
- SHA-256: `3566f961aaa5cbf430764a67b87e880c7a222736a559c80617bf5ba3b5afcf2b`
- Size: 8408415 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3566f961aaa5cbf4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3566f961aaa5cbf4/_openwrt-25.12.5-ipq40xx-generic-linksys_mr9000-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_mr9000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
