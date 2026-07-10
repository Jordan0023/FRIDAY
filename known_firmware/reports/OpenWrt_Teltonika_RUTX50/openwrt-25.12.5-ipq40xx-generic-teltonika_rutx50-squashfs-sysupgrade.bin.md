# Firmware Audit: OpenWrt Teltonika RUTX50 / openwrt-25.12.5-ipq40xx-generic-teltonika_rutx50-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-teltonika_rutx50-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Teltonika_RUTX50/openwrt-25.12.5-ipq40xx-generic-teltonika_rutx50-squashfs-sysupgrade.bin
- SHA-256: `6a699fab47d0531769079700cb138018da69119710f123e92373b5895625b8be`
- Size: 9595435 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6a699fab47d05317 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6a699fab47d05317/_openwrt-25.12.5-ipq40xx-generic-teltonika_rutx50-squashfs-sysupgrade.bin.extracted/sysupgrade-teltonika_rutx50/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
