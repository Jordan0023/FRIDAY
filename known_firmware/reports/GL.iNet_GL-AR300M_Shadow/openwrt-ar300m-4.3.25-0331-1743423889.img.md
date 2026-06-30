# Firmware Audit: GL.iNet GL-AR300M Shadow / openwrt-ar300m-4.3.25-0331-1743423889.img

- Source URL: https://fw.gl-inet.com/firmware/ar300m/nand/release4/openwrt-ar300m-4.3.25-0331-1743423889.img
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.25-0331-1743423889.img
- SHA-256: `8e528e385678baccf4b659215aea74744ed5a1d83ec5add2bd3eff42db8d1732`
- Size: 17695635 bytes
- Version: 4.3.25
- Release date: 2025-03-31 20:23:09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, bOA, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8e528e385678bacc exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
