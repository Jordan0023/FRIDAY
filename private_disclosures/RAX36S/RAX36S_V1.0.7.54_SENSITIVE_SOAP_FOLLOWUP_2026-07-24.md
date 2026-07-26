# RAX36S V1.0.7.54 sensitive SOAP follow-up

Date: 2026-07-24

## Result

No unauthenticated RCE or administrator-password takeover was established.
The genuine `lighttpd` and `net-cgi` binaries do expose
`DeviceConfig#GetSecurityQuestions` without web authentication, but the
adjacent recovery and password-changing actions retained their security
checks in the tested configured-router state.

## Lab correction

The existing network-isolated ARM lab was corrected in two fidelity details:

- `/www/soapapi` was created, matching the stock lighttpd init script and
  `/soap/server_sa` rewrite target.
- The configuration-only preload shim was extended with `PWD_question1`,
  `PWD_question2`, `PWD_answer1`, and `PWD_answer2`. Request parsing,
  authentication, SOAP dispatch, and action handlers remained genuine
  firmware code. `config_set` remained a no-op, preventing persistent changes.

## Unauthenticated results

| Action | Result |
| --- | --- |
| `GetSecurityQuestions` | HTTP 200, `ResponseCode=000`; returned configured question identifiers 1 and 2 |
| `RecoverAdminPassword` | HTTP 200, `ResponseCode=003` for inert, matching-plaintext, and Base64 answer variants |
| `ResetAdminPassword` | HTTP 200, `ResponseCode=402`; inert new password not accepted |
| `UpdateAdminPassword` | HTTP 200, `ResponseCode=001`; deliberately wrong old password not accepted |
| `SOAPSecurityQAVerifyAns` | HTTP 200, `ResponseCode=404`; not an independently dispatched SOAP action |
| `SOAPQueryAccessToken` | HTTP 200, `ResponseCode=404`; not an independently dispatched SOAP action |

The service remained live after every case. No password material was returned,
no command-execution marker was used or needed, and the lab's no-op
configuration layer prevented an accepted password change from being hidden
by a later read.

## Static resolution

The SOAP action table in `net-cgi` contains explicit handlers for
`GetSecurityQuestions`, `RecoverAdminPassword`, `ResetAdminPassword`, and
`UpdateAdminPassword`. Focused decompilation confirmed that the question path
is conditioned on `enable_password_recovery` and reads the `PWD_question*`
configuration values. The recovery action remained gated before any
password-returning behavior in the tested state.

The ordinary `/recover.cgi` form parser was also resolved through its indirect
callback dispatcher. It caps the decoded form buffer at 32,767 bytes, stores
at most 127 key/value pairs in a bounded local pointer array, and dispatches
only names present in a static callback table. This does not supply a
pre-authentication memory-corruption or command-execution path.

## Artifacts

- `scripts/probe_rax36s_sensitive_soap.py`
- `ghidra_scripts/DecompileFunctionsByAddress.java`
- `ghidra_scripts/DecompileRecursiveStringXrefs.java`
- `known_firmware/emulation/RAX36/rax36_web_shim.c`

## Disposition

`GetSecurityQuestions` is an intentional recovery-information exposure, not
RCE. The strongest password-recovery-to-authenticated-RCE bridge was tested
and rejected on current evidence. A physical-device run remains useful for
confirming encrypted answer storage and persistent configuration behavior,
but there is no defensible unauthenticated-RCE or zero-day claim from this
follow-up.
