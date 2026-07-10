# Firmware Audit: TP-Link Deco BE65 / Deco_BE65_V1_1.0.8_240723.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202408/20240805/Deco BE65_V1_1.0.8_240723.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE65/Deco_BE65_V1_1.0.8_240723.zip
- SHA-256: `11ad518cc9a2b0ec46811405b6948c6d57558ac68b4a05be3b129231322f8172`
- Size: 38772915 bytes
- Version: V1.6_1.0.8 Build 20240723
- Release date: 2024-08-05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Sink Summary

- exec: 0
- file_write: 0
- popen: 0
- system: 0
- unsafe_copy: 0

### Config Writer Leads

No config-writer markers found in sampled strings.

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/TP-Link_Deco_BE65/Deco_BE65_V1_1.0.8_240723.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/11ad518cc9a2b0ec exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
