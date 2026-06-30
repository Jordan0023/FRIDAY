# Firmware Audit: TP-Link Festa FR365 / Festa_FR365_US__V1.0_1.1.11_Build_20250627.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202510/20251017/Festa_FR365(US)_V1.0_1.1.11 Build 20250627.zip
- Local path: known_firmware/firmware/TP-Link_Festa_FR365/Festa_FR365_US__V1.0_1.1.11_Build_20250627.zip
- SHA-256: `61b7035ea3738759da99bf5f7b731737be6275c72c7ce490397adf2e7e5c4ec6`
- Size: 37979817 bytes
- Version: V1.6_1.1.11 Build 20250627
- Release date: 2025-10-17

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eVAL`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/61b7035ea3738759 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
