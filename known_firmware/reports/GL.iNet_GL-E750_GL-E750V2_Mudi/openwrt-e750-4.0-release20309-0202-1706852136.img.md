# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release20309-0202-1706852136.img

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release20309-0202-1706852136.img
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release20309-0202-1706852136.img
- SHA-256: `5df28bb4dae518f9f2ed052779758e8f3ba0af15e1fa3e41f4cc50a9233acef3`
- Size: 21233664 bytes
- Version: 4.3.9
- Release date: 2024-02-02 13:33:59

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5df28bb4dae518f9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
