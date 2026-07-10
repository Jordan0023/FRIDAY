# Firmware Audit: OpenWrt MobiPromo CM520-79F / openwrt-25.12.5-ipq40xx-generic-mobipromo_cm520-79f-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-mobipromo_cm520-79f-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_MobiPromo_CM520-79F/openwrt-25.12.5-ipq40xx-generic-mobipromo_cm520-79f-squashfs-sysupgrade.bin
- SHA-256: `e4105af1142e51c3ebc920a0fd5954807e0f37208adc91fae7fa9f5c0505fa79`
- Size: 7998004 bytes
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

- binwalk -eM --directory known_firmware/extracted/e4105af1142e51c3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e4105af1142e51c3/_openwrt-25.12.5-ipq40xx-generic-mobipromo_cm520-79f-squashfs-sysupgrade.bin.extracted/sysupgrade-mobipromo_cm520-79f/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
