# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.6.9-1030-1730284273.tar

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.6.9-1030-1730284273.tar
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.6.9-1030-1730284273.tar
- SHA-256: `a974ed53c0058cc068bc2908eef592192fe279e259511294ea5baecad2a65d5e`
- Size: 48231171 bytes
- Version: 4.6.9
- Release date: 2024-10-30 17:53:56

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a974ed53c0058cc0 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a974ed53c0058cc0/_openwrt-mt3000-4.6.9-1030-1730284273.tar.extracted/sysupgrade-glinet_gl-mt3000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
