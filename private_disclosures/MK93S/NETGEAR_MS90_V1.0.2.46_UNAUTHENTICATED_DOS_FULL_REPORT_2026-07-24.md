# NETGEAR MS90 V1.0.2.46 Pre-Authentication SOAP Bypass and Denial of Service

**Report date:** July 24, 2026  
**Status:** Confirmed vulnerability; unpatched zero-day candidate  
**Vendor contacted:** No  
**CVE assigned:** No  
**Remote code execution demonstrated:** No

## Executive summary

NETGEAR MS90 firmware V1.0.2.46 contains a hard-coded universal SOAP
`SessionID` that bypasses authentication for privileged administrative actions.

An unauthenticated, network-adjacent attacker can supply the embedded
`SessionID` and invoke the `DeviceConfig#Reboot` action. Testing against the
genuine MS90 daemon confirmed successful privileged dispatch, a successful SOAP
response, and activation of the daemon's reboot state.

The latest vendor-published firmware remains vulnerable. The issue is best
classified as an unpatched pre-authentication SOAP authentication bypass
permitting unauthenticated device reboot and denial of service.

It is a zero-day candidate because no public MS90 advisory or CVE was identified
for this specific fixed-token vulnerability. Definitive zero-day or CVE status
depends on whether NETGEAR or a CNA already tracks it privately.

## Affected product

- **Vendor:** NETGEAR
- **Product:** Nighthawk MS90
- **Product family:** MK93S
- **Role:** Mesh satellite; MR90 is the corresponding router
- **Firmware:** V1.0.2.46
- **Internal software version:** 1.0.42
- **Architecture:** 32-bit ARM
- **Affected component:** `/usr/sbin/httpd`
- **Network prerequisite:** Access to the device's management service,
  ordinarily from the local network
- **End-of-Service status:** Not listed as End of Service as of the report date

## Firmware provenance

**Vendor download**

`https://www.downloads.netgear.com/files/GDC/MK93S/MS90-V1.0.2.46.zip`

**Vendor release page**

`https://kb.netgear.com/000068328/MR90-MS90-Firmware-Version-1-0-2-46`

**Server upload timestamp**

`2025-07-30 11:42:08 UTC`

**Firmware identity**

- ZIP SHA-256:
  `b08a61b04a5b75c7d722b49bb303f1e17d091c92baae3dc66d8a9beddf90851d`
- Image: `MS90-V1.0.2.46_1.0.42.chk`
- `/usr/sbin/httpd` SHA-256:
  `91a220763fbd1f7f99041a6a60e8a18fee024fd8bca1de62e7631ecd5c49b570`
- `httpd` size: 1,467,480 bytes

For comparison, V1.0.2.38 shipped a different `httpd`:

- SHA-256:
  `ac586f79dfe037b57fcd1cc163c2364c5f44bc1695d5124cd9335efa220a86cc`
- Size: 1,463,364 bytes

The current result therefore does not rely on assuming that the older binary
was simply repackaged.

## Vulnerability description

The MS90 SOAP dispatcher normally validates a request's `SessionID` against the
runtime NVRAM value:

`soap_Auth_SessionID`

The dispatcher contains an additional comparison against the firmware literal:

`12345678901234567890`

If either comparison succeeds, execution branches to the same privileged
SOAP-handler dispatch block. This literal functions as an undocumented
universal credential.

Cross-reference and control-flow analysis confirm that the value directly
influences authorization decisions for privileged SOAP actions. It is not
merely unused test or diagnostic data.

## Static root-cause evidence

Relevant strings in the V1.0.2.46 `httpd`:

```text
0x0011cfb8  12345678901234567890
0x0011cfcd  soap_Auth_SessionID
0x0011d068  soap_getSessionID
```

The affected dispatcher starts at `0x00067910`.

The authorization sequence is:

```text
0x00067c5c  load "soap_Auth_SessionID"
0x00067c64  call acosNvramConfig_match
0x00067c6c  bne  0x00067ba0
0x00067c80  load "12345678901234567890"
0x00067c88  call strcmp
0x00067c90  beq  0x00067ba0
```

Both a legitimate runtime-session match and a fixed-token match reach
`0x00067ba0`, the privileged dispatch path.

Conceptually:

```c
if (session_matches_runtime_token(session) ||
    strcmp(session, "12345678901234567890") == 0) {
    dispatch_privileged_soap_handler();
} else {
    return_soap_401();
}
```

## Dynamic validation environment

The genuine V1.0.2.46 root filesystem and `httpd` were executed in an isolated
full-system ARM environment.

The guest used restricted QEMU user networking with `restrict=on` and a
loopback-only host forward. It was not exposed to the LAN or Internet.

Three authentication controls were used:

1. no `SessionID`;
2. an arbitrary invalid `SessionID`; and
3. the embedded fixed `SessionID`.

## Control results

### Missing SessionID

The `DeviceInfo#GetInfo` action produced:

```text
soap_getSessionID ret 702, name SessionID: , content_len 0
<ResponseCode>401</ResponseCode>
```

**Result:** Rejected.

### Invalid SessionID

The test value `FRIDAY_INVALID_SESSION` produced:

```text
soap_getSessionID ret 0, name SessionID: FRIDAY_INVALID_SESSION
<ResponseCode>401</ResponseCode>
```

**Result:** Rejected.

### Fixed SessionID

The embedded fixed value produced:

```text
func_index ===7
soap_getSessionID ret 0, name SessionID: 12345678901234567890
function index 7
<ModelName>MS90</ModelName>
<Firmwareversion>V1.0.2.46</Firmwareversion>
<OthersoftwareVersion>1.0.42</OthersoftwareVersion>
<ResponseCode>000</ResponseCode>
```

**Result:** Authentication bypass confirmed.

The missing and random controls returned `401`, while the fixed token caused
successful privileged dispatch. This separates the finding from a generally
unauthenticated informational endpoint.

## Denial-of-service validation

The fixed token was used with the privileged `DeviceConfig#Reboot` action.

The genuine daemon produced:

```text
get_service_and_api DeviceConfig:Reboot E
func_index ===79 E
soap_getSessionID ret 0, name SessionID: 12345678901234567890
function index 79 E
<m:RebootResponse>
<ResponseCode>000</ResponseCode>
sa_rebootRequired
```

This confirms:

1. authentication was bypassed;
2. the privileged reboot handler was selected;
3. the handler completed successfully; and
4. the daemon activated its reboot-required state.

The emulated guest did not disappear because the generic QEMU platform cannot
complete the MS90's board-specific Ethernet power-down and hardware-reset
sequence. This limitation occurs after the genuine daemon has authorized and
executed the reboot action.

## Security impact

A network-adjacent unauthenticated attacker may be able to:

- bypass SOAP administrative authentication;
- read information exposed through privileged SOAP actions;
- invoke configuration-changing actions;
- invoke administrative credential-management actions, subject to further
  physical-device validation;
- reboot the device and interrupt network availability; and
- invoke factory-reset functionality, subject to physical-device confirmation.

The confirmed impact in this report is unauthenticated privileged reboot and
resulting denial of service.

Arbitrary command or code execution was not demonstrated.

## Classification

Relevant weakness classes include:

- **CWE-798:** Use of Hard-coded Credentials
- **CWE-287:** Improper Authentication
- **CWE-306:** Missing Authentication for Critical Function

Suggested vulnerability title:

> NETGEAR MS90 Hard-Coded SOAP SessionID Authentication Bypass Leading to
> Unauthenticated Device Reboot

## Zero-day assessment

The finding satisfies the principal technical conditions for a zero-day
candidate:

- it affects the latest published firmware;
- the latest firmware is unpatched;
- the affected product is not listed as End of Service;
- the concrete fixed-token mechanism is technically distinct from the publicly
  documented RBR760 SOAP issue; and
- no public advisory or CVE was located that explicitly covers this MS90
  fixed-token defect.

Public research cannot determine whether NETGEAR already tracks the issue
privately. The defensible description is:

> Confirmed unpatched vulnerability and unauthenticated DoS zero-day candidate,
> pending vendor or CNA deduplication.

## Distinction from CVE-2023-41183

CVE-2023-41183 affects the NETGEAR RBR760 SOAP API.

| Property | MS90 | RBR760 |
|---|---|---|
| HTTP implementation | Proprietary `httpd` | lighttpd |
| SOAP component | Integrated into `httpd` | Separate `soap-api` CGI |
| Concrete bypass | Hard-coded universal SessionID | Publicly described as missing SOAP authentication |
| Fixed token in SOAP component | Present | Absent |
| Tested affected version | V1.0.2.46 | V6.3.6.4 |

The fixed token is absent from the RBR760 SOAP components in both the vulnerable
V6.3.6.4 and fixed V6.3.8.5 firmware. This establishes that the MS90
fixed-token authorization predicate is not the same concrete implementation
patched under CVE-2023-41183.

A CNA could still choose to broaden an existing CVE based on unpublished vendor
information.

## Remediation

NETGEAR should:

- remove the hard-coded SessionID exception;
- accept only cryptographically unpredictable authenticated runtime sessions;
- require authorization separately for every privileged SOAP action;
- invalidate sessions after password changes and factory reset;
- add regression tests ensuring fixed, missing, malformed, expired, and
  arbitrary SessionIDs cannot invoke privileged handlers;
- rate-limit sensitive administrative actions; and
- disable the legacy SOAP management interface when it is not required.

Users should:

- install patched firmware if NETGEAR releases one;
- restrict untrusted devices from the management network;
- avoid exposing management services through WAN or port-forwarding rules;
- place IoT and guest devices on isolated networks; and
- monitor unexpected reboots or configuration changes.

## Evidence and supporting artifacts

- `private_disclosures/MK93S/MS90_V1.0.2.46_SOAP_BYPASS_VALIDATION_2026-07-24.md`
- `private_disclosures/MK93S/MS90_CVE-2023-41183_DISTINCTION_2026-07-24.md`
- `private_disclosures/MK93S/MS90_V1.0.2.38_PREAUTH_RCE_DOS_TRIAGE_2026-07-24.md`
- `known_firmware/emulation/MK93S/V1.0.2.46-full-system-http-lab/serial.log`
- `scripts/emulate_ms90_10246_http_full_system.py`
- `scripts/probe_ms90_soap_session.py`

## Final disposition

| Question | Result |
|---|---|
| Latest published firmware affected? | Yes |
| Product officially End of Service? | No |
| Authentication required? | No |
| Hard-coded authorization token confirmed? | Yes |
| Privileged SOAP dispatch confirmed? | Yes |
| Reboot/DoS path confirmed? | Yes |
| Remote code execution confirmed? | No |
| Public CVE for this precise MS90 defect identified? | No |
| Vendor contacted? | No |

**Recommended public description:** Unpatched pre-authentication SOAP bypass
enabling unauthenticated reboot and denial of service; zero-day candidate
pending CNA deduplication.

## Subsequent WAN assessment

The genuine MR90 V1.0.2.46 router firmware was subsequently inspected and
booted in a dual-interface full-system lab. MR90 ships a different `httpd`, and
the fixed universal SessionID is absent from that server binary. Although its
optional remote-management feature opened a simulated WAN listener on TCP/8443,
the precise MS90 server-side defect cannot be projected onto it.

The current finding must therefore remain classified as LAN/network-adjacent,
not Internet/WAN exploitable. See
`private_disclosures/MK93S/MR90_MS90_WAN_REACHABILITY_ASSESSMENT_2026-07-24.md`.
