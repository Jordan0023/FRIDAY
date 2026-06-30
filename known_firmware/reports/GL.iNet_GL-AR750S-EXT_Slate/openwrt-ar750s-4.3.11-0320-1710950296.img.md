# Firmware Audit: GL.iNet GL-AR750S-EXT Slate / openwrt-ar750s-4.3.11-0320-1710950296.img

- Source URL: https://fw.gl-inet.com/firmware/ar750s/release4/openwrt-ar750s-4.3.11-0320-1710950296.img
- Local path: known_firmware/firmware/GL.iNet_GL-AR750S-EXT_Slate/openwrt-ar750s-4.3.11-0320-1710950296.img
- SHA-256: `9aa051f3b408e6e34481f814887844d48122e8a34bd79b95de09b21981c95be0`
- Size: 18614046 bytes
- Version: 4.3.11
- Release date: 2024-03-20 23:56:40

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9aa051f3b408e6e3 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
