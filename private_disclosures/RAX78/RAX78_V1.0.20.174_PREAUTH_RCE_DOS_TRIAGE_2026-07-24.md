# RAX78 V1.0.20.174 pre-authentication RCE/DoS triage

Date: 2026-07-24

## Status

No new unauthenticated RCE or reliable input-specific DoS is confirmed.

The latest downloaded firmware was tested:

- product: NETGEAR RAX78;
- firmware: V1.0.20.174;
- archive SHA-256:
  `09cd2acd7b5de824406a63f91f1d0d3afcb0bdbe7a4e584ed66aee9b51a6350a`;
- firmware rootfs: UBI volume containing a Squashfs 4.0 filesystem;
- architecture: 32-bit ARM EABI5.

## Public-prior-art boundary

The June 2026 NETGEAR advisory lists RAX78 under CVE-2026-9212. The issue is
adjacent-network command execution caused by insufficient authentication and
input validation, and the listed RAX78 fixed version is V1.0.19.172:

- https://kb.netgear.com/000070811/June-2026-NETGEAR-Security-Advisory
- https://nvd.nist.gov/vuln/detail/CVE-2026-9212

Therefore any matching path is known prior art, not a zero-day. V1.0.20.174 is
newer than the listed fixed version.

The following high-priority binaries are byte-identical between V1.0.19.172
and V1.0.20.174:

- `/usr/sbin/net-cgi`;
- `/usr/sbin/telnetenable`;
- `/usr/sbin/dnsmasq`.

`miniupnpd` differs in only 12 bytes, all in its embedded build identifier and
date. Its code is otherwise byte-identical. This makes V1.0.19.172 a useful
behavioral baseline and shows that V1.0.20.174 did not introduce a substantive
new parser implementation in these daemons.

## RAX30-method transfer

RAX78 does not use the proprietary Broadcom-derived `upnp` daemon affected by
the RAX30 event-subscription crash. It uses:

`miniupnpd 2.2.0-RC0 rax70-jira-250110-2f7a574 Sep 24 2025`

The genuine V1.0.20.174 daemon ran under qemu-arm in a privileged Docker
container with `--network none`. Only synthetic `br0`, LAN-client, and WAN
interfaces existed. The client bound to `192.168.1.2`; the daemon listened at
`192.168.1.1:56688`.

Ten RAX30-derived eventing cases covered:

- a valid control subscription;
- the RAX30-shaped 73-byte callback;
- missing callback scheme;
- callbacks of 8,192 and 65,536 bytes;
- 65,536-byte `TIMEOUT` and `NT`;
- duplicate callback fields;
- 8,192-byte renewal and unsubscribe SIDs.

The valid and long callback cases were accepted, invalid fields received HTTP
412, and the descriptor health check returned HTTP 200 after every case. No
daemon termination was observed.

## HTTP/SOAP parser matrix

A second bounded 35-case corpus covered:

- 18 truncated XML bodies;
- empty, malformed, 1,024-byte, and 8,192-byte `SOAPAction` values;
- negative, non-numeric, hexadecimal, signed, 2,147,483,647, and
  4,294,967,295 `Content-Length` values;
- a 16 KiB header;
- a 64 KiB body.

Malformed requests returned HTTP 500 or no response as expected. The
`/rootDesc.xml` health check returned HTTP 200 after every case. No
input-specific DoS was observed.

The daemon imports `popen`, but reverse engineering shows its sole call uses
the fixed command:

`/usr/sbin/port_conflict_detect -f /tmp/cache/netwall/upnp_conflict_detect`

Attacker values are written as fields in the input file; they do not alter the
command string. This candidate is rejected as command injection.

## Web surface

The management stack is:

`lighttpd -> /usr/sbin/net-cgi`

Notable unauthenticated or special-case paths in the firmware include
`/unauth.cgi`, `/recover.cgi`, `/securityquestions.cgi`,
`/passwd_reset.cgi`, `/soapapi`, and `/cgi-bin/genie.cgi`.

The genuine lighttpd and net-cgi were run together under qemu-arm. The lab
supplied the actual CGI filename, synthetic `br0` interface state, and
read-only partition device paths returned by `part_dev`. Shell execution was
replaced with a logging/no-side-effect shim; request parsing, authentication,
dispatch, and page generation remained in the genuine net-cgi.

`GET /unauth.cgi` returned HTTP 200 and the genuine V1.0.20.174 recovery page.

An 11-case unauthenticated raw HTTP matrix covered:

- 8,192- and 65,536-byte query strings and paths;
- 8,192- and 65,536-byte cookies;
- 65,536-byte `User-Agent` and `Host`;
- conflicting `Content-Length` fields;
- chunked form data;
- an encoded-NUL query.

Oversized request lines and headers received HTTP 431, malformed framing
received HTTP 400, and `/unauth.cgi` returned HTTP 200 after every case. No
web parser DoS was observed.

Canary metacharacters in the unauthenticated `serial_num` recovery field
received HTTP 400. The system-call logger captured only fixed initialization
commands:

- `echo '1' > /tmp/ABC_language_reboot`;
- `ip -6 neigh show > /tmp/ipv6_ip_mac`.

No canary value reached a command sink.

Reusable compatibility sources:

- `known_firmware/emulation/RAX78/rax78_lab_shell.c`;
- `known_firmware/emulation/RAX78/rax78_popen_shim.c`;
- `known_firmware/emulation/RAX78/rax78_net_cgi_launcher.c`.

The valid serial/security-question flow could not be completed without a
faithful device serial and encrypted configuration partition. This limits
conclusions about post-serial recovery handlers, but does not affect the raw
HTTP parser results above.

## Other exposed services

- `telnetenable` is byte-identical to the post-CVE-2026-9212 V1.0.19.172
  binary, but is not started for RAX78 in normal mode. `/etc/init.d/telnet`
  starts it only when `module_name` is `RAX10` or `R6700AX`. RAX78's factory
  mode can instead start `utelnetd`, with direct `/bin/sh` restricted to the
  calibration condition. This surface is not remotely reachable in the
  normal RAX78 configuration and is deprioritized.
- The genuine RAX78 dnsmasq 2.80 binary ran in DNS-only mode on synthetic
  `br0`. Ten UDP cases, four TCP framing cases, and 512 deterministic DNS
  mutations completed with the control query healthy. Cases covered truncated
  headers/labels, compression loops and chains, a maximum wire name, binary
  labels, EDNS length overrun, a 4 KiB datagram, and malformed TCP lengths.
  No DNS parser DoS was observed.
- Enabling the DHCP range reaches a deterministic qemu-arm `SIGBUS` during
  daemon initialization, before any network request. Missing `/dev/urandom`
  and `/dev/null` were separately corrected; the same pre-request fault
  remained. DHCP packet results are therefore not counted as live validation.

## Current disposition

- RAX30 UPnP DoS transfer: tested negative.
- MiniUPnPd malformed HTTP/SOAP DoS: tested negative.
- MiniUPnPd command injection: fixed-command path, rejected.
- Web pre-authentication parser DoS: tested negative.
- Recovery-field command injection: canary-to-system flow tested negative for
  the unauthenticated serial stage.
- Telnet activation: not started for RAX78 in normal mode.
- DNS parser DoS: tested negative.
- DHCP parser DoS: unresolved because of a pre-request qemu initialization
  fault.
- Confirmed new zero-day: none.
