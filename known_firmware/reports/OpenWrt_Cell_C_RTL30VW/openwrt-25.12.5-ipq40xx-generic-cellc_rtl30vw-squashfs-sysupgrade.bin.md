# Firmware Audit: OpenWrt Cell C RTL30VW / openwrt-25.12.5-ipq40xx-generic-cellc_rtl30vw-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-cellc_rtl30vw-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cell_C_RTL30VW/openwrt-25.12.5-ipq40xx-generic-cellc_rtl30vw-squashfs-sysupgrade.bin
- SHA-256: `f0915302f54b0ad49d14e15766c891b42f624a1a11411ae1348565c5e2d11947`
- Size: 8090146 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f0915302f54b0ad4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f0915302f54b0ad4/_openwrt-25.12.5-ipq40xx-generic-cellc_rtl30vw-squashfs-sysupgrade.bin.extracted/sysupgrade-cellc_rtl30vw/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
