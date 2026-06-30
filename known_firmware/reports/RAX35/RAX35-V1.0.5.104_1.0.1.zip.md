# Firmware Audit: RAX35 / RAX35-V1.0.5.104_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX35/RAX35-V1.0.5.104_1.0.1.zip
- Local path: known_firmware/firmware/RAX35/RAX35-V1.0.5.104_1.0.1.zip
- SHA-256: `40c5a76e0727b180b9ea504bf78ae3e928a9aa0761b2b705ee7fa3409faab9e1`
- Size: 39705699 bytes
- Version: 1.0.5.104_1.0.1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `Eval`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/40c5a76e0727b180 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/40c5a76e0727b180/_RAX35-V1.0.5.104_1.0.1.zip.extracted/_RAX35-V1.0.5.104_1.0.1.img.extracted/squashfs-root/opt/lantiq/bin/drv_event_logger.ko -> /usr/lib/modules/3.10.108/drv_event_logger.ko; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
