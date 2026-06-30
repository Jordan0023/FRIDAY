# Firmware Audit: RAX70 / RAX70_V1.0.19.172.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX70/RAX70_V1.0.19.172.zip
- Local path: known_firmware/firmware/RAX70/RAX70_V1.0.19.172.zip
- SHA-256: `409d42a3d3209c629b60061e48a598f3ddca7e2e17f8af73f7fcd57f932f3e13`
- Size: 67756912 bytes
- Version: 0.19.172
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/409d42a3d3209c62 exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
