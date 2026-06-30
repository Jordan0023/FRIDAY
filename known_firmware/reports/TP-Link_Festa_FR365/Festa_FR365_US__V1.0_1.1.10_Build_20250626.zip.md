# Firmware Audit: TP-Link Festa FR365 / Festa_FR365_US__V1.0_1.1.10_Build_20250626.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202510/20251017/Festa_FR365(US)_V1.0_1.1.10 Build 20250626.zip
- Local path: known_firmware/firmware/TP-Link_Festa_FR365/Festa_FR365_US__V1.0_1.1.10_Build_20250626.zip
- SHA-256: `3d1521d68f1e087d56099f1328eb5e0230cd24cb111f355e61da66a54c181fd4`
- Size: 35608452 bytes
- Version: V1.6_1.1.10 Build 20250626
- Release date: 2025-10-17

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3d1521d68f1e087d stopped: extraction exceeded 2048 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
