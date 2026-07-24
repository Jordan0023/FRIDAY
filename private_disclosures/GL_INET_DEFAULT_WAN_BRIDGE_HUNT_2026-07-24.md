# GL.iNet default-WAN bridge vulnerability hunt

Date: 2026-07-24

Products:

- GL-MT5000 Brume 3 firmware 4.9.0
- GL-MT5000 Brume 3 firmware 4.8.6
- GL-MT2500/MT2500A Brume 2 firmware 4.7.4

## Objective

Find a separate pre-authentication vulnerability that crosses the factory WAN
boundary and reaches or exposes the vulnerable WebUI `/rpc` handler without
prior owner configuration.

## Outcome

No unconditional bridge vulnerability was confirmed in this pass.

One additional configuration-dependent exposure was identified: GL.iNet
Drop-in Gateway mode installs an accept-all router-input rule on the physical
WAN interface. In that supported mode, the wildcard Nginx listener and `/rpc`
are reachable from the upstream network even when DDNS remote HTTPS is not
enabled.

Factory configuration sets `edgerouter.global.enabled=0`, so this does not
promote the finding to unconditional WAN DoS.

## Factory WAN surface

All three images assign `wan` and `wan6` to a zone with router-local input
`REJECT`. The only explicit factory WAN accepts are:

- UDP/68 DHCP replies;
- IPv4 ICMP echo requests;
- IGMP;
- DHCPv6 replies on UDP/546;
- required ICMPv6/MLD;
- forwarded ESP; and
- forwarded UDP/500 ISAKMP.

No factory rule accepts router-local HTTP, HTTPS, SSH, UPnP, RPC, WireGuard,
OpenVPN, Tailscale, or ZeroTier.

ESP and UDP/500 are configured as forwarding rules toward LAN, not
router-local VPN listeners. They do not reach Nginx.

## Cloud-agent hypothesis

The cloud service starts only when:

```text
gl-cloud.@cloud[0].enable = 1
```

The factory `gl-cloud` configuration contains only a log-level setting and no
enable flag. The init script returns without starting the agent unless the flag
equals `1`.

Therefore the outbound MQTT/cloud command plane is not an unconditional
factory bridge. Device enrollment or another authenticated setting is a
prerequisite. No pre-enrollment unauthenticated method that starts or binds the
cloud agent was identified.

## DHCP-client hypothesis

The default firewall accepts DHCP replies, making the WAN DHCP client a real
pre-authentication parser surface for an upstream-network attacker.

The checked `lib/netifd/dhcp.script` versions pass address and route values
through netifd JSON helpers. Potentially concerning `eval` calls consume the
output of `ipcalc.sh`, not DHCP option text directly. Domain, hostname,
message, NTP, route, and 6rd values are added with typed JSON helper functions.

No command-injection path from a DHCP-controlled value to an executed shell
fragment was confirmed. This is an adjacent/upstream-WAN threat model in any
case, not arbitrary Internet reachability through routed traffic.

## Drop-in Gateway exposure

All three images ship `etc/edgerouter.fw`. When Drop-in Gateway mode is enabled,
the fw4 path writes:

```nft
iifname "$WANIF" accept
```

into the pre-input chain. The older iptables path equivalently inserts:

```text
EDGEROUTER_INPUT -i $WANIF -j ACCEPT
```

The init service activates this only when:

```text
edgerouter.global.enabled = 1
glconfig.general.mode = router
```

All three factory images contain `glconfig.general.mode=router`, but explicitly set
`edgerouter.global.enabled=0`.

Consequences when the feature is enabled:

1. all router-local services bound to the physical WAN interface bypass the
   normal WAN-zone rejection;
2. Nginx's wildcard TCP/80 and TCP/443 listeners become upstream reachable;
3. `/rpc` becomes reachable; and
4. the confirmed unauthenticated global login lockout can be triggered from
   that upstream network.

This is broader than the DDNS remote-HTTPS exposure because it accepts every
protocol on the interface. It warrants vendor hardening review, but it is a
documented-mode/configuration risk rather than a demonstrated authentication
bypass.

## Unauthenticated flag-change check

The WebUI RPC objects capable of modifying firewall, local access, cloud,
network mode, or Drop-in Gateway state are not in the no-auth allowlist.
Configured devices require a valid administrative session for those component
calls. The setup-only `ui.init` path refuses reuse after initialization.

No unauthenticated route that changes `edgerouter.global.enabled` was
established.

## Current classification

Confirmed remote paths:

1. GL.iNet DDNS remote HTTPS enabled: conditional Internet-facing TCP/443
   exposure.
2. Drop-in Gateway enabled: conditional exposure to the upstream network,
   including TCP/80 and TCP/443.

Not confirmed:

- factory/default WAN reachability;
- an authentication bypass that enables either feature;
- cloud pre-enrollment command acceptance;
- DHCP-to-command-execution or DHCP-to-firewall-rule injection;
- an IPv6 firewall bypass; or
- arbitrary routed-Internet access to `/rpc`.

## DHCP/cloud deep-dive follow-up

A marker-only execution of the genuine DHCP hook did not produce command
execution through attacker-shaped IP, gateway, domain, or classless-route
values. Static shell review likewise found no DHCP-to-accept-rule path.

The genuine cloud agent was brought up in a disposable, network-disabled
firmware root. Factory init still prevents it from starting unless cloud is
enabled. Repeated `insecure` TLS-option constants in its bytecode create a
separate enabled-cloud interception lead, but not a factory-default bridge.
See `private_disclosures/GL_INET_DHCP_CLOUD_DEEP_DIVE_2026-07-24.md`.
