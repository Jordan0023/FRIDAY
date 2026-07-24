# GL.iNet DHCP and cloud WAN-bridge deep dive

Date: 2026-07-24

Firmware:

- GL-MT5000 4.9.0
- GL-MT2500/Brume 2 4.7.4

## Outcome

Neither remaining candidate produced an unconditional Internet-to-WebUI
bridge.

- DHCP option command injection: not reproduced and not supported by the
  reviewed shell data flow.
- Cloud pre-enrollment command acceptance: not reachable in the factory state
  because the cloud agent is disabled. No pre-enrollment command path was
  confirmed.

The cloud agent contains a separate TLS-verification lead: its bytecode
contains repeated `insecure` options near server-discovery, CA-download, and
binding HTTP paths. This deserves a dedicated enabled-cloud interception test,
but it cannot make the current DoS unconditionally WAN reachable because the
agent does not start on a factory configuration.

## DHCP attack matrix

The genuine `lib/netifd/dhcp.script` was executed under the firmware AArch64
shell in a disposable, network-disabled container. Marker-only metacharacter
values were supplied through:

- assigned IPv4 address;
- router/gateway;
- domain search;
- RFC3442 static routes.

No marker file was created.

The partial user-mode execution could not complete netifd updates because the
isolated root lacked a running `ubus`/netifd service and several extracted
BusyBox applet links. It nevertheless exercised shell parsing through the
candidate expansions before failing. This is not a full DHCP packet-level
negative receipt.

## DHCP static data flow

The relevant shell behavior does not reparse DHCP metacharacters as commands:

- `$ip` and each `$router` item are passed as quoted arguments to `ipcalc.sh`;
- command substitution is evaluated from `ipcalc.sh` output, not directly from
  the input string;
- expanded semicolons produced by parameter expansion are data, not shell
  control operators;
- DNS and domain values are passed to netifd JSON helpers;
- classless routes become typed route arguments;
- hostname, message, NTP, and 6rd fields become typed JSON values.

The Brume 2 `update_wan_isolate` hook has unsafe-looking unquoted tests and UCI
arguments, but its `wan_ip` and mask come back from netifd's validated
interface-status object rather than directly from an arbitrary textual DHCP
field. No path to an `ACCEPT` rule was found; the hook only maintains guest
`REJECT` isolation rules.

Disposition: no confirmed DHCP-to-command-execution, DHCP-to-firewall-accept,
or DHCP-to-WebUI relay.

## Cloud factory-state test

Both products ship:

```text
config cloud
    option log 'INFO'
```

They do not ship `enable=1`. The init service reads
`gl-cloud.@cloud[0].enable` and returns without launching the agent unless it
equals `1`.

The genuine MT5000 AArch64 `eco`/`gl-cloud` process was also started directly
inside a disposable firmware-root container with networking disabled. It
loaded its cloud command modules and then attempted normal network/server
discovery. This shows the genuine bytecode is executable in the lab, but
directly starting the binary intentionally bypasses the factory init gate and
does not establish default reachability.

## Cloud authentication observations

The agent implements:

- HMAC/SHA-256 signing;
- timestamp or nonce-bearing server-discovery requests;
- device MAC, serial number, certificate, and private-key inputs;
- broker username/password or token data;
- device-specific MQTT topics;
- bind/unbind state; and
- server-side bind-status checks.

An unbound configuration has no token, and the factory-disabled service has no
outbound MQTT connection on which an attacker could deliver a command.

No static evidence established that an arbitrary MQTT publisher can bypass
broker credentials or device-topic authorization. Testing the real vendor
broker was intentionally not attempted.

## TLS-verification lead

Both cloud-agent bytecode families contain an `insecure` option. On MT5000
4.9.0 it occurs near:

- bind and clean-token requests;
- `getCaCert/ca.crt`;
- server discovery/authentication; and
- MQTT TLS option construction.

The underlying `eco.mqtt` client explicitly supports `insecure`, CA,
certificate, and private-key options. Constants alone do not prove which calls
set `insecure=true`; bytecode control-flow reconstruction or an authorized
interception test is still required.

If TLS verification is disabled on an enabled/enrolled device, an on-path
attacker might impersonate cloud infrastructure. That would be a serious
separate vulnerability, but it has two prerequisites absent from the desired
unconditional chain:

1. cloud management enabled/enrolled; and
2. an attacker capable of influencing the device's cloud connection path or
   DNS.

## Final disposition

No new evidence supports changing the global-login DoS to unconditional WAN
reachability.

The highest-value follow-up is an isolated fake-cloud test with:

1. a synthetic device identity and token;
2. cloud explicitly enabled in the disposable root;
3. DNS pinned to a local TLS/MQTT server;
4. an untrusted certificate first, followed by a trusted control;
5. marker-only cloud commands; and
6. no connection to GL.iNet production services.

That test can confirm or reject the TLS-verification lead, but any result will
apply to cloud-enabled devices rather than factory-default devices.

