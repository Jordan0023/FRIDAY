# Firmware Audit: OpenWrt MediaTek MT7987A rfb / openwrt-25.12.5-mediatek-filogic-mediatek_mt7987a-rfb-squashfs-sysupgrade.itb

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-mediatek_mt7987a-rfb-squashfs-sysupgrade.itb
- Local path: known_firmware/firmware/OpenWrt_MediaTek_MT7987A_rfb/openwrt-25.12.5-mediatek-filogic-mediatek_mt7987a-rfb-squashfs-sysupgrade.itb
- SHA-256: `599fae9916413c3e908df46b840f470123c73af3234e9b1be9bf980491586021`
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

- binwalk -eM --directory known_firmware/extracted/599fae9916413c3e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/599fae9916413c3e/_openwrt-25.12.5-mediatek-filogic-mediatek_mt7987a-rfb-squashfs-sysupgrade.itb.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
