# 74-router campaign: stock-WAN unauthenticated RCE/DoS leads

Date: 2026-07-24

## Result

No new default-WAN vulnerability is confirmed yet. One candidate is strong enough to
advance to an isolated packet-level reproduction gate. The remaining high-ranked
scanner results do not yet satisfy stock WAN reachability plus attacker-controlled
dataflow.

## Priority 1: DHCPv6 DS-Lite AFTR command injection

Affected firmware instances in this corpus:

- NETGEAR RAX41V2
- NETGEAR RAX42V2
- NETGEAR RAX49S
- NETGEAR RAX54S
- NETGEAR RAX54SV2

Component: `/sbin/wdhcp6c`

Why it is strong:

1. `wdhcp6c` receives unauthenticated DHCPv6 replies from the upstream/WAN network
   (`recvmsg` in function `0x13ae4`).
2. The reply-processing path identifies `client6_recvreply` and handles a DS-Lite
   AFTR domain.
3. The client-script/environment construction path reads the parsed AFTR value from
   the option structure (`[r4 + 0xac]`, then the string at `[node + 0x10]`) and
   constructs `new_aftr_name=<value>` around `0x20904`-`0x209b8`.
4. It then formats the parsed value into:

       nvram set ipv6_dslite_aftr="%s"

   using `snprintf` at `0x209c0`-`0x209cc`, and executes that buffer with `system()`
   at `0x209dc`-`0x209e0`.
5. The outer double quotes do not make this safe if the DHCPv6 domain decoder
   preserves a quote, command substitution, backtick, newline, or another
   shell-significant byte.

Impact hypothesis: root command execution from a malicious or compromised DHCPv6
server on the WAN/ISP segment, without router-administration authentication.

What remains unproved:

- Whether the DHCPv6 domain-name decoder accepts and preserves a shell-significant
  byte in the AFTR option.
- Whether each model starts this client in its default IPv6 configuration, versus
  only when DS-Lite/DHCPv6 is enabled or negotiated.
- A controlled execution marker in an isolated emulator or sacrificial device.

Confidence: high-quality RCE lead; not yet a confirmed vulnerability.

## Priority 2: DHCPv6 command-buffer memory-safety paths

The same `client6_recvreply` function creates 256-byte stack command buffers using
unbounded `sprintf`/`strcat`, including:

- `dhcp6c_up %s %s %d`
- ` %s %d &`
- `dhcp6c_up %s`

and passes the result to `system()` (`0x15250`-`0x15368` and
`0x156bc`-`0x15748`).

This is a possible crash/RCE surface, but it is weaker than Priority 1 until the
origin and maximum decoded length of each `%s` argument are established. Several
arguments appear to be local interface/configuration values or canonical textual
addresses rather than arbitrary packet strings.

Confidence: medium DoS/memory-corruption lead.

## Leads downgraded by manual triage

- `udhcpc` `FUN_000111a0`: this is the program's large `main`; its `read`,
  `strcpy`, and `system` references are unrelated branches. The visible `strcpy`
  copies `inet_ntoa` output, and the scanner did not establish packet-to-sink
  flow.
- `wandetect main`: it mixes socket receive logic and several command executions,
  but current evidence does not establish that its socket is bound to a
  remotely reachable WAN port or that received bytes enter a command.
- `configd main`: `recvfrom` plus `execl` is only same-function correlation; its
  bind/interface and packet-to-exec dataflow remain unproved.
- Web, SOAP, and UPnP findings: potentially unauthenticated on LAN, but WAN
  administration/UPnP exposure is not enabled by default in the examined stock
  configurations.
- ASUS `dhcpfwd`: `fgets` and command/memory sinks occur together, but no
  packet-to-sink dataflow has been established.

## Strongest next gate

Build an isolated DHCPv6-server/client harness for the exact `wdhcp6c` binary and
its libraries. Feed a standards-shaped DS-Lite AFTR option containing one inert
shell-syntax marker at a time. Interpose or replace `system()` so commands are
captured but never executed. A valid proof requires:

1. the packet is accepted as a DHCPv6 reply;
2. the decoded AFTR reaches the command buffer unchanged;
3. the captured command demonstrates shell-token breakout; and
4. stock startup/configuration evidence shows the daemon is active on the WAN
   under a documented default or automatically negotiated mode.

Until all four hold, this remains a lead, not a zero-day claim.
