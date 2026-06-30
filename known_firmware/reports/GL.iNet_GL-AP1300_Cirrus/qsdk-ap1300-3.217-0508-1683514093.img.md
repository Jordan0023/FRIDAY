# Firmware Audit: GL.iNet GL-AP1300 Cirrus / qsdk-ap1300-3.217-0508-1683514093.img

- Source URL: https://fw.gl-inet.com/firmware/ap1300/release/qsdk-ap1300-3.217-0508-1683514093.img
- Local path: known_firmware/firmware/GL.iNet_GL-AP1300_Cirrus/qsdk-ap1300-3.217-0508-1683514093.img
- SHA-256: `df49296f935e0813911b55cd5c9c67cd1c8b107008f43bf5ed5f29adfdafd852`
- Size: 34738900 bytes
- Version: 3.217
- Release date: 2023-05-08 10:48:13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/df49296f935e0813 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
