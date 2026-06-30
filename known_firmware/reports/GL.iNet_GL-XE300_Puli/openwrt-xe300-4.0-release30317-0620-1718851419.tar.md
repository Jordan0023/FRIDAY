# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-4.0-release30317-0620-1718851419.tar

- Source URL: https://fw.gl-inet.com/firmware/xe300/release4/openwrt-xe300-4.0-release30317-0620-1718851419.tar
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-4.0-release30317-0620-1718851419.tar
- SHA-256: `f8e1bab04119679a13bb2bbd21020937a9a93cfc722758d049cf9e34c7ae4b9b`
- Size: 15883760 bytes
- Version: 4.3.17
- Release date: 2024-06-20 10:42:00

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f8e1bab04119679a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f8e1bab04119679a/_openwrt-xe300-4.0-release30317-0620-1718851419.tar.extracted/sysupgrade-glinet_gl-xe300-nor-nand/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
