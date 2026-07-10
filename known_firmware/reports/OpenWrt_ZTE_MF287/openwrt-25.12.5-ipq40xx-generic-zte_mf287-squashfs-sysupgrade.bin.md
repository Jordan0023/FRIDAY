# Firmware Audit: OpenWrt ZTE MF287 / openwrt-25.12.5-ipq40xx-generic-zte_mf287-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-zte_mf287-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ZTE_MF287/openwrt-25.12.5-ipq40xx-generic-zte_mf287-squashfs-sysupgrade.bin
- SHA-256: `6a6ebc025fffb77d103f56085a1e2331a43582ec31e53974fa0b2b24cccaccaf`
- Size: 8049174 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6a6ebc025fffb77d exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6a6ebc025fffb77d/_openwrt-25.12.5-ipq40xx-generic-zte_mf287-squashfs-sysupgrade.bin.extracted/sysupgrade-zte_mf287/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
