# Firmware Audit: RAX38 / RAX38-V1.0.3.94_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX38/RAX38-V1.0.3.94_1.0.1.zip
- Local path: known_firmware/firmware/RAX38/RAX38-V1.0.3.94_1.0.1.zip
- SHA-256: `2ff9e87047408024a8c3c5c4b4d5c7a359038853ca3e84d3c912a9c4e58ac13c`
- Size: 39686066 bytes
- Version: 1.0.3.94_1.0.1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2ff9e87047408024 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/2ff9e87047408024/_RAX38-V1.0.3.94_1.0.1.zip.extracted/_RAX38-V1.0.3.94_1.0.1.img.extracted/squashfs-root/opt/lantiq/bin/drv_event_logger.ko -> /usr/lib/modules/3.10.108/drv_event_logger.ko; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
