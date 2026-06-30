# Firmware Audit: GL.iNet GL-X1200 Amarok / openwrt-x1200-3.105-1207-1607326109.tar

- Source URL: https://fw.gl-inet.com/firmware/x1200/release/openwrt-x1200-3.105-1207-1607326109.tar
- Local path: known_firmware/firmware/GL.iNet_GL-X1200_Amarok/openwrt-x1200-3.105-1207-1607326109.tar
- SHA-256: `ed8f200c1a8146e3e698d5c23d046a05389f039f546cec6159725b6a0640cb7e`
- Size: 16087040 bytes
- Version: 3.105
- Release date: 2020-12-07 15:28:29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ed8f200c1a8146e3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ed8f200c1a8146e3/_openwrt-x1200-3.105-1207-1607326109.tar.extracted/sysupgrade-gl-x1200/_root.extracted/squashfs-root-0/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
