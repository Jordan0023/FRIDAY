# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release20309-0202-1706852136.tar

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release20309-0202-1706852136.tar
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release20309-0202-1706852136.tar
- SHA-256: `6a8e43907b5226ed1b44d44a289a12e7516fec16c105df96122e8ef53fd3e250`
- Size: 18813544 bytes
- Version: 4.3.9
- Release date: 2024-02-02 13:33:59

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6a8e43907b5226ed exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6a8e43907b5226ed/_openwrt-e750-4.0-release20309-0202-1706852136.tar.extracted/sysupgrade-glinet_gl-e750/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
