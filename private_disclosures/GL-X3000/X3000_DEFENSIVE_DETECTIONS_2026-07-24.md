# GL-X3000 eSIM push-channel defensive detections

Date: 2026-07-24

These controls detect exposure and post-dispatch behavior without attempting
to publish commands or interact with GL.iNet production infrastructure.

## Network controls

The affected 4.8.3 daemon initiates plaintext TCP to
`34.196.94.121:1887`. Until a fixed firmware is available:

- inventory every device making this connection;
- restrict TCP/1887 egress to the documented vendor destination;
- alert if the destination, next hop, ARP mapping, or route changes;
- alert on TCP/1887 connections from any process other than the expected eSIM
  daemon;
- do not treat destination allowlisting as a complete fix because the protocol
  lacks server authentication.

Example Suricata visibility rules:

```text
alert tcp $HOME_NET any -> 34.196.94.121 1887 (msg:"GL-X3000 legacy plaintext eSIM push channel"; flow:to_server,established; sid:930001; rev:1;)
alert tcp $HOME_NET any -> !$HOME_NET 1887 (msg:"Unexpected outbound TCP/1887 push destination"; flow:to_server,established; sid:930002; rev:1;)
```

The first rule is an inventory/legacy-protocol alert, not proof of
exploitation. Tune `$HOME_NET` and suppress known fixed devices.

## Host controls

High-confidence behavior is the eSIM daemon spawning a shell. On an owned
router with audit support, alert whenever `lpa_arm64_v1.50` creates
`/bin/sh`, `ash`, or another command interpreter.

Equivalent EDR logic:

```text
parent executable ends_with "/lpa_arm64_v1.50"
AND child executable IN ("/bin/sh", "/bin/ash", "/usr/bin/bash")
```

Also monitor:

- modifications to `/root/esim/conf.json`;
- unexpected changes to routes covering `34.196.94.121`;
- unauthenticated requests to `/sdk/v1`;
- repeated eSIM profile mutations or unexpected `sh_resp` log entries.

## Containment

If suspicious activity is observed, isolate the router from WAN, preserve its
logs and configuration, rotate device-side credentials through the vendor,
and reimage with a fixed firmware. Blocking TCP/1887 prevents the vulnerable
push path but may disable eSIM synchronization.
