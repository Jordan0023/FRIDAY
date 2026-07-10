# Firmware Audit: OpenWrt Fortinet FAP-421E / openwrt-25.12.5-ipq806x-generic-fortinet_fap-421e-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-fortinet_fap-421e-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Fortinet_FAP-421E/openwrt-25.12.5-ipq806x-generic-fortinet_fap-421e-squashfs-sysupgrade.bin
- SHA-256: `5ec5b8d6f2ff436b8200ad84d9d7fce88b6e4fcd30dddacbd6e9830467f2453b`
- Size: 9718024 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5ec5b8d6f2ff436b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5ec5b8d6f2ff436b/_openwrt-25.12.5-ipq806x-generic-fortinet_fap-421e-squashfs-sysupgrade.bin.extracted/sysupgrade-fap-421e/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
