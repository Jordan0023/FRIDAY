# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.19-0823-1724382267.tar

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.19-0823-1724382267.tar
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.19-0823-1724382267.tar
- SHA-256: `558401f701b2a8200b83616c54bbe135344a0aa60988da00746db67d0540b78a`
- Size: 17081052 bytes
- Version: 4.3.19
- Release date: 2024-08-23 10:44:31

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/558401f701b2a820 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/558401f701b2a820/_openwrt-sft1200-4.3.19-0823-1724382267.tar.extracted/sysupgrade-glinet_gl-sft1200/_root.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
