# Firmware Audit: OpenWrt ZTE MF286D / openwrt-25.12.5-ipq40xx-generic-zte_mf286d-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-zte_mf286d-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ZTE_MF286D/openwrt-25.12.5-ipq40xx-generic-zte_mf286d-squashfs-sysupgrade.bin
- SHA-256: `27302eb6af64af3613098f18325a20a726360e92985c4882d43da35b0c771a34`
- Size: 8090137 bytes
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

- binwalk -eM --directory known_firmware/extracted/27302eb6af64af36 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/27302eb6af64af36/_openwrt-25.12.5-ipq40xx-generic-zte_mf286d-squashfs-sysupgrade.bin.extracted/sysupgrade-zte_mf286d/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
