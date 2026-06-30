# Firmware Audit: WNHDE111 / WNHDE111_SW_CD_v1_1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNHDE111/WNHDE111_SW_CD_v1_1.zip
- Local path: known_firmware/firmware/WNHDE111/WNHDE111_SW_CD_v1_1.zip
- SHA-256: `dee760fe3108b89e324072ac44f720a21abf493e71e66344790b41f4ef05d26b`
- Size: 6415130 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dee760fe3108b89e exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
