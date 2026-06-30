# Firmware Audit: RAX36 / RAX36-V1.0.5.50.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX36/RAX36-V1.0.5.50.zip
- Local path: known_firmware/firmware/RAX36/RAX36-V1.0.5.50.zip
- SHA-256: `e0c2d86d8c8a2d528470033275e305425105d5b56d56a063da8afb8fd27adc03`
- Size: 58295877 bytes
- Version: 1.0.5.50
- Release date: unknown

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `ssHd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e0c2d86d8c8a2d52 exited 0: WARNING: Extractor.execute failed to run external extractor 'yaffshiv --auto --brute-force -f '%e' -d 'yaffs-root'': [Errno 2] No such file or directory: 'yaffshiv', 'yaffshiv --auto --brute-force -f '%e' -d 'yaffs-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
