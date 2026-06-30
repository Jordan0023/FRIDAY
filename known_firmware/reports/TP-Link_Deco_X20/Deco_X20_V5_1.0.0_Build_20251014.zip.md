# Firmware Audit: TP-Link Deco X20 / Deco_X20_V5_1.0.0_Build_20251014.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202510/20251030/Deco X20_V5_1.0.0 Build 20251014.zip
- Local path: known_firmware/firmware/TP-Link_Deco_X20/Deco_X20_V5_1.0.0_Build_20251014.zip
- SHA-256: `631a08720f55c8bb2dda476b07c5c9b897b4b12d487ca4c3b298038079697a80`
- Size: 30214051 bytes
- Version: V5.6_1.0.0 Build 20251014
- Release date: 2025-10-30

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `SSHd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/631a08720f55c8bb exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
