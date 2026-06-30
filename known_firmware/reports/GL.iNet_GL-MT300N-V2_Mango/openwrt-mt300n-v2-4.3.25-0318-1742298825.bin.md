# Firmware Audit: GL.iNet GL-MT300N-V2 Mango / openwrt-mt300n-v2-4.3.25-0318-1742298825.bin

- Source URL: https://fw.gl-inet.com/firmware/mt300n-v2/release4/openwrt-mt300n-v2-4.3.25-0318-1742298825.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT300N-V2_Mango/openwrt-mt300n-v2-4.3.25-0318-1742298825.bin
- SHA-256: `05a823f7714848bf039a27afa9f2eca28089ab978aac9dcb9c3f3613f78a9023`
- Size: 14680959 bytes
- Version: 4.3.25
- Release date: 2025-03-18 19:53:12

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/05a823f7714848bf exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/05a823f7714848bf/_openwrt-mt300n-v2-4.3.25-0318-1742298825.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
