# Firmware Audit: RAX35 / RAX35v1_V1.0.3.88_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX35/RAX35v1_V1.0.3.88_1.0.1.zip
- Local path: known_firmware/firmware/RAX35/RAX35v1_V1.0.3.88_1.0.1.zip
- SHA-256: `4d883947727b5f5a92e916bbadc08ab12bda1cee4c448edaa1b6507f0542629b`
- Size: 37606820 bytes
- Version: 0.3.88_1.0.1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4d883947727b5f5a exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/4d883947727b5f5a/_RAX35v1_V1.0.3.88_1.0.1.zip.extracted/_RAX35v1_V1.0.3.88_1.0.1.img.extracted/squashfs-root/opt/lantiq/bin/drv_event_logger.ko -> /usr/lib/modules/3.10.104/drv_event_logger.ko; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
