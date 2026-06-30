# Firmware Audit: RAX40 / RAX40_V1.0.1.41_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX40/RAX40_V1.0.1.41_1.0.1.zip
- Local path: known_firmware/firmware/RAX40/RAX40_V1.0.1.41_1.0.1.zip
- SHA-256: `3485372e0cf16ec096414270fed3cb770377c81cc2573200a30523104267ef03`
- Size: 36640799 bytes
- Version: 0.1.41_1.0.1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3485372e0cf16ec0 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/3485372e0cf16ec0/_RAX40_V1.0.1.41_1.0.1.zip.extracted/_RAX40-V1.0.1.41_1.0.1.img.extracted/squashfs-root/opt/lantiq/bin/drv_event_logger.ko -> /usr/lib/modules/3.10.104/drv_event_logger.ko; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
