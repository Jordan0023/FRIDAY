# Firmware Audit: RAXE500 / RAXE500-V1.2.13.100_2.0.54.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE500/RAXE500-V1.2.13.100_2.0.54.zip
- Local path: known_firmware/firmware/RAXE500/RAXE500-V1.2.13.100_2.0.54.zip
- SHA-256: `00ac97d4fdf68deecec0c9266941155ca266954df8b17411e85e6e1411baa276`
- Size: 80996034 bytes
- Version: 1.2.13.100_2.0.54
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eVaL, eval`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/00ac97d4fdf68dee stopped: extraction exceeded 60000 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
