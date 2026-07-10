# Firmware Audit: OpenWrt Cisco Meraki Z3 / openwrt-25.12.5-ipq40xx-generic-meraki_z3-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-meraki_z3-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cisco_Meraki_Z3/openwrt-25.12.5-ipq40xx-generic-meraki_z3-squashfs-sysupgrade.bin
- SHA-256: `a0b16798a5777c07560cc79ab91b2f5ea5ec4236e641f7cde3015ff2f2f3bcad`
- Size: 9462294 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a0b16798a5777c07 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a0b16798a5777c07/_openwrt-25.12.5-ipq40xx-generic-meraki_z3-squashfs-sysupgrade.bin.extracted/sysupgrade-meraki_z3/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
