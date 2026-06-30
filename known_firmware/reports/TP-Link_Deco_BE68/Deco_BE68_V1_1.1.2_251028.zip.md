# Firmware Audit: TP-Link Deco BE68 / Deco_BE68_V1_1.1.2_251028.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202512/20251218/Deco BE68_V1_1.1.2_251028.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE68/Deco_BE68_V1_1.1.2_251028.zip
- SHA-256: `f42129b7a18a9f2bede49bdb6e3ffb3dec1305cd2768bd7dfa3f645406243fb7`
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

- binwalk -eM --directory known_firmware/extracted/f42129b7a18a9f2b exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
