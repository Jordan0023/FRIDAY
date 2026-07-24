# RAX42v2 V1.1.6.38 proprietary HTTP pre-authentication investigation

Date: 2026-07-24

## Result

No unauthenticated remote-code-execution path or persistent request-triggered
denial of service was confirmed in the exact RAX42v2 `/usr/sbin/httpd`.

This is a bounded negative result, not a claim that the daemon is free of
vulnerabilities. The full-system lab still lacks enough production runtime
state to keep the request worker alive, so the most important residual work is
physical-device or complete-stock-boot validation.

## Provenance

- Firmware: NETGEAR RAX42v2 V1.1.6.38
- Package SHA-256:
  `e6f2fe38e6ad0fa00eb6602f5b1925a7b0710c2f160ef2ab2c9f311ae6875bf8`
- Exact `/usr/sbin/httpd` SHA-256:
  `93881747b464384203309bf42dad4eb20ad9b8950e5b7850da06ac9cb57cc862`
- Exact `/usr/sbin/httpd` MD5:
  `f852870ad213611b8e556d1f9f13ef75`

The binary differs from the previously tested RAX54S `httpd`; no result was
transferred by product-name similarity.

## Static coverage

Ghidra discovered 574 functions and attempted all 574. It decompiled 573
successfully; one function remained unresolved after two retries and none
timed out. Sixteen functions contained function-local combinations of a
dangerous sink and a recognized input/file source.

Focused review established:

- `/soap/server_sa/` is handled by `FUN_0002b4a0`, which applies NVRAM and
  request-header gating before accepting the private SOAP path.
- `SOAPAction:` is parsed by `FUN_0009b3fc`; its recovered header copy uses
  `snprintf` with a 129-byte destination limit.
- `FUN_00066d58`, the strongest automated `recv` plus `system` candidate,
  executes fixed firmware commands before receiving. Its request accumulator
  allocates from the declared request length and copies only while the
  accumulated size remains below that allocation.
- The numerous `system` calls in `FUN_00033724` are in the main
  initialization/maintenance dispatcher and use firmware-owned strings or
  local state. Review did not recover request text entering those calls.
- `FUN_000a56c4` processes a URL-like path for a helper/CGI workflow. It
  rejects semicolon, backtick, dollar-sign, and an additional firmware-defined
  forbidden substring before forking; constrains extracted components to 64/256-byte
  buffers; checks a firmware allowlist; and only then formats a command.
  No pre-authentication route-to-command bypass was established.
- Other command candidates build commands from fixed strings or data read
  from locally generated files. No route-local unauthenticated source was
  shown to control their command text.

String presence and binary-wide sink imports were not treated as evidence of
an exploitable flow.

## Full-system validation

The exact ARM daemon was staged with the corrected RAX42v2 root filesystem and
booted under QEMU with:

- restricted user networking;
- loopback-only host forwarding;
- a generated disposable TLS certificate at the daemon's embedded default
  paths;
- stock libraries and request parser; and
- narrow shims for absent NAT and device-control APIs.

The setup process briefly created the firmware listener. The request worker
then consumed 32 bytes from the kernel RNG and faulted at address zero before
serving a request. A bounded 500-attempt loopback control sweep obtained no
HTTP response. No inbound request preceded the fault.

The startup failure is therefore an emulation/runtime-state artifact, not
evidence of unauthenticated DoS. It prevents a valid live claim about
`/soap/server_sa/`, recovery pages, or malformed HTTP requests.

### More complete stock boot

A second harness follows the firmware's real init path:

`bcm_boot_launcher start` -> rc3 scripts -> `smd` -> `acos_init_once` ->
`acos_init` -> `acos_service start` -> stock `start_httpd`.

It restored 806 ACOS defaults, 516 SDK defaults, and 54 project defaults.
The Broadcom 4.1.52 hardware modules cannot load on the Debian 6.1 emulation
kernel, so the harness uses one explicit continuation at 60 seconds after the
stock SMD remains in the foreground: it invokes the next two original rc3
scripts. It does not invoke `httpd` directly.

The stock chain completed `acos_init` and emitted `START HTTPD` at 190-192
seconds. The genuine `/usr/sbin/httpd` remained alive through the bounded
240-second observation and eventually opened wildcard TCP ports 80 and 443.
A loopback-only forwarded connection to port 80 was accepted, but returned no
bytes before the eight-second client timeout. Thus this run establishes a
substantially complete stock boot and stable listener creation, but not a
request/response-capable target suitable for attributing a malformed-request
crash. Missing `/dev/brcmboard`, wireless/switch hardware, and dependent
services remain the principal fidelity gaps.

## Disposition

- Confirmed unauthenticated RCE: **no**
- Confirmed request-triggered service DoS: **no**
- Startup NULL dereference without inbound traffic: **yes, not remotely
  attributable**
- Static request-to-command flow: **not established**
- Zero-day claim justified from this surface: **no**

## Artifacts

- Harness: `scripts/emulate_rax42v2_http_full_system.py`
- Exhaustive receipt:
  `known_firmware/reports/RAX42V2/decompile/httpd-receipt.json`
- Candidate index:
  `known_firmware/reports/RAX42V2/decompile/httpd-evidence.jsonl`
- Sensitive route/authentication xrefs:
  `known_firmware/reports/RAX42V2/decompile/httpd-sensitive-xrefs.c`
- Reviewed command candidates:
  `known_firmware/reports/RAX42V2/decompile/httpd-command-candidates.c`
- Dynamic serial evidence:
  `known_firmware/emulation/RAX42V2/full-system-http-lab/serial.log`
- Stock init:
  `known_firmware/emulation/RAX42V2/full_system_stock_init`
