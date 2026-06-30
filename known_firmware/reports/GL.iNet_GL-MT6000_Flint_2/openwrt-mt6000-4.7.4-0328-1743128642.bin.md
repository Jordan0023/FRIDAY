# Firmware Audit: GL.iNet GL-MT6000 Flint 2 / openwrt-mt6000-4.7.4-0328-1743128642.bin

- Source URL: https://fw.gl-inet.com/firmware/mt6000/release/openwrt-mt6000-4.7.4-0328-1743128642.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT6000_Flint_2/openwrt-mt6000-4.7.4-0328-1743128642.bin
- SHA-256: `5c78e3ac46fb32fb886728b2b0aa1c02a742305bde0777a949aaa900f38cb06c`
- Size: 60479849 bytes
- Version: 4.7.4
- Release date: 2025-03-28 09:53:50

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5c78e3ac46fb32fb exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5c78e3ac46fb32fb/_openwrt-mt6000-4.7.4-0328-1743128642.bin.extracted/sysupgrade-glinet_gl-mt6000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
