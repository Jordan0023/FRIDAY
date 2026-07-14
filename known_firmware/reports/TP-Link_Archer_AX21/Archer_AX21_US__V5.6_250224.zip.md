# Firmware Audit: TP-Link Archer AX21 / Archer_AX21_US__V5.6_250224.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202505/20250506/Archer AX21(US)_V5.6_250224.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX21/Archer_AX21_US__V5.6_250224.zip
- SHA-256: `021103002dbf716c12fc1dc0c0cf581de5eeb57a1ceea7c9f2f7a0cb8467a89d`
- Size: 24525417 bytes
- Version: V5.6_1.0.2 Build 20250224
- Release date: 2025-05-06

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

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

### Manual LuCI Review

The automated extraction did not descend into the UBI root-filesystem volume,
so the Archer AX21 image was also unpacked manually. The resulting SquashFS
contains the compiled Lua controller
`usr/lib/lua/luci/controller/admin/folder_sharing.lua` and its subprocess
helper.

The highest-interest flow is `folder_add`, which accepts share metadata and
ultimately invokes the `usbshare add` utility. Lua 5.1 bytecode disassembly
shows that the controller constructs a positional argument table containing
`usbshare`, `add`, and separate values for `-m`, `-d`, `-n`, `-r`, `-w`,
`-i`, `-t`, `-g`, and `-N`. The called `luci.model.subprocess.call` helper
passes that table to `nixio.execp(unpack(argv))`. It does not use the helper's
separate `/bin/sh -c` variants, so shell metacharacters in a share name or
path do not create a command-injection primitive in this flow.

Before constructing the argument table, `folder_add` derives the requested
path below the selected volume's mount directory and requires its prefix to
equal the configured volume `path_prefix`; otherwise it returns `Invalid
path`. No traversal or command-injection finding was established from this
controller. This is a manual negative disposition, not a claim that the rest
of the LuCI application is vulnerability-free.

Structured zero-day triage JSON: `known_firmware/reports/TP-Link_Archer_AX21/Archer_AX21_US__V5.6_250224.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/021103002dbf716c exited 0

## Decompiler Notes

- No ELF binaries found for Ghidra import.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
