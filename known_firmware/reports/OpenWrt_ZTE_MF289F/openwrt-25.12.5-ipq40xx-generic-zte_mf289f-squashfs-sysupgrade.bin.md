# Firmware Audit: OpenWrt ZTE MF289F / openwrt-25.12.5-ipq40xx-generic-zte_mf289f-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-zte_mf289f-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ZTE_MF289F/openwrt-25.12.5-ipq40xx-generic-zte_mf289f-squashfs-sysupgrade.bin
- SHA-256: `da6c912b4740ed36d07a4e66de5b88c324483eeea6c1f881183bb77c2742a3e4`
- Size: 8540697 bytes
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

- binwalk -eM --directory known_firmware/extracted/da6c912b4740ed36 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/da6c912b4740ed36/_openwrt-25.12.5-ipq40xx-generic-zte_mf289f-squashfs-sysupgrade.bin.extracted/sysupgrade-zte_mf289f/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
