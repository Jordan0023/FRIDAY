# Firmware Audit: OpenWrt Ubiquiti RouterStation / openwrt-25.12.5-ath79-generic-ubnt_routerstation-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-ubnt_routerstation-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Ubiquiti_RouterStation/openwrt-25.12.5-ath79-generic-ubnt_routerstation-squashfs-sysupgrade.bin
- SHA-256: `3818e69ddff27fed1e4f87f0404f8222981baf6d8235422f1ea1f036ca55f4c5`
- Size: 6759399 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3818e69ddff27fed exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3818e69ddff27fed/_openwrt-25.12.5-ath79-generic-ubnt_routerstation-squashfs-sysupgrade.bin.extracted/sysupgrade-ubnt_routerstation/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
