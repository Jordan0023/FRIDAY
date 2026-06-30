# Firmware Audit: RAX40 / RAX40_V1.0.1.36_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX40/RAX40_V1.0.1.36_1.0.1.zip
- Local path: known_firmware/firmware/RAX40/RAX40_V1.0.1.36_1.0.1.zip
- SHA-256: `1ea49cb44b8bc420dde4b7fb44049a664b68e7d39a096382ebf0c8217447694d`
- Size: 36407471 bytes
- Version: 0.1.36_1.0.1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1ea49cb44b8bc420 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/1ea49cb44b8bc420/_RAX40_V1.0.1.36_1.0.1.zip.extracted/_RAX40-V1.0.1.36_1.0.1.img.extracted/squashfs-root/opt/lantiq/bin/drv_event_logger.ko -> /usr/lib/modules/3.10.104/drv_event_logger.ko; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
