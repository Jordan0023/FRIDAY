# Firmware Audit: ASUS RT-N13U B1 / FW_RT_N13U_B1_2025F.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N13U_B1/FW_RT_N13U_B1_2025F.zip
- Local path: known_firmware/firmware/ASUS_RT-N13U_B1/FW_RT_N13U_B1_2025F.zip
- SHA-256: `754ca7e299de3d22d74822425e213d1b64586655b9297edefcfa195922066d6a`
- Size: 6440487 bytes
- Version: 2.0.2.5F
- Release date: 2012/04/30

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/754ca7e299de3d22 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
