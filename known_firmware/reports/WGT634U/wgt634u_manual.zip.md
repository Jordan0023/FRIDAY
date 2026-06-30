# Firmware Audit: WGT634U / wgt634u_manual.zip

- Source URL: https://www.downloads.netgear.com/files/wgt634u_manual.zip
- Local path: known_firmware/firmware/WGT634U/wgt634u_manual.zip
- SHA-256: `86a7608507c533f5389675967ee025d035a4c3fdfb08bc213b451ddebce62fda`
- Size: 3129445 bytes
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

- binwalk -eM --directory known_firmware/extracted/86a7608507c533f5 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
