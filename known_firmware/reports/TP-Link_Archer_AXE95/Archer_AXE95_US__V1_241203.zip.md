# Firmware Audit: TP-Link Archer AXE95 / Archer_AXE95_US__V1_241203.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202412/20241206/Archer AXE95(US)_V1_241203.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AXE95/Archer_AXE95_US__V1_241203.zip
- SHA-256: `abc55cc906642b719dddfa4123d9895e42f9809700948fc9f67ca46a84737462`
- Size: 43916718 bytes
- Version: V1.6_1.1.6 Build 20241203
- Release date: 2024-12-06

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOA, bOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eVal`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/abc55cc906642b71 exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
