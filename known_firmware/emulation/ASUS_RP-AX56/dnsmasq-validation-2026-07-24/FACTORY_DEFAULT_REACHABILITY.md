# Factory-default DHCPv6 reachability

Date: 2026-07-24

## Conclusion

CVE-2022-0934 is **not shown reachable in the factory-default RP-AX56
configuration**.

The exported `router_defaults` table in each firmware's exact `libshared.so`
contains:

| Firmware | `ipv6_service` | `ipv6_radvd` | `ipv6_autoconf_type` |
| --- | --- | --- | --- |
| 3.0.0.4.386_42860 | `disabled` | `1` | `0` |
| 3.0.0.4.386_51891 | `disabled` | `1` | `0` |

`ipv6_radvd=1` is only a subordinate preference. The service selector is
`ipv6_service=disabled`, so IPv6 service type resolves to zero.

The focused decompilation of the exact 51891 `rc` binary confirms that
`start_dnsmasq` calls `get_ipv6_service()` before emitting IPv6 configuration.
When that function returns zero, control jumps past the block that writes:

- `enable-ra`
- the stateful `dhcp-range=lan,::...` directive
- the stateless `dhcp-range=lan,::,constructor:...` directive

The only exported model-default override table,
`router_defaults_override_type1`, contains no `ipv6_service` or other IPv6
override.

Therefore a reset device should start dnsmasq for its normal IPv4/DNS roles
without configuring its DHCPv6 server. Enabling a supported IPv6 service after
setup can make the vulnerable DHCPv6 path reachable.

## Evidence and limitations

- `factory-ipv6-xrefs.c` contains the relevant exact-binary pseudocode and
  string references.
- The defaults were read directly from the exported `router_defaults` objects,
  not from the Greenhouse test profile.
- A physical factory-reset boot was not captured. Hardware validation should
  confirm `/etc/dnsmasq.conf`, the dnsmasq command line, and UDP/547 before and
  after IPv6 is enabled.
