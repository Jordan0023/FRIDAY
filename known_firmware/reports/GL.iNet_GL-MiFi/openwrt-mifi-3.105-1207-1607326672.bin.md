# Firmware Audit: GL.iNet GL-MiFi / openwrt-mifi-3.105-1207-1607326672.bin

- Source URL: https://fw.gl-inet.com/firmware/mifi/v1/openwrt-mifi-3.105-1207-1607326672.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MiFi/openwrt-mifi-3.105-1207-1607326672.bin
- SHA-256: `b9b8ee8c16834a30159271e60663037baefbb7f9860f8c55bc6a6018bf3d6e96`
- Size: 13238276 bytes
- Version: 3.105
- Release date: 2020-12-07 15:37:52

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b9b8ee8c16834a30 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b9b8ee8c16834a30/_openwrt-mifi-3.105-1207-1607326672.bin.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
