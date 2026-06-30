# Firmware Audit: GL.iNet GL-AR300M Shadow / openwrt-ar300m-4.3.17-0607-1717695110.img

- Source URL: https://fw.gl-inet.com/firmware/ar300m/nand/release4/openwrt-ar300m-4.3.17-0607-1717695110.img
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.17-0607-1717695110.img
- SHA-256: `cd698560ccbb0edd1b169c4b2da18d835331c4e6bc1ae17a0ffe192ac181d3ae`
- Size: 17696186 bytes
- Version: 4.3.17
- Release date: 2024-06-07 01:30:13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cd698560ccbb0edd exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
