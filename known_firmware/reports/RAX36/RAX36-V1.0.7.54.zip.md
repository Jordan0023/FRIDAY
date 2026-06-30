# Firmware Audit: RAX36 / RAX36-V1.0.7.54.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX36/RAX36-V1.0.7.54.zip
- Local path: known_firmware/firmware/RAX36/RAX36-V1.0.7.54.zip
- SHA-256: `7dfad4f35401482f562210c3406de68b3cc3bf1b886819feeb965ba161dcd200`
- Size: 60767433 bytes
- Version: 1.0.7.54
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7dfad4f35401482f exited 0: WARNING: Extractor.execute failed to run external extractor 'yaffshiv --auto --brute-force -f '%e' -d 'yaffs-root'': [Errno 2] No such file or directory: 'yaffshiv', 'yaffshiv --auto --brute-force -f '%e' -d 'yaffs-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
