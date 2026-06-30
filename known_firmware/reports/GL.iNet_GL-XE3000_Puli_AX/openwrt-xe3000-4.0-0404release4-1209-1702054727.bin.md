# Firmware Audit: GL.iNet GL-XE3000 Puli AX / openwrt-xe3000-4.0-0404release4-1209-1702054727.bin

- Source URL: https://fw.gl-inet.com/firmware/xe3000/release/openwrt-xe3000-4.0-0404release4-1209-1702054727.bin
- Local path: known_firmware/firmware/GL.iNet_GL-XE3000_Puli_AX/openwrt-xe3000-4.0-0404release4-1209-1702054727.bin
- SHA-256: `cbca8e7a2b4838e64766b276a05a674b5746826b2227721cfbfe514957398257`
- Size: 61481626 bytes
- Version: 4.4.4
- Release date: 2023-12-09 00:56:00

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

- binwalk -eM --directory known_firmware/extracted/cbca8e7a2b4838e6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/cbca8e7a2b4838e6/_openwrt-xe3000-4.0-0404release4-1209-1702054727.bin.extracted/sysupgrade-glinet_gl-xe3000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
