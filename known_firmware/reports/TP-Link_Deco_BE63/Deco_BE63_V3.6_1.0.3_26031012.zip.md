# Firmware Audit: TP-Link Deco BE63 / Deco_BE63_V3.6_1.0.3_26031012.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202604/20260415/Deco BE63_V3.6_1.0.3_26031012.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE63/Deco_BE63_V3.6_1.0.3_26031012.zip
- SHA-256: `b3c23f8df9ebcfc57c9230eb53b8ae27d01683b2bbe67485a1a1ebc454427858`
- Size: 51403082 bytes
- Version: V3.6_1.0.3 Build 26031012
- Release date: 2026-04-15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, bOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b3c23f8df9ebcfc5 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
