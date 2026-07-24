# GT-BE98 Pro strongest-leads follow-up

## DUT utility / Telnet lead

Recursive decompilation resolves selector value `7` unambiguously:

- `FUN_000b093c` parses a structured user-agent string;
- its direct comparison with the literal `DUTUtil` returns `7`;
- `FUN_000b16dc` requires that result, then requires an additional
  11-byte prefix match before setting NVRAM and dispatching the fixed
  `run_telnetd` service token.

The only recovered caller of `FUN_000b16dc` is the large network-tool CGI
dispatcher at `0x7692c`. It invokes the Telnet helper only for a hidden
network-tool operation; the public administration UI exposes types 1, 3, 4,
5 and 6, not the DUT-only type 7.

The handler-table entry is:

```text
netool.cgi* -> input 0x35e04 -> handler 0x5d734 -> sentinel 0x20fe8
```

The trailing sentinel is shared by protected CGI entries and is absent from
explicit login handlers. The route name also carries the protected `*`
variant. No setup/QIS reference reaches the network-tool dispatcher or its
Telnet helper.

Conclusion: the Telnet capability is a real factory/DUT function, but the
stock web route that reaches it remains authentication-tagged. Spoofing the
`DUTUtil` user agent alone does not cross the HTTP authentication boundary.

## QIS/setup lead

`QIS_default.cgi` has its own handler-table entry and setup-state parsing, but
its recursively recovered references do not connect to:

- the DUT network-tool path;
- `run_telnetd`;
- `syscmd.sh`;
- `wl_server_socket`; or
- a one-shot authorization marker analogous to EX2800 `/var/upgUnauth`.

## Command dispatcher lead

The dispatcher at `0x51344` has a generic `system()` branch and therefore
remains a high-impact sink. Its recovered web caller is within the
authentication-tagged network-tool flow. No unauthenticated route-to-sink
edge was recovered.

## Result

- Hidden DUT Telnet activation logic: confirmed.
- `DUTUtil` selector semantics: confirmed.
- Generic command-execution sink: confirmed.
- HTTP route protection for the recovered caller: confirmed statically by
  handler-table classification.
- QIS/setup transition into the sink: not found.
- Unauthenticated Telnet activation or command execution: not confirmed.
