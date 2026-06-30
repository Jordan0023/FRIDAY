# Firmware Audit: GL.iNet GL-MiFi / openwrt-mifi-3.215-0921-1663732612.bin

- Source URL: https://fw.gl-inet.com/firmware/mifi/v1/openwrt-mifi-3.215-0921-1663732612.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MiFi/openwrt-mifi-3.215-0921-1663732612.bin
- SHA-256: `3e6fe49ca485d7ec7f1f9a00d11c9ba90a6efcdc0ee596b7aecb759d88f2d906`
- Size: 12714296 bytes
- Version: 3.215
- Release date: 2022-09-21 11:56:52

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3e6fe49ca485d7ec exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3e6fe49ca485d7ec/_openwrt-mifi-3.215-0921-1663732612.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
