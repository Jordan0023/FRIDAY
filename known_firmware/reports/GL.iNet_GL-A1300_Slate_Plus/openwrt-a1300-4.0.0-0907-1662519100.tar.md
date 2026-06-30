# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.0.0-0907-1662519100.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.0.0-0907-1662519100.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.0.0-0907-1662519100.tar
- SHA-256: `fda913633637731c1fd4ebfb77038f171fadbb2c447b2be1d945ae327c79f296`
- Size: 46408568 bytes
- Version: 4.0.0
- Release date: 2022-09-07 10:51:40

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fda913633637731c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fda913633637731c/_openwrt-a1300-4.0.0-0907-1662519100.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
