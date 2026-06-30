# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.6.4-0904-1725421504.tar

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.6.4-0904-1725421504.tar
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.6.4-0904-1725421504.tar
- SHA-256: `e2946cade2d265f315035bfcadf675fad70c63476693df100740af6fde71c73a`
- Size: 47998979 bytes
- Version: 4.6.4
- Release date: 2024-09-04 11:06:41

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e2946cade2d265f3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e2946cade2d265f3/_openwrt-mt3000-4.6.4-0904-1725421504.tar.extracted/sysupgrade-glinet_gl-mt3000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
