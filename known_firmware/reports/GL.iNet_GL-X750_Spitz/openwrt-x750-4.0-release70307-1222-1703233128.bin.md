# Firmware Audit: GL.iNet GL-X750 Spitz / openwrt-x750-4.0-release70307-1222-1703233128.bin

- Source URL: https://fw.gl-inet.com/firmware/x750/release4/openwrt-x750-4.0-release70307-1222-1703233128.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X750_Spitz/openwrt-x750-4.0-release70307-1222-1703233128.bin
- SHA-256: `dc329943aa99fba63243fef3d9b013006a99e6a68159216653c8cfb74bad88bd`
- Size: 14618701 bytes
- Version: 4.3.7
- Release date: 2023-12-22 16:17:13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dc329943aa99fba6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/dc329943aa99fba6/_openwrt-x750-4.0-release70307-1222-1703233128.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
