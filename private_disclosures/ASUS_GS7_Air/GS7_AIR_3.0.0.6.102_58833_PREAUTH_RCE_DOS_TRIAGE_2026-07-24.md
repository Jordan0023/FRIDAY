# ASUS ROG Strix GS7 Air pre-authentication RCE/DoS triage

Date: 2026-07-24

Verification update: on 2026-07-25 ASUS's live support API still listed
`3.0.0.6.102_58833` as the newest GS7 Air production firmware. Three
additional GS7 Air repetitions and a cross-model reproduction on the latest
GS7 Bear Brick firmware succeeded. Public prior-art searches found no matching
`netool.cgi` worker-exhaustion disclosure. See
`private_disclosures/ASUS_GS7_Air/GS7_AIR_ZERO_DAY_VERIFICATION_2026-07-25.md`.

## Scope and disposition

- Product: ASUS ROG Strix GS7 Air
- Firmware: 3.0.0.6.102_58833
- Package SHA-256:
  `a0ea5c3a242b006a91ff8d2d0a3e766798c249a0832ad5abe61461dae472af49`
- `httpd` SHA-256:
  `d7ac77b37044b6878ed460a46b77fa27765ea1445084560f746b9047f6edb1d3`
- `miniupnpd` SHA-256:
  `190dcf11c22da51d08e896e54442d06efb00a3d8b6c8a40c89143a930ec94108`
- `infosvr` SHA-256:
  `fd0a60828942c9820283e863f9e5779b69582e820053d5f1080661ec8a7bf3bf`
- Confirmed unauthenticated RCE: no
- Confirmed unauthenticated DoS on GS7 Air: yes in full-system emulation
- Confirmed mechanism: `netool.cgi` worker/process exhaustion
- Product zero-day claim: physical-device validation and prior-art review are
  still required

This pass transferred the EX2800/RAX30 process without assuming that NETGEAR
implementation details transfer to ASUS: complete filesystem extraction,
binary identity comparison, authentication-first HTTP route review, command
sink review, exhaustive decompilation of the model-specific UPnP daemon, and
construction of a network-isolated full-system image.

## Extraction correction

The automated firmware audit stopped after exceeding its 768 MB recursive
extraction limit and sampled only 12 executables. The actual firmware contains
a SquashFS filesystem at TRX offset `0x35b244`, size 54,938,221 bytes, with
2,458 inodes. Direct SquashFS extraction recovered 2,084 files, 200
directories, and 374 symlinks under:

`router-agent-results/gs7-air-triage/rootfs`

The earlier automated report is therefore insufficient for reachability or
negative-security conclusions.

## EX2800 command-injection transfer

The GS7 Air `miniupnpd` imports `snprintf` and `memcpy`, but not `system`,
`popen`, `_eval`, `strcpy`, or `sprintf`. Ghidra discovered and successfully
decompiled all 173 non-external, non-thunk functions (zero failures). Fourteen
functions met the broad source/route/sink correlation rule. The network
receive correlations use `memcpy`; no command-execution sink exists in the
binary.

This rejects a direct code-level transfer of the EX2800 UPnP command-injection
chain. It is a negative result, not proof that all parser states are safe.

Artifacts:

- `router-agent-results/gs7-air-triage/receipts/miniupnpd.json`
- `router-agent-results/gs7-air-triage/evidence/miniupnpd.jsonl`

## RAX30 callback-crash transfer

The GS7 Air contains a different `miniupnpd` build from the GS-BE7200:

- GS7 Air: `190dcf11...4108`
- GS-BE7200: `20e6527c...e6a`

The complete GS7 Air decompilation contains the expected GENA `Callback`,
`SUBSCRIBE`, and `UNSUBSCRIBE` paths. It has no unsafe string-copy import, and
the broad receive/sink candidates did not expose an obvious unbounded callback
copy. Static evidence therefore does not support the RAX30 crash transfer.
Dynamic GENA boundary and state-transition tests remain required before
closing the candidate.

## Byte-identical ASUS service transfer

Two particularly useful exact matches were established:

1. The GS7 Air `httpd` is byte-identical to the immediately preceding
   GS-BE7200 `httpd` (`d7ac77b3...b1d3`). It contains the same `netool.cgi`,
   `check_Auth.cgi`, `cfg_onboarding.cgi`, `SystemCmd`, and `syscmd.sh`
   machinery.
2. The GS7 Air `infosvr` is byte-identical to the fully exercised GS-BE7200
   daemon (`fd0a6082...3bf`).

The matching `httpd` is the build in which authentication-first reverse
engineering found that selected nominally authenticated handlers can continue
after an authentication redirect. In the GS-BE7200 lab this made
`netool.cgi` reachable without a session. Its apparent format-string and
shell-command-injection paths were rejected by the exact input allowlist, but
a bounded 40-request burst caused transient management-plane worker
exhaustion.

This identified the model-specific path to validate because the downstream
GS7 Air `rc`/`netool_main` binary is not byte-identical:

- GS7 Air `rc`: `02600421...3145`
- GS-BE7200 `rc`: `ca826b34...c3`

The GS7 Air `rc` does contain `/var/run/netool_socket`, the ping, traceroute,
nslookup, netstat, and netstat-nat command constructors, and `system()`-driven
diagnostic strings. No surviving allowlisted character was identified that
turns the option-injection surface into shell command execution.

## Confirmed emulated net-tool worker-exhaustion DoS

A disposable 1.6 GiB ext4 image containing the exact GS7 Air root filesystem
was built for the existing isolated ARM64 QEMU harness with the genuine
`httpd`, `miniupnpd`, `infosvr`, and `rc` binaries. All host forwards were
loopback-only and both synthetic LAN/WAN networks used QEMU `restrict=on`.

The final runner executes QEMU and its probes in one approved localhost
network context, dynamically selects a free loopback HTTP port, and removes
all unrelated host forwards. This completed direct model-specific validation.

An unauthenticated `GET /netool.cgi` returned two HTTP 200 status lines and
`{"successful":"0"}`, reproducing handler continuation after the
authentication redirect. A benign request reached the genuine GS7 Air
`rc/netool_main` daemon.

The bounded impact case used 40 requests at concurrency 20:

```text
type=3
target=192.0.2.1
pcnt=1
response=10
exec=10
```

Two independent runs reproduced the effect:

- run one: 30 of 40 burst requests timed out; the first three independent
  login controls timed out at six seconds;
- run two: 31 of 40 burst requests timed out; the first independent login
  control remained unavailable for 15.001 seconds, followed by recovery;
- the second run's stable pre-burst controls were 5.115 to 5.354 seconds
  (the first warm-up control was 10.834 seconds);
- the exact GS7 Air syscall trace recorded 42 `CLONE_THREAD` operations and
  41 `/bin/ping` executions; and
- `httpd`, `netool_main`, `miniupnpd`, and `infosvr` remained alive.

This is a reproducible, input-specific transient management-plane DoS through
worker/thread and child-process accumulation, not a daemon crash and not RCE.
The QEMU/strace baseline is slow, but the post-trigger 15-second failure,
request loss, syscall attribution, daemon liveness, and recovery distinguish
the effect from a generic boot or service failure.

### Conditional WAN-interface reachability

The harness was then extended with separate, dynamically allocated loopback
forwards to the synthetic LAN and WAN NICs. The bounded trigger was sent only
through the WAN NIC (`192.0.2.15`).

Direct WAN-interface results:

- unauthenticated `netool.cgi` again returned two HTTP 200 status lines and
  `{"successful":"0"}`;
- 33 of 40 WAN trigger requests timed out;
- the first independent WAN login control and the first independent LAN login
  control both remained unavailable for 15.015 seconds;
- subsequent WAN and LAN controls recovered;
- the trace again recorded 42 `CLONE_THREAD` operations and 41 ping
  executions; and
- the genuine daemons remained alive.

This confirms a global management-plane DoS when WAN traffic is permitted to
reach `httpd`. It does not establish factory-default Internet exposure. The
lab forwards directly to the WAN NIC and does not reconstruct the complete
production firewall. The firmware's management UI and NVRAM defaults use
`misc_http_x` to gate "Web Access from WAN", and the extracted default profile
has `misc_http_x=0`. Thus the current exposure classification is:

- LAN: unauthenticated and confirmed;
- WAN with remote administration/exposure enabled: confirmed in emulation;
- factory-default WAN/Internet exposure: not supported by current evidence.

### Unconditional-WAN chain attempts

On 2026-07-25 every identified prerequisite for crossing the default WAN gate
was tested against the exact GS7 Air image:

1. **Pre-auth remote-management mutation.** Seven `apply.cgi` variants covered
   a plain request, invalid cookie, invalid bearer token, dot path,
   double-slash path, semicolon suffix, and absolute-form URI. Each response
   contained one HTTP status and no second apply-handler response. None
   established `misc_http_x=1`.
2. **Firewall/NAT mutation.** The same requests attempted `fw_enable_x=0`,
   `restart_firewall`, `vts_enable_x=1`, and a TCP 40080-to-router-port-80
   virtual-server rule. They stopped at the authentication boundary with no
   apply-handler continuation.
3. **UPnP/PCP self-mapping.** Genuine GS7 Air `miniupnpd` returned HTTP 500
   with UPnP error 501 `ActionFailed` for a 40080-to-10.0.2.15:80 router
   self-map. The mapped-port control remained closed. A PCP MAP with
   `THIRD_PARTY` targeting 10.0.2.15 also left the mapped port closed.
   NAT-PMP cannot select a third-party internal client.
4. **IPv6.** The defaults have `ipv6_fw_enable=1`. The exact firewall
   templates classify INPUT by kernel interface and direct non-LAN traffic to
   the WAN chain. QEMU slirp cannot host-forward to the guest IPv6 address, so
   a direct WAN-v6 connection was not available with this backend; no
   configuration mutation, classification confusion, or default accept rule
   exposing `httpd` was found.
5. **Auxiliary forwarding services.** Defaults have `webdav_proxy=0`,
   `webdav_aidisk=0`, `sshd_enable=0`, and `vts_enable_x=0`. The included
   lighttpd configuration is for the optional captive portal. No
   default-enabled WAN listener forwarding to router port 80 was identified.

The positive control directly forwarded traffic to the WAN NIC and again
produced the two-status unauthenticated `netool.cgi` response. This shows that
the application-layer chain remains present while confirming that none of the
tested prerequisites bypasses the production WAN gate.

Disposition: no factory-default unconditional WAN path was established.

Lab artifacts:

- `known_firmware/emulation/ASUS_GS7_Air/full-system-lab/gs7-air-root.ext4`
- `known_firmware/emulation/ASUS_GS7_Air/full-system-lab/gs7-air-boot.cpio.gz`
- `scripts/probe_asus_gs7_air_netool_dos.py`
- `scripts/probe_asus_gs7_air_unconditional_wan.py`
- `router-agent-results/gs7-air-triage/netool-wan-dos-evidence-2026-07-24.txt`
- `router-agent-results/gs7-air-triage/unconditional-wan-chain-matrix-2026-07-25.txt`

## Conclusion and next validation

No unauthenticated RCE is established. The direct EX2800 command-execution
shape does not transfer, and static review found no command-capable bypass of
the GS7 Air net-tool input allowlist.

An unauthenticated transient DoS through `netool.cgi` worker/process
accumulation is confirmed against the exact GS7 Air binaries in full-system
emulation. The vulnerable HTTP dispatcher is byte-identical to the related
ASUS build, and the effect has now been attributed to the exact GS7 Air
downstream daemon.

Required confirmation sequence:

1. Complete normal setup on a GS7 Air without enabling remote administration.
2. Verify that unauthenticated `netool.cgi` returns the redirect plus its
   second handler response.
3. Run a bounded 40-request LAN burst with
   `type=3,target=192.0.2.1,pcnt=1,response=10,exec=10`.
4. Measure independent login/API latency, process/thread counts, recovery, and
   daemon liveness.
5. On hardware, repeat from WAN only if remote administration is explicitly
   enabled; do not infer factory-default Internet exposure.
6. Search dated public prior art and ASUS advisories before using the term
   zero-day.
