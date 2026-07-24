# Four-router cross-model zero-day hunt

Date: 2026-07-14

## Scope

The four non-ASUS targets from the five-router campaign were reviewed using
the RT-AX82U workflow: identify authentication gates, map upload/restore paths,
trace length and archive handling, look for credential-recovery chains, and
require runtime reachability before claiming a vulnerability.

| Target | Exact firmware | Initial result |
|---|---|---|
| GL.iNet GL-MT5000 Brume 3 | 4.8.6 | No transferred ASUS bug; upload allowlist needs focused pattern-boundary testing |
| TP-Link Archer C5400X | V1.6 1.1.7 Build 20240510 | Four scanner leads reduced to UI/string noise; native RPC/import mapping remains priority |
| NETGEAR RAXE500 | 1.2.13.100_2.0.54 | Existing UPnP record-overflow lead remains unreachable and rejected |
| TP-Link Archer AX21 | V5.6 1.0.2 Build 20250224 | No transferred ASUS handler; restore/TR-069 components remain priority |

## Exact ASUS bug-class transfer

The extracted filesystems were searched for the RT-AX82U-specific handler and
profile markers, including `upload_config_sync`, `settings_u.prf`, `HDR1`, and
`prepare_restore`. None of the four targets contains the vulnerable ASUS
configuration-sync handler. Generic matches for backup, restore, multipart,
and sysupgrade are not treated as data-flow evidence.

## GL.iNet Brume 3 upload path

`/upload` is implemented by `usr/share/gl-ngx/oui-upload.lua`.

- Network clients must present a SID that `gl-session.session` accepts.
- The unauthenticated localhost exception checks `ngx.var.remote_addr` against
  `127.0.0.1` or `::1`; it does not trust `X-Forwarded-For`.
- An authenticated client is additionally checked with
  `rpc.access("upload", path)`.
- Paths containing `..` or `~` are rejected.
- Upload destinations are selected from `/usr/share/gl-upload.d`.
- OpenVPN and WireGuard text/config inputs have a 256 KiB limit.

The destination allowlist uses attacker-supplied paths as Lua-pattern matches
with `'^' .. line`, and several entries are prefix matches rather than explicit
end-anchored literal comparisons. This is a review lead, not yet a confirmed
write primitive: the currently observed prefixes remain under `/tmp` or the
static web CSV path, traversal is separately rejected, and network callers
still require a valid session.

## TP-Link C5400X scanner-lead reduction

The four automated candidates are `cgi-bin/luci`, `luci.sgi.cgi`, a
`show_bug.cgi` string inside bundled Angular code, and an OpenVPN documentation
URL. The latter two are false-positive strings. The LuCI entries identify the
management dispatcher but do not establish a parameter-to-sink flow or an
authentication bypass. They remain below confirmation level.

## NETGEAR RAXE500 carry-forward

The prior `sa_parseRcvCmd` unchecked record copy is real unsafe code, but GDB
reachability tests established that normal `AddPortMapping`, NETGEAR SOAP
login, and parental-control requests do not call it. The proposed network path
was falsified; it remains rejected unless a supported route reaches the parser
breakpoint.

## Current verdict

No new zero-day is confirmed in this initial cross-model transfer pass. In
particular, generic unsafe-call counts and route strings are not evidence of
exploitability. The best next investigations are Brume 3 no-auth RPC method
implementations, C5400X native LuCI RPC/import handlers, AX21 TR-069 restore
parsing, and RAXE500 web-recovery/profile import bounds.

## Historical-bug regression map

### GL.iNet GL-MT5000 Brume 3

The vendor's April 2024 advisory identifies the relevant v4.x families:
OpenVPN upload traversal (CVE-2023-46455/46456), arbitrary API uploads
(CVE-2023-47464), Lua-pattern authentication bypass (CVE-2023-50919), SID
confusion (CVE-2023-50920), unauthorised `add_user` access
(CVE-2023-50921), authenticated crontab upload RCE (CVE-2023-50922), command
injection in log/upgrade methods (CVE-2023-50445), and unauthenticated log
archive download (CVE-2024-27356).

Regression findings in 4.8.6:

- `/rpc` validates object and method identifiers with an end-anchored pattern
  before dispatch; the looser internal validator is not directly reachable
  with an invalid outer identifier.
- No-auth RPC methods are an explicit short list in `etc/config/oui-httpd`.
- `/upload` and `/download` require a live `gl-session` for network peers;
  localhost is derived from the actual socket peer address.
- Upload and download still use Lua-pattern prefix allowlists. Traversal tokens
  are rejected and reviewed destinations remain constrained, so this is not
  yet an arbitrary-write/read primitive.

Disposition: historical auth and traversal areas reviewed; no new pre-auth
variant confirmed.

### TP-Link Archer C5400X

The exact audited build, 1.1.7 Build 20240510, is the vendor-designated fix for
CVE-2024-5035. The vendor describes the original issue as a source weakness
without a demonstrated kill chain. Older C5400X firmware was also included in
the KCodes NetUSB CVE-2021-45608 advisory.

Regression focus:

- sibling `rftest`/wireless-test command handlers around the CVE-2024-5035
  fix;
- NetUSB listener registration and message-length boundaries;
- LuCI import/restore and VPN archive handlers.

The current automated `show_bug.cgi` and OpenVPN-URL candidates are bundled UI
strings, not handlers. No new command path or pre-auth NetUSB primitive is yet
confirmed.

### TP-Link Archer AX21

CVE-2023-1389 is the model's principal historical unauthenticated command
injection. The current V5.6 firmware is a different hardware/software branch
from the older affected releases, so string similarity alone cannot establish
a regression. The extracted image includes `tddp`, TR-069 `mybackup` and
`myrestore`, and a native management stack; these are being treated as sibling
attack surfaces, with authentication and listener registration required before
any sink is promoted.

Disposition: no CVE-2023-1389 regression or distinct sibling root cause has
been demonstrated in V5.6.

### NETGEAR RAXE500

The audited 1.2.13.100 firmware predates vendor-fixed 1.2.14.114 and is listed
in the June 2026 advisory for at least CVE-2026-0416, an authenticated crafted-
input bypass of protected management functionality. This means behavior fixed
by that release is public known-vulnerability territory, not a zero-day.

The strongest new-variant method is an old/new binary diff followed by sibling
handler review. Until the 1.2.14.114 root filesystem is extracted and the
changed functions are mapped, the existing unreachable UPnP parser copy must
not be conflated with the June advisory or claimed as a new vulnerability.

Disposition: exact target is known-vulnerable according to the vendor; no
distinct unpublished root cause confirmed in this pass.

## Follow-up execution record

The GL.iNet unauthenticated RPC implementations were inspected rather than
inferred from route names. `ui.init` is deliberately no-auth for first-time
setup, but its bytecode checks the initialized state and contains an explicit
access-denied return. The outer `/rpc` handler validates complete object and
method identifiers before the internal Lua/C loader. Therefore the internal
loader's looser pattern is not, by itself, an unauthenticated module-name
bypass.

The RAXE500 1.2.14.114 firmware was staged and audited under a 4 GiB extraction
budget (SHA-256
`b1a11003db07a998df113338b035e066dee7cd503b62126a1fdb9a789a9b22f3`).
Binwalk recursively treated many offsets inside one XZ stream as nested
archives, creating 5.4 GiB of overlapping fragments but no usable new
rootfs. The bounded scratch tree was removed after preserving the firmware and
audit report. This output cannot support a security patch diff; a format-aware
single-root extraction is still required.

No new zero-day is claimed from this follow-up. Both tempting leads—the GL
repeat-initialization route and automated RAXE fragment correlations—failed the
reachability/evidence gate.

## Historical-access-method execution — 2026-07-15

The five targets were rechecked against the principal historical entry methods:
unauthenticated LAN services, management authentication bypass, setup/onboarding
routes, upload/restore processing, and browser/session-assisted management.
Testing was bounded to extracted firmware and isolated emulators.

| Target | Methods exercised | Evidence and result |
|---|---|---|
| ASUS RT-AX82U `388_25101` | malformed pre-auth HTTP paths; tokenless route aliases; IFTTT/session recovery; native `u2ec` and `cfg_server` parser corpora; WebDAV cross-model regression | Current URL decoding, short-packet, key-length, and WebDAV pre-database gates rejected the historical triggers. Tokenless aliases did not reach `upload_config_sync_cgi`. The retained IFTTT condition is public prior art and supplies a token before the protected handler. No new tokenless RCE/DoS. |
| GL.iNet Brume 3 `4.8.6` | SID confusion; localhost spoofing; RPC identifier confusion; upload traversal/pattern-boundary review | The network path calls `gl-session`, derives localhost from `ngx.var.remote_addr`, applies `rpc.access`, and rejects traversal tokens. Prefix-pattern allowlists remain a hardening lead, but reviewed destinations stay constrained and network callers still need a valid session. No new pre-auth primitive. |
| TP-Link Archer C5400X `1.1.7` | historical `rftest`/TDDP command-handler and NetUSB sibling review; LuCI/import surface | `tddp` retains command-execution-capable internals such as `popen` and special-command handlers, but strings/imports do not prove a network-reachable unauthenticated dispatch path. No route-local packet-to-command flow or reproducible effect was recovered. Static-only negative result. |
| TP-Link Archer AX21 V5.6 `1.0.2` | CVE-2023-1389 sibling/TDDP review; TR-069 backup/restore review | The hardware/software branch differs from the published AX21 target. `tddp` contains command-capable factory/test handlers, but no unauthenticated packet-to-command flow was proven. `myrestore` decrypts and checks a product digest before processing configuration; its tar extraction lacks obvious path-safety flags, but the input is an encrypted restore artifact and no pre-auth delivery route or overwrite effect is established. Retain as authenticated restore-hardening lead only. |
| NETGEAR RAXE500 `1.2.13.100` | UPnP oversized-record replay; web setup/auth classification; fixed-command wireless-handler review | The isolated UPnP listener returned HTTP 200 through 1600-byte bounded probes and a controlled HTTP 500 at 2048 bytes, then remained listening. `wireless.cgi` command sites use fixed strings; `genie_wifi_change.cgi` is a separate bounded handler. No crash, persistent outage, or command control. |

### Promotion decision

None of the five reaches the required combination of unauthenticated
reachability, function-local attacker control of a dangerous sink, and a
reproducible RCE or reliable service/device DoS. The newly observed AX21 restore
detail and TP-Link TDDP command-capable internals are review leads, not promoted
vulnerabilities: both are missing the access and data-flow gates.

## AX21 TDDPv2 follow-up — 2026-07-15

Later dynamic work supersedes the static-only TDDP statement above. In a
network-disabled AX21 V5.6 emulator, the publicly documented CVE-2026-0834
zero-declared-length packet shape reached the read-only get-PIN handler without
an administrator credential. TP-Link's current advisory does not list AX21, so
this is a potentially omitted affected model, not a new zero-day root cause.

An 808-case structured length/dispatch run did not crash the daemon. A separate
static shell-formatting lead in the product-name setter was tested with a
harmless marker and a 30-position benign command-offset sweep; neither reached
the setter and no marker was created. Unauthenticated RCE and DoS therefore
remain unconfirmed. Full evidence and confidence gates are recorded in
`TP-Link_Archer_AX21/TDDPV2_REVIEW_2026-07-15.md`.

Switch-table recovery subsequently resolved the setter limitation: TDDPv2
commands `0x4b` through `0x7b`, including product-name command `0x52`, all map
to the default error path in this build. The additional reachable commands
`0x7c` through `0x7e` use fixed `ubus` motor-service command strings, not
request-controlled shell arguments. The public bypass therefore does not
provide the suspected command-injection chain.

## Historical sources

- GL.iNet April 2024 security advisories:
  https://www.gl-inet.com/en-de/blogs/security-updates/security-advisories-vulnerabilities-and-cves-apr-29-2024
- TP-Link C5400X CVE-2024-5035 statement:
  https://www.tp-link.com/uk/support/faq/4008/
- TP-Link security-advisory index, including Archer AX21 CVE-2023-1389:
  https://www.tp-link.com/us/press/security-advisory/
- TP-Link CVE-2026-0834 advisory:
  https://www.tp-link.com/uk/support/faq/4905/
- NETGEAR June 2026 advisory:
  https://kb.netgear.com/000070811/June-2026-NETGEAR-Security-Advisory

## 2026 attack-pattern application — 2026-07-15

The five targets were mapped against the recurring 2026 network-device attack
classes: authentication bypass, configuration/VPN import command injection,
information-disclosure-to-takeover chains, crafted-request DoS, transport trust
failure, and browser/session-assisted management. Existing evidence was reused
where the same gate had already been tested; dynamic replays remained confined
to disposable network-disabled containers.

| Target | Applied checks | Result / next gate |
|---|---|---|
| ASUS RT-AX82U `388_25101` | tokenless route aliases, IFTTT/session recovery, configuration-sync imports, malformed pre-auth HTTP, native parser corpora | Protected configuration sync still requires a valid token. Prior token-recovery behavior is public prior art and does not turn the retained stack overwrite into a new tokenless root cause. No unauthenticated RCE or DoS confirmed. |
| GL.iNet Brume 3 `4.8.6` | SID confusion, localhost trust, no-auth RPCs, upload/import allowlists, command-building and log-download siblings | `/upload` verifies a live `gl-session` for network peers and calls `rpc.access`; socket peer address, not a forwarding header, controls the localhost exception. Lua-pattern prefixes remain imperfect hardening, but traversal tokens are rejected and destinations are constrained. No pre-auth read/write or command primitive confirmed. |
| TP-Link C5400X `1.1.7` | management/upload authentication boundary, backup/restore and VPN import markers, TDDP/NetUSB siblings, upload storage path | New high-priority review lead: Nginx listens on `8081` and TLS `4433`; `/upload` enables resumable upload and uses `/mnt/$arg_path` for state and file storage. The location contains no explicit access directive, while the custom binary contains session-validation strings and an app-auth module. Static firmware does not establish firewall/interface exposure, whether the module canonicalizes/rejects traversal, or whether a request lacking a session reaches storage. Treat as an authentication/path-validation candidate only; a faithful isolated listener or owned-device capture is required before promotion. |
| TP-Link AX21 V5.6 `1.0.2` | unauthenticated TDDPv2 dispatch, declared/actual length boundaries, command offsets, restore/TR-069, encrypted-current-build boundary | The isolated campaign sent 808 structured cases and a 30-case offset sweep. TDDP remained bound and a fresh read-only probe responded afterward. No crash, hang, or request-controlled command handler was found. The public zero-length bypass shape reaches a read handler but does not establish a new root cause or RCE. |
| NETGEAR RAXE500 `1.2.13.100` | UPnP record bounds, certificate/trust advisory mapping, authenticated command siblings, web setup/recovery | Fresh isolated replay returned HTTP 200 through 1,600 bytes and a controlled 500 at 2,048 bytes; TCP 56688 remained listening. The unsafe XML copy remains disconnected from the exercised routes. The audited version is also in public known-vulnerability territory, so a distinct root cause and route are required. |

### Cross-model disposition

No target currently satisfies all promotion gates: unauthenticated LAN or WAN
reachability, function-local attacker control of a dangerous operation,
repeatable security impact, and a distinct unpublished root cause. The C5400X
upload configuration is the strongest newly exposed gate because it combines a
listener with request-derived storage configuration, but calling it arbitrary
write or authentication bypass would exceed the evidence. The next bounded
step is to rehost that exact Nginx binary/configuration with its custom modules
and observe an unauthenticated harmless upload to a disposable `/mnt` tree;
physical-device testing is only appropriate on an owned and authorized unit.

An initial exact-binary rehost was attempted in a disposable Docker container
with network mode `none`. The immutable firmware tree was copied into a chroot,
QEMU ARM static was installed, and the firmware Nginx configuration was passed
to the original stripped ARM executable. The daemon did not remain running and
neither candidate port appeared in `/proc/net/tcp`. One concrete fidelity
blocker is that the extracted image represents `/var` as a `/dev/null` symlink,
whereas Nginx requires runtime paths beneath `/var/run`, `/var/log`, and
`/var/lib`; recreating those writable overlay paths without altering firmware
semantics requires a dedicated harness. The container was removed. No upload
request was sent, so this attempt adds no exploitability evidence and leaves
the C5400X candidate at the static-review gate.

### C5400X upload-gate resolution

A corrected rehost resolved the initial extraction/runtime limitations. The
firmware extraction had lost executable mode bits on ARM programs and modeled
`/var` as a `/dev/null` symlink. Both were corrected only in the disposable
copy: executable permissions were restored and a writable `/var` overlay was
created. QEMU then executed the original BusyBox and stripped Nginx binary;
`nginx -t` reported valid syntax and a successful configuration test.

The exact daemon subsequently bound `0.0.0.0:8081` and `0.0.0.0:4433` inside a
Docker namespace with network mode `none`. An unauthenticated GET to
`/upload?path=friday-probe` returned HTTP 403. A harmless multipart upload to a
precreated disposable `/mnt/friday-probe` directory also returned HTTP 403 with
`{"error_code":-1}`. A filesystem check found no created file, and both
listeners remained alive. The container was then removed.

This runtime result falsifies the suspected unauthenticated storage primitive
for the ordinary no-session request shape. The request-derived
`/mnt/$arg_path` configuration remains worth authenticated path-containment
review, but it is not a pre-auth arbitrary-write finding and does not meet this
campaign's unauthenticated RCE/DoS objective. No zero-day is promoted from this
route.

### C5400X TDDP bounded campaign

The exact C5400X `usr/bin/tddp` was also rehosted under QEMU in a fresh Docker
namespace with network mode `none`. After restoring the extraction-lost execute
bit in the disposable copy, the daemon remained running and bound UDP 1040.
The same structured corpus used for AX21 sent 808 version/type/subtype and
declared-versus-actual-length cases, with real payloads bounded to 4,096 bytes.
It received 181 responses and reported zero socket errors.

The daemon remained bound and its QEMU process remained alive after the
campaign. The AX21-specific read-only `0x45` shape received no reply on this
build, consistent with a different dispatcher and not evidence of service loss.
No crash, restart, or persistent outage was observed. The container was
removed. This is a negative result for the tested generic parser boundaries;
handler-specific coverage still requires recovering this build's distinct
command table. No zero-day is promoted.

### C5400X TDDPv2 command-table recovery

Static control-flow recovery resolved the model-specific special-command
dispatcher in the exact stripped binary (SHA-256
`aa172d2f0f0cc3e0864b1e07508b63adc0d1b2ffb9897803decb81032df340ae`).
Incoming byte 0 is stored at internal offset `0x1b`; therefore internal packet
type `0x1c` is outer header byte 1, and the special-command selector at internal
offset `0x25` is outer header byte 10. Packet type 3 selects the special-command
dispatcher.

Implemented selectors are `0x0a`, `0x11`, `0x12`, `0x32`, `0x35` through
`0x3c`, `0x40` through `0x43`, and `0x49` through `0x4c`. Recovered handlers
include product/device/MAC/firmware/hardware/OEM/special-ID/country getters and
setters, calibration and TXBF hooks, eMMC format/mount actions, and TDDPv2 MAC
and PIN setters. Several handlers invoke fixed shell commands. The PIN setter
formats eight request bytes into a shell command, but it is guarded by internal
state and the packet decode/integrity path; this is a sink review lead, not
proof of unauthenticated reachability or injection.

Nine getter-only probes were generated with outer version 2, packet type 3,
and selectors `0x0a`, `0x35`, `0x37`, `0x38`, `0x39`, `0x3a`, `0x3b`, `0x40`,
and `0x42`. All returned the same 28-byte error frame rather than
handler-specific data. The daemon remained alive and bound afterward. This
demonstrates that correct outer dispatch alone does not bypass the TDDPv2
decode/integrity gate; no setter was invoked. The container was removed.

The immediate limitation is now precise: handler-aware dynamic testing needs a
valid lab-generated TDDPv2 encoded body or instrumentation immediately after
successful decode. Guessing credentials or testing external devices is outside
scope. No zero-day is confirmed from this table recovery.
