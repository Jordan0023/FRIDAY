# Firmware Audit: OpenWrt NETGEAR SRS60 / openwrt-25.12.5-ipq40xx-generic-netgear_srs60-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-netgear_srs60-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_SRS60/openwrt-25.12.5-ipq40xx-generic-netgear_srs60-squashfs-sysupgrade.bin
- SHA-256: `4653462f7771c8f8de7eea97c242be6c0de0a72b14886df1c723cc1ba7cca1f8`
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

- binwalk -eM --directory known_firmware/extracted/4653462f7771c8f8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/4653462f7771c8f8/_openwrt-25.12.5-ipq40xx-generic-netgear_srs60-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_srs60/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
