# Firmware Audit: TP-Link Archer AXE95 / Archer_AXE95_US__V1_231027.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202311/20231122/Archer AXE95(US)_V1_231027.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AXE95/Archer_AXE95_US__V1_231027.zip
- SHA-256: `75888962a31cbeca16de4dcf937a9bf8f142da54714e8d726013eb9bd76cd7bc`
- Size: 43754272 bytes
- Version: V1.6_1.1.4 Build 20231027
- Release date: 2023-11-22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOA, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `EVal`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/75888962a31cbeca exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
