# Firmware Audit: WPN824N / WPN824N-V1.0.0.28.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WPN824N/WPN824N-V1.0.0.28.zip
- Local path: known_firmware/firmware/WPN824N/WPN824N-V1.0.0.28.zip
- SHA-256: `d3e2d4ec317d5b91aa0fb9b040ea26ad3db0c771bcf8239eab9125423f283cce`
- Size: 2898773 bytes
- Version: 1.0.0.28
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d3e2d4ec317d5b91 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
