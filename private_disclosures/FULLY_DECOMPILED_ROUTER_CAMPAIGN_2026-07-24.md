# Fully decompiled router unauthenticated RCE/DoS campaign

Date: 2026-07-24

## Scope

The completed subset of
`20260722T235859Z-seventy-four-router-hunt` contains 15 firmware images whose
bounded campaign decompilation status is `complete`. The later exhaustive
all-ELF campaign is not complete and must not be represented as finished
coverage: its current summary records 9,095 unique ELF binaries but zero
processed results.

This campaign therefore separates:

- completed bounded decompilation;
- later focused/manual decompilation;
- static candidates;
- genuine-binary emulation;
- full-system or end-to-end HTTP confirmation; and
- physical-device validation.

## Strong confirmed findings

| Product | Firmware | Finding | Confirmation |
|---|---|---|---|
| NETGEAR EX2800 | 1.0.1.84 | Factory-unconfigured authentication bypass chained with `webupg` command injection; unauthenticated root RCE | End-to-end isolated firmware emulation |
| NETGEAR EX6110 | 1.0.1.84 | Same unauthenticated root RCE chain | Distinct official-image end-to-end emulation |
| NETGEAR EX5000 | 1.0.1.84 | Same unauthenticated root RCE chain | Distinct official-image end-to-end emulation, confirmed 2026-07-24 |
| NETGEAR RAX9 | 1.0.3.32 | Pre-authentication password-reset dispatcher command injection | Full-system MIPS emulation; root marker created |
| NETGEAR RAX9 | 1.0.3.32 | MiniUPnPd malformed `SOAPAction` daemon DoS | Genuine-binary emulation |
| NETGEAR RAX30 | 1.0.14.108 | UPnP `SUBSCRIBE` callback crash | Full-system emulation; daemon exited with status 139 |
| NETGEAR RAX29 | 1.0.14.108 | UPnP daemon DoS in shared family | Full-system emulation |
| GL.iNet Brume 3 | 4.8.6, 4.9.0 | Process-global unauthenticated WebUI authentication DoS | Native service and two-client HTTP emulation |
| GL.iNet Brume 2 | 4.7.4 | Process-global unauthenticated WebUI authentication DoS | Native two-client HTTP emulation |

The RAX30 result has strong matching public prior art and is not presently
classified as a zero-day. The other novelty classifications remain separate
from technical confirmation.

## Completed bounded-decompilation set

| Product | Version | Current disposition |
|---|---|---|
| ASUS ROG Rapture GT-BE98 Pro Edition 20 | 3.0.0.6.102_39271 | Static command and unsafe-copy sinks; targeted pre-auth reachability review pending |
| ASUS ROG STRIX GS-AX3000 | 3.0.0.4.388_23169 | Static HTTP and command helper evidence; targeted reachability review pending |
| NETGEAR RAX30 | 1.0.14.108 | Unauthenticated LAN UPnP daemon DoS confirmed |
| NETGEAR RAX36 | 1.0.7.54 | Focused network-daemon review performed; no new unauthenticated RCE confirmed |
| NETGEAR RAX36S | 1.0.7.54 family | Focused RCE/DoS triage performed; retain report-specific limitations |
| NETGEAR RAX41v2 | 1.1.6.38 | Focused HTTP/UPnP review performed; no confirmed RCE in current evidence |
| NETGEAR RAX42v2 | 1.1.6.38 | Emulation-only IPP termination did not transfer to the stock service; product-level DoS not confirmed |
| ASUS ROG Strix GS7 Air | 3.0.0.6.102_58833 | Static HTTP/SSH surface; targeted pre-auth reachability review pending |
| NETGEAR RAX49S | 1.1.6.38 | Focused review performed; no confirmed unauthenticated RCE in current evidence |
| NETGEAR RAX54S | 1.0.17.144 | UPnP/HTTP candidate evidence exists; report-specific validation must be consulted |
| NETGEAR RAX54Sv2 | 1.1.6.38 | Focused residual SOAP review performed; report-specific validation must be consulted |
| NETGEAR RAX78 | 1.0.20.174 | Focused pre-auth RCE/DoS triage performed; no confirmed RCE in current evidence |
| NETGEAR RAX9 | 1.0.3.32 | Pre-authentication root RCE and separate UPnP daemon DoS confirmed |
| NETGEAR RAXE290 | 1.0.9.82 | Focused HTTP/IPP/UPnP review performed; no confirmed RCE in current evidence |
| NETGEAR RAXE300 | 1.0.9.82 | Static HTTP and unsafe-copy evidence; sibling/focused dynamic review pending |

## Newly completed work

The EX5000 V1.0.1.84 official image was compared with the confirmed EX2800
chain. `webproc`, `webupg`, `mini_httpd`, and `logic` are byte-identical.

The first distinct-root run was a false negative because the disposable
runtime `/var` directory was not writable by the emulated Web UID. After
correcting only that lab permission, the original EX5000 components produced:

```text
setup_trigger_status=200
upgUnauth_created=true
webshell_status=200
upgUnauth_consumed=true
harmless_command_executed=true
command_output_reflected=true
unauthenticated_rce_reproduced=true
```

This promotes EX5000 from binary-equivalence evidence to end-to-end
official-firmware emulation confirmation.

## Next priority

1. Obtain and compare the official EX3110 1.0.1.84 image, then run the same
   harmless reflected-output proof.
2. Audit RAXE300 against the RAXE290 service families and validate only
   non-identical or newly reachable implementations.
3. Trace the ASUS GT-BE98 Pro Edition 20 and GS-AX3000 pre-auth route tables to
   the already decompiled command and unsafe-copy sinks.
4. Resolve the RAX54S and RAX54Sv2 report-specific candidates into a single
   corrected family matrix.
5. Resume the all-ELF exhaustive campaign separately; do not confuse bounded
   “complete” status with full-firmware all-binary coverage.

## Classification rule

A static sink or byte-identical binary is a lead. A vulnerability is marked
confirmed only after the unauthenticated entry point, required state, sink,
and security impact are reproduced through genuine components. RCE requires
an execution marker or reflected command output; a crash alone is DoS
evidence.
