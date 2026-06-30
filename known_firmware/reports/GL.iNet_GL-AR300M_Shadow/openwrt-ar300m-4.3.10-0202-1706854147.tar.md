# Firmware Audit: GL.iNet GL-AR300M Shadow / openwrt-ar300m-4.3.10-0202-1706854147.tar

- Source URL: https://fw.gl-inet.com/firmware/ar300m/nand/release4/openwrt-ar300m-4.3.10-0202-1706854147.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.10-0202-1706854147.tar
- SHA-256: `037c575e83670c41b6e0747e920818b497eee2ff2fac4d99d4f923ac6a5e784e`
- Size: 15526382 bytes
- Version: 4.3.10
- Release date: 2024-02-02 14:07:33

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/037c575e83670c41 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/037c575e83670c41/_openwrt-ar300m-4.3.10-0202-1706854147.tar.extracted/sysupgrade-glinet_gl-ar300m-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
