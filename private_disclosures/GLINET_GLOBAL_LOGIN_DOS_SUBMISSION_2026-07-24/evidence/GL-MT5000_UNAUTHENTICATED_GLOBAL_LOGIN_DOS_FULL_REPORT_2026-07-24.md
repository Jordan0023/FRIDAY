# GL.iNet GL-MT5000 Brume 3 unauthenticated global WebUI login denial of service

## Report status

Confirmed vulnerability; zero-day candidate/new affected-product finding.

The vulnerability is dynamically confirmed on firmware 4.8.6 through isolated
execution of its native AArch64 services. It is also dynamically confirmed end
to end on firmware 4.9.0 through the native Nginx/Lua `/rpc` HTTP stack, Ubus
proxy, `ubusd`, Eco runtime, and session daemon.

No physical-device demonstration or vendor confirmation is required to support
the technical conclusion that the vulnerable behavior exists. The narrower
claim that this is a previously unknown zero-day cannot be proven from the
technical evidence alone because GL.iNet has publicly acknowledged its
all-source lockout design on a different model.

## Executive summary

The GL.iNet GL-MT5000 Brume 3 WebUI authentication service uses one
process-global failure counter and one process-global lockout timer for every
user and source address. An unauthenticated client can submit ten challenge
requests using a nonexistent but syntactically valid username. This activates
a 600-second lockout that rejects subsequent authentication challenges and
login attempts from all clients, including the legitimate administrator.

The attack does not require knowledge of a username, password, session token,
or cryptographic challenge value. Ten small requests are sufficient. Repeating
the sequence after each lockout interval can indefinitely deny new
administrative WebUI sessions at a very low request rate.

The demonstrated effect is denial of WebUI authentication. This report does
not claim interruption of packet forwarding, DNS, VPN tunnels, SSH, or
previously authenticated WebUI sessions.

## Affected product

| Field | Value |
|---|---|
| Vendor | GL Technologies (Hong Kong) Limited / GL.iNet |
| Product | GL-MT5000 Brume 3 |
| Confirmed firmware | 4.8.6 |
| Confirmed firmware SHA-256 | `001503668d83a939627f6bd92614fff417251f9f517e011d14abe2fb0a307417` |
| Additional confirmed firmware | 4.9.0, dynamically confirmed through HTTP |
| 4.9.0 SHA-256 | `e69e440c2715122793e2a4229d1acab3fbcfd193532e9167cd2f4d57bfbfe2d9` |
| Component | `/usr/sbin/gl-ngx-session` |
| Network interface | Nginx JSON-RPC endpoint `/rpc`, normally TCP 80/443 |
| Default reachability | Adjacent/LAN network |
| Authentication required | None |

## Vulnerability classification

- Vulnerability type: unauthenticated denial of service
- Impact scope: administrative WebUI authentication
- Suggested CWE: CWE-307, Improper Restriction of Excessive Authentication
  Attempts
- Secondary weakness: globally shared security state without source/account
  isolation
- Suggested CVSS 3.1: `CVSS:3.1/AV:A/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:L`
- Suggested base score: 4.3 (Medium)

The adjacent-network vector reflects the default deployment. If an
administrator exposes the WebUI through WAN access, port forwarding, a VPN, or
another remote-management path, the practical attack surface becomes remote.
That deployment-dependent condition is not included in the base vector above.

## Security impact

An attacker who can reach the WebUI can:

1. prevent the administrator from starting a new WebUI session for roughly ten
   minutes;
2. block correct authentication from other source addresses;
3. repeat the low-rate attack indefinitely;
4. obstruct time-sensitive configuration, monitoring, incident response, and
   recovery through the normal management interface.

The attack requires only ten authentication failures per lockout interval.
This is amplification in time: a short request sequence causes approximately
600 seconds of denied authentication.

The demonstrated availability loss is narrower than a whole-device outage.
Routing and other independent services may continue operating.

## Attack prerequisites

- The GL-MT5000 must have completed initial setup.
- The attacker must be able to send HTTP or HTTPS requests to its WebUI.
- No valid account, password, session identifier, or prior access is needed.
- No malformed memory input, race condition, or high-volume flood is needed.

## Attack surface

The Nginx configuration exposes `/rpc` on HTTP and HTTPS:

```nginx
location = /rpc {
    access_by_lua_file /usr/share/gl-ngx/oui-access.lua;
    content_by_lua_file /usr/share/gl-ngx/oui-rpc.lua;
    add_header Content-Type application/json;
    add_header X-Frame-Options DENY;
}
```

`oui-rpc.lua` exposes `challenge` and `login` as top-level JSON-RPC methods.
They are processed before object-method ACL authorization because their purpose
is to establish an authenticated session.

## Technical root cause

`gl-ngx-session` declares authentication failure and lockout state once at
process scope:

```lua
local login_wait = 0
local login_fail = 0
local login_fail_max_cnt
local login_fail_wait_time
```

During initialization, it loads the configured thresholds:

```lua
login_fail_max_cnt =
    tonumber(c:get("oui-httpd", "main", "max_login_fail") or 10)
login_fail_wait_time =
    tonumber(c:get("oui-httpd", "main", "login_fail_wait") or 600)
```

The shipped configuration specifies:

```text
option max_login_fail 10
option login_fail_wait 600
```

The unauthenticated challenge handler increments the global counter when a
username has no password record:

```lua
local alg, salt = get_crypt_info(username)
if not alg then
    if initialized then
        login_fail = login_fail + 1
    end

    if login_fail == login_fail_max_cnt then
        login_fail = 0
        login_wait = sys.uptime() + login_fail_wait_time
    end

    conn:reply(req, { code = ERROR_CODE_ACCESS })
    return
end
```

No source address, account identity, or client-specific key is associated with
`login_fail` or `login_wait`.

Both the challenge handler and login handler enforce the same global timer:

```lua
if login_wait - sys.uptime() > 0 then
    conn:reply(req, {
        code = ERROR_CODE_LOGIN_FAIL_OVER_LIMIT,
        data = { wait = login_wait - sys.uptime() }
    })
    return
end
```

Consequently, failures generated by one unauthenticated client prevent every
client from authenticating.

## Reproduction procedure

Use only an isolated device or laboratory instance that you own or are
authorized to test. Successful reproduction intentionally disables new WebUI
logins for approximately ten minutes.

### Preconditions

1. Complete initial router setup.
2. Verify that a normal administrator authentication challenge succeeds.
3. Ensure an alternate recovery or management path is available if testing a
   physical router.

### Trigger

Send ten JSON-RPC `challenge` calls to `/rpc`, each containing the same
nonexistent but syntactically valid username:

```json
{
  "jsonrpc": "2.0",
  "id": 1,
  "method": "challenge",
  "params": {
    "username": "friday_nonexistent_user"
  }
}
```

Each trigger request returns access-denied code `-32000`.

### Observation

Immediately request a challenge for the legitimate `root` account. The
vulnerable service returns:

```json
{
  "code": -32003,
  "data": {
    "wait": 599
  }
}
```

A direct login request is rejected with the same code and a decreasing global
wait value.

### Guarded verifier

The accompanying verifier is:

```text
known_firmware/emulation/GL-MT5000/mt5000_login_lockout_probe.py
```

It is dry-run by default, restricts targets to private/local addresses, and
requires the explicit `--confirm-lockout` switch before sending the ten
triggering requests.

## Dynamic confirmation

The 4.8.6 firmware's native AArch64 components were executed under QEMU in an
isolated container:

- `/sbin/ubusd`
- `/usr/bin/eco`
- `/usr/sbin/gl-ngx-session`
- the firmware's native Ubus client

A disposable root filesystem was placed in a realistic initialized state with
a lab-only root password.

### Baseline

A legitimate root challenge succeeded:

```json
{
  "code": 0,
  "data": {
    "hash-method": "sha256",
    "salt": "fridaylab",
    "alg": 6,
    "nonce": "u24Sd4empQdPOdIpeMDR1tISV1hqxUt6"
  }
}
```

### Trigger results

Ten consecutive nonexistent-user challenges each returned:

```json
{
  "code": -32000
}
```

### Post-trigger results

The next root challenge returned error `-32003` and `wait: 599`. A login call
during the same interval returned error `-32003` and `wait: 587`.

The native `gl-ngx-session` and `ubusd` processes remained running throughout.
The result therefore confirms global authentication denial rather than a
daemon crash.

The complete captured output is stored in:

```text
private_disclosures/GL-MT5000/MT5000_LOGIN_LOCKOUT_RUNTIME_TRANSCRIPT_2026-07-24.txt
```

## Version analysis

Firmware 4.9.0 modifies runtime compatibility and WebSocket synchronization in
`gl-ngx-session`. It does not isolate the failure counter or timer by source
address or account. The following relevant behavior remains:

- one process-global `login_fail`;
- one process-global `login_wait`;
- default threshold of ten failures;
- default wait of 600 seconds;
- enforcement in both challenge and login;
- no per-source or per-account state.

### Firmware 4.9.0 end-to-end HTTP confirmation

The 4.9.0 firmware's native AArch64 Nginx/OpenResty binary was started with its
shipped `oui_nginx.conf`, Lua access and RPC handlers, native Ubus proxy,
`ubusd`, Eco runtime, and `gl-ngx-session`. The lab used an internal-only Docker
network with no published host ports.

Two persistent clients had distinct addresses:

- client A: `172.20.0.3`
- client B: `172.20.0.4`
- emulated router: `172.20.0.2`

Before triggering, client B sent `POST /rpc` and received a successful root
challenge with algorithm 6, the lab salt, and a nonce. Client A then sent ten
invalid challenge requests through HTTP; each returned JSON-RPC error
`-32000`. Client B's next legitimate root challenge returned:

```json
{
  "id": 200,
  "jsonrpc": "2.0",
  "error": {
    "message": "Login fail number over limit",
    "data": {
      "wait": 600
    },
    "code": -32003
  }
}
```

A login request from client B containing the correctly computed response for
the baseline lab challenge was also rejected with error `-32003` and a
remaining wait of 572 seconds.

During lockout, an ordinary HTTP request from client B continued to receive
status 200 in approximately 44 milliseconds. Native `ubusd` and
`gl-ngx-session` remained running. This confirms that the availability impact
is specifically global denial of new authentication, not an Nginx crash or
general HTTP outage.

Therefore, firmware 4.9.0 is dynamically confirmed affected through its real
network-facing HTTP RPC path, in addition to the native service-level 4.8.6
confirmation.

## Why authentication does not mitigate the attack

The vulnerable methods must be reachable before authentication because they
implement authentication. The attacker does not bypass an ACL or forge a
session. Instead, the attacker abuses globally shared anti-brute-force state.

The security control intended to slow password guessing becomes the DoS
primitive.

## Detection

Potential indicators include:

- repeated challenge failures for nonexistent usernames;
- WebUI responses containing code `-32003`;
- legitimate users seeing a roughly 600-second failure countdown;
- repeated lockout periods beginning immediately after each prior period ends.

The router should log source addresses for challenge failures and global
lockout activation. Current process-global state alone is insufficient for
attribution or safe throttling.

## Workarounds

Until corrected:

- do not expose the GL.iNet WebUI to WAN;
- restrict WebUI access to a trusted management VLAN or specific source
  addresses;
- use firewall rules to rate-limit new requests to `/rpc`;
- maintain a separate authorized recovery path;
- monitor repeated failed challenges and lockout errors.

Restarting the session service or router clears the in-memory timer but does
not remove the vulnerability.

## Recommended remediation

1. Maintain failure state per source address and per target account.
2. Expire and bound tracking entries to prevent state-exhaustion attacks.
3. Never reject a correct administrator authentication solely because another
   source generated failures.
4. Apply progressive per-source delay rather than a global lockout.
5. Add Nginx rate limiting for authentication RPC methods.
6. Log the triggering source, username, count, and lockout decision.
7. Add regression tests using two clients:
   - client A submits invalid challenges;
   - client B must retain the ability to authenticate correctly.
8. Backport the correction to every supported firmware branch sharing
   `gl-ngx-session`.

## Suggested regression test

1. Initialize the router with a known administrator password.
2. From source A, submit at least ten invalid challenges.
3. From source B, perform a correct administrator challenge and login.
4. Pass condition: source B authenticates successfully.
5. Confirm that source A alone receives progressive throttling.
6. Confirm that tracking storage remains bounded under many spoofed usernames.

## Novelty and zero-day terminology

This report establishes a confirmed vulnerability in the GL-MT5000 on both
4.8.6 and 4.9.0. A search did not identify an advisory or CVE specifically
naming the GL-MT5000 for this condition.

However, GL.iNet support has publicly stated for a different model that after
ten failed attempts, authentication from every source is blocked for 600
seconds. Accordingly:

- “confirmed unauthenticated DoS” is supported;
- “new affected product/firmware finding” is supported by the available
  evidence;
- “zero-day candidate” is reasonable shorthand before coordinated triage;
- “proven previously unknown zero-day” is not supportable without ignoring
  relevant prior public information.

## Evidence and artifacts

- Full report:
  `private_disclosures/GL-MT5000/GL-MT5000_UNAUTHENTICATED_GLOBAL_LOGIN_DOS_FULL_REPORT_2026-07-24.md`
- Runtime transcript:
  `private_disclosures/GL-MT5000/MT5000_LOGIN_LOCKOUT_RUNTIME_TRANSCRIPT_2026-07-24.txt`
- 4.9.0 end-to-end HTTP transcript:
  `private_disclosures/GL-MT5000/MT5000_4.9.0_HTTP_TWO_CLIENT_LOCKOUT_TRANSCRIPT_2026-07-24.txt`
- Initial triage:
  `private_disclosures/GL-MT5000/MT5000_PREAUTH_RCE_DOS_TRIAGE_2026-07-24.md`
- Guarded verifier:
  `known_firmware/emulation/GL-MT5000/mt5000_login_lockout_probe.py`
- Decompiled source component:
  `known_firmware/extracted/001503668d83a939/.../squashfs-root/usr/sbin/gl-ngx-session`

## WAN reachability follow-up

Firmware analysis confirms a supported conditional WAN path on both checked
releases. Nginx exposes `/rpc` through wildcard IPv4 and IPv6 listeners on
TCP/443. The stock WAN zone rejects router-local input, but GL.iNet's shipped
DDNS remote-HTTPS configuration creates an `https_wan` rule accepting WAN
TCP/443. The rule opens the same Nginx server and `/rpc` handler.

Accordingly, this is a **configuration-dependent unauthenticated remote
administrative DoS when GL.iNet DDNS remote HTTPS is enabled**, while remaining
blocked from the stock WAN zone when that feature is disabled. Physical
WAN-side confirmation remains pending.

## Final assessment

The GL.iNet GL-MT5000 Brume 3 contains a reproducible unauthenticated
administrative-plane denial of service. Ten low-cost pre-authentication
requests activate one global ten-minute timer that rejects legitimate WebUI
authentication from all sources. The behavior was dynamically reproduced with
the firmware's native services, and the vulnerable logic persists in firmware
4.9.0.

The finding is technically confirmed without a physical demonstration or
vendor verification. Its most accurate pre-coordination label is “confirmed
unauthenticated DoS and zero-day candidate affecting a current, non-EOL
product.”
