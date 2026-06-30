# Firmware Audit: TP-Link Deco BE13000 / Deco_BE13000_V1.6_1.3.0_260330.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202604/20260429/Deco BE13000_V1.6_1.3.0_260330.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE13000/Deco_BE13000_V1.6_1.3.0_260330.zip
- SHA-256: `9541720cf3b7a7cdeb9356eb88e232cf30f702ca86cebb725c4125e42bcbd6a1`
- Size: 50092258 bytes
- Version: V1.6_1.3.0 Build 20260330
- Release date: 2026-04-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9541720cf3b7a7cd exited 0: WARNING: Extractor.execute failed to run external extractor 'unstuff '%e'': [Errno 2] No such file or directory: 'unstuff', 'unstuff '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
