# Firmware Audit: RAXE290 / RAXE290-V1.0.9.82.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE290/RAXE290-V1.0.9.82.zip
- Local path: known_firmware/firmware/RAXE290/RAXE290-V1.0.9.82.zip
- SHA-256: `3de38411e3c0353b373dffe4eb632d6c9f750e3b96c885410b0fb9fc67298f8c`
- Size: 65923668 bytes
- Version: 1.0.9.82
- Release date: unknown

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `SShD`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3de38411e3c0353b exited 0: WARNING: Extractor.execute failed to run external extractor 'lzop -f -d '%e'': [Errno 2] No such file or directory: 'lzop', 'lzop -f -d '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
