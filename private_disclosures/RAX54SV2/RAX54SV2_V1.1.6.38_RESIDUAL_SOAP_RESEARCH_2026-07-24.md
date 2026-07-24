# RAX54Sv2 V1.1.6.38 residual SOAP research

Date: 2026-07-24  
Target: local firmware image and isolated QEMU guest only  
Outcome: no confirmed unauthenticated RCE or persistent DoS

## Scope

This pass covered the residual high-impact SOAP targets after the general
`httpd` and UPnP triage:

- password recovery/reset
- configuration import
- NTP configuration
- firmware check/download
- WLAN credential changes
- unauthenticated login/logout
- parental-control authentication

The tested `httpd` SHA-256 is
`93881747...` (full digest is retained in the earlier HTTP triage report).

## Dispatch-table result

The complete 207-entry SOAP dispatch table starts at virtual address
`0x001d7804`. The common dispatcher checks for an authenticated session when
bit `0x2` is clear in an entry's flags.

Only five entries set the unauthenticated bit:

| Index | Service | Action | Handler | Flags |
|---:|---|---|---:|---:|
| 0 | DeviceConfig | SOAPLogin | `0x0009b81c` | `0x7e` |
| 1 | DeviceConfig | SOAPLogout | `0x0009bba8` | `0x7e` |
| 53 | DeviceConfig | GetSecurityQuestions | `0x000a04dc` | `0x7e` |
| 54 | DeviceConfig | ResetAdminPassword | `0x000a2770` | `0x7e` |
| 176 | ParentalControl | Authenticate | `0x00098f4c` | `0x7e` |

The sensitive state-changing handlers are gated:

| Action | Handler | Flags | Unauthenticated result |
|---|---:|---:|---|
| SetConfiguration | `0x000a0e54` | `0x7c` | SOAP `401` |
| SetNTP | `0x000a0750` | `0x18` | SOAP `401` |
| CheckAndDownloadNewFirmware | `0x0009e9ac` | `0x7c` | SOAP `401` |
| SetWLANWPAPSKByPassphrase | `0x0008e408` | `0x7c` | SOAP `401` |

## Password-reset resolution

`ResetAdminPassword` returning SOAP response code `000` initially looked like
a possible unauthenticated reset. Static handler resolution disproved that
hypothesis for this firmware:

- handler `0x000a2770` allocates/clears a 256 KiB response buffer;
- it calls the common response formatter with an empty payload;
- it performs no NVRAM read, NVRAM write, password comparison, or credential
  mutation.

It is therefore a success-reporting compatibility stub, not a password reset.
`GetSecurityQuestions` reads only the two configured question identifiers and
formats them into the response.

## Credential-handler review

`SOAPLogin` extracts the username with a `0x80` bound and password with a
`0x100` bound. It hashes the password and compares both values with NVRAM.
The observed `system()` call is reached only after both comparisons succeed
and uses a firmware constant, not request data.

Parental-control `Authenticate` extracts its two credential fields with
`0x40` bounds and `ModelType` with a three-byte bound before calling the
authentication routine. No request-derived shell sink was identified.

Correctly shaped control, shell-metacharacter, and 4 KiB-field requests were
sent to both handlers. The service remained alive after every case. Guest
serial evidence shows truncation to 64 bytes for parental-control
`NewUsername` and three bytes for `ModelType`; no marker command execution,
stack-check failure, or daemon crash was observed.

## Parser stress

Unauthenticated `ResetAdminPassword` bodies were exercised at:

- 16,383 bytes
- 65,535 bytes
- 262,143 bytes
- 262,144 bytes
- 262,145 bytes
- 524,288 bytes

The smallest request returned normally. Larger requests exceeded the
client-side read timeout, but a fresh health request succeeded after every
case and after the full series. This is not a persistent DoS.

## Evidence

- `known_firmware/emulation/RAX54SV2/full-system-http-lab/soap-dispatch-table.txt`
- `known_firmware/emulation/RAX54SV2/full-system-http-lab/soap-entry-dump.txt`
- `known_firmware/emulation/RAX54SV2/full-system-http-lab/soap-auth-entry-dump.txt`
- `known_firmware/emulation/RAX54SV2/full-system-http-lab/sensitive-soap-matrix.json`
- `known_firmware/emulation/RAX54SV2/full-system-http-lab/unauth-credential-soap-matrix.json`
- `known_firmware/emulation/RAX54SV2/full-system-http-lab/serial.log`
- `scripts/audit_rax54sv2_unauth_soap.py`
- `scripts/probe_rax54sv2_http_security.py`
- `ghidra_scripts/DumpSoapEntries.java`

## Conclusion

No disclosure-grade unauthenticated RCE or persistent DoS was confirmed in
these residual SOAP targets. The potentially alarming password-reset response
is a non-mutating stub, and all tested configuration, NTP, firmware, and WLAN
setters pass through the common authentication gate before their handlers are
called.
