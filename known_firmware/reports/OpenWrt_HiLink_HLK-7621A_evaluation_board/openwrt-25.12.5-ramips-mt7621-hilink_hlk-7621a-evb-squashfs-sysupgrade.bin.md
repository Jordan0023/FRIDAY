# Firmware Audit: OpenWrt HiLink HLK-7621A evaluation board / openwrt-25.12.5-ramips-mt7621-hilink_hlk-7621a-evb-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-hilink_hlk-7621a-evb-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_HiLink_HLK-7621A_evaluation_board/openwrt-25.12.5-ramips-mt7621-hilink_hlk-7621a-evb-squashfs-sysupgrade.bin
- SHA-256: `feea26ddc21562e37cb61f0d68a95feb170ebc7a747e75fdb9ea3575b5761721`
- Size: 7733817 bytes
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

- binwalk -eM --directory known_firmware/extracted/feea26ddc21562e3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/feea26ddc21562e3/_openwrt-25.12.5-ramips-mt7621-hilink_hlk-7621a-evb-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
