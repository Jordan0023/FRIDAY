# GT-BE98 Pro `wl_server_socket` LAN/WAN emulation

Date: 2026-07-24

## Outcome

The extracted stock `wl_server_socket` binary was executed under QEMU in an
isolated Docker topology with separate LAN and WAN broadcast domains:

- WAN: `eth0`, `172.30.99.2/24`
- LAN: `br0`, `172.30.98.2/24`
- no ports published to the host
- one client attached only to LAN and one client attached only to WAN

All checks passed:

| Launch/policy | Source | Destination | Result |
|---|---|---|---|
| Default binary launch (`eth0:8000`) | WAN client | WAN address | TCP reachable |
| Default binary launch (`eth0:8000`) | WAN client | WAN address | Fixed unauthenticated marker command executed |
| Default launch plus representative WAN INPUT drop | WAN client | WAN address | TCP blocked |
| Explicit `br0:8000` launch | LAN client | LAN address | TCP reachable |
| Explicit `br0:8000` launch | LAN client | LAN address | Fixed unauthenticated marker command executed |
| Explicit `br0:8000` launch | WAN client | LAN address | Unreachable |

The command proof used the binary's native 36-byte request header and remote
shell flag. It performed only a fixed inert write under `/tmp` inside the
disposable router container.

## Interpretation

This proves two component-level exposure modes:

1. If started with no interface argument, the stock binary binds to `eth0`.
   On the physical GT-BE98 Pro evidence collected for this investigation,
   `eth0` is the WAN interface. Without a WAN INPUT rule blocking TCP/8000,
   the unauthenticated command path is therefore WAN-reachable.
2. If the daemon is launched explicitly on `br0`, the unauthenticated command
   path is LAN-reachable.

A representative firewall rule successfully blocked the WAN case. This
demonstrates the relevant boundary, but it is not a claim that the emulated
rule exactly reproduces every rule in a running retail unit.

## Important limitation

No stock startup reference or demonstrated runtime trigger for
`wl_server_socket` has yet been found in this firmware image. Consequently,
this is strong proof of the vulnerable component and its binding behavior,
not yet proof that a factory-configured physical router starts the service.
Physical-device or full-system boot evidence is still required to classify
the shipping product as actively LAN- or WAN-exposed.

## Reproduction

Run:

```sh
python3 scripts/emulate_gtbe98_wl_lan_wan.py
```

The script creates exact-name, internal-only Docker networks and containers,
prints JSON results, and removes the lab resources in a `finally` block.
