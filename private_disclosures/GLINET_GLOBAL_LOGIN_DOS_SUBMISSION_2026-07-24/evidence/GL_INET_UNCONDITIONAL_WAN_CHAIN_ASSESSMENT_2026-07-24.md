# GL.iNet unconditional WAN reachability chain assessment

Date: 2026-07-24

## Goal

Determine whether a remote unauthenticated party can make the GL-MT5000 or
GL-MT2500/Brume 2 WebUI `/rpc` endpoint WAN reachable without prior owner-side
remote-access configuration.

The work was limited to extracted firmware and the isolated native-service
lab. No Internet scanning or third-party device testing was performed.

## Outcome

No unconditional WAN-enablement chain was confirmed.

The supported DDNS remote-HTTPS path remains conditional on a stored
`enabled_http=1` or `enabled_https=1` value. The shipped migration script reads
those values and creates the WAN TCP/443 accept rule; it does not set either
value on a factory configuration.

## Hypothesis results

| Hypothesis | Result | Reason |
|---|---|---|
| Unauthenticated `/rpc` call enables DDNS remote HTTPS | Negative | DDNS, firewall, local-access, cloud, and system setters are absent from the no-auth allowlist and require a valid session |
| Setup-only `ui.init` can be reused after setup | Negative from recovered control flow | `ui.init` calls the initialization check and returns `ERROR_CODE_ACCESS` when already initialized |
| Header spoof creates a privileged local RPC session | Negative | the special `glinet` header is honored only when Nginx's actual peer address is `127.0.0.1` or `::1`; forwarded headers are not used |
| Direct request to `/cgi-bin/glc` bypasses RPC authorization | Negative | Nginx exposes the CGI route, but the genuine `glc` executable returns HTTP 403 unless its `REQUEST_URI` is `/rpc`; ordinary direct requests retain `/cgi-bin/glc` |
| IPv6 avoids the WAN firewall | Negative under shipped policy | `wan6` belongs to the same WAN zone with router-local input `REJECT` |
| Cloud management enables HTTPS without enrollment | Not demonstrated | cloud RPC operations require normal RPC authorization; an enrolled/paired cloud device would itself be a prior owner-side condition |
| DDNS migration enables HTTPS automatically | Negative on factory image | factory `gl_ddns` specifies ports and `enabled_ssh=0` but no enabled HTTP/HTTPS flag |
| Port-forwarding helper silently exposes router-local HTTPS | Negative | the default configuration contains no WAN TCP/443 redirect or accept rule |

## Authentication-boundary evidence

The `/rpc` dispatcher accepts top-level `challenge` and `login` without a
session. Component calls use the `call` method. Before dispatching a component
call, it:

1. checks the static `oui-httpd` no-auth object/method list;
2. otherwise calls `rpc.access`;
3. obtains the session from `gl-session`;
4. rejects a missing/empty ACL group; and
5. allows administrative calls only for the root ACL group.

The checked no-auth lists contain setup and localization operations:

```text
ui.get_lang
ui.load_locales
ui.check_initialized
ui.get_wifi_config_init
ui.init
ui.get_timezone_list        # MT5000 4.9.0
system.get_timezone_list    # MT5000 4.9.0
screen.get_lock_status      # MT5000 4.9.0
```

They do not include the `ddns`, `firewall`, `local-access`, `cloud`, or
privileged `system` setters needed to create an `https_wan` rule.

## Component-dispatch path

Nginx has a generic `/cgi-bin/` FastCGI location and the genuine component
dispatcher exists as `www/cgi-bin/glc`, so this path required explicit review.
The genuine MT5000 4.9.0 and Brume 2 4.7.4 executables contain an early
request-boundary check:

```text
REQUEST_METHOD
Status: 403 Forbidden
REQUEST_URI
/rpc
```

The normal authorized dispatcher reaches it with an Nginx subrequest made
while handling `/rpc`. A direct request to `/cgi-bin/glc` does not satisfy the
required URI and is rejected before object/method dispatch. No request-target
normalization form that simultaneously selects the CGI location and supplies
`REQUEST_URI=/rpc` was established.

## Setup-only path

`ui.init` is intentionally no-auth so a new device can be configured. The
recovered bytecode strings and control flow show:

```text
check_initialized
initialized
ERROR_CODE_ACCESS
start_initialization
```

Thus a configured victim does not expose this method as a reusable
configuration setter. An actually uninitialized router is a distinct,
setup-state threat model and is not an unconditional WAN path because the
stock WAN firewall still rejects TCP/443.

## Local-header path

`oui.rpc.access` contains a special internal-service condition:

```lua
if s.is_local and headers["glinet"] then
    return true
end
```

`s.is_local` is derived from `ngx.var.remote_addr` and is true only for
loopback. `X-Forwarded-For`, `Host`, and the `glinet` header cannot by
themselves satisfy it. No WAN-facing reverse proxy that converts an external
request into the required loopback peer was identified.

## Cloud-management path

The firmware contains cloud-management components, but the WebUI `cloud`
object is not in the no-auth list. A device already enrolled in a vendor cloud
account may accept authenticated remote management through an outbound
channel, but enrollment/account authorization is an owner-side condition. No
pre-enrollment unauthenticated cloud command path was established.

## Classification

The global login lockout remains:

> LAN-reachable by default and remotely reachable when a supported management
> exposure such as GL.iNet DDNS remote HTTPS is enabled.

It should not be described as unconditional WAN DoS. Promoting it would require
a separate, independently confirmed pre-authentication boundary failure that
opens TCP/443 or relays a request to `/rpc`.
