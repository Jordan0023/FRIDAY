# RAXE500 Impactful Route Follow-up — 2026-07-15

## Scope and target

- Model: NETGEAR RAXE500
- Firmware: `1.2.13.100`
- Binary: `usr/sbin/httpd`
- Binary SHA-256: `8352fe0f7d5cd66587c6176740f781106a2a0496383a692701a93776f81ab651`
- Desired impact: remote or LAN unauthenticated RCE, or a reliable unauthenticated device/service DoS
- Method: static dispatcher and data-flow review in the extracted firmware. No production router was targeted.

## Result

No zero-day vulnerability is confirmed from these leads. The review rejected the two strongest apparent paths and found no request-controlled value reaching a command launcher or an established memory-corruption condition.

## Lead 1: `wireless.cgi`

The dispatcher maps `wireless.cgi` to the large handler at `0x000c1210`. That handler contains unsafe-looking library calls and three `system()` calls, making it the strongest initial lead.

The command sites are not command-injection paths:

| Call site | Argument | Finding |
|---|---|---|
| `0x000c25b8` | `killall acsd` | Fixed firmware string |
| `0x000c25c0` | `/usr/sbin/acsd` | Fixed firmware string |
| `0x000c40e4` | `rc wlanrestart` | Fixed firmware string |

The `strcpy()` calls at `0x000c3cb8`, `0x000c3d24`, `0x000c3d90`, and `0x000c3e08` process WEP keys only after exact-length checks. The request extractor is invoked with an `0x800`-byte destination bound, the function has a stack canary, and this review did not establish an overwrite of the selected destination objects. These calls remain code-quality review points, but they are not evidence of exploitable corruption.

Authentication is also not proven absent. The earlier scanner result saying `auth=none` was a false positive caused by the ordinary word `public` in adjacent page text. That heuristic has been tightened; generic UI wording no longer proves a route is pre-authenticated.

## Lead 2: `genie_wifi_change.cgi`

The dispatcher maps this route to a separate handler at `0x000e59e0`; it does not enter the `wireless.cgi` handler. It accepts setup fields for 2.4/5/6 GHz SSIDs and passphrases, but copies them into cleared local storage with explicit 32-byte SSID and 64-byte passphrase limits. The reviewed handler contains no `system()` call and no demonstrated request-to-dangerous-sink flow.

The route may be setup-state reachable, but setup-state or unauthenticated reachability alone does not establish a vulnerability. No RCE or reliable DoS primitive was recovered here.

## Scanner correction

The authentication classifier now accepts only explicit markers such as `no_auth`, `unauth`, `pre_auth`, or `auth_skip` as static evidence of no authentication. The generic terms `public`, `whitelist`, `setup`, `wizard`, and `onboard` no longer classify an ordinary route as unauthenticated. Routes explicitly named as setup/wizard/onboarding surfaces are tracked as `setup-only`, not generally unauthenticated.

A regression test verifies that text such as “public wireless network” beside `wireless.cgi` leaves authentication `unknown` and cannot promote an impactful candidate.

## Confidence and next gate

Confidence is high that the three observed command-launch sites use constant commands. Confidence is moderate that the reviewed copy sites are non-exploitable because this conclusion is static and path-specific.

Promotion would require new evidence showing all of the following:

1. a reachable request path without supplied administrator credentials;
2. attacker control reaching a command, control-flow, or availability-critical sink;
3. a reproducible security effect in an isolated high-fidelity harness; and
4. novelty checks distinguishing the root cause from public prior art.

Current disposition: **rejected as an impactful zero-day candidate; retain only as a hardening/fuzzing lead.**

## Promotion-gate execution — 2026-07-15

The promotion gates were subsequently executed rather than left as future work.

| Gate | Evidence | Result |
|---|---|---|
| Network handler identified | Dispatcher mappings recover `wireless.cgi` → `0x000c1210` and `genie_wifi_change.cgi` → `0x000e59e0`. | Pass (L2) |
| No-admin reachability proven | Static page wording was the only prior no-auth evidence and was a classifier false positive. No explicit auth-skip decision was recovered for `wireless.cgi`; setup-state reachability is not equivalent to general no-auth reachability. | Fail |
| Request-to-dangerous-sink control | The three `system()` arguments are constant. The setup handler is separate and uses bounded field copies. No request field was shown to control a command or corrupt control data. | Fail |
| Reproducible security effect | The exact ARM `httpd` and its firmware libraries load under QEMU user emulation and reach firmware initialization. No candidate request-to-sink primitive exists to exercise, and no security crash, command effect, or reliable service/device DoS was reproduced. | Fail |
| Novel root cause | NETGEAR's June 2026 advisory already documents CVE-2026-9212, an insufficient-authentication/input-validation issue affecting RAXE500 before `1.2.14.114`. The reviewed leads do not establish a distinct root cause and must not be represented as novel. | Fail / no distinct root cause |

### Confidence after gate execution

- **0.95** that the observed `system()` sites are not request-driven command injection, because each call directly loads a fixed string immediately before invocation.
- **0.90** that `genie_wifi_change.cgi` does not enter the reviewed `wireless.cgi` sink path, because the dispatcher and complete setup handler are separate.
- **0.85** that these specific leads do not satisfy unauthenticated RCE or reliable unauthenticated DoS promotion. Residual uncertainty covers unreviewed paths elsewhere in the large monolithic binary, not these rejected flows.
- **0.00 promotion confidence** for calling this a confirmed zero-day: two mandatory technical gates fail and no distinct novel root cause exists.

### Final gate decision

Evidence level remains **L2 (handler identified)**, not L3/L4/L5. The candidate is **not promoted**. Starting a fuller web harness could improve route-reachability knowledge, but it cannot repair the missing request-to-sink primitive in these handlers. Reopening requires a new, function-local data-flow lead rather than additional attempts to label these same constant-command sites as exploitable.
