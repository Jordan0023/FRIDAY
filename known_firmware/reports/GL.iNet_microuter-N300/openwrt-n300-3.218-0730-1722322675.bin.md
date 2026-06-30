# Firmware Audit: GL.iNet microuter-N300 / openwrt-n300-3.218-0730-1722322675.bin

- Source URL: https://fw.gl-inet.com/firmware/n300/v4/openwrt-n300-3.218-0730-1722322675.bin
- Local path: known_firmware/firmware/GL.iNet_microuter-N300/openwrt-n300-3.218-0730-1722322675.bin
- SHA-256: `3a5a43ab7e85332cf4f342c881de648557adeb5fbf40b4f11ff0644c87c65076`
- Size: 12583200 bytes
- Version: 3.218
- Release date: 2024-07-30 14:57:55

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3a5a43ab7e85332c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3a5a43ab7e85332c/_openwrt-n300-3.218-0730-1722322675.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
