# Firmware Audit: OpenWrt NETGEAR LBR20 / openwrt-25.12.5-ipq40xx-generic-netgear_lbr20-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-netgear_lbr20-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_LBR20/openwrt-25.12.5-ipq40xx-generic-netgear_lbr20-squashfs-sysupgrade.bin
- SHA-256: `c2dbd223cac75a4c0c85af35e8547cc42379f06ada1e4487f655df2b5ce4b295`
- Size: 8591906 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c2dbd223cac75a4c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c2dbd223cac75a4c/_openwrt-25.12.5-ipq40xx-generic-netgear_lbr20-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_lbr20/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
