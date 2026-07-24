# RP-AX56 `miniupnpd` Validation Evidence

Date: 2026-07-24

## Outcome

No unauthenticated RCE or DoS was reproduced in the RP-AX56 MiniUPnPd service.

The 42860 and 51891 executables have different hashes, but byte comparison
shows only eight differing bytes. Those bytes encode the build dates
`20210422` and `20230627`; executable code and parser strings are otherwise
identical.

| Firmware | Exact `miniupnpd` SHA-256 |
| --- | --- |
| 3.0.0.4.386_42860 | `c2b6ee4ddf253c9dd92a0811396421f00915bd0b69ef19c0ea0705b5cd74ec16` |
| 3.0.0.4.386_51891 | `3c30a0bb354963a7bfc62864bb9d985d609a9afd8f66535902c92d95ed983073` |

The binary imports no `system`, `popen`, or `exec` family API. That does not
alone rule out every RCE primitive, but removes the obvious direct
command-execution path.

## Dynamic validation

Both exact ARM binaries ran in separate Docker namespaces with network mode
`none`, synthetic `br0`/`wan0` interfaces, and syscall tracing. A small preload
shim made legacy `libiptc` firewall bookkeeping a no-op; it did not replace the
firmware HTTP, SOAP, GENA, MiniXML, SSDP, socket, or memory-handling code.

Each daemon bound TCP 5000 for HTTP/SOAP/GENA and UDP 1900 for SSDP. A
synthetic LAN client at `192.168.50.2` reached the service at
`192.168.50.1`. Before and after the parser corpus, `GET /rootDesc.xml`
returned `HTTP/1.1 200 OK` with a 2737-byte response.

The bounded corpus covered 29 cases:

- 10 HTTP framing cases, including short requests, unknown methods, a
  2048-byte path, a 4096-byte header, conflicting/negative/oversized content
  lengths, fragmentation, and an embedded NUL;
- six SOAPAction cases, including empty, oversized, fragmented, and
  CRLF-bearing values;
- six GENA callback cases using only inert loopback destinations, including
  empty, IPv4/IPv6, oversized, fragmented, and CRLF-bearing values; and
- seven SSDP datagrams, including a valid M-SEARCH shape, truncations, an
  oversized header, duplicate MX fields, and an embedded NUL.

Both original QEMU process IDs remained alive, TCP 5000 remained listening,
and the traces contain no terminating `SIGSEGV`, `SIGABRT`, or `SIGBUS`.
Malformed requests produced bounded errors such as 404, 412, 500, or
connection close.

## Artifacts

- `42860/*.json` and `51891/*.json`: machine-readable results and controls.
- `42860/miniupnpd.trace` and `51891/miniupnpd.trace`: syscall traces.
- Probe: `scripts/probe_asus_rpax56_miniupnpd.py`.

## Limitations

This is component emulation rather than physical-device validation. It covers
the exposed request parsers and common length/header boundaries but is not an
exhaustive stateful UPnP protocol fuzzer. The firewall shim also means port
mapping effects were intentionally not tested.
