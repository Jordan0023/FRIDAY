# ASUS GT-BE98 Pro Edition 20 3.0.0.6.102_39271 pre-auth RCE/DoS triage

Date: 2026-07-24

## Outcome

- Confirmed unauthenticated RCE: **no**
- Confirmed unauthenticated DoS: **yes in isolated full-system emulation;
  physical hardware pending**
- Confirmed mechanism: **`netool.cgi`/`netool` worker and process exhaustion**
- RAX30 GENA callback defect transferred: **no evidence**
- EX2800 setup/auth-marker command-injection chain transferred: **no**

This pass applied the EX2800/RAX30 process to the complete recovered root
filesystem rather than relying on the original five-executable automated
sample. It mapped the HTTP command sink, inspected the manufacturing shortcut,
identified the genuine UPnP implementation, and decompiled the genuine
`rc`/`netool` request and command paths.

The strongest result was promoted from a static candidate to a confirmed
emulated unauthenticated management-plane DoS. Edition 20 contains the same
architectural ingredients as the separately emulated GS-BE7200 net-tool DoS:
an HTTP `netool.cgi` route, a Unix-socket net-tool daemon, one `fork()` per
accepted request, blocking `waitpid()`, and attacker-selected repeated ping
parameters. Two fresh-boot runs proved that a no-session request continues
through the handler after the login response, reaches the genuine backend, and
causes an input-specific transient management outage.

## Firmware and principal binaries

- Product: ASUS ROG Rapture GT-BE98 Pro Edition 20
- Firmware: `3.0.0.6.102_39271`
- Release date: 2026-07-03
- Package SHA-256:
  `87681575e1f4a3621e8bec774290ffa84a9f8095855452482f3177bdc2d3a341`
- `httpd` SHA-256:
  `f1046100f0bd833789855dcafc27958e57cc655a87166eecc8b9219bdeb0db87`
- `rc` SHA-256:
  `b53c79752d7739e602250ac1dccc9351f5f11f2c26843ba0864adc4df5771cb4`
- `miniupnpd` SHA-256:
  `e7bcb71678a23876a62e1e755925d11c6bd406d5d593dc3c5a861b90c65cb018`
- `wl_server_socket` SHA-256:
  `cb3ee4e407d1868d4f33f7cf9d7cabcc6410fb6ede781410685976246a55cd25`

## EX2800-method transfer

The genuine HTTP binary contains the privileged `syscmd.sh`/`SystemCmd`
facility. The handler at `0x5134c` formats the global command into a bounded
stack buffer and calls `system()`. This is an important sink, but no
unauthenticated request-to-`SystemCmd` flow was established.

The alternate manufacturing function at `0xb16e4`:

1. requires the internal mode check to return ATE state `7`;
2. requires a case-insensitive `run_telnetd` prefix; and
3. only then dispatches `syscmd.sh`.

That is materially different from the EX2800 factory-unconfigured chain. No
equivalent unconfigured authentication marker or one-shot upgrade bypass was
identified in this firmware.

`wl_server_socket` remains present, but presence alone is not a product-level
RCE. The prior GT-BE98 Pro activation audit found this Broadcom diagnostic
component orphaned from stock startup. This pass found no Edition 20 evidence
that changes that disposition.

## RAX30-method transfer

Edition 20 uses ASUS `miniupnpd`, not the NETGEAR Broadcom-derived RAX30
daemon. The Edition 20 binary is not byte-identical to either RAX30 or the
GT-BE98 Pro 39262 build. Therefore the RAX30 callback crash cannot be
transferred by binary identity.

No command-execution conclusion is drawn from UPnP strings or imports. A
stateful genuine-daemon boundary matrix remains necessary for a strong
negative, including short and long `CALLBACK`, `SID`, `TIMEOUT`, and `NT`
headers, valid subscribe/renew/unsubscribe lifecycles, SOAP boundaries, SSDP,
NAT-PMP, and PCP. Until that run is complete, the correct disposition is
**not confirmed**, rather than safe.

## Confirmed emulated net-tool DoS

The HTTP route table contains `netool.cgi*`. The large handler reached from
the same table performs JSON/request processing and communicates with the
net-tool backend. Static analysis alone does not prove that the handler runs
after an unauthenticated login response on Edition 20.

The downstream implementation is concrete:

- `/sbin/netool` resolves to the genuine `rc` multicall binary.
- `netool_main` listens on Unix socket `/var/run/netool_socket`.
- The listener accepts a connection, reads a fixed 320-byte request, and
  accepts types 1 through 7.
- Every accepted request calls `fork()`.
- The parent calls blocking `waitpid()` before accepting the next request.
- Type 1 clamps a count to 10 and a duration to 60.
- Type 3 clamps a count to 100.
- Types 1 and 3 construct ping commands and invoke `system()`.
- Other accepted types invoke traceroute, nslookup, netstat, or related
  diagnostic commands.

This was validated using the same bounded request used on GS-BE7200:

```text
type=3
target=192.0.2.1
pcnt=1
```

The test ran only in the isolated firmware lab. A bounded parallel burst
recorded requests received by the genuine Unix-socket daemon, process creation
and child `execve` events, and independent `Main_Login.asp` controls before,
during, and after the burst.

## Evidence

- `known_firmware/reports/ASUS_ROG_Rapture_GT-BE98_Pro_Edition_20/httpd-preauth-sink-xrefs.txt`
- `known_firmware/reports/ASUS_ROG_Rapture_GT-BE98_Pro_Edition_20/httpd-netool-auth-xrefs.txt`
- `known_firmware/reports/ASUS_ROG_Rapture_GT-BE98_Pro_Edition_20/rc-netool-worker-xrefs.txt`
- `known_firmware/reports/ASUS_ROG_Rapture_GT-BE98_Pro_Edition_20/FW_GT_BE98_PRO_300610239271.zip.md`

## Current disposition

No unauthenticated RCE was confirmed. The net-tool finding is a confirmed
unauthenticated DoS in full-system emulation. Physical-device confirmation,
and factory-default WAN/firewall assessment are still required before
describing it as a confirmed product vulnerability.

A bounded public-prior-art check was performed on 2026-07-25 against the ASUS
Product Security Advisory index and public CVE/NVD search results. It found no
entry matching `netool.cgi` unauthenticated worker/process exhaustion. This
does not exclude a private, embargoed, differently described, or unindexed
duplicate. The appropriate novelty label is therefore **apparent zero-day
candidate**, not confirmed zero-day.

## Runtime follow-up

A dedicated Edition 20 full-system profile was built after the static pass:

- genuine 39271 root filesystem;
- genuine ARM32 `httpd`;
- genuine ARM32 `rc` launched through the `netool` multicall name;
- ARM64 Ubuntu kernel with ARM compatibility;
- two QEMU user-network backends with `restrict=on`;
- a single LAN HTTP forward bound to host loopback only; and
- an ARM32 ASUS NVRAM compatibility preload.

The guest reached the following controls:

```text
FRIDAY_GTBE98E20_NETOOL_READY=1
FRIDAY_GTBE98E20_HTTP_READY=1
tcp 0 0 0.0.0.0:80 0.0.0.0:* LISTEN
FRIDAY_GTBE98E20_HEALTH httpd=alive netool=alive netool_children=0
```

The first launch was discarded because the detached QEMU child was reaped by
the execution sandbox. The lab was changed to keep QEMU in a foreground
session. A second mismatch was corrected after the reused NVRAM state showed
`lan_ipaddr=192.168.1.1` while the first forward targeted `10.0.2.15`.

ARM32 syscall tracing showed that the apparent HTTP stall was outside the
daemon: its listening socket remained in `select()` and never received the
host-forwarded connection. The QEMU virtio NICs had enumerated in the reverse
order from the assumed backend mapping. Swapping the guest address assignments
fixed the lab. Both loopback-only forwards then returned HTTP 200 with the
complete 27,451-byte login page.

### Reproducible DoS result

Two fresh-boot runs used 40 requests with 20-way bounded parallelism. In both
runs a single no-session `netool.cgi` request returned a 574-byte response
containing two HTTP status lines, proving handler continuation after the
authentication response.

| Measurement | Run 1 | Run 2 |
|---|---:|---:|
| Baseline login | 6.574 s, success | 6.152 s, success |
| Burst timeouts | 27/40 | 26/40 |
| Independent login timeouts | 6/10 | 5/10 |
| Recovery | Controls 7-10 succeeded | Controls 6-10 succeeded |
| HTTP-to-net-tool connects | 43 | 42 |
| Genuine net-tool accepts | 42 | 42 |
| Backend process creations | 165 | 165 |
| Backend `execve` calls | 124 | 124 |

The second trace contains 41 direct executions of:

```text
/bin/ping -c 1 -W 10 192.0.2.1
```

Both daemons remained alive throughout. The independent login failures and
subsequent recovery establish transient resource starvation rather than a
daemon crash. The repeated result attributes the outage to attacker-selected
no-session diagnostic work, not generic boot slowness.

Runtime artifacts:

- `scripts/emulate_gtbe98e20_netool.py`
- `known_firmware/emulation/ASUS_GT-BE98_Pro_Edition_20/netool_full_system_init`
- `known_firmware/emulation/ASUS_GT-BE98_Pro_Edition_20/full-system-lab/serial.log`
- `known_firmware/emulation/ASUS_GT-BE98_Pro_Edition_20/full-system-lab/netool-dos-evidence-2026-07-24.txt`
- `known_firmware/emulation/ASUS_GT-BE98_Pro_Edition_20/full-system-lab/netool-dos-run1-2026-07-25.txt`
- `known_firmware/emulation/ASUS_GT-BE98_Pro_Edition_20/full-system-lab/netool-dos-run2-2026-07-25.txt`
- `known_firmware/emulation/ASUS_GT-BE98_Pro_Edition_20/full-system-lab/httpd.strace`
- `known_firmware/emulation/ASUS_GT-BE98_Pro_Edition_20/full-system-lab/netool.strace`
- `known_firmware/emulation/ASUS_GT-BE98_Pro_Edition_20/full-system-lab/httpd-run2.strace`
- `known_firmware/emulation/ASUS_GT-BE98_Pro_Edition_20/full-system-lab/netool-run2.strace`
