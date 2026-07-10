# Firmware Audit: OpenWrt ASUS RT-AC42U / openwrt-25.12.5-ipq40xx-generic-asus_rt-ac42u-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-asus_rt-ac42u-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_RT-AC42U/openwrt-25.12.5-ipq40xx-generic-asus_rt-ac42u-squashfs-sysupgrade.bin
- SHA-256: `e7b5db2205d399dc15c0b7ebd0293b4adcc7f324a0b1482d84a75cd0f67d4348`
- Size: 8632866 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e7b5db2205d399dc exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e7b5db2205d399dc/_openwrt-25.12.5-ipq40xx-generic-asus_rt-ac42u-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_rt-ac42u/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
