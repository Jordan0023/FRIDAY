# Firmware Audit: OpenWrt Ubiquiti RouterStation Pro / openwrt-25.12.5-ath79-generic-ubnt_routerstation-pro-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-ubnt_routerstation-pro-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Ubiquiti_RouterStation_Pro/openwrt-25.12.5-ath79-generic-ubnt_routerstation-pro-squashfs-sysupgrade.bin
- SHA-256: `4c979ed40c6b05d2c69a229414dd201a56a83cbfcd8e134757389827f13ab035`
- Size: 6759411 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4c979ed40c6b05d2 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/4c979ed40c6b05d2/_openwrt-25.12.5-ath79-generic-ubnt_routerstation-pro-squashfs-sysupgrade.bin.extracted/sysupgrade-ubnt_routerstation-pro/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
