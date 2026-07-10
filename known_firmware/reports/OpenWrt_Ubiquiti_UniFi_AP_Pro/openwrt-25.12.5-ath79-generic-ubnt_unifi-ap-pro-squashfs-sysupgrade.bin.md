# Firmware Audit: OpenWrt Ubiquiti UniFi AP Pro / openwrt-25.12.5-ath79-generic-ubnt_unifi-ap-pro-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-ubnt_unifi-ap-pro-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Ubiquiti_UniFi_AP_Pro/openwrt-25.12.5-ath79-generic-ubnt_unifi-ap-pro-squashfs-sysupgrade.bin
- SHA-256: `895bdd56632a9943a7df81ff6fe77e5004dde6f3baab943a88e9a87db57d4b07`
- Size: 7405853 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/895bdd56632a9943 exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
