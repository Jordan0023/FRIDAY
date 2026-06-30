# Firmware Audit: GL.iNet GL-AP1300 Cirrus / qsdk-ap1300-3.105-1207-1607326585.img

- Source URL: https://fw.gl-inet.com/firmware/ap1300/release/qsdk-ap1300-3.105-1207-1607326585.img
- Local path: known_firmware/firmware/GL.iNet_GL-AP1300_Cirrus/qsdk-ap1300-3.105-1207-1607326585.img
- SHA-256: `3ba8948fd1e464f29a4eb0dae260362c71aaad772ddc275641380bd122d79c87`
- Size: 29102372 bytes
- Version: 3.105
- Release date: 2020-12-07 15:36:25

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3ba8948fd1e464f2 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
