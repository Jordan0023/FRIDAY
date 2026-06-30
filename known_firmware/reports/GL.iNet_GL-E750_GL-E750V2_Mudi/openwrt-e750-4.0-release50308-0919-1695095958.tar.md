# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release50308-0919-1695095958.tar

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release50308-0919-1695095958.tar
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release50308-0919-1695095958.tar
- SHA-256: `5d686d0063b9f6f9f5420df19ff4ceba133264ce99888abed67d197fa6361af0`
- Size: 18886713 bytes
- Version: 4.3.8
- Release date: 2023-09-19 11:57:55

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5d686d0063b9f6f9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5d686d0063b9f6f9/_openwrt-e750-4.0-release50308-0919-1695095958.tar.extracted/sysupgrade-glinet_gl-e750/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
