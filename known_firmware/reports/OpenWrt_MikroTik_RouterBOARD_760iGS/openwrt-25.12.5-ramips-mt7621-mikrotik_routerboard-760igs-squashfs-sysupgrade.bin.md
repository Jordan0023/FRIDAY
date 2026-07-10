# Firmware Audit: OpenWrt MikroTik RouterBOARD 760iGS / openwrt-25.12.5-ramips-mt7621-mikrotik_routerboard-760igs-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-mikrotik_routerboard-760igs-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_MikroTik_RouterBOARD_760iGS/openwrt-25.12.5-ramips-mt7621-mikrotik_routerboard-760igs-squashfs-sysupgrade.bin
- SHA-256: `d9207b0aad4c68bd6f52a34541189b117e6ecf5d6c0a18f2449b66ef336e8cf1`
- Size: 6685262 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password, token`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `DROPBEAR, Dropbear, dropbear, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d9207b0aad4c68bd exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
