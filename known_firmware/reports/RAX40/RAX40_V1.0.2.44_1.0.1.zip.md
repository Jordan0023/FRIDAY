# Firmware Audit: RAX40 / RAX40_V1.0.2.44_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX40/RAX40_V1.0.2.44_1.0.1.zip
- Local path: known_firmware/firmware/RAX40/RAX40_V1.0.2.44_1.0.1.zip
- SHA-256: `6584a2b9f5f761da5168d3970a541eb874cd52e7bb098c27e0ab381bc0a541f3`
- Size: 36629837 bytes
- Version: 0.2.44_1.0.1
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, BoA, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6584a2b9f5f761da exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/6584a2b9f5f761da/_RAX40_V1.0.2.44_1.0.1.zip.extracted/_RAX40-V1.0.2.44_1.0.1.img.extracted/squashfs-root/opt/lantiq/bin/drv_event_logger.ko -> /usr/lib/modules/3.10.104/drv_event_logger.ko; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
