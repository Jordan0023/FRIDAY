# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-4.0-release10318-0823-1724388935.tar

- Source URL: https://fw.gl-inet.com/firmware/xe300/release4/openwrt-xe300-4.0-release10318-0823-1724388935.tar
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-4.0-release10318-0823-1724388935.tar
- SHA-256: `007f1c1fc6e44484814f64346515b104876768c4d64a3920b66aea1c9068f854`
- Size: 15883110 bytes
- Version: 4.3.18
- Release date: 2024-08-23 12:53:54

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/007f1c1fc6e44484 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/007f1c1fc6e44484/_openwrt-xe300-4.0-release10318-0823-1724388935.tar.extracted/sysupgrade-glinet_gl-xe300-nor-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
