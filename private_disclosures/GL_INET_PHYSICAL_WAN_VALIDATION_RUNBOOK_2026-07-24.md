# GL.iNet physical WAN validation runbook

Date: 2026-07-24

## Current execution status

The host was inspected on 2026-07-24. Its unused physical Ethernet interfaces
were down with `NO-CARRIER`, and no GL-MT5000 or GL-MT2500 hardware or matching
lab container was attached. The physical packet test therefore remains
pending; no hardware result is claimed.

## Safe lab topology

- Connect a researcher-controlled WAN test host directly to the router WAN
  port through an isolated switch or cable.
- Connect a second researcher-controlled host to LAN.
- Do not connect the router WAN to the public Internet during testing.
- Use private addresses on the WAN segment.

## Matrix

For each GL-MT5000 firmware 4.8.6 and 4.9.0, and GL-MT2500 firmware 4.7.4:

1. Factory/default remote HTTPS disabled:
   - capture the router's effective firewall rules;
   - confirm LAN `/rpc` responds;
   - run the WAN probe and record rejection/timeout.
2. Enable the supported DDNS remote HTTPS option through the local
   authenticated UI:
   - capture the resulting `https_wan` firewall rule;
   - record the wildcard Nginx TCP/443 listener;
   - from the isolated WAN host, run exactly one non-destructive probe:

     `python3 scripts/probe_glinet_wan_rpc.py https://<private-wan-ip>/rpc --output <evidence.json>`

3. If the root challenge succeeds, execute the existing bounded two-client
   reproducer once and verify that the separate LAN administrator client
   receives error `-32003`.
4. Disable remote HTTPS and verify WAN TCP/443 closes again.

The supplied reachability probe refuses publicly routable targets and sends
one challenge for the real `root` account. It does not use a nonexistent
username and therefore does not contribute to the vulnerable ten-failure
counter.

## Evidence to retain

- product, firmware version, firmware SHA-256, and factory-reset state;
- topology diagram and interface addresses;
- packet capture on the isolated WAN host;
- effective firewall rules before, during, and after remote HTTPS;
- Nginx listener output;
- WAN probe JSON;
- two-client lockout transcript, if reachability is established;
- confirmation that remote HTTPS was disabled after the test.
