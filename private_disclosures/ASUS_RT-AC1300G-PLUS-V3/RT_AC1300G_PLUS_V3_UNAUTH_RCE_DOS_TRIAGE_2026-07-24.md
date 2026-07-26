# ASUS RT-AC1300G Plus V3 Unauthenticated RCE/DoS Triage

Date: 2026-07-24

## Outcome

An unauthenticated denial of service is dynamically reproduced in the exact
stock `httpd` from firmware 3.0.0.4.386_51312. A single request to
`/login.cgi` using the ASUS Windows utility User-Agent caused the MIPS process
to terminate with SIGSEGV. A control request succeeded immediately before the
probe and failed afterward.

This is **not presented as a new zero-day**. The request and failure mode match
the publicly disclosed CVE-2023-34359 bug family. The useful new result is an
exact-build/product confirmation for RT-AC1300G Plus V3 and three models that
ship a byte-identical `httpd`:

- RT-AC57U V3
- RT-AC58U V3
- RT-AC59U V2

No unauthenticated RCE is confirmed.

## Firmware identity

- Product: ASUS RT-AC1300G Plus V3
- Firmware: 3.0.0.4.386_51312
- Archive: `FW_RT_AC1300G_PLUS_V3_300438651312.zip`
- Archive SHA-256:
  `2173b5a63e83720b556e6fe1956446e8559b16efd9ea927cb3ff98894461f6c1`
- `httpd` SHA-256:
  `e04b631a12452c915a91c9c330d9258464c62f8e337205ca23cc868b5aa92297`
- `infosvr` SHA-256:
  `fa372130eac00ae5cc4d3ecbb1a71c6db47e2d76f2a94667d1c15a5772d6f07b`

The binaries are 32-bit big-endian MIPS ASUSWRT/uClibc executables.

## Factory-setup HTTP reachability

The exact stock `httpd` was started under MIPS user-mode emulation with a
minimal, allocation-free NVRAM shim. The shim set `x_Setting=0`,
`restore_defaults=1`, LAN interface `lo`, and a non-privileged lab port.

An unauthenticated request to `/` returned HTTP 200 and redirected to:

```text
/QIS_wizard.htm?flag=welcome
```

This confirms that the real HTTP parser and setup-state routing were active
before the crash test.

## Reproduced denial of service

The crashing request was:

```http
GET /login.cgi HTTP/1.1
Host: 127.0.0.1
User-Agent: asusrouter-Windows-DUTUtil-1.0.1.278
Connection: close

```

Observed result:

- baseline HTTP health: live
- probe response: HTTP 200, 235 bytes
- post-probe HTTP health: dead
- emulator termination: target SIGSEGV
- authentication supplied: none

The adjacent CVE-2023-34358 regression request (`GET /` with a one-byte body)
returned HTTP 200 and did not terminate this exact process.

## `infosvr` result

The exact stock `infosvr` bound UDP/9999 in the same isolated component lab.
An unauthenticated opcode-31 request returned 512 bytes, confirming that the
real parser was active.

It survived:

- every truncated datagram size from the existing 16-case boundary set;
- opcodes 0, 1, 29 through 55, and 65535;
- the opcode-51 declared-length boundary matrix;
- the service/type header matrix.

Only opcodes 31, 52, 53, and 54 returned responses. Static dispatch recovery
also shows that these are the only implemented request opcodes. Opcode 51,
used by historical ASUS command-execution attacks, is not dispatched in this
binary. The inert marker command was not executed, and a final opcode-31
health request still returned 512 bytes.

Therefore no `infosvr` RCE or DoS was reproduced.

## Other relevant surface

The firmware also ships:

- `miniupnpd`
- `cfg_server`
- `dnsmasq`
- `aaews`
- `mastiff`

The exact dnsmasq reports version 2.84 with IPv6 and DHCPv6 compiled in. This
is old enough for known CVE-2022-0934 prior art, but the firmware default table
contains `ipv6_service=disabled`; it is not claimed reachable at factory
defaults here.

## Confidence and limitations

High confidence:

- firmware and binary identities;
- factory-setup HTTP control response;
- unauthenticated `httpd` process death and target SIGSEGV;
- byte identity across the four listed ASUS models;
- active `infosvr` parser and negative bounded corpus;
- absence of opcode-51 dispatch in this `infosvr`.

Not established:

- physical-device reproduction;
- WAN exposure;
- persistence beyond daemon restart;
- a distinct zero-day root cause;
- unauthenticated RCE;
- flaws outside the bounded protocol cases.

The next responsible step is physical confirmation on an owned,
factory-reset RT-AC1300G Plus V3 isolated from production networks, followed
by coordinated ASUS disclosure as a CVE-2023-34359 affected-product/build
confirmation.
