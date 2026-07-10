# Firmware Audit: OpenWrt Plasma Cloud PA2200 / openwrt-25.12.5-ipq40xx-generic-plasmacloud_pa2200-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-plasmacloud_pa2200-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Plasma_Cloud_PA2200/openwrt-25.12.5-ipq40xx-generic-plasmacloud_pa2200-squashfs-sysupgrade.bin
- SHA-256: `bb7bf68c873c601e57c78f01d0c07f73684f08472fdc4fe8b86c24bc1daab83d`
- Size: 8725041 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bb7bf68c873c601e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/bb7bf68c873c601e/_openwrt-25.12.5-ipq40xx-generic-plasmacloud_pa2200-squashfs-sysupgrade.bin.extracted/sysupgrade-plasmacloud_pa2200/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
