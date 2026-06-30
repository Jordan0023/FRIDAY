# Firmware Audit: RAX9 / RAX9-V1.0.3.32.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX9/RAX9-V1.0.3.32.zip
- Local path: known_firmware/firmware/RAX9/RAX9-V1.0.3.32.zip
- SHA-256: `0d20c9b101b197d3bacc1d8d8749db1716208984cd21432c6d98dca50c5c051d`
- Size: 22788329 bytes
- Version: 1.0.3.32
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0d20c9b101b197d3 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/0d20c9b101b197d3/_RAX9-V1.0.3.32.zip.extracted/_RAX9-V1.0.3.32.img.extracted/squashfs-root/usr/bin/nvram_set -> /usr/bin/nvram_get; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
