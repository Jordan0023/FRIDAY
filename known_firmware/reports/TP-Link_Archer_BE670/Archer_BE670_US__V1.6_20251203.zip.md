# Firmware Audit: TP-Link Archer BE670 / Archer_BE670_US__V1.6_20251203.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202601/20260126/Archer BE670(US)_V1.6_20251203.zip
- Local path: known_firmware/firmware/TP-Link_Archer_BE670/Archer_BE670_US__V1.6_20251203.zip
- SHA-256: `01ff96c165ca4959d81912a14f22c4e45095426931a1a10facd72b4d383383c3`
- Size: 49101539 bytes
- Version: V1.6_1.0.2 Build 20251203
- Release date: 2026-01-26

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/01ff96c165ca4959 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
