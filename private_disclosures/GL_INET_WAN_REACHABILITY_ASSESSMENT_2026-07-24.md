# GL-MT5000 and GL-MT2500 WebUI DoS WAN reachability assessment

Date: 2026-07-24

## Outcome

The global login-lockout DoS is **not reachable from the stock WAN zone with
remote access disabled**, because the shipped OpenWrt firewall assigns
`wan`/`wan6` to a zone whose router-local input policy is `REJECT`.

The same vulnerable `/rpc` handler is **WAN reachable when GL.iNet's normal
DDNS remote HTTPS option is enabled**. This is a supported configuration path,
not an unrelated manual port-forwarding hypothesis:

1. Nginx listens on wildcard IPv4 and IPv6 addresses on TCP/443.
2. `/rpc` is served in that same wildcard HTTPS server.
3. the shipped DDNS migration/configuration script creates an `https_wan`
   firewall rule accepting WAN TCP/443 when `enabled_https=1`;
4. after initial setup, the Nginx access hook returns without imposing a
   source-interface or source-address restriction;
5. the previously confirmed pre-authentication `challenge` method is therefore
   available through the accepted WAN HTTPS connection.

Correct classification:

> Unauthenticated remote administrative login DoS when GL.iNet DDNS remote
> HTTPS access is enabled; LAN-only under the stock remote-access-disabled
> configuration.

A second supported conditional path exists: Drop-in Gateway mode installs an
early accept-all input rule for the physical WAN interface. In that mode,
wildcard Nginx ports 80/443 and `/rpc` are reachable from the upstream network.
The factory images explicitly set this feature to disabled.

## Affected firmware checked

| Product | Firmware | WAN-disabled result | Remote HTTPS enabled |
|---|---|---|---|
| GL-MT5000 Brume 3 | 4.8.6 | blocked by WAN input `REJECT` | `/rpc` reachable through accepted TCP/443 |
| GL-MT5000 Brume 3 | 4.9.0 | blocked by WAN input `REJECT` | `/rpc` reachable through accepted TCP/443 |
| GL-MT2500/MT2500A Brume 2 | 4.7.4 | blocked by WAN input `REJECT` | `/rpc` reachable through accepted TCP/443 |

## Shipped Nginx path

Each checked `etc/nginx/conf.d/gl.conf` has the equivalent server:

```nginx
server {
    listen 80;
    listen [::]:80;
    listen 443 ssl;
    listen [::]:443 ssl;

    location = /rpc {
        content_by_lua_file /usr/share/gl-ngx/oui-rpc.lua;
    }
}
```

The listener is not bound only to the LAN address. Both IPv4 and IPv6 wildcard
listeners are configured. The firewall is consequently the control deciding
whether a packet arriving on WAN can reach Nginx.

On MT5000 4.9.0, `/rpc` also runs `oui-access.lua`. That hook does not restore
LAN-only reachability: once `oui-httpd.main.inited` exists, it returns at lines
41-42 without testing the source interface or address. The Brume 2 4.7.4
`/rpc` location does not invoke this access hook at all.

## Shipped default firewall path

All three checked images use the equivalent UCI zones:

```text
zone lan: networks lan; input ACCEPT
zone wan: networks wan and wan6; input REJECT
```

No default WAN TCP/80 or TCP/443 accept rule is present in
`etc/config/firewall`. Thus wildcard binding alone is not default WAN
exposure.

## Supported remote-HTTPS path

All three images ship `etc/uci-defaults/zzz-ddns-glsdk4-config`. When either
legacy remote HTTP or remote HTTPS is enabled, it creates:

```text
firewall.https_wan = rule
firewall.https_wan.src = wan
firewall.https_wan.proto = tcp
firewall.https_wan.dest_port = 443
firewall.https_wan.target = ACCEPT
```

The legacy HTTP setting is migrated to HTTPS, so the remotely exposed handler
is TCP/443. The factory `gl_ddns` file does not set `enabled_http` or
`enabled_https`; therefore this rule is not enabled by default in the extracted
images.

This path opens the router-local wildcard Nginx server, including `/rpc`; it
does not create a separate restricted remote-management virtual host.

## Validation boundary

This is a firmware-control-flow and policy confirmation. It does not include a
physical WAN packet capture. A disclosure-grade hardware receipt should show:

1. remote HTTPS disabled: WAN TCP/443 rejected and LAN `/rpc` control works;
2. enable GL.iNet DDNS remote HTTPS through the normal UI;
3. record the resulting `https_wan` rule and wildcard Nginx listener;
4. from an isolated WAN-side host, send one non-triggering `/rpc` challenge;
5. only after reachability is established, use the already-bounded two-client
   lockout reproducer and confirm that a LAN administrator is locked out.

Do not scan Internet hosts or test devices not owned and isolated by the
researcher.
