# NETGEAR RAX30 V1.0.14.108 Unauthenticated IPP Service DoS Report

Date: 2026-07-23  
Firmware SHA-256: `6e7f95ab08e7b70280c3c97944e18d0895903b3cf836b8397fe1a20cd395e658`

## Executive summary

Two unauthenticated heap-overflow paths were dynamically reproduced in the
exact ARM `/bin/ippd` shipped with NETGEAR RAX30 firmware V1.0.14.108. A remote
client able to reach TCP/631 can terminate the daemon using either an oversized
request URI or an oversized HTTP header value. No credentials, session cookie,
or prior authenticated action is required by the request parser.

The daemon was not automatically restarted in the tested firmware environment,
so printing remained unavailable until service restart or reboot. This is a
reproducible denial of service against the IPP printing service, not a
demonstrated whole-router outage.

The service is conditionally enabled and appears to require the router's USB
printer feature. Real RAX30 hardware exposure and impact have not yet been
verified. Remote code execution was investigated but not demonstrated.

### Classification

- Product: NETGEAR RAX30
- Firmware tested: V1.0.14.108
- Component: `/bin/ippd`
- Attack surface: unauthenticated HTTP/IPP over TCP/631
- Weakness: unbounded copies into fixed-size heap objects
- Likely CWE: CWE-122 (Heap-based Buffer Overflow)
- Confirmed impact: IPP daemon termination and persistent service loss until
  restart in emulation
- Not demonstrated: arbitrary code execution or whole-router denial of service
- Exposure prerequisite: IPP/USB-printer feature enabled and TCP/631 reachable
- Novelty status: apparently unpublished; **zero-day candidate, not yet
  vendor/CNA-confirmed**
- Suggested CVSS v3.1 vector, if adjacent-network exposure is confirmed:
  `CVSS:3.1/AV:A/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H` (6.5, Medium)

The CVSS vector is provisional because physical-device reachability, default
feature state, restart behavior, and affected-version range remain unverified.

## Scope and result

The investigation initially covered the unauthenticated SOAP and UPnP
surfaces. Neither produced a confirmed RCE or persistent service DoS. Follow-up
analysis of the conditionally enabled IPP daemon produced the confirmed
service-level DoS described in this report.

This result applies to the tested firmware binary and controlled emulation
environment. It does not establish that every physical RAX30 exposes the
service, nor that other firmware versions are affected.

## Environment

- Exact RAX30 ARM userland from V1.0.14.108.
- Full-system ARM QEMU with kernel-backed fixed-address SysV shared memory.
- Loopback-only host forwarding: `127.0.0.1:25130` to guest TCP port 5000.
- Synthetic LAN identity for QEMU's forwarded peer.
- Hardware-only flash geometry supplied by a lab shim.
- Hardware-dependent SSK suppressed; stale CMS descriptors filtered by the
  lab shim.

The clean unauthenticated baseline returned `HTTP/1.1 200 OK` with 1,499 bytes.

## RCE validation

The daemon imports `system()` and `popen()`. Static cross-reference analysis
identified 14 `system()` callsites and 8 `popen()` callsites.

The lab interposed both functions without suppressing normal execution. It
also instruments marker-bearing `fopen()` paths. A
unique marker is emitted to the serial console if attacker input containing
`FRIDAY_RAX30_RCE_MARKER` reaches either sink.

Tests included:

- command syntax in `SOAPAction`;
- NTP, file-value, and firmware URL fields;
- all 101 generated `Service_Action` strings recovered from `soap_serverd`;
- all 186 exact `New...` XML field names recovered from the daemon;
- 16 parser-sized field batches supplied to every recovered handler;
- no-credential, invalid-bearer, and invalid-cookie request states.

Outcome:

- actions discovered: 101;
- actions tested: 101;
- handler/authentication/field-batch requests: 4,848;
- command-sink marker hits: 0;
- service failures during matrix: 0;
- post-matrix baseline: passed.

The response classifier recorded 95 ordinary SOAP responses, 3 apparent SOAP
faults, and 3 responses containing authentication-related text. These labels
are triage heuristics; the sink instrumentation and liveness checks are the
impact evidence.

## DoS validation

Bounded malformed-input and resource tests included:

- a 16 KiB action name;
- 512 levels of nested XML;
- a 256 KiB XML value;
- malformed and command-shaped values across the action matrix.
- 25 sequential and 40 requests at concurrency 8 for each of 128-level XML,
  512-level XML, 64 KiB values, and 256 KiB values.

Deep XML and the 256 KiB value could terminate or reset their individual
connections. A fresh baseline request succeeded immediately afterward. No
daemon exit, persistent hang, kernel fault, assertion, stack-smashing report,
OOM event, or required restart was observed.

The SOAP PID stayed constant during the expanded matrix. Observed RSS moved
from 11,648 KiB to 11,712 KiB without unbounded growth. Post-stress baseline
latency remained below 0.09 seconds.

Those outcomes are per-connection rejection/failure, not a confirmed
service-level denial of service.

## Evidence

- Matrix: `known_firmware/emulation/RAX30/full-system-lab/security-matrix.json`
- Serial evidence: `known_firmware/emulation/RAX30/full-system-lab/serial.log`
- Full-system harness: `scripts/emulate_rax30_soap_full_system.py`
- Security probes: `scripts/probe_rax30_soap_security.py`
- Action matrix: `scripts/audit_rax30_soap_matrix.py`
- Sink/lab shim: `known_firmware/emulation/RAX30/rax30_emulation_shim.c`

## Disposition

- Confirmed unauthenticated RCE: **no**
- Confirmed unauthenticated IPP service DoS: **yes, when `ippd` is enabled**
- Confirmed whole-router persistent DoS: **no**
- Per-connection malformed-input disruption: **yes**
- Apparently absent from reviewed public disclosures: **yes**
- Confirmed zero-day: **not yet; vendor/CNA duplicate determination pending**

The bounded SOAP coverage gaps addressed here do not provide absolute coverage
of non-SOAP firmware services, authenticated administrator workflows, or
hardware-only behavior unavailable on QEMU.

## Follow-up command-sink decompilation

The exact `soap_serverd` ELF was imported into a clean Ghidra project and the
previously unresolved command callers were explicitly recovered. The
request-handler `system()` calls use fixed firmware strings, or select between
fixed strings. Two statistics handlers construct fixed commands whose only
request-derived value is parsed by `atoi()`. A speed-test helper constructs
`cat /tmp/ookla_result.txt | %s`, but every caller supplies a fixed
firmware-owned filter string. Another pair of formatted `system()` calls uses
entries from a fixed global interface table rather than SOAP arguments.

This removes the strongest remaining static SOAP lead: no recovered
unauthenticated handler was shown to copy request text into a shell command.

The next-service triage examined the image's UPnP daemon. It imports `execvp()`
but not `system()` or `popen()`; both `execvp()` references belong to a generic
fork/daemon launch helper, not a SOAP action handler. The daemon still warrants
separate parser and memory-safety testing because it exposes unauthenticated
UPnP parsing and contains unbounded `strcpy()` references, but this pass did
not establish an unauthenticated request-to-command path.

## UPnP fixed-copy lead disposition

The two apparent strongest memory-corruption candidates were initially
recovered at virtual addresses `0x14da4` and `0x14e08` as functions that
allocated 32 bytes and then called `strcpy()`. Exact section and instruction
validation disproved both candidates:

- `0x14da4` is within the read-only HTTP status string table, between
  `Not Implemented` and `Forbidden`;
- `0x14e08` is within the read-only diagnostic-name string table, between
  `process_get` and `dispatch_http_request`;
- disassembly across the region decodes strings, not executable instructions;
- the decompiler's condition-flag input and missing callers were artifacts of
  manually forcing function creation in data.

The isolated full-system image did bring `/bin/upnp` up without credentials,
with UDP/1900 and a TCP listener on port 56688. A loopback-only GET reached the
daemon and returned its `LINUX/2.4 UPnP/1.0 BRCM400/1.0` 404 response. The
emulated CMS object store did not populate an Internet Gateway Device service
tree, so standard description/control URL requests returned 404; no action
handler or crash condition was reached.

This follow-up therefore removes, rather than confirms, the fixed-32-byte-copy
lead. It provides no evidence of unauthenticated RCE from those two addresses.

## Additional lead: UPnP event-subscription service DoS

A later isolated test found a distinct input-specific UPnP daemon exit that
does not depend on the USB printer or IPP feature. The exact firmware
`/bin/upnp` was listening without authentication on UDP/1900 and its
dynamically selected LAN HTTP port. SSDP discovery exposed a generated device
UUID and the `Layer3Forwarding:1` service path.

On a clean control boot, an unauthenticated `SUBSCRIBE` request containing the
ordinary short callback URL `http://10.0.2.2:9/event` did not terminate the
daemon. Its PID remained alive through repeated five-second health checks.

On a separate clean boot, a single otherwise equivalent `SUBSCRIBE` containing
a longer inert callback path caused:

- loss of the UPnP HTTP listener;
- `smd` to record the exit of `upnp`;
- shell wait status `139`, consistent with SIGSEGV; and
- `UPNP_EXITED=1`, with no automatic restart in the lab.

No SOAP action, credentials, printer configuration, or event-producing request
was needed. The malformed subscription alone was sufficient in the emulated
environment.

Evidence:

- control boot:
  `known_firmware/emulation/RAX30/full-system-lab/upnp-control-confirmation.log`
- crashing boot:
  `known_firmware/emulation/RAX30/full-system-lab/upnp-crash-confirmation.log`
- bounded reproducer:
  `scripts/reproduce_rax30_upnp_event_dos.py`

Disposition:

- unauthenticated UPnP daemon exit: **confirmed in emulation**
- USB printer/IPP prerequisite: **none**
- service-level UPnP DoS: **confirmed in the isolated lab**
- precise root cause and faulting instruction: **not yet established**
- production-hardware restart behavior: **not yet established**
- whole-router DoS: **not demonstrated**

This is presently a strong second vulnerability candidate, not yet a
hardware-confirmed finding. Physical validation must use an isolated WAN/LAN
test setup, first verify that stock UPnP is enabled and reachable, and use the
smallest bounded request necessary to distinguish the short control from the
crashing case.

## Next lead: IPP HTTP parser heap overflows

The next strongest RAX30 lead is `/bin/ippd`, a dynamically enabled Internet
Printing Protocol daemon. Unlike the discarded UPnP artifacts, the following
paths were validated as executable ARM code with direct callers:

- the daemon creates a TCP listening socket and accepts HTTP requests without
  an authentication check in the request parser;
- each accepted connection receives a `0x8c`-byte request object;
- the request line reader accepts as many as 1,023 bytes and tokenizes the
  method, URI, and HTTP version;
- the URI is copied with `strcpy()` into the request object at offset `8`,
  allowing a request URI substantially larger than the remaining object;
- each HTTP header node is allocated as `0x104` bytes, with apparent
  128-byte name and value fields at offsets `0` and `0x80`;
- the same 1,023-byte line reader passes the header name and value to two
  unbounded `strcpy()` calls, allowing either field to overwrite the node and
  its next pointer at offset `0x100`.

The binary is a fixed-address ARM executable, has a non-executable stack and
partial RELRO, and does not import stack-canary support. These properties make
the parser a credible unauthenticated heap-corruption and daemon-DoS candidate,
but they do not establish code execution.

Exposure is conditional: `ippd` is marked `BUILD_IPPD=dynamic`, is registered
as `EID_IPPD`, and requires a printer-definition file at startup. The firmware
image does not ship a populated definition file, suggesting that the service
is started only when a supported USB printer/configuration is present.

The initial disposition was a strong L3 static candidate. The impact testing
below raises the IPP service DoS path to reproducible dynamic evidence.
Real-device applicability still requires verifying that RAX30 exposes this
daemon when its printer feature is active.

### IPP emulation blocker resolved

The missing printer runtime state was reproduced without physical hardware:

- a synthetic definition named `lab` supplies a harmless make string and maps
  its device to a regular temporary output file;
- a dedicated full-system init starts the exact firmware `/bin/ippd`;
- the daemon remained alive as PID 91 with 584 KiB RSS;
- `/proc/net/tcp` confirmed an unauthenticated listener on `0.0.0.0:631`;
- QEMU exposed only `127.0.0.1:25133` to guest TCP/631;
- an empty `POST /printers/lab` with `Content-Type: application/ipp` returned
  `HTTP/1.1 200 OK` and a 10-byte IPP response;
- the daemon retained the same PID and RSS after the baseline request.

Artifacts:

- `known_firmware/emulation/RAX30/full_system_ippd_init`
- `known_firmware/emulation/RAX30/ippd-printers.conf`
- `known_firmware/emulation/RAX30/full-system-lab/ippd-serial.log`

The conditional-service emulation limitation is resolved. No overflow impact
is claimed from the baseline request alone.

### Confirmed unauthenticated IPP service DoS

Two independent bounded requests containing only inert repeated bytes reached
the statically identified copies and terminated the daemon:

1. A 257-byte URI reached the request-line `strcpy()` at call-return address
   `0x11b68`. Serial evidence recorded
   `FRIDAY_RAX30_LONG_STRCPY caller=0x00011b68 length=0x00000101`, immediately
   followed by `malloc(): corrupted top size` and `IPPD_EXITED=1`.
2. On a separate clean boot, a 256-byte HTTP header value reached the header
   node `strcpy()` at call-return address `0x124f4`. Serial evidence recorded
   `FRIDAY_RAX30_LONG_STRCPY caller=0x000124f4 length=0x00000100`, followed by
   the same allocator-corruption diagnostic and daemon exit.

The URI case was repeated after another clean boot with the same callsite,
length, allocator failure, closed connection, and daemon exit. The init
health loop did not restart `ippd`; its TCP/631 service therefore remained
unavailable until explicit restart or reboot.

Evidence:

- first URI run:
  `known_firmware/emulation/RAX30/full-system-lab/ippd-serial.log`
- clean URI reproduction:
  `known_firmware/emulation/RAX30/full-system-lab/ippd-repro-serial.log`
- independent header run:
  `known_firmware/emulation/RAX30/full-system-lab/ippd-header-serial.log`

Disposition:

- unauthenticated heap corruption: **confirmed in emulation**
- unauthenticated IPP daemon DoS: **confirmed and reproducible**
- whole-router DoS: **not demonstrated**
- remote code execution: **not demonstrated**
- default real-device exposure: **conditional printer-feature state still
  requires physical-device verification**

### IPP RCE control-flow validation

A fresh emulation run tested a narrower URI overwrite intended to avoid the
allocator's top-chunk abort and expose the first corrupted use. Fatal-signal
register tracing was enabled in the guest.

A 133-byte URI reached the same request-line copy and caused SIGSEGV with:

- `PC=0x1250c`
- `LR=0x124f4`
- `r0=0x43434343`
- `r3=0x43434343`

Disassembly confirms that `0x1250c` is the fixed linked-list traversal
instruction `ldr r0, [r0, #0x100]`. The URI overwrote the request object's
header-list pointer; the daemon then dereferenced the attacker-shaped value.
The program counter and link register were not derived from the request.

This raises the evidence from a generic allocator abort to confirmed control
of a data pointer and an attacker-selected invalid dereference. It still does
not prove control of `PC`, execution from attacker-controlled memory, a
function-pointer overwrite, ROP, or a harmless marker invocation. Consequently:

- unauthenticated service DoS remains confirmed;
- a memory-corruption primitive stronger than simple resource exhaustion is
  confirmed;
- unauthenticated RCE remains **not demonstrated**.

Register evidence:
`known_firmware/emulation/RAX30/full-system-lab/ippd-rce-fault-serial.log`

## Affected-version and hardware status

Only the exact `ippd` binary from RAX30 V1.0.14.108 was dynamically validated.
No minimum or maximum affected firmware version has been established. The
RAX30 was not marked End-of-Support in NETGEAR's June 2026 security advisory,
so coordinated disclosure and a supported-firmware fix request are
appropriate.

Physical validation should confirm:

1. enabling a supported USB printer starts `ippd`;
2. TCP/631 is reachable from an ordinary unauthenticated LAN client;
3. the bounded malformed request terminates only `ippd`;
4. whether a supervisor restarts the daemon on production hardware;
5. whether printing remains unavailable until restart or reboot; and
6. whether current and earlier supported firmware contain the same vulnerable
   copies.

## Novelty and zero-day assessment

Public-source review did not identify an advisory or CVE describing these exact
RAX30 `ippd` request-line and header-copy overflows. Known public RAX30
buffer-overflow reports reviewed during triage concern other CGI and SOAP
components. NETGEAR also uses non-descriptive PSV identifiers in some
advisories, however, and public searching cannot exclude a private report,
embargoed issue, silent fix, or duplicate tracked under a broader entry.

Accordingly, the defensible pre-disclosure description is:

> Apparently unpublished, emulation-confirmed unauthenticated IPP service DoS
> vulnerability and zero-day candidate in NETGEAR RAX30 V1.0.14.108.

The report should be upgraded to “confirmed zero-day” only after physical
reproduction and NETGEAR or a CNA confirms that the issue is not previously
known or duplicated.

## Recommended remediation

NETGEAR should replace the unbounded URI and header copies with length-aware
parsing that rejects inputs exceeding the destination fields before any copy.
Request-object and header-node lengths should be derived from the actual
destination sizes, not the 1,023-byte line-reader limit. The daemon should also
be supervised with bounded restart behavior, and TCP/631 should be exposed only
on intended trusted interfaces while the printer feature is active.

Until patched, users should disable USB printer sharing/IPP if unused and
restrict untrusted clients from reaching the router's TCP/631 service.

## Disclosure recommendation

Submit the report and minimal crash artifacts privately through NETGEAR's
security reporting channel. Ask NETGEAR to:

- confirm physical RAX30 exposure and affected versions;
- determine whether the finding duplicates an existing PSV;
- assign or request a CVE if novel;
- provide a remediation timeline; and
- coordinate publication after a fix is available.

Do not publish a weaponized proof of concept. A bounded reproducer using inert
bytes, accompanied by serial logs and firmware hashes, is sufficient for
vendor validation.
