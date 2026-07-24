# ASUS GT-BE98 Pro 3.0.0.6.102_39262 unauthenticated RCE research

Date: 2026-07-24

## Outcome

No product-level unauthenticated RCE is confirmed in this pass.

Two genuine root-command execution surfaces were resolved:

1. `wl_server_socket` executes commands received on TCP/8000 when manually
   launched, but stock-init emulation and a root-filesystem reference search
   found no production activation path.
2. The primary `httpd` contains the administrative `SystemCmd` shell facility,
   but it remains behind the normal authenticated WebUI dispatcher. Its
   alternate manufacturing dispatcher requires internal ATE state and a
   `run_telnetd` prefix.

These are high-impact latent components. Neither currently satisfies the
required unauthenticated, stock-active entry-point condition.

## Product status and firmware

ASUS was still publishing GT-BE98 Pro firmware and support material in 2026.
The inspected official package is:

- Product: ASUS ROG Rapture GT-BE98 Pro
- Version: `3.0.0.6.102_39262`
- Package SHA-256:
  `e9c3bdc196cdc00528be40fd92de066793dfada1b181ba01b142a5319a011eaf`
- `httpd` SHA-256:
  `3b8da6ae1c0c35d6ede142110b10491fc28d08231f3bc4636d56670ba5ecba2a`

## `wl_server_socket`

The genuine binary accepts a framed command and executes it when explicitly
started. Existing isolated dual-interface tests demonstrated command execution
on both manually selected interfaces.

That component result is not a product vulnerability by itself:

- stock full-system init did not launch the service;
- no TCP/8000 listener appeared;
- no startup script, service table, or configuration reference to
  `wl_server_socket` or `/tmp/RWL` was found outside the component;
- no symlink or alternate hard-link name points to the executable;
- the available owned-device evidence collector remains read-only and has not
  supplied physical activation evidence.

A cross-firmware activation audit inspected 20 extracted Broadcom router roots
containing one of two `wl_server_socket` builds. Every root had the same
pattern: zero external references to the executable name and zero external
references to its `/tmp/RWL` runtime directory. This supports classification
as an orphaned Broadcom Remote WL diagnostic utility included in vendor SDK
images, rather than a production service.

The generic full-system lab could not load the proprietary Broadcom kernel
modules, so its runtime negative is supporting evidence rather than the sole
basis for the conclusion.

Resolved disposition: **component command execution confirmed; product-level
unauthenticated RCE rejected on current firmware because no shipping activation
path exists**.

## HTTP `SystemCmd`

The latest `httpd` contains a handler at ARM address `0x51344`. For
`syscmd.sh`, it formats the global `SystemCmd` value into:

```text
%s > /tmp/syscmd.log 2>&1 && echo 'XU6J03M6' >> /tmp/syscmd.log &
```

and invokes `system()`. This is intentionally privileged administrative
functionality and would provide command execution if its authentication
boundary failed.

Static caller tracing found:

- ordinary WebUI dispatch through the normal authenticated route machinery;
- no `syscmd.sh` entry in the no-login exemption set;
- a separate manufacturing path at `0xb16dc` that requires the internal mode
  check to return ATE state `7`;
- that path additionally requires a case-insensitive `run_telnetd` prefix
  before dispatching `syscmd.sh`.

No pre-authentication request-to-`SystemCmd` dataflow was established.

Disposition: **root shell sink present; unauthenticated reachability not
confirmed**.

## Other ranked leads

The automated same-function correlations in `dnsmasq`, `dnsqd`, `lld2c`,
`networkmap`, and libraries combine configuration-file reads, fixed helper
commands, and network functions. They are leads rather than dataflow proof.
No additional unauthenticated attacker-input-to-command path was established
during this bounded pass.

## Evidence

- `private_disclosures/ASUS_GT-BE98_PRO/GT_BE98_PRO_WL_SERVER_RESEARCH_QUESTIONS_RESOLVED_2026-07-24.md`
- `known_firmware/emulation/ASUS_GT-BE98_Pro/full-system-lab/serial.log`
- `scripts/emulate_gtbe98_full_system.py`
- `scripts/emulate_gtbe98_wl_dual_isolated.py`
- `scripts/collect_gtbe98_activation_evidence.sh`
- `private_disclosures/ASUS_GT-BE98_PRO/GT_BE98_PRO_WL_SERVER_ACTIVATION_AUDIT_2026-07-24.txt`
- exhaustive campaign evidence for HTTPD SHA-256
  `3b8da6ae1c0c35d6ede142110b10491fc28d08231f3bc4636d56670ba5ecba2a`

## Next validation

The only evidence that would promote `wl_server_socket` is read-only proof from
an owned stock router that the firmware launches it and exposes TCP/8000. The
only evidence that would promote `SystemCmd` is a naturally shipping
authentication-routing defect demonstrated through genuine `httpd`.

Until either exists, the correct result is **no confirmed unauthenticated RCE**.
