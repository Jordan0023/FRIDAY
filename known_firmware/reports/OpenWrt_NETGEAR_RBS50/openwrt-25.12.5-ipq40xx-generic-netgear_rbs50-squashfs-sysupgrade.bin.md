# Firmware Audit: OpenWrt NETGEAR RBS50 / openwrt-25.12.5-ipq40xx-generic-netgear_rbs50-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-netgear_rbs50-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_RBS50/openwrt-25.12.5-ipq40xx-generic-netgear_rbs50-squashfs-sysupgrade.bin
- SHA-256: `9ecf7ba3071db068ed75382a0f2e7d80b300e6aed1a7321061a1b63439dbe63f`
- Size: 9216546 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9ecf7ba3071db068 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9ecf7ba3071db068/_openwrt-25.12.5-ipq40xx-generic-netgear_rbs50-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_rbs50/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
