# Firmware Audit: RAX35 / RAX35-V1.0.6.106_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX35/RAX35-V1.0.6.106_1.0.1.zip
- Local path: known_firmware/firmware/RAX35/RAX35-V1.0.6.106_1.0.1.zip
- SHA-256: `15023d21b8e01b202365d1035f85a2a3e776187c71c3ea7d534adefa8560ed55`
- Size: 39682259 bytes
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

- binwalk -eM --directory known_firmware/extracted/15023d21b8e01b20 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/15023d21b8e01b20/_RAX35-V1.0.6.106_1.0.1.zip.extracted/_RAX35-V1.0.6.106_1.0.1.img.extracted/squashfs-root/opt/lantiq/bin/drv_event_logger.ko -> /usr/lib/modules/3.10.108/drv_event_logger.ko; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
