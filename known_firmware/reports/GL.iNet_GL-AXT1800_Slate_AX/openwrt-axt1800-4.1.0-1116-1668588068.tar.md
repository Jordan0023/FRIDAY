# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.1.0-1116-1668588068.tar

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.1.0-1116-1668588068.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.1.0-1116-1668588068.tar
- SHA-256: `d152cddffee821355613ba6a0db074d9b686f128e7ef6a5d65a1952e1942b655`
- Size: 51961046 bytes
- Version: 4.1.0
- Release date: 2022-11-16 16:39:51

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, bOA, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d152cddffee82135 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d152cddffee82135/_openwrt-axt1800-4.1.0-1116-1668588068.tar.extracted/sysupgrade-glinet_axt1800/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
