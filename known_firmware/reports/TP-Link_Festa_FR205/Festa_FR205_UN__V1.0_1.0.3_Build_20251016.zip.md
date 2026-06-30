# Firmware Audit: TP-Link Festa FR205 / Festa_FR205_UN__V1.0_1.0.3_Build_20251016.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202510/20251017/Festa_FR205(UN)_V1.0_1.0.3 Build 20251016.zip
- Local path: known_firmware/firmware/TP-Link_Festa_FR205/Festa_FR205_UN__V1.0_1.0.3_Build_20251016.zip
- SHA-256: `2e40898d4726f5f48989c5c132c92cb16de2e57f05799136f87d52ab306a1035`
- Size: 20940445 bytes
- Version: V1.6_1.0.3 Build 20251016
- Release date: 2025-10-17

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eval, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2e40898d4726f5f4 stopped: extraction exceeded 2048 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
