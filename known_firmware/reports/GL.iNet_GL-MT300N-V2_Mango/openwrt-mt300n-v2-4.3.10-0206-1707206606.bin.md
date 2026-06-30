# Firmware Audit: GL.iNet GL-MT300N-V2 Mango / openwrt-mt300n-v2-4.3.10-0206-1707206606.bin

- Source URL: https://fw.gl-inet.com/firmware/mt300n-v2/release4/openwrt-mt300n-v2-4.3.10-0206-1707206606.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT300N-V2_Mango/openwrt-mt300n-v2-4.3.10-0206-1707206606.bin
- SHA-256: `7ac5bd6b8111a70f1201a57a62c5769ba75325349ced3b1316428fa3bccc3d59`
- Size: 14944730 bytes
- Version: 4.3.10
- Release date: 2024-02-06 16:01:46

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7ac5bd6b8111a70f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7ac5bd6b8111a70f/_openwrt-mt300n-v2-4.3.10-0206-1707206606.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
