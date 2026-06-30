# Firmware Audit: WGR614V4 / wgr614v4_ref_manual.zip

- Source URL: https://www.downloads.netgear.com/files/wgr614v4_ref_manual.zip
- Local path: known_firmware/firmware/WGR614V4/wgr614v4_ref_manual.zip
- SHA-256: `02eb1a37aba2c2255581ba643d0d35422d4e94e135c611bdf16c08876fd3d29a`
- Size: 2639625 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/02eb1a37aba2c225 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
