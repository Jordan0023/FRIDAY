# Firmware Audit: OpenWrt MediaTek MT7988A rfb / openwrt-25.12.5-mediatek-filogic-mediatek_mt7988a-rfb-squashfs-sysupgrade.itb

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-mediatek_mt7988a-rfb-squashfs-sysupgrade.itb
- Local path: known_firmware/firmware/OpenWrt_MediaTek_MT7988A_rfb/openwrt-25.12.5-mediatek-filogic-mediatek_mt7988a-rfb-squashfs-sysupgrade.itb
- SHA-256: `7ad3d9aa7a5dd9682df04eac430f1be5b12228f3b84d9308606237b1db86a1ea`
- Size: 9961756 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7ad3d9aa7a5dd968 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7ad3d9aa7a5dd968/_openwrt-25.12.5-mediatek-filogic-mediatek_mt7988a-rfb-squashfs-sysupgrade.itb.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
