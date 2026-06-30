# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release40312-0410-1712747721.img

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release40312-0410-1712747721.img
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release40312-0410-1712747721.img
- SHA-256: `4ab5682181365381e824b0821e49f22b42f352efec4df219c2f1084e426fcf8e`
- Size: 20840448 bytes
- Version: 4.3.12
- Release date: 2024-04-10 19:13:44

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4ab5682181365381 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
