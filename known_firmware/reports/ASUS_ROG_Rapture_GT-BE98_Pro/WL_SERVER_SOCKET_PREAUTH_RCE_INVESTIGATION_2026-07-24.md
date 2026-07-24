# GT-BE98 Pro `wl_server_socket` unauthenticated RCE investigation

Date: 2026-07-24 UTC

## Result

The stock `usr/sbin/wl_server_socket` contains and exposes an unauthenticated
remote-shell protocol. A loopback-only user-mode emulation reproduced command
execution through the service's TCP protocol.

This establishes a vulnerable component and an unauthenticated command
execution primitive when the service is running. It does **not** yet establish
a production device-level RCE because no stock startup reference or other
activation path for `wl_server_socket` was found in the extracted filesystem.

## Firmware and binary

- Product: ASUS ROG Rapture GT-BE98 Pro
- Firmware: `3.0.0.6.102_39262`
- Firmware SHA-256:
  `e9c3bdc196cdc00528be40fd92de066793dfada1b181ba01b142a5319a011eaf`
- Binary SHA-256:
  `cb3ee4e407d1868d4f33f7cf9d7cabcc6410fb6ede781410685976246a55cd25`
- Architecture: ARM 32-bit, dynamically linked

## Static proof

The server defaults to TCP port 8000. With no interface argument it uses its
compiled default interface; it also accepts an explicit interface and port.
The socket setup performs `bind()`, `listen(..., 4)`, and an unconditionally
repeating `accept()`.

The 36-byte remote header contains a flags word. In the main dispatcher,
`flags & 0x8` selects the remote-shell handler. No authentication, token,
source-address allowlist, or challenge occurs before this branch.

The shell handler:

1. accepts the received message as a command string;
2. creates an output file under `/tmp/RWL`;
3. forks;
4. invokes `/bin/sh -c <received command>` with `execl`;
5. returns captured output to the client.

The handler also has a direct `system(received_command)` branch for commands
containing `kill`.

Retained pseudocode:

- `router-agent-results/20260724T-GT-BE98-Pro-wl-server-audit/wl-server-full.c`
- `router-agent-results/20260724T-GT-BE98-Pro-wl-server-audit/wl-server-targets.c`

## Component-level runtime confirmation

The stock binary was executed with QEMU user mode and bound only to loopback:

```text
wl_server_socket lo 8000
```

The verifier sent a little-endian nine-word header with flag `0x8`, followed by
an inert command that wrote a fixed marker under `/tmp`. The stock server log
reported:

```text
REC : cmd 0  msg len 68  msg flag 8  msg status 0
```

The verifier then reported:

```text
response_status=0 response=b''
component_rce_reproduced=True
```

Verifier:
`scripts/probe_gtbe98_wl_server.py`

## Production reachability

A filesystem-wide search found no script, configuration file, symlink, or
other binary containing `wl_server_socket`, `/tmp/RWL`, or a remote-WL server
startup command outside the component itself. The stock `sbin/rc` and `httpd`
also contain no `wl_server_socket` reference.

Current classification:

- unauthenticated component command execution: **confirmed**
- TCP listener and protocol behavior when launched: **confirmed**
- stock boot activation: **not demonstrated**
- LAN/WAN reachability on a production router: **not demonstrated**
- device-level unauthenticated RCE: **not yet confirmed**

## LAN/WAN interface determination

The server does not bind `INADDR_ANY`. Its default interface string is
`eth0`; socket setup obtains that interface's IPv4 address with
`SIOCGIFADDR` (`ioctl 0x8915`) and binds TCP/8000 specifically to the
returned address.

GT-BE98 Pro runtime interface output published from a physical device
identifies:

- `br0` as the LAN bridge;
- `eth0` as the WAN-facing logical interface carrying the WAN address.

The firmware's `sbin/rc` independently treats `br0` as the LAN-side bridge.
No port-8000 WAN firewall exception was found.

Consequently:

- direct binding to the router's LAN address: **no, not by default**
- default component bind target: **WAN logical address (`eth0`)**
- Internet/WAN reachability through the stock firewall: **not demonstrated**
- possible access from a LAN client via the router's WAN address: **untested**
- normal stock activation of the service: **not demonstrated**

The command line permits an explicit interface argument, so launching the
binary as `wl_server_socket br0 8000` would make it a direct LAN listener.
No stock path that launches it with `br0` was found.

## Shared exposure

The exact binary is also present in several ASUS firmware images, including
the GT-BE98 Pro Edition 20, GS-BE12000, GS-BE18000, GS7 Pro, GS7 Pro Max,
ZenWiFi BQ16 Pro, and RT-BE96U. Binary presence alone does not prove that any
of those products start or expose the service.

## Next decisive tests

1. Capture `ps`, `ss -lntp`, and port-8000 reachability from a stock physical
   GT-BE98 Pro in normal and manufacturing/diagnostic modes.
2. Trace any authenticated or unauthenticated HTTP diagnostic action that can
   start arbitrary binaries or specifically activate remote-WL testing.
3. Inspect NVRAM-controlled diagnostic and factory-mode branches in `sbin/rc`
   for dynamically constructed execution paths.
4. If production activation is found, repeat the inert marker proof from an
   isolated LAN client and record the daemon UID.
# LAN/WAN emulation update

An isolated two-segment emulation using the extracted stock ARM binary
confirmed both conditional exposure modes. The default `eth0` launch was
reachable and accepted the fixed unauthenticated command from the WAN
segment until a representative WAN INPUT drop rule was installed. An explicit
`br0` launch was reachable and accepted the same proof from LAN, while the WAN
client could not reach the LAN address.

See `LAN_WAN_EMULATION_2026-07-24.md` and
`scripts/emulate_gtbe98_wl_lan_wan.py`. This does not remove the outstanding
activation caveat: no stock startup reference has been demonstrated.
