# GT-BE98 Pro transfer of the EX2800 discovery method

The EX2800 result depended on a complete chain:

`factory-unconfigured state -> legitimate unauthenticated setup handler ->
one-shot auth-bypass marker -> existing command sink`

The equivalent GT-BE98 Pro search examined the stock `httpd` for setup-state
handlers, no-auth decisions, token endpoints, service-control actions and
command sinks. Recursive Ghidra string/table references were followed into
owning functions.

## Findings

- `check_noauth_referrer` is referenced by function `0xa7ec4`. Its recovered
  logic compares request/referrer state and optionally logs failures; it does
  not create an EX2800-like one-shot authorization marker.
- `run_telnetd` is referenced by function `0xb16dc`. That function first
  requires an internal mode selector to equal `7`, then requires an
  11-character case-insensitive prefix match before setting NVRAM and passing
  a fixed service token to the command dispatcher. No unauthenticated HTTP
  route was connected to this mode gate.
- `syscmd.sh` reaches the command dispatcher at `0x51344`. The dispatcher
  includes fixed-command cases and a generic `system()` branch. This confirms
  a powerful sink, but not an unauthenticated source-to-sink path.
- `QIS_default.cgi` is part of the setup routing logic, but recursive
  decompilation did not connect it to `run_telnetd`, `syscmd.sh`, or
  `wl_server_socket`.
- `enable_remote_control.cgi` and token endpoints occur in handler tables.
  Their table references alone do not establish that they bypass the
  authentication boundary.
- No stock file, init script, symlink or executable references
  `wl_server_socket` as a launch target.

## Result

The EX2800 method uncovered additional high-value GT-BE98 Pro ingredients,
especially the gated Telnet action and generic command dispatcher. It did not
produce a complete unauthenticated chain. The current evidence supports:

- dormant `wl_server_socket` pre-auth command primitive: confirmed;
- stock web command/service sinks: confirmed;
- setup/no-auth-to-command chain: not found;
- stock LAN/WAN unauthenticated RCE: not confirmed.

Raw recursive decompilation evidence is in
`httpd-preauth-chain-xrefs.txt`.
