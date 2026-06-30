# Firmware Audit: TP-Link Archer AXE300 / Archer_AXE300_US__V1_230525.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202306/20230608/Archer AXE300(US)_V1_230525.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AXE300/Archer_AXE300_US__V1_230525.zip
- SHA-256: `6bd449a47797858a0637fca890dfe189eefc806d4af7051b838c4a45511d9d04`
- Size: 47569256 bytes
- Version: V1.6_1.0.9 Build 20230525
- Release date: 2023-06-08

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6bd449a47797858a exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
