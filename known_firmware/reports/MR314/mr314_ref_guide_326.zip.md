# Firmware Audit: MR314 / mr314_ref_guide_326.zip

- Source URL: https://www.downloads.netgear.com/files/mr314_ref_guide_326.zip
- Local path: known_firmware/firmware/MR314/mr314_ref_guide_326.zip
- SHA-256: `b5e4b4176854d77b5f3f64b9a1731b63a798546417051c5f9d5b5dea35ca0b56`
- Size: 892261 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b5e4b4176854d77b exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
