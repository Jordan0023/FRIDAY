# Firmware Audit: GL.iNet GL-MiFi / openwrt-mifi-3.217-0508-1683514110.bin

- Source URL: https://fw.gl-inet.com/firmware/mifi/v1/openwrt-mifi-3.217-0508-1683514110.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MiFi/openwrt-mifi-3.217-0508-1683514110.bin
- SHA-256: `d51a72d2263189e3d088e0f322e37d0bd256b8de8163a606a8fbf1d6ff4f94cb`
- Size: 12714296 bytes
- Version: 3.217
- Release date: 2023-05-08 10:48:30

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d51a72d2263189e3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d51a72d2263189e3/_openwrt-mifi-3.217-0508-1683514110.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
