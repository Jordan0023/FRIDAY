# Firmware Audit: GL.iNet GL-X300B Collie / openwrt-x300b-4.5.17-0607-1717712958.bin

- Source URL: https://fw.gl-inet.com/firmware/x300b/release4/openwrt-x300b-4.5.17-0607-1717712958.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X300B_Collie/openwrt-x300b-4.5.17-0607-1717712958.bin
- SHA-256: `203f6a660c958a664db83b50930d3ea1fd113f5343b62eb74946cd7cb6329648`
- Size: 13961591 bytes
- Version: 4.5.17
- Release date: 2024-06-07 06:27:42

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/203f6a660c958a66 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/203f6a660c958a66/_openwrt-x300b-4.5.17-0607-1717712958.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
