# RAX54Sv2 V1.1.6.38 default-on UPnP and HTTP security triage

Date: 2026-07-24

## Result

The exact RAX54Sv2 V1.1.6.38 `upnpd` and `httpd` were tested in isolated
emulation using the RAX30/RAX54S unauthenticated RCE and DoS process.

No service-level denial of service or remote code execution was confirmed.

- The RAX30 GENA callback crash does not transfer to the RAX54Sv2 `upnpd`.
- UPnP command markers did not execute.
- Large UPnP actions and values reset only their individual connections.
- The proprietary `/soap/server_sa/` route is reachable without HTTP Basic
  credentials over HTTPS, but tested actions enforce their own security or
  reject incomplete arguments.
- A command marker reached SOAP action parsing but did not reach the lab's
  command-execution sink.
- The exact `httpd` survived the route, action, URI, header, and body matrices.

This is a negative result for the tested surfaces and inputs, not a claim that
the firmware is vulnerability-free.

## Firmware

- Product: NETGEAR RAX54Sv2
- Version: V1.1.6.38
- Package SHA-256:
  `c9b1ed79f8f766b583969f1a2cd3f849a8d788f7053a0d845c39db425ef56110`
- `/usr/sbin/upnpd` SHA-256:
  `590c2ad4564b68f82f2241237d8bd6ead413e1a0e610f54d08bbe08abd0ca8d1`
- `/usr/sbin/httpd` SHA-256:
  `93881747b464384203309bf42dad4eb20ad9b8950e5b7850da06ac9cb57cc862`

The v2 binaries differ from the RAX54S V1.0.17.144 binaries, so dynamic results
were reproduced directly rather than transferred by binary identity.

## UPnP validation

### Lab

The exact ARM daemon was launched in a privileged but `--network none`
container with:

- a synthetic `br0` at `192.168.1.1/24`;
- initialized ACOS NVRAM with UPnP enabled;
- the expected empty NAT shared-memory segment; and
- no host port or external network.

The daemon listened on TCP/56688 and served unauthenticated requests at
`/Public_UPNP_C3`.

Harness:
`scripts/emulate_rax54sv2_upnp.py`

### Body-copy transfer

`DeviceInfo:1#GetInfo` was sent to `/Public_UPNP_C3` with inert padding from
zero through 1,024 bytes. Every request returned the same SOAP 500 response,
and the daemon remained available.

Evidence:
`known_firmware/emulation/RAX54SV2/upnp-body-overflow.log`

### Command and parser cases

The bounded cases covered:

- command syntax in `SOAPAction`;
- `NewNTPServer1`;
- `NewFirmwareURL`;
- OOKLA speed-test server input;
- a 16 KiB action name;
- 512 XML nesting levels; and
- a 256 KiB XML value.

No marker was created. The long action and 256 KiB value reset their
individual connections, but a fresh WANIPConnection baseline passed
immediately afterward and TCP/56688 remained listening.

Evidence:
`known_firmware/emulation/RAX54SV2/upnp-full-security.log`

### GENA callback transfer

Both an explicit-port callback and a valid no-port callback returned HTTP 200.
Callback paths of 64, 128, and 256 bytes returned HTTP 200. Paths from 512
through 4,096 bytes returned HTTP 400. Paths of 8,192 and 16,384 bytes reset
only their connections.

The daemon passed a fresh liveness request after every case. The RAX30 callback
null-dereference/daemon-exit behavior did not reproduce.

Evidence:
`known_firmware/emulation/RAX54SV2/upnp-gena.log`

## HTTP/SOAP validation

### Lab

The exact v2 root filesystem was booted under QEMU with restricted user
networking. Host forwarding was limited to:

- `127.0.0.1:25082` to guest HTTP/80; and
- `127.0.0.1:25156` to guest HTTPS/9443.

The lab supplies the firmware's expected certificate files, ACOS NVRAM, SMD
socket, and narrowly modeled empty NAT/firewall table. Command execution is
preserved but traced by the shared preload.

Harness:
`scripts/emulate_rax54sv2_http_full_system.py`

The exact daemon remained alive and served:

- an HTTP redirect page on port 80; and
- the HTTPS administration/SOAP listener on port 9443.

### Authentication boundary

Without credentials, HTTPS GET requests for the following returned
`HTTP/1.0 401 Unauthorized`:

- `/`
- `/index.htm`
- `/unauth.cgi`
- `/passwordrecovered.cgi`
- `/passwordrecovered_debug`
- `/passwordrecovered_debug2`
- `/upgrade_check.cgi`
- `/soap/server_sa/`

SOAP POST requests to `/soap/server_sa/` are admitted before HTTP Basic
authentication and return HTTP 200. Security is then expressed in the SOAP
`ResponseCode`.

A normal `DeviceInfo:GetInfo` returned internal `ResponseCode` 401. The OOKLA
start action also returned 401 when supplied with a bounded server identifier.
Incomplete or incorrectly namespaced setters returned SOAP 404.

`GetSecurityQuestions` under the DeviceConfig namespace returned
`ResponseCode` 000. This is consistent with the deliberate password-recovery
flow and is not by itself an authentication bypass, RCE, or DoS.

### Command-marker cases

The following inert marker syntax was tested:

- appended to the `GetInfo` SOAP action;
- placed in a generic SOAP body value;
- NTP server values;
- a firmware URL; and
- an OOKLA server identifier.

Serial evidence proves the SOAP action marker reached
`get_service_and_api`:

```text
get_http_header_value header_item SOAPAction, value
"urn:NETGEAR-ROUTER:service:DeviceInfo:1#GetInfo;$(touch${IFS}/tmp/FRIDAY_RAX54SV2_HTTP_RCE_MARKER)"
get_service_and_api DeviceInfo:GetInfo;$(touch${IFS}/tmp/FRIDAY_RAX54SV2_HTTP_RCE_MARKER)
```

No tracing sink or marker creation followed. The daemon remained alive.

### Parser cases

The HTTPS listener survived:

- 1,024- and 4,096-byte request URIs;
- 1,024- and 4,096-byte HTTP header values; and
- a 64 KiB SOAP body.

The 64 KiB body timed out on its individual connection. A new authenticated
boundary control returned immediately afterward, so this is not classified as
a service-level DoS.

Probe:
`scripts/probe_rax54sv2_http_security.py`

### Action inventory

Two hundred eight action-like strings recovered from the exact `httpd` were
sent sequentially under the DeviceConfig namespace without credentials. The
daemon remained available throughout. Most returned SOAP 404 because the
service/action pair was unknown or required arguments; recognized protected
actions returned 401. `GetSecurityQuestions` was the sole response code 000 in
this generic matrix.

This matrix is useful for reachability and availability, but it is not an
exhaustive valid-argument test of every service because service namespaces and
required arguments differ.

Evidence:
`known_firmware/emulation/RAX54SV2/full-system-http-lab/unauth-soap-action-matrix.json`

Full serial trace:
`known_firmware/emulation/RAX54SV2/full-system-http-lab/http-security-serial.log`

## Classification

- Default-on `upnpd` unauthenticated RCE: not confirmed.
- Default-on `upnpd` service DoS: not confirmed.
- RAX30 GENA crash transfer: tested negative.
- HTTPS CGI authentication boundary: enforced for tested GET routes.
- Pre-Basic-auth SOAP dispatcher reachability: confirmed.
- SOAP action-level security: confirmed for representative protected actions.
- SOAP command-marker execution: not observed.
- `httpd` service DoS: not confirmed.
- Whole-router DoS: not demonstrated.
- Zero-day claim justified by this pass: **no**.

## Residual leads

The highest-value remaining work is:

1. recover the precise service namespace and required argument schema for each
   state-changing SOAP action;
2. focus decompilation on `ResetAdminPassword`, firmware-update, NTP, WLAN
   passphrase, and configuration-import handlers;
3. verify password-recovery state transitions and attempt limits with
   production-equivalent NVRAM;
4. test on physical RAX54Sv2 hardware to remove uncertainty from modeled
   NAT/firewall and SMD behavior; and
5. compare older v2 builds to determine whether any dangerous handler was
   silently changed before V1.1.6.38.

