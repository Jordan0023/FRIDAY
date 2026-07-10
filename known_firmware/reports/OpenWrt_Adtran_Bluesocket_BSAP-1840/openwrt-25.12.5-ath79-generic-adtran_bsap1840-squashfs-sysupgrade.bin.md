# Firmware Audit: OpenWrt Adtran/Bluesocket BSAP-1840 / openwrt-25.12.5-ath79-generic-adtran_bsap1840-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-adtran_bsap1840-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Adtran_Bluesocket_BSAP-1840/openwrt-25.12.5-ath79-generic-adtran_bsap1840-squashfs-sysupgrade.bin
- SHA-256: `e59a330def917514e6f668efa65496555f38cf0a7f74e7b4299a01567d95fd6e`
- Size: 6953227 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, cgi-bin, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e59a330def917514 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e59a330def917514/_openwrt-25.12.5-ath79-generic-adtran_bsap1840-squashfs-sysupgrade.bin.extracted/sysupgrade-adtran_bsap1840/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
