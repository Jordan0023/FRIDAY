# ASUS RP-AX56 Unauthenticated RCE/DoS Triage

Date: 2026-07-24

## Outcome

No new unauthenticated RCE or DoS is confirmed in the latest available RP-AX56
firmware, 3.0.0.4.386_51891. The latest image does, however, retain dnsmasq
2.84 and therefore known prior art: CVE-2022-0934, a DHCPv6 single-byte
write-after-free with potential unauthenticated denial-of-service impact when
IPv6/DHCPv6 is enabled.

The older 3.0.0.4.386_42860 image is dynamically confirmed vulnerable to the
unauthenticated `/login.cgi` denial-of-service condition assigned
CVE-2023-34359. The exact firmware `httpd` crashed with SIGSEGV in isolated
ARM user-mode emulation. The CVE-2023-34358 request did not crash the tested
setup-state profile.

No unauthenticated RCE claim is supported by the evidence collected so far.
The next LAN service, `infosvr`, was also dynamically exercised on both exact
firmware versions; no command execution or parser DoS was reproduced.
`cfg_server` was subsequently compared and exercised. The latest binary has a
direct minimum-length fix for the historical ConnDiag short-packet class, and
no new RCE or DoS was confirmed.
Both `miniupnpd` versions were then exercised across HTTP, SOAP, GENA, and SSDP
parsers. No crash or command-execution path was confirmed.
The unchanged dnsmasq binary was subsequently identified as version 2.84,
which predates the CVE-2022-0934 fix. Its live DNS and DHCPv4 parsers survived
the bounded matrix; DHCPv6 exposure is configuration-dependent.

## Firmware examined

| Version | Release date | Archive SHA-256 |
| --- | --- | --- |
| 3.0.0.4.386_51891 | 2023-06-30 | `296921c9e504780c75cdc8d6957661dd1ab52cb27709eee129e32ce5255fc905` |
| 3.0.0.4.386_42860 | 2021-06-09 | `eb39365e9847ca830a67f626e1295785dd87837d4c3e0a031452b0bcad8a5e4c` |

The images were taken from the repository's ASUS download artifacts and their
UBIFS root filesystems were extracted locally.

## Exposed attack surface

The firmware is 32-bit ARM ASUSWRT and includes these LAN-facing candidates:

- `/usr/sbin/httpd`
- `/usr/sbin/httpds`
- `/usr/sbin/infosvr`
- `/usr/sbin/cfg_server`
- `/usr/sbin/miniupnpd`
- `/usr/sbin/dnsmasq`

The 51891 `httpd` embeds the pre-auth routes and dispatch entries
`login.cgi*`, `findasus.cgi`, `cfg_onboarding.cgi`, `appGet.cgi*`, and
`blocking_request.cgi*`. Route presence alone does not establish a
vulnerability.

## Patch-differential evidence

The security-relevant services changed between 42860 and 51891:

| Binary | 42860 SHA-256 | 51891 SHA-256 | Result |
| --- | --- | --- | --- |
| `httpd` | `0194c6115b18af9443992ccae6d3fe3b0df0d294c335151744ce16c15e7fac43` | `aa5f8d3a2a64e9ff3ea9ed997fc774f215077669336d3142bc39ff361b52a504` | changed |
| `infosvr` | `d5d8e0be8067e8118a20cd67929bc23b5ebd4978f64917b3472646d17c411a8d` | `667accc5ab7e13fffa66ad890cd397963c9b213a528c12965d89529ef2a1edc2` | changed |
| `miniupnpd` | `c2b6ee4ddf253c9dd92a0811396421f00915bd0b69ef19c0ea0705b5cd74ec16` | `3c30a0bb354963a7bfc62864bb9d985d609a9afd8f66535902c92d95ed983073` | changed |
| `cfg_server` | `c659d4637c34dc18a3aaad33dc534b8d4f062e8c5229c96f616a5e064e89dc92` | `4578801e3b86a5171181d1ef95764b4d028e0e8a214e2d6852ab17a1f2957a67` | changed |
| `dnsmasq` | `5645f92fd7030840cfc232d07a5ea9347d2dde315f6785441e2439369c06081d` | same | unchanged |

ASUS's 51891 release notes explicitly state that it fixed `httpd` DoS,
null-pointer dereferences, and a `cfg server` vulnerability. This aligns with
the binary changes and with the timing of CVE-2023-34358/34359.

Both `httpd` binaries have non-executable GNU stacks and partial RELRO. Neither
showed `BIND_NOW`, so neither has full RELRO. These mitigations do not prove or
disprove exploitability.

## Older-build DoS candidates

The two bounded regression cases for an isolated lab are:

1. A request to `/` with a one-byte body beginning with an integer
   (CVE-2023-34358 family). Public analysis attributes the crash to malformed
   JSON handling.
2. A request to `/login.cgi` with the ASUS Windows utility User-Agent and no
   authorization data (CVE-2023-34359 family). Public analysis attributes the
   crash to a null `strlen` in `login_cgi`.

The 42860 binary contains the relevant `/login.cgi` route, `login_cgi`,
`Content-Length` handling, and ASUSWRT request-processing lineage. Dynamic
testing confirmed the `/login.cgi` case: the service returned HTTP 200 before
the unauthenticated request, logged `SIGSEGV`, and stopped serving HTTP.

The exact 51891 `httpd` was replayed under the same component runtime and NVRAM
profile. Its PID remained unchanged and HTTP remained 200 after both regression
requests, supporting that the vendor fixed the confirmed login crash.

## RCE assessment

- CVE-2023-28702 is described as command injection in an ASUS router family,
  but the available product-specific evidence does not establish that RP-AX56
  exposes the vulnerable handler unauthenticated.
- CVE-2023-28703 is an administrator-required CGI stack overflow according to
  the public CVE record. It is therefore outside this investigation's
  unauthenticated criterion.
- `httpd` has local `system`/`popen` and unsafe-copy call sites in generated
  decompiler evidence, but no pre-auth attacker-controlled dataflow to those
  sinks has been established.
- The historical `infosvr` opcode-51 command-execution packet was replayed
  against both exact binaries. Neither executed the harmless marker command or
  spawned a child process. This is consistent with the `ateCommand_flag`
  command-dispatch guard added by ASUS.

## `infosvr` dynamic validation

Both exact ARM binaries bound UDP port 9999 in isolated component containers.
A valid unauthenticated opcode-31 discovery packet returned 512 bytes on each,
confirming that the real parser was active.

Each build then received 65 bounded packets covering the historical command,
16 truncated sizes, 30 opcode values, 12 declared command-length boundaries,
and five service/type header combinations. The original PIDs remained alive,
the historical marker file remained absent, and the syscall traces showed no
fatal signal or command `execve`.

Raw JSON and syscall evidence is preserved under
`known_firmware/emulation/ASUS_RP-AX56/infosvr-validation-2026-07-24/`.

## `cfg_server` dynamic validation

The 51891 UDP receive path checks that the `recvfrom` result is greater than 11
before entering ConnDiag packet processing. The 42860 path lacks this
caller-side guard. This is a concrete code-level fix for the historical
CVE-2022-38393 eight-byte trigger class and aligns with ASUS's cfg-server
security-fix release note.

Both parsers were brought up on TCP and UDP port 7788 using identical,
startup-only model/auth scaffolding. Each survived the published eight-byte
packet plus 74 adjacent UDP-length and TCP-header cases. The old profile did
not establish a real AiMesh group key, so its non-crash does not disprove
physical-device susceptibility; it is not promoted beyond a historical
vulnerable-code match. Raw evidence is under
`known_firmware/emulation/ASUS_RP-AX56/cfg-server-validation-2026-07-24/`.

## `miniupnpd` dynamic validation

The two MiniUPnPd files differ only in their embedded build dates; executable
code is byte-identical. Both exact binaries were brought up on isolated TCP
5000 and UDP 1900 listeners with only firewall bookkeeping replaced by a
no-op shim.

Each daemon survived 29 bounded HTTP-framing, SOAPAction, GENA-callback, and
SSDP cases. A valid root-description request returned HTTP 200 with 2737 bytes
before and after the corpus. The processes and listeners remained alive, and
their syscall traces contain no terminating memory-fault signal. The binary
also imports no direct command-execution API.

Raw evidence is under
`known_firmware/emulation/ASUS_RP-AX56/miniupnpd-validation-2026-07-24/`.

## `dnsmasq` validation

Both firmware versions contain the exact same dnsmasq file, SHA-256
`5645f92fd7030840cfc232d07a5ea9347d2dde315f6785441e2439369c06081d`.
The binary reports dnsmasq 2.84 and compile-time support for IPv6, DHCP, and
DHCPv6.

This establishes a known vulnerable-version match for CVE-2022-0934. The
official dnsmasq 2.87 announcement identifies that release as containing the
fix. The maintainer's official patch replaces message-type writes through a
pointer saved before `new_opt6()` can reallocate the output buffer. The
original report characterizes the primitive as a remotely triggered,
single-byte, non-arbitrary write to freed memory with likely denial-of-service
impact, not demonstrated RCE.

The RP-AX56 `rc` binary contains generators for `enable-ra`, `ra-param`,
stateful DHCPv6 ranges, and stateless DHCPv6 ranges. The affected parser can
therefore be configured on this product, but its live exposure depends on the
user's IPv6 settings.

It is not shown reachable at factory defaults. The exported `router_defaults`
tables in both exact `libshared.so` files set `ipv6_service=disabled`, and the
only model-default override table contains no IPv6 override. Focused
decompilation of the exact 51891 `start_dnsmasq` path shows that a zero result
from `get_ipv6_service()` bypasses `enable-ra` and both DHCPv6 range
directives. Enabling a supported IPv6 service after setup changes this
assessment.

The exact 51891 daemon processed 17 bounded DNS/UDP, DNS/TCP, and DHCPv4 cases.
A valid DNS response and DHCPDISCOVER/DHCPOFFER exchange confirmed active
parsers, and every post-case health check passed. No additional parser DoS was
found. DHCPv6 dynamic reproduction was blocked by ARM user-mode QEMU's lack of
the raw ICMPv6 socket dnsmasq requires; this is a lab limitation rather than a
negative result for physical hardware.

Raw evidence and the official patch are under
`known_firmware/emulation/ASUS_RP-AX56/dnsmasq-validation-2026-07-24/`.

## Confidence and limitations

- High confidence: firmware identity, filesystem contents, route strings,
  binary hashes, and version-to-version changes.
- High confidence: 42860 has an RP-AX56-specific unauthenticated `httpd`
  SIGSEGV under emulation; the same request does not crash the exact 51891
  component under the matched runtime.
- High confidence for the tested cases: both live `infosvr` parsers reject the
  historical command packet and survive the truncation, opcode, header, and
  declared-length matrices.
- High confidence: 51891 rejects sub-12-byte `cfg_server` UDP packets before
  the ConnDiag queue path; this guard is absent in 42860.
- High confidence for the tested cases: the byte-identical MiniUPnPd parser
  code in both builds survives the bounded HTTP, SOAP, GENA, and SSDP corpus.
- High confidence: both releases ship the same dnsmasq 2.84 binary with
  DHCPv6 compiled in, and RP-AX56 configuration code can enable DHCPv6.
- High confidence from static stock-firmware evidence: both releases default
  `ipv6_service` to `disabled`, with no model override, and the 51891 dnsmasq
  generator skips DHCPv6 configuration in that state.
- High confidence for the tested cases: the exact 51891 DNS and DHCPv4 parsers
  survived all 17 cases, including active control exchanges.
- Not established: physical-device impact, WAN exposure, CVE-2023-34358 under
  other configured-state profiles, old-build ConnDiag impact after a real
  AiMesh key exchange, physical factory-reset confirmation, physical-device
  reproduction of CVE-2022-0934 after enabling IPv6, stateful flaws outside
  the tested matrices, or any unauthenticated RCE.

Physical confirmation of the `httpd` DoS, conditional DHCPv6 CVE-2022-0934
impact, old `cfg_server` stateful behavior, and the negative service results
should follow only on an owned RP-AX56 isolated from production networks.
