# Firmware Audit: GL.iNet GL-AR300M16 Shadow / openwrt-ar300m16-4.3.25-0331-1743424534.bin

- Source URL: https://fw.gl-inet.com/firmware/ar300m/release4/openwrt-ar300m16-4.3.25-0331-1743424534.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M16_Shadow/openwrt-ar300m16-4.3.25-0331-1743424534.bin
- SHA-256: `759b0263128754d0dbdd86ff20b9f6d9a200fa293e784ab397ada41b525d21e1`
- Size: 15467426 bytes
- Version: 4.3.25
- Release date: 2025-03-31 20:32:26

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/759b0263128754d0 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/759b0263128754d0/_openwrt-ar300m16-4.3.25-0331-1743424534.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
