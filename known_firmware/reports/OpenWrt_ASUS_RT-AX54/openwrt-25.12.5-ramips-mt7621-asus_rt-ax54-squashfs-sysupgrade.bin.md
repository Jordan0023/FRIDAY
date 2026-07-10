# Firmware Audit: OpenWrt ASUS RT-AX54 / openwrt-25.12.5-ramips-mt7621-asus_rt-ax54-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-asus_rt-ax54-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_RT-AX54/openwrt-25.12.5-ramips-mt7621-asus_rt-ax54-squashfs-sysupgrade.bin
- SHA-256: `e5e19f1ca7366b83b9eaab67090b85d701c924d9ed0dfc929276649b343daa68`
- Size: 7997981 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e5e19f1ca7366b83 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e5e19f1ca7366b83/_openwrt-25.12.5-ramips-mt7621-asus_rt-ax54-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_rt-ax54/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
