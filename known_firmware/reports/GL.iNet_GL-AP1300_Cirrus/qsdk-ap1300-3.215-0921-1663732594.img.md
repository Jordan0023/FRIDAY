# Firmware Audit: GL.iNet GL-AP1300 Cirrus / qsdk-ap1300-3.215-0921-1663732594.img

- Source URL: https://fw.gl-inet.com/firmware/ap1300/release/qsdk-ap1300-3.215-0921-1663732594.img
- Local path: known_firmware/firmware/GL.iNet_GL-AP1300_Cirrus/qsdk-ap1300-3.215-0921-1663732594.img
- SHA-256: `72c276fdb6e76f66159e7889813dbd292bb7fda0ced4ce5b055f121eeaf62775`
- Size: 34738900 bytes
- Version: 3.215
- Release date: 2022-09-21 11:56:34

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/72c276fdb6e76f66 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
