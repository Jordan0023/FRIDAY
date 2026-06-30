# Firmware Audit: RAXE500 / RAXE500-V1.2.14.114_2.0.67.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE500/RAXE500-V1.2.14.114_2.0.67.zip
- Local path: known_firmware/firmware/RAXE500/RAXE500-V1.2.14.114_2.0.67.zip
- SHA-256: `b1a11003db07a998df113338b035e066dee7cd503b62126a1fdb9a789a9b22f3`
- Size: 83132824 bytes
- Version: 1.2.14.114_2.0.67
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eVaL`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b1a11003db07a998 stopped: extraction exceeded 60000 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
