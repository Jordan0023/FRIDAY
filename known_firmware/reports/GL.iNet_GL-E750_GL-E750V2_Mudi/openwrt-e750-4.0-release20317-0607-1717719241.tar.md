# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release20317-0607-1717719241.tar

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release20317-0607-1717719241.tar
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release20317-0607-1717719241.tar
- SHA-256: `17be4823da02cdc9044bdf9ccf9e06df0fe2f63967d015640d619727dbeb873a`
- Size: 18382261 bytes
- Version: 4.3.17
- Release date: 2024-06-07 08:12:27

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/17be4823da02cdc9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/17be4823da02cdc9/_openwrt-e750-4.0-release20317-0607-1717719241.tar.extracted/sysupgrade-glinet_gl-e750/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
