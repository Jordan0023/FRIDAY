# MR90/MS90 fixed-SessionID WAN reachability assessment

Date: 2026-07-24

## Conclusion

The MS90 fixed-SessionID SOAP bypass must not currently be classified as a WAN
or Internet-exploitable router vulnerability.

The MS90 is the mesh satellite. The corresponding Internet gateway is the
MR90. Direct inspection of the latest MR90 V1.0.2.46 firmware shows that it
ships a different `httpd`, and the hard-coded authorization token
`12345678901234567890` is absent from that server binary.

The token occurs in the MR90 root filesystem only in client, synchronization,
test, or generic-library components:

```text
/usr/bin/diltest
/usr/lib/libjson-c.so.2.0.1
/usr/sbin/net_scan
/usr/sbin/soapc
/usr/sbin/agent_sync
```

It does not occur in `/usr/sbin/httpd`. Consequently, the exact MS90 server-side
authorization predicate cannot be projected onto the MR90 WAN management
service.

## Firmware identity

- MR90 V1.0.2.46 package SHA-256:
  `e7db707b7299175c27ae7cac269510d2554ebd0ca87469a21ec2a63f4d0e99f1`
- MR90 `/usr/sbin/httpd` SHA-256:
  `037fb578bbad7b4ad71637d6d60be4ffd91d4e0c2f9b66409186e9f51628af48`
- MS90 `/usr/sbin/httpd` SHA-256:
  `91a220763fbd1f7f99041a6a60e8a18fee024fd8bca1de62e7631ecd5c49b570`

The router and satellite HTTP daemons are not byte-identical.

## Realistic router emulation

The genuine MR90 V1.0.2.46 root filesystem was booted in a dual-interface ARM
full-system lab:

- `eth0`: simulated WAN, `192.0.2.15/24`;
- `br0`: simulated LAN, `10.0.2.15/24`;
- QEMU user networks: `restrict=on`;
- host access: loopback-only forwards;
- remote management: explicitly enabled;
- remote-management port: TCP/8443.

The genuine router daemon opened:

```text
httpd: socket bound in 10.0.2.15:9443.
httpd: socket bound in 192.0.2.15:8443.
```

This confirms that the firmware contains a distinct WAN remote-management
listener when that optional feature is enabled.

Under the generic QEMU platform, the remote-management listener repeatedly
retried its IPv6 setup and did not complete TLS acceptance through the host
forward. This prevents a valid dynamic request/response conclusion about the
emulated WAN listener. It does not change the binary-level negative result:
the MR90 server does not contain the MS90 universal-token predicate.

## WAN-to-satellite path analysis

Static tracing does not show a transparent path from the MR90 WAN listener to
the MS90 SOAP server.

The MR90 `soapc` binary is an outbound satellite-management client. It contains
the fixed token, satellite address variables such as `soapc_sat_%d_ip`, and the
request material `POST /soap/server_sa/` and `HOST: %s`. This explains why the
token is present in the router root filesystem: the router uses it when the
router itself initiates management requests to a satellite. It is not evidence
that the MR90 HTTP server accepts the token from a WAN client.

The router's `/etc/proxy.conf` terminates TLS and proxies to its own local web
service; it does not define a satellite-management proxy. A review of the
firmware firewall configuration also found no fixed DNAT or REDIRECT rule that
maps the WAN remote-management port to an MS90 management address.

The MR90 `httpd` function associated with `/soap/server_sa/` and `SOAPAction`
classifies a request as SOAP for parsing. It does not contain the MS90 fixed
SessionID comparison, and the token is absent from the entire MR90 server
binary. Therefore, a hypothetical WAN-to-satellite exploit would require a
separate MR90 authentication or request-dispatch flaw that invokes `soapc`.
No such unauthenticated trigger was identified in this analysis.

Remote management is conditional on `http_rmenable`; the WAN listener seen in
the lab required explicitly enabling that option. The firmware default does
not establish an Internet listener by itself.

## Classification boundary

- MS90 satellite, LAN/backhaul fixed-token bypass: **confirmed**
- MS90 unauthenticated privileged reboot action: **confirmed**
- MR90 router contains the same fixed-token server defect: **no**
- MR90 optional WAN listener exists when enabled: **confirmed**
- Transparent WAN-to-MS90 SOAP forwarding: **not present in the inspected
  proxy and firewall configuration**
- Unauthenticated MR90 action that triggers privileged satellite `soapc`
  traffic: **not identified**
- Fixed-token bypass through the MR90 WAN listener: **not supported by the
  shipping server binary and not dynamically confirmed**
- Internet-exploitable WAN DoS claim: **not established**

The defensible attack-vector classification for the current finding remains
network-adjacent/local network.

## Evidence

- `known_firmware/emulation/MK93S/MR90-V1.0.2.46-wan-http-lab/serial.log`
- `known_firmware/emulation/MK93S/mr90_wan_http_init`
- `scripts/emulate_mr90_10246_wan_http.py`
