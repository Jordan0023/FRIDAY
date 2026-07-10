# Firmware Audit: OpenWrt GL.iNet GL-B2200 / openwrt-25.12.5-ipq40xx-generic-glinet_gl-b2200-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-glinet_gl-b2200-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_GL.iNet_GL-B2200/openwrt-25.12.5-ipq40xx-generic-glinet_gl-b2200-squashfs-sysupgrade.bin
- SHA-256: `515a7a083f16c552fa3d93bd18ca4a2613c0723ae01e488538fdea82e2a2ab63`
- Size: 9308712 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/515a7a083f16c552 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/515a7a083f16c552/_openwrt-25.12.5-ipq40xx-generic-glinet_gl-b2200-squashfs-sysupgrade.bin.extracted/sysupgrade-glinet_gl-b2200/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
