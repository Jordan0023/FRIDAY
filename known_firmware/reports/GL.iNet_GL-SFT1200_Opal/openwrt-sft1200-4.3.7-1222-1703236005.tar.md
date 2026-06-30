# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.7-1222-1703236005.tar

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.7-1222-1703236005.tar
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.7-1222-1703236005.tar
- SHA-256: `8eec38e33fe348b8b7f5d6b87300fb0876c97f5b926c4fee06311e333b7bb092`
- Size: 17401875 bytes
- Version: 4.3.7
- Release date: 2023-12-22 17:04:10

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8eec38e33fe348b8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/8eec38e33fe348b8/_openwrt-sft1200-4.3.7-1222-1703236005.tar.extracted/sysupgrade-glinet_gl-sft1200/_root.extracted/squashfs-root-0/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
