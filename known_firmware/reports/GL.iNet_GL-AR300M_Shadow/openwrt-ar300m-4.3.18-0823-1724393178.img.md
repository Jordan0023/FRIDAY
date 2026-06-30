# Firmware Audit: GL.iNet GL-AR300M Shadow / openwrt-ar300m-4.3.18-0823-1724393178.img

- Source URL: https://fw.gl-inet.com/firmware/ar300m/nand/release4/openwrt-ar300m-4.3.18-0823-1724393178.img
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.18-0823-1724393178.img
- SHA-256: `cbea224daefc608418cbef01fa410a59af7d2d3f7c689d1cce3c77e2c7eb7200`
- Size: 17695578 bytes
- Version: 4.3.18
- Release date: 2024-08-23 14:04:37

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cbea224daefc6084 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
