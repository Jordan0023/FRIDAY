# Firmware Audit: RAXE450 / RAXE450-V1.2.14.114_2.0.67.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE450/RAXE450-V1.2.14.114_2.0.67.zip
- Local path: known_firmware/firmware/RAXE450/RAXE450-V1.2.14.114_2.0.67.zip
- SHA-256: `6ff1a084616ba4bbd484c728a6c1ea3e4d05b7c5d6843c9206b4ad9cce7883d2`
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

- binwalk -eM --directory known_firmware/extracted/6ff1a084616ba4bb stopped: extraction exceeded 60000 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
