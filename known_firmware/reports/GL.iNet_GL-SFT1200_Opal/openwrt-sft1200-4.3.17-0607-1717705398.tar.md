# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.17-0607-1717705398.tar

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.17-0607-1717705398.tar
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.17-0607-1717705398.tar
- SHA-256: `99b662d97d5f6bf5f34f79ecbce45d654c2c3cb2cb8b1745ad247ed520b36e05`
- Size: 17051062 bytes
- Version: 4.3.17
- Release date: 2024-06-07 04:03:16

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/99b662d97d5f6bf5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/99b662d97d5f6bf5/_openwrt-sft1200-4.3.17-0607-1717705398.tar.extracted/sysupgrade-glinet_gl-sft1200/_root.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
