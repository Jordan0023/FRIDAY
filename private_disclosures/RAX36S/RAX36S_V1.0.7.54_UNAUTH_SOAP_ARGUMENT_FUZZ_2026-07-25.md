# RAX36S V1.0.7.54 unauthenticated SOAP argument campaign

Date: 2026-07-25

## Method

Handler schemas recovered during the focused `net-cgi` analysis were used to
build action-specific requests for:

- `RecoverAdminPassword`;
- `ResetAdminPassword`; and
- `UpdateAdminPassword`.

Credential, password, and recovery-answer fields were independently tested at
lengths 0, 127, 128, 129, 256, 1,024, and 4,096. Recovery enablement and
question identifiers were tested with `-1`, `4294967295`, and nonnumeric text.
Non-mutated fields retained inert defaults. The configuration preload makes
set/commit operations no-ops, preventing a test password from persisting.

Every case was saved as an exact raw HTTP request with its SHA-256. After each
mutation the harness sent unauthenticated `GetSecurityQuestions` and required
HTTP plus `ResponseCode=000`.

## Result

All 78 planned cases completed:

- `RecoverAdminPassword`: 14;
- `ResetAdminPassword`: 27; and
- `UpdateAdminPassword`: 37.

All mutated actions returned HTTP 200. Every post-case health control passed.
There was no QEMU exit, lighttpd loss, persistent CGI wedge, or observable
service restart. No crash candidate was generated, so replay/minimization was
not applicable.

Result: `no-observable-dos`.

Artifacts:

`known_firmware/emulation/RAX36S/full-system-web-lab/unauth-actions-campaign-20260725T134627Z/`

## Conclusion

This handler-specific campaign does not confirm an unauthenticated DoS in
RAX36S V1.0.7.54. Combined with the generic parser campaign, 96 bounded cases
have preserved service availability. Further work should prioritize a
different attack surface selected from static sink analysis rather than
increasing SOAP string sizes.
