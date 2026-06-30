# Firmware Audit: GL.iNet GL-MT6000 Flint 2 / openwrt-mt6000-4.6.8-1017-1729163236.bin

- Source URL: https://fw.gl-inet.com/firmware/mt6000/release/openwrt-mt6000-4.6.8-1017-1729163236.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT6000_Flint_2/openwrt-mt6000-4.6.8-1017-1729163236.bin
- SHA-256: `d496846f44cfae16a9579ea6cc8c7880f38f603fa099ad71eb1fce2a2b174c8f`
- Size: 49593821 bytes
- Version: 4.6.8
- Release date: 2024-10-17 18:34:54

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eVal, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d496846f44cfae16 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d496846f44cfae16/_openwrt-mt6000-4.6.8-1017-1729163236.bin.extracted/sysupgrade-glinet_gl-mt6000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
