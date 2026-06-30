# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.5.0-0123-1706004682.tar

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.5.0-0123-1706004682.tar
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.5.0-0123-1706004682.tar
- SHA-256: `233f09c7adaf46a9d6748c40b8fc4f49f7793f5ffeb32e353b35a773c65060eb`
- Size: 48203946 bytes
- Version: 4.5.0
- Release date: 2024-01-23 18:08:58

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/233f09c7adaf46a9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/233f09c7adaf46a9/_openwrt-mt3000-4.5.0-0123-1706004682.tar.extracted/sysupgrade-glinet_gl-mt3000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
