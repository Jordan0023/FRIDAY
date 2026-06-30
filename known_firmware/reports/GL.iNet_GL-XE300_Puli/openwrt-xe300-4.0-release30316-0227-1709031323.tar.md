# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-4.0-release30316-0227-1709031323.tar

- Source URL: https://fw.gl-inet.com/firmware/xe300/release4/openwrt-xe300-4.0-release30316-0227-1709031323.tar
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-4.0-release30316-0227-1709031323.tar
- SHA-256: `3af11d52ba7e972546b5551c942116d4f262bdc65f7e23c012314013b17621be`
- Size: 16297467 bytes
- Version: 4.3.16
- Release date: 2024-02-27 18:53:43

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3af11d52ba7e9725 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3af11d52ba7e9725/_openwrt-xe300-4.0-release30316-0227-1709031323.tar.extracted/sysupgrade-glinet_gl-xe300-nor-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
