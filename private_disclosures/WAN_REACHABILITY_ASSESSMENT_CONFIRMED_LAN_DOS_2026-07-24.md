# WAN reachability assessment for confirmed LAN DoS findings

Date: 2026-07-24

## Scope and decision rule

This assessment asks whether the already-confirmed unauthenticated LAN denial
of service on RAX29, RAX30, GL-MT5000, GL-MT2500/Brume 2 4.7.4, and RAX9 has
an Internet-to-vulnerable-handler path.

WAN reachability is not inferred merely because a daemon accepts
unauthenticated input or listens on a non-loopback address. It requires an
external-interface listener or a demonstrated forwarding/proxy path, together
with firewall acceptance. Administrator-created port forwarding, WAN
management, or VPN access is classified as conditional exposure rather than
stock/default WAN reachability.

## Results

| Product / firmware | Vulnerable surface | Default WAN result | Conditional WAN result | Confidence |
|---|---|---|---|---|
| RAX30 V1.0.14.108 | UPnP event `SUBSCRIBE`, TCP/56688 | Negative | Possible only after non-default exposure or another vulnerability | High in emulation/static analysis; hardware check remains |
| RAX29 V1.0.14.108 | UPnP event `SUBSCRIBE`, TCP/56688 | Negative by equivalent production controls | Possible only after non-default exposure or another vulnerability | Medium-high; direct two-interface hardware/runtime check remains |
| GL-MT5000 4.8.6/4.9.0 | WebUI JSON-RPC `/rpc`, TCP/443 | Negative with remote access disabled | Confirmed firmware path when GL.iNet DDNS remote HTTPS is enabled | High statically; physical WAN receipt remains |
| GL-MT2500/Brume 2 4.7.4 | WebUI JSON-RPC `/rpc`, TCP/443 | Negative with remote access disabled | Confirmed firmware path when GL.iNet DDNS remote HTTPS is enabled | High statically; physical WAN receipt remains |
| RAX9 V1.0.9.44 | UPnP WFA `/control`, TCP/56688 | Not established; current evidence is LAN-scoped | Possible only after non-default exposure or another vulnerability | Medium; production firewall and two-interface runtime evidence absent |

## NETGEAR RAX30

The two-interface genuine-daemon boot used LAN `10.0.2.15` and WAN
`198.51.100.15`. `/proc/net/tcp` showed the port-56688 listener only on
`10.0.2.15`, not the WAN address or wildcard. SSDP advertised only the LAN
address, and a WAN-address request did not reach or terminate the daemon.

The production `AccessLocal_Deny.sh` also installs restricted-interface drops
for TCP/56688 and UDP/1900 in both IPv4 and IPv6 paths. This rules out direct
stock WAN reachability under the emulated configuration and rules out a simple
IPv6 exposure oversight in the shipped policy.

Disposition: retain as unauthenticated LAN DoS, not WAN DoS.

## NETGEAR RAX29

The RAX29 UPnP binary is byte-for-byte identical to the affected RAX30 binary.
The RAX29 production filesystem independently contains these rules in
`AccessLocal_Deny.sh`:

```text
IPv4 TCP destination port 56688 -> DROP
IPv4 UDP destination port 1900  -> DROP
IPv6 TCP destination port 56688 -> DROP
IPv6 UDP destination port 1900  -> DROP
```

The rules occur at lines 68-69 and 109-110 of the extracted script. Thus the
stock policy has the same direct-ingress and IPv6 barriers as RAX30.

Disposition: no defensible stock WAN upgrade. Add a two-interface runtime or
physical-WAN test to raise the model-specific conclusion to the same confidence
as RAX30.

## GL.iNet GL-MT5000 and GL-MT2500/Brume 2

These findings affect the WebUI authentication path, not UPnP. The vulnerable
handler is the unauthenticated JSON-RPC `/rpc` endpoint served by Nginx on the
management HTTP/HTTPS service. Therefore, unlike the NETGEAR UPnP cases, no
protocol translation or second vulnerable daemon is needed when that same
WebUI is intentionally exposed remotely.

This supports a conditional statement:

> An unauthenticated remote client that can already reach the router's WebUI
> `/rpc` endpoint can trigger the global login lockout.

It does not support a default-WAN statement without evidence that stock
firewall policy exposes TCP/80 or 443 on the WAN interface. A user-configured
VPN also makes the endpoint remotely reachable, but ordinarily places the
client logically on a trusted/internal network; reports should describe that
precondition precisely.

The shipped Nginx configuration listens on wildcard IPv4 and IPv6 addresses.
The stock WAN zone rejects router-local input, so the endpoint is not reachable
from WAN by default. However, the shipped GL.iNet DDNS configuration path
creates a WAN TCP/443 accept rule when remote HTTPS is enabled. That rule opens
the same wildcard Nginx server containing `/rpc`; it does not select a separate
restricted remote-management handler.

Disposition: **confirmed configuration-dependent remote administrative DoS
path** when GL.iNet DDNS remote HTTPS is enabled. A physical WAN-side receipt
remains necessary before describing this as hardware-confirmed.

## NETGEAR RAX9

The current finding reaches unauthenticated
`WFAWLANConfig:1#SetSelectedRegistrar` through MiniUPnPd's `/control` URL. The
firmware evidence currently establishes a LAN-interface service on TCP/56688,
with no demonstrated WAN listener, firewall acceptance, proxy, or forwarding
path.

The RAX30/RAX29 firewall conclusion cannot simply be inherited: RAX9 uses a
different platform and MiniUPnPd implementation. Its production firewall and
IPv6 policy must be checked independently.

Disposition: LAN DoS only on present evidence.

## Remaining bounded validation

For each physical device, use a WAN-side test host on an isolated,
documentation-only network and collect:

1. `ss -lntup` or `/proc/net/{tcp,tcp6,udp,udp6}` with interface addresses;
2. complete IPv4 and IPv6 input/bridge rules after normal boot;
3. a LAN control request showing the vulnerable service is active;
4. a non-triggering WAN request or packet capture first;
5. only if the service is reachable, one bounded trigger followed by service
   liveness and supervisor-restart checks.

For GL.iNet devices, repeat the capture with remote WebUI management disabled
and enabled. A positive result only in the enabled state is a conditional WAN
DoS. Do not use Internet scanning or test devices not owned and isolated by the
researcher.
