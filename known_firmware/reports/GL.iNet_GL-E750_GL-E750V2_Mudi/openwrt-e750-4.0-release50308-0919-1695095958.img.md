# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release50308-0919-1695095958.img

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release50308-0919-1695095958.img
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release50308-0919-1695095958.img
- SHA-256: `9e0b711e317ed2f6b42de7460427d31e4fb760419532d93e1eea91269774c7fc`
- Size: 21364736 bytes
- Version: 4.3.8
- Release date: 2023-09-19 11:57:55

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9e0b711e317ed2f6 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
