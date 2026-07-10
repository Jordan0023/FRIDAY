# Firmware Audit: OpenWrt Linksys MR6350 / openwrt-25.12.5-ipq40xx-generic-linksys_mr6350-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-linksys_mr6350-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_MR6350/openwrt-25.12.5-ipq40xx-generic-linksys_mr6350-squashfs-sysupgrade.bin
- SHA-256: `c6a0eae2e130f284e135a875fae2a6d0b984dabcebd58babb46d52a3472d085e`
- Size: 7968095 bytes
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

- binwalk -eM --directory known_firmware/extracted/c6a0eae2e130f284 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c6a0eae2e130f284/_openwrt-25.12.5-ipq40xx-generic-linksys_mr6350-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_mr6350/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
