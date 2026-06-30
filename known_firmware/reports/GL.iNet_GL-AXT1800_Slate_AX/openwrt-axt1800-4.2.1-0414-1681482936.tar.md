# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.2.1-0414-1681482936.tar

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.2.1-0414-1681482936.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.2.1-0414-1681482936.tar
- SHA-256: `4d50428028b63b35dbc039d0069c56a57ec8747380e9ae9cc4cd57bfa874c7a4`
- Size: 59373123 bytes
- Version: 4.2.1
- Release date: 2023-04-14 22:33:55

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

- binwalk -eM --directory known_firmware/extracted/4d50428028b63b35 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/4d50428028b63b35/_openwrt-axt1800-4.2.1-0414-1681482936.tar.extracted/sysupgrade-glinet_axt1800/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
