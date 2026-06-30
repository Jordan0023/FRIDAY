# Firmware Audit: TP-Link Deco PX50 / Deco_PX50_V1_1.2.3_20240724.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202410/20241008/Deco_PX50_V1_1.2.3_20240724.zip
- Local path: known_firmware/firmware/TP-Link_Deco_PX50/Deco_PX50_V1_1.2.3_20240724.zip
- SHA-256: `2a498424f1e0ad414b558fcd3b91beb7f09ca7012c88a65c9e9da3858107e4a9`
- Size: 33452091 bytes
- Version: V1.6_1.2.3 Build 20240724
- Release date: 2024-10-08

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----`

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Token`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2a498424f1e0ad41 stopped: extraction exceeded 2048 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
