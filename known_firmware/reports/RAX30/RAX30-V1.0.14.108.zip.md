# Firmware Audit: RAX30 / RAX30-V1.0.14.108.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX30/RAX30-V1.0.14.108.zip
- Local path: known_firmware/firmware/RAX30/RAX30-V1.0.14.108.zip
- SHA-256: `6e7f95ab08e7b70280c3c97944e18d0895903b3cf836b8397fe1a20cd395e658`
- Size: 66681154 bytes
- Version: 1.0.14.108
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOA, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6e7f95ab08e7b702 exited 0: WARNING: Extractor.execute failed to run external extractor 'lzop -f -d '%e'': [Errno 2] No such file or directory: 'lzop', 'lzop -f -d '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
