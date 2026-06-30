# Firmware Audit: GL.iNet GL-MT300N-V2 Mango / openwrt-mt300n-v2-3.105-1207-1607326251.bin

- Source URL: https://fw.gl-inet.com/firmware/mt300n-v2/v1/openwrt-mt300n-v2-3.105-1207-1607326251.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT300N-V2_Mango/openwrt-mt300n-v2-3.105-1207-1607326251.bin
- SHA-256: `b6b9788732641275c3e0a149854e311db91f59f42161f91628ad0578a4b063be`
- Size: 13107377 bytes
- Version: 3.105
- Release date: 2020-12-07 15:30:51

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b6b9788732641275 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b6b9788732641275/_openwrt-mt300n-v2-3.105-1207-1607326251.bin.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
