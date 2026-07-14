# Firmware Audit: RAXE500 / RAXE500-V1.2.13.100_2.0.54.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE500/RAXE500-V1.2.13.100_2.0.54.zip
- Local path: known_firmware/firmware/RAXE500/RAXE500-V1.2.13.100_2.0.54.zip
- SHA-256: `00ac97d4fdf68deecec0c9266941155ca266954df8b17411e85e6e1411baa276`
- Size: 80996034 bytes
- Version: 1.2.13.100_2.0.54
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, boa`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Sink Summary

- exec: 3
- file_write: 6
- popen: 1
- system: 4
- unsafe_copy: 4

### Config Writer Leads

No config-writer markers found in sampled strings.

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/RAXE500/RAXE500-V1.2.13.100_2.0.54.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/00ac97d4fdf68dee stopped: extraction exceeded 768 MB

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE500_00ac97d4 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
