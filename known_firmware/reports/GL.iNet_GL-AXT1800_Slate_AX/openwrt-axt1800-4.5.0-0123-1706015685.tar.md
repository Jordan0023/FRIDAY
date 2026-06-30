# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.5.0-0123-1706015685.tar

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.5.0-0123-1706015685.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.5.0-0123-1706015685.tar
- SHA-256: `dd59b3e6b4e8e5b5bdf56266152ea847433bb11a60dbced77c68780610b37105`
- Size: 47507619 bytes
- Version: 4.5.0
- Release date: 2024-01-23 21:13:10

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dd59b3e6b4e8e5b5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/dd59b3e6b4e8e5b5/_openwrt-axt1800-4.5.0-0123-1706015685.tar.extracted/sysupgrade-glinet_axt1800/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
