# GL.iNet GL-MT5000 Brume 3 pre-authentication RCE/DoS triage

Date: 2026-07-24

## Scope

- Product: GL.iNet GL-MT5000 Brume 3
- Firmware analyzed: 4.8.6
- SHA-256: `001503668d83a939627f6bd92614fff417251f9f517e011d14abe2fb0a307417`
- Patch comparison: 4.9.0
- Comparison SHA-256: `e69e440c2715122793e2a4229d1acab3fbcfd193532e9167cd2f4d57bfbfe2d9`

## Outcome

No unauthenticated RCE has been confirmed.

One strong unauthenticated administrative-plane DoS is statically and
dynamically confirmed: any client that can reach the GL.iNet WebUI can cause a
global ten-minute login lockout with ten invalid requests. Firmware 4.8.6 was
confirmed at the native service layer, and 4.9.0 was confirmed end to end
through the native HTTP `/rpc` stack using two distinct network clients. A
second, lower-confidence process-amplification/worker-
exhaustion candidate exists in `/logfeedback`.

The global lockout behavior is publicly acknowledged by GL.iNet support for a
different model, so it should not be represented as a previously unknown
mechanism. No CVE or advisory specifically covering GL-MT5000 4.8.6/4.9.0 was
located during this review.

## Candidate 1: global pre-authentication WebUI login lockout

### Root cause

`/usr/sbin/gl-ngx-session` stores the following counters as process-global
variables:

```lua
local login_wait = 0
local login_fail = 0
```

The daemon loads default thresholds of ten failures and 600 seconds from
`/etc/config/oui-httpd`. Its unauthenticated `challenge` handler increments
`login_fail` when a supplied username has no crypt record:

```lua
if not alg then
    if initialized then
        login_fail = login_fail + 1
    end

    if login_fail == login_fail_max_cnt then
        login_fail = 0
        login_wait = sys.uptime() + login_fail_wait_time
    end
```

Both `challenge` and `login` reject every caller while the one shared
`login_wait` is active. There is no source-IP or account key in this state.

### Reachability

Nginx exposes `/rpc` on ports 80 and 443. `challenge` is a top-level JSON-RPC
method and is handled before authenticated object-method authorization.

The attack is LAN-reachable by default. It is remotely reachable from any
network on which the administrator deliberately exposes or forwards the WebUI.

### Minimal verification

The guarded verifier is:

`known_firmware/emulation/GL-MT5000/mt5000_login_lockout_probe.py`

It is dry-run by default. Destructive verification requires
`--confirm-lockout`, restricts the target to a private/local address, sends ten
invalid challenges, then checks that a valid `root` challenge receives error
`-32003` with a positive `wait`.

Expected impact is loss of WebUI authentication for approximately ten minutes.
Repeating ten requests after each interval can maintain the lockout
indefinitely. Existing authenticated sessions may remain usable, and routing
traffic is not shown to stop; therefore this is an administrative-plane DoS,
not a whole-router DoS.

### Isolated runtime confirmation

The firmware's native AArch64 `ubusd`, Eco runtime, and
`/usr/sbin/gl-ngx-session` were executed with QEMU in an isolated container
using a disposable copy of the extracted 4.8.6 root filesystem. The copy was
placed in a realistic initialized state with a lab-only root password.

Before the test, a `root` challenge returned code `0`, algorithm `6`, the
configured salt, and a nonce. Ten challenges for the syntactically valid but
nonexistent username `friday_nonexistent_user` each returned access-denied code
`-32000`. The immediately following `root` challenge returned:

```json
{
  "code": -32003,
  "data": {
    "wait": 599
  }
}
```

A direct `login` call was also rejected with code `-32003` and a remaining wait
of 587 seconds. Both the native session daemon and `ubusd` remained running,
which distinguishes this behavior from a service crash.

No physical router or public-network host was contacted. The raw confirmation
transcript is preserved in
`private_disclosures/GL-MT5000/MT5000_LOGIN_LOCKOUT_RUNTIME_TRANSCRIPT_2026-07-24.txt`.

### Version comparison

Firmware 4.9.0 changes unrelated runtime compatibility and WebSocket handling
in `gl-ngx-session`, but retains the shared login counters and lockout logic.

### Suggested remediation

- Track failures by source address and account, with bounded/expiring storage.
- Do not globally reject valid administrator credentials.
- Add progressive per-source delay or a proof-of-work challenge.
- Rate-limit `/rpc` authentication methods at Nginx.
- Log and expose suspicious failures without turning the protection into a
  low-rate DoS primitive.

## Candidate 2: unauthenticated `/logfeedback` process amplification

`/etc/nginx/gl-conf.d/log_feedback.conf` defines an exact location without the
normal `access_by_lua_file` hook. Before parsing a session token,
`oui-log-feedback.lua` synchronously runs:

```lua
ngx.pipe.spawn({"rm", "/tmp/log_feedback", "-rf"}):wait()
ngx.pipe.spawn({"mkdir", "/tmp/log_feedback"}):wait()
ngx.pipe.spawn({"mkdir", "/tmp/log_feedback/img"}):wait()
```

A syntactically valid multipart request can therefore cause three privileged
process launches and destructive shared-directory churn before authentication.
The same files are byte-identical in 4.9.0.

This is not yet confirmed as a security-impacting DoS. Validation still needs
to measure Nginx worker occupancy, request concurrency, CPU consumption, and
whether normal administration becomes unavailable under a low request rate.

## RCE review status

- `/rpc` object and method names are constrained before dispatch.
- Non-no-auth object methods require a valid session ACL.
- Intentional no-auth methods are limited to UI initialization/localization
  and timezone queries.
- The root command proxy is a Unix-domain socket and is not directly exposed
  by Nginx.
- No pre-authenticated request-to-command path has been proven.

Further RCE work should prioritize:

1. first-boot `ui.init` state/race and validation behavior;
2. parser bugs in the native `www/cgi-bin/glc` dispatcher;
3. memory-safety review of native RPC modules reachable during initialization;
4. full-system emulation of Nginx, `gl-ngx-session`, and the command proxy;
5. patch-diffing native modules between 4.8.6 and 4.9.0.
