# Firmware Audit: TP-Link Festa FR307-M2 / Festa_FR307-M2_UN__V1.0_1.2.5_Build_20251015.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202510/20251017/Festa_FR307-M2(UN)_V1.0_1.2.5 Build 20251015.zip
- Local path: known_firmware/firmware/TP-Link_Festa_FR307-M2/Festa_FR307-M2_UN__V1.0_1.2.5_Build_20251015.zip
- SHA-256: `53f2af96142b83945064383855fd9bb2ff463db60d2c9a97e2501298608c0708`
- Size: 30799667 bytes
- Version: V1.6_1.2.5 Build 20251015
- Release date: 2025-10-17

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `sShd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/53f2af96142b8394 stopped: extraction exceeded 2048 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
