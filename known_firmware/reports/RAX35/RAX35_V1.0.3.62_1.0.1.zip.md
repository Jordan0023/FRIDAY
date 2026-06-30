# Firmware Audit: RAX35 / RAX35_V1.0.3.62_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX35/RAX35_V1.0.3.62_1.0.1.zip
- Local path: known_firmware/firmware/RAX35/RAX35_V1.0.3.62_1.0.1.zip
- SHA-256: `4ed6747f7848fd0049c550aaeaf94f6ee2f67f88045f2aeb560af373ceb698e4`
- Size: 37240748 bytes
- Version: 0.3.62_1.0.1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4ed6747f7848fd00 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/4ed6747f7848fd00/_RAX35_V1.0.3.62_1.0.1.zip.extracted/_RAX35-V1.0.3.62_1.0.1.img.extracted/squashfs-root/opt/lantiq/bin/drv_event_logger.ko -> /usr/lib/modules/3.10.104/drv_event_logger.ko; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
