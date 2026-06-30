# Firmware Audit: TP-Link Deco BE68 / Deco_BE68_US__V1_1.0.4_250718.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202509/20250905/Deco BE68(US)_V1_1.0.4_250718.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE68/Deco_BE68_US__V1_1.0.4_250718.zip
- SHA-256: `662aa96260b9654422f80fe366a7109f5395a8728309e5f85de1bb9de5fff253`
- Size: 49413944 bytes
- Version: V1.60_1.0.4 Build 20250718
- Release date: 2025-09-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, bOA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/662aa96260b96544 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
