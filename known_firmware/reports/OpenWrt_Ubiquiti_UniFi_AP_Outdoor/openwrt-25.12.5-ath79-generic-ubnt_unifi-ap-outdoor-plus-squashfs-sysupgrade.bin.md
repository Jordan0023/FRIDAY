# Firmware Audit: OpenWrt Ubiquiti UniFi AP Outdoor+ / openwrt-25.12.5-ath79-generic-ubnt_unifi-ap-outdoor-plus-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-ubnt_unifi-ap-outdoor-plus-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Ubiquiti_UniFi_AP_Outdoor/openwrt-25.12.5-ath79-generic-ubnt_unifi-ap-outdoor-plus-squashfs-sysupgrade.bin
- SHA-256: `54c66b1fe692acfa8b69abbaa069275b20d31ed08898223f5d77458f94329aae`
- Size: 7405882 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/54c66b1fe692acfa exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
