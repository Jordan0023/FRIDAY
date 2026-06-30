# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.1.2-1227-1672126828.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.1.2-1227-1672126828.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.1.2-1227-1672126828.tar
- SHA-256: `846d9c855dbf29d739ea70638f75db9be179cc657504d79a7c676f21129b0132`
- Size: 48978844 bytes
- Version: 4.1.2
- Release date: 2022-12-27 15:38:51

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/846d9c855dbf29d7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/846d9c855dbf29d7/_openwrt-a1300-4.1.2-1227-1672126828.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
