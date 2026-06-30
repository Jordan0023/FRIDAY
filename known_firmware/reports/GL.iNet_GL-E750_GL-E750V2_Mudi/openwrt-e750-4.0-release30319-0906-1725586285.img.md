# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release30319-0906-1725586285.img

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release30319-0906-1725586285.img
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release30319-0906-1725586285.img
- SHA-256: `f5c451f14a9b780579a368cce44c5f7a13e2ece2fc850c727c2a779d0de116e0`
- Size: 24117248 bytes
- Version: 4.3.19
- Release date: 2024-09-06 09:29:08

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f5c451f14a9b7805 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
