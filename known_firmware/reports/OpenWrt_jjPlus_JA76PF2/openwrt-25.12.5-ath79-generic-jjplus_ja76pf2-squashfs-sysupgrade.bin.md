# Firmware Audit: OpenWrt jjPlus JA76PF2 / openwrt-25.12.5-ath79-generic-jjplus_ja76pf2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-jjplus_ja76pf2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_jjPlus_JA76PF2/openwrt-25.12.5-ath79-generic-jjplus_ja76pf2-squashfs-sysupgrade.bin
- SHA-256: `85d2535597fdc1711baff465da324549e102c1361dc2274746f52f490515fc36`
- Size: 6626233 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/85d2535597fdc171 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/85d2535597fdc171/_openwrt-25.12.5-ath79-generic-jjplus_ja76pf2-squashfs-sysupgrade.bin.extracted/sysupgrade-jjplus_ja76pf2/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
