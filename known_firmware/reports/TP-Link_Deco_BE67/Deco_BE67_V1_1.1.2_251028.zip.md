# Firmware Audit: TP-Link Deco BE67 / Deco_BE67_V1_1.1.2_251028.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202512/20251218/Deco BE67_V1_1.1.2_251028.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE67/Deco_BE67_V1_1.1.2_251028.zip
- SHA-256: `580c0d3aa37c42ed7c640d1a8dcbba7ef293260287ed20285301038525351de0`
- Size: 49698490 bytes
- Version: V1.6_1.1.2 Build 20251028
- Release date: 2025-12-18

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/580c0d3aa37c42ed exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
