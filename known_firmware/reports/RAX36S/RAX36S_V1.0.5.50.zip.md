# Firmware Audit: RAX36S / RAX36S_V1.0.5.50.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX36S/RAX36S_V1.0.5.50.zip
- Local path: known_firmware/firmware/RAX36S/RAX36S_V1.0.5.50.zip
- SHA-256: `15c9b43c1ff0b121e10f373b0a5f5d1fdb1e232825d5b094125433366ce03e0f`
- Size: 58295959 bytes
- Version: 0.5.50
- Release date: unknown

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `ssHd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/15c9b43c1ff0b121 exited 0: WARNING: Extractor.execute failed to run external extractor 'yaffshiv --auto --brute-force -f '%e' -d 'yaffs-root'': [Errno 2] No such file or directory: 'yaffshiv', 'yaffshiv --auto --brute-force -f '%e' -d 'yaffs-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
