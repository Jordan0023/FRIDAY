# Firmware Audit: RAX5 / RAX5_V1.0.9.44_1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX5/RAX5_V1.0.9.44_1.zip
- Local path: known_firmware/firmware/RAX5/RAX5_V1.0.9.44_1.zip
- SHA-256: `153256d317551b7bc486b51f79c10f81657e28237f83664c36924effa090408e`
- Size: 23320282 bytes
- Version: 0.9.44_1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/153256d317551b7b exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/153256d317551b7b/_RAX5_V1.0.9.44_1.zip.extracted/_RAX5-V1.0.9.44_1.img.extracted/squashfs-root/usr/bin/nvram_set -> /usr/bin/nvram_get; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
