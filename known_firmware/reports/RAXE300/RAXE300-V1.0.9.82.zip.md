# Firmware Audit: RAXE300 / RAXE300-V1.0.9.82.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE300/RAXE300-V1.0.9.82.zip
- Local path: known_firmware/firmware/RAXE300/RAXE300-V1.0.9.82.zip
- SHA-256: `08e53e0924044be57ce57e75b8c6b74e40e0513bbb3215fc70a47b5b8c1dbea6`
- Size: 65923672 bytes
- Version: 1.0.9.82
- Release date: unknown

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `SShD`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/08e53e0924044be5 exited 0: WARNING: Extractor.execute failed to run external extractor 'lzop -f -d '%e'': [Errno 2] No such file or directory: 'lzop', 'lzop -f -d '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
