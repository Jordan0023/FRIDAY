# Firmware Audit: WNR854T / WNR854T_V1.5.2NA.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR854T/WNR854T_V1.5.2NA.zip
- Local path: known_firmware/firmware/WNR854T/WNR854T_V1.5.2NA.zip
- SHA-256: `64c0ed87508b9a4f2f5119d51300a4b46638ef2630e4a950313e69ed96efb96c`
- Size: 5419327 bytes
- Version: 5.2NA
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `httpd, mini_httpd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/64c0ed87508b9a4f exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
