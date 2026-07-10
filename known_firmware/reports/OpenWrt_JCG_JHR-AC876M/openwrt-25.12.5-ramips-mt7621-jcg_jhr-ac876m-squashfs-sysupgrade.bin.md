# Firmware Audit: OpenWrt JCG JHR-AC876M / openwrt-25.12.5-ramips-mt7621-jcg_jhr-ac876m-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-jcg_jhr-ac876m-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_JCG_JHR-AC876M/openwrt-25.12.5-ramips-mt7621-jcg_jhr-ac876m-squashfs-sysupgrade.bin
- SHA-256: `e66d0eb78d294e64be32f6c879558520aabf35988f2384e070a37bfef8ac335a`
- Size: 8258087 bytes
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

- binwalk -eM --directory known_firmware/extracted/e66d0eb78d294e64 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e66d0eb78d294e64/_openwrt-25.12.5-ramips-mt7621-jcg_jhr-ac876m-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
