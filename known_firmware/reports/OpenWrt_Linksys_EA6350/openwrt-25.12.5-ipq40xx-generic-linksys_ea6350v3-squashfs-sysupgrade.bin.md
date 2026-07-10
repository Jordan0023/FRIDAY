# Firmware Audit: OpenWrt Linksys EA6350 / openwrt-25.12.5-ipq40xx-generic-linksys_ea6350v3-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-linksys_ea6350v3-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_EA6350/openwrt-25.12.5-ipq40xx-generic-linksys_ea6350v3-squashfs-sysupgrade.bin
- SHA-256: `ac316758720022227e3bcb5c1e3f51b9ed1db01975cd3c4ac385b5a41760b8e1`
- Size: 7998821 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ac31675872002222 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ac31675872002222/_openwrt-25.12.5-ipq40xx-generic-linksys_ea6350v3-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_ea6350v3/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
