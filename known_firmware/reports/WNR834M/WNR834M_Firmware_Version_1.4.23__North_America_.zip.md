# Firmware Audit: WNR834M / WNR834M_Firmware_Version_1.4.23__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR834M/WNR834M%20Firmware%20Version%201.4.23%20(North%20America).zip
- Local path: known_firmware/firmware/WNR834M/WNR834M_Firmware_Version_1.4.23__North_America_.zip
- SHA-256: `0774122943e524f29b25d815c7a25f76d3e64874bc7cb076232e68fc46638ad5`
- Size: 5333050 bytes
- Version: 4.23__North_America_
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boA, httpd, mini_httpd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0774122943e524f2 exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
