# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.25-0307-1741318217.tar

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.25-0307-1741318217.tar
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.25-0307-1741318217.tar
- SHA-256: `294611525e5498670a3262fcdce4ee92953612b02e0ad4abedc5279c77bb4188`
- Size: 17204110 bytes
- Version: 4.3.25
- Release date: 2025-03-07 11:19:12

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/294611525e549867 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/294611525e549867/_openwrt-sft1200-4.3.25-0307-1741318217.tar.extracted/sysupgrade-glinet_gl-sft1200/_root.extracted/squashfs-root-0/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
