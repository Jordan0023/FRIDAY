# Firmware Audit: OpenWrt GL.iNet GL-B1300 / openwrt-25.12.5-ipq40xx-generic-glinet_gl-b1300-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-glinet_gl-b1300-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_GL.iNet_GL-B1300/openwrt-25.12.5-ipq40xx-generic-glinet_gl-b1300-squashfs-sysupgrade.bin
- SHA-256: `62133da6c2aa4e8b3b881f2115639cea1686e7b6a6890ff64fb25f01a7c1e7ce`
- Size: 8127013 bytes
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

- binwalk -eM --directory known_firmware/extracted/62133da6c2aa4e8b exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
