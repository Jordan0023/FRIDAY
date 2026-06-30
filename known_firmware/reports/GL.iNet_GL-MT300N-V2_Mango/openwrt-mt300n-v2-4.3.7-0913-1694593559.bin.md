# Firmware Audit: GL.iNet GL-MT300N-V2 Mango / openwrt-mt300n-v2-4.3.7-0913-1694593559.bin

- Source URL: https://fw.gl-inet.com/firmware/mt300n-v2/release4/openwrt-mt300n-v2-4.3.7-0913-1694593559.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT300N-V2_Mango/openwrt-mt300n-v2-4.3.7-0913-1694593559.bin
- SHA-256: `bed878d4bdafef9327f16957713138f8eb9479629f5f6679d25f4a4a619535f7`
- Size: 14682406 bytes
- Version: 4.3.7
- Release date: 2023-09-13 16:24:35

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

- binwalk -eM --directory known_firmware/extracted/bed878d4bdafef93 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/bed878d4bdafef93/_openwrt-mt300n-v2-4.3.7-0913-1694593559.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
