# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.4.5-0811-1691737355.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.4.5-0811-1691737355.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.4.5-0811-1691737355.img
- SHA-256: `675c149df383e9075da003eb2e85801ba8f1ac78e848efe3baecf0d3654faaa2`
- Size: 58589184 bytes
- Version: 4.4.5
- Release date: 2023-08-11 15:00:32

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/675c149df383e907 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
