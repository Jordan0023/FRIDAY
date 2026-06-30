# Firmware Audit: ASUS RT-N13U B1 / FW_RT_N13U_B1_2025p.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N13U_B1/FW_RT_N13U_B1_2025p.zip
- Local path: known_firmware/firmware/ASUS_RT-N13U_B1/FW_RT_N13U_B1_2025p.zip
- SHA-256: `10b8ebfc79dccefa806f5203ce4dcbfe063b3f99ea637ca54c05e3b5d54fba4e`
- Size: 6414941 bytes
- Version: 2.0.2.5p
- Release date: 2015/04/13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/10b8ebfc79dccefa exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
