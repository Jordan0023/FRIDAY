# Firmware Audit: OpenWrt Linksys WHW03 / openwrt-25.12.5-ipq40xx-generic-linksys_whw03-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-linksys_whw03-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_WHW03/openwrt-25.12.5-ipq40xx-generic-linksys_whw03-squashfs-sysupgrade.bin
- SHA-256: `7c9b5fd00fd21b644d7496032496fe5bc66df2cc1c4dcadd2cb26bcd67d04cb6`
- Size: 9636386 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7c9b5fd00fd21b64 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7c9b5fd00fd21b64/_openwrt-25.12.5-ipq40xx-generic-linksys_whw03-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_whw03/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
