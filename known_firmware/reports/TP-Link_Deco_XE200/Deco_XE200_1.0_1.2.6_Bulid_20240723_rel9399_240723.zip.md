# Firmware Audit: TP-Link Deco XE200 / Deco_XE200_1.0_1.2.6_Bulid_20240723_rel9399_240723.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202408/20240808/Deco_XE200 1.0_1.2.6 Bulid 20240723 rel9399_240723.zip
- Local path: known_firmware/firmware/TP-Link_Deco_XE200/Deco_XE200_1.0_1.2.6_Bulid_20240723_rel9399_240723.zip
- SHA-256: `4f13e434df8accb975c8b00f52c3ed10ab5b072acea07ae3c56e8c9e72a50998`
- Size: 32307896 bytes
- Version: V1.6_1.2.6 Build 20240723
- Release date: 2024-08-08

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4f13e434df8accb9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
