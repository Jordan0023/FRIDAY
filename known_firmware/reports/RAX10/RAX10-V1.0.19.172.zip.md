# Firmware Audit: RAX10 / RAX10-V1.0.19.172.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.19.172.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.19.172.zip
- SHA-256: `0fe685e21b0ed524a5c587226f376b2d7bdc1903f9b0347e6dfa8fcaac415a4f`
- Size: 54088887 bytes
- Version: 1.0.19.172
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eVaL`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0fe685e21b0ed524 exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
