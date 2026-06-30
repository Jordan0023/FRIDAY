# Firmware Audit: RAX38 / RAX38-V1.0.6.106_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX38/RAX38-V1.0.6.106_1.0.1.zip
- Local path: known_firmware/firmware/RAX38/RAX38-V1.0.6.106_1.0.1.zip
- SHA-256: `c4768e67e5d6d0d9f3215303b873337195a84710f83ea7ae628388acbb92fabf`
- Size: 39682264 bytes
- Version: 1.0.6.106_1.0.1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `Eval`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c4768e67e5d6d0d9 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/c4768e67e5d6d0d9/_RAX38-V1.0.6.106_1.0.1.zip.extracted/_RAX38-V1.0.6.106_1.0.1.img.extracted/squashfs-root/opt/lantiq/bin/drv_event_logger.ko -> /usr/lib/modules/3.10.108/drv_event_logger.ko; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
