# Firmware Audit: ASUS RT-N13U B1 / FW_RT_N13U_B1_2025o.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N13U_B1/FW_RT_N13U_B1_2025o.zip
- Local path: known_firmware/firmware/ASUS_RT-N13U_B1/FW_RT_N13U_B1_2025o.zip
- SHA-256: `5a2849f2620b33e04a0e339eb7ae0d0cc605e86c4396426b6e00aec0a3b20737`
- Size: 6453485 bytes
- Version: 2.0.2.5o
- Release date: 2012/11/19

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5a2849f2620b33e0 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
