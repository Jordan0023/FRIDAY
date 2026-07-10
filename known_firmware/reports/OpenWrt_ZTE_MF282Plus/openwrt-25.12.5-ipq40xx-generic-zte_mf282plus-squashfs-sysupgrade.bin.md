# Firmware Audit: OpenWrt ZTE MF282Plus / openwrt-25.12.5-ipq40xx-generic-zte_mf282plus-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-zte_mf282plus-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ZTE_MF282Plus/openwrt-25.12.5-ipq40xx-generic-zte_mf282plus-squashfs-sysupgrade.bin
- SHA-256: `4b0ad2080fc6e60fa491d32a2202f19fbcfc10d76f05c394630f46f3fba8c0c9`
- Size: 8028706 bytes
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

- binwalk -eM --directory known_firmware/extracted/4b0ad2080fc6e60f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/4b0ad2080fc6e60f/_openwrt-25.12.5-ipq40xx-generic-zte_mf282plus-squashfs-sysupgrade.bin.extracted/sysupgrade-zte_mf282plus/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
