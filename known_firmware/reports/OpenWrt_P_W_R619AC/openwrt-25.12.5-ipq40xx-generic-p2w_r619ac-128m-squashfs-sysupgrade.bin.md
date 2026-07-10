# Firmware Audit: OpenWrt P&W R619AC / openwrt-25.12.5-ipq40xx-generic-p2w_r619ac-128m-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-p2w_r619ac-128m-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_P_W_R619AC/openwrt-25.12.5-ipq40xx-generic-p2w_r619ac-128m-squashfs-sysupgrade.bin
- SHA-256: `377624da066a58b769c73a5b6f6281e0c757d82ded3461d383655c085d2126b8`
- Size: 7997992 bytes
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

- binwalk -eM --directory known_firmware/extracted/377624da066a58b7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/377624da066a58b7/_openwrt-25.12.5-ipq40xx-generic-p2w_r619ac-128m-squashfs-sysupgrade.bin.extracted/sysupgrade-p2w_r619ac-128m/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
