# Firmware Audit: GL.iNet GL-AP1300 Cirrus / qsdk-ap1300-3.218-0726-1721960677.img

- Source URL: https://fw.gl-inet.com/firmware/ap1300/v4/qsdk-ap1300-3.218-0726-1721960677.img
- Local path: known_firmware/firmware/GL.iNet_GL-AP1300_Cirrus/qsdk-ap1300-3.218-0726-1721960677.img
- SHA-256: `c50c61c2bd3c6fa87c74afc317f4b4c7acc0e473f4f576725d74637b158eda18`
- Size: 34738900 bytes
- Version: 3.218
- Release date: 2024-07-26 10:24:37

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c50c61c2bd3c6fa8 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
