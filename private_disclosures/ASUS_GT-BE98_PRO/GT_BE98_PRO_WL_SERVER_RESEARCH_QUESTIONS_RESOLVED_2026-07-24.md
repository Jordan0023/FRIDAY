# ASUS GT-BE98 Pro `wl_server_socket` research questions resolved

Date: 2026-07-24  
Firmware: `3.0.0.6.102_39262`  
Package SHA-256: `e9c3bdc196cdc00528be40fd92de066793dfada1b181ba01b142a5319a011eaf`  
Component SHA-256: `cb3ee4e407d1868d4f33f7cf9d7cabcc6410fb6ede781410685976246a55cd25`

## Executive conclusion

The binary contains a genuine remote command-execution capability when a
researcher manually launches it. The shipping GT-BE98 Pro firmware does not
provide an identified path that launches the binary, registers it with the
service dispatcher, or exposes its TCP/8000 socket.

Accordingly, this is **confirmed component-level command execution, but not a
confirmed product-level unauthenticated RCE or DoS, and not a supportable
zero-day claim**.

## Research-question matrix

| Question | Test or evidence | Result |
|---|---|---|
| Does stock boot start it? | Full-system stock-init emulation, process observation, and listener observation | No launch and no TCP/8000 listener observed. Proprietary wireless modules could not load in generic QEMU, so this negative is supporting rather than conclusive physical evidence. |
| Do diagnostics, pairing, recovery, or support mode start it? | Exhaustive root-filesystem search of WebUI, init, service, configuration, and recovery material for `wl_server_socket` and `/tmp/RWL` | No trigger, configuration key, service registration, or hardware-event reference found. |
| Does a WebUI action launch it? | Focused WebUI source and `httpd` route audit | No authenticated or unauthenticated action referencing the component was found. |
| Can `rc_service` or another stock daemon launch it generically? | `rc` dispatcher strings and filesystem reference audit | The dispatcher supports many named services, but contains no `wl_server_socket` or `/tmp/RWL` registration. No stock daemon launcher was found. |
| Does `SystemCmd` provide the activation path? | Static caller and route analysis of `httpd` | `SystemCmd` is a real root shell sink, but its ordinary `syscmd.sh` route is authenticated. The alternate path requires ATE/manufacturing state and a `run_telnetd` prefix. It is not an unauthenticated shipping activation path. |
| Is activation controlled by a documented option or hardware event? | Configuration, NVRAM-name, script, and binary-string searches | No such option or event was identified. |
| Does another supported model provide a genuine launcher? | Cross-firmware audit of 20 extracted ASUS and NETGEAR Broadcom root filesystems containing two component builds | Zero external executable-name references and zero external `/tmp/RWL` references in all 20 roots. |
| Is an owned physical GT-BE98 Pro available for the final check? | Read-only host link, address, and USB inventory | No connected owned ASUS router was present. Physical boot, pairing, diagnostics, and recovery observations therefore could not be collected. |
| Is it reachable over LAN? | Shipping activation audit | No. The component is dormant, so no stock LAN listener is established. A manually launched laboratory instance is not evidence of product reachability. |
| Is it reachable over WAN? | Shipping activation and routing-boundary audit | No. There is no stock listener to expose, and no evidence of a WAN firewall or forwarding path to it. |
| Is it unconditional RCE? | Entry-condition analysis | No. Execution requires the binary to be launched and its socket to be reachable; the firmware supplies neither condition on current evidence. |
| Is it unauthenticated DoS? | Stock reachability analysis | No confirmed product DoS. A dormant component cannot be remotely crashed through a socket that the product does not open. |
| Is it a zero-day? | Vulnerability classification | No supportable product zero-day. Uniqueness or prior non-publication does not replace exploitability and affected-product proof. |

## Latest focused test

The latest test narrowed the earlier broad search to the firmware's WebUI and
service-dispatch machinery:

- WebUI and configuration material contained no `wl_server_socket` or
  `/tmp/RWL` reference.
- `/sbin/rc` exposed its normal `notify_rc` and named-service machinery but no
  registration for this component.
- `httpd` contained `syscmd.sh`, `SystemCmd`, and `run_telnetd`, consistent with
  the separately analyzed authenticated/ATE command facility.
- Only `wl_server_socket` itself contained `/tmp/RWL`.

This closes the most plausible remaining software-only activation hypothesis:
the component is not silently registered under the generic service dispatcher.

## Why command execution is not yet product RCE

The component's command sink already is code execution. What is missing is a
shipping remote entry point:

```text
remote attacker
  -> stock-reachable listener
  -> attacker-controlled protocol message
  -> command sink
```

The final two stages were demonstrated only after manually starting the
component. The first stock-reachable-listener stage was not found. Manually
adding startup, changing firewall policy, or invoking an authenticated shell
facility would alter the product and would not prove a vulnerability in the
released firmware.

## Product status

The GT-BE98 Pro is not treated as end-of-life in this assessment. ASUS was
still publishing current support downloads and 2026 firmware for the model at
the time of testing.

## Evidence and limitations

- `GT_BE98_PRO_WL_SERVER_ACTIVATION_AUDIT_2026-07-24.txt`
- `GT_BE98_PRO_3.0.0.6.102_39262_UNAUTH_RCE_RESEARCH_2026-07-24.md`
- `known_firmware/emulation/ASUS_GT-BE98_Pro/full-system-lab/serial.log`
- `scripts/emulate_gtbe98_full_system.py`
- `scripts/emulate_gtbe98_wl_dual_isolated.py`
- `scripts/collect_gtbe98_activation_evidence.sh`

The remaining high-value test is read-only observation on an owned physical
GT-BE98 Pro through normal boot, pairing, diagnostics/support, and recovery.
No such device was connected during this pass. That limitation prevents an
absolute statement about every hardware-only state, but it does not supply
positive evidence for a vulnerability.

## Final disposition

**Do not report this as unauthenticated RCE, unauthenticated DoS, unconditional
RCE, WAN RCE, or a zero-day on the present evidence.** Preserve it as a latent
diagnostic component finding and reassess only if natural stock activation or
pre-authentication reachability is independently demonstrated.
