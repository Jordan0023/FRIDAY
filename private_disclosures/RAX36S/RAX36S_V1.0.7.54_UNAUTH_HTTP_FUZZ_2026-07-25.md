# RAX36S V1.0.7.54 bounded unauthenticated HTTP/SOAP campaign

Date: 2026-07-25

## Scope

The full-system ARM emulator ran the genuine firmware `lighttpd`, `net-cgi`,
`datalib`, and configuration libraries. The campaign was reachable only on
host loopback and used `GetSecurityQuestions` as its sole SOAP action. It did
not invoke reset, firmware-update, or persistent configuration actions.

The corpus covered:

- `SOAPAction` lengths from 256 through 16,384 bytes;
- oversized Host, X-Forwarded-For, Cookie, and User-Agent fields;
- XML padding, truncation, nesting, and an internal entity;
- an 8,192-byte request target;
- conflicting Content-Length fields; and
- chunked plus Content-Length framing.

Each exact request and SHA-256 was saved. After every case, the harness sent a
known-good unauthenticated SOAP control and required HTTP plus
`ResponseCode=000`.

## Result

All 18 cases completed. No QEMU exit, lighttpd loss, persistent CGI wedge, or
failed health control was observed. The result is `no-observable-dos`.

SOAPAction values at 8,192 and 16,384 bytes, the oversized header cases, and
the 8,192-byte path did not return a response within eight seconds. Those
individual connection timeouts are not classified as denial of service:
immediate control requests succeeded and the genuine service remained
available. Conflicting length and chunked/length framing received HTTP 400.

Artifacts:

`known_firmware/emulation/RAX36S/full-system-web-lab/unauth-http-campaign-20260725T132818Z/`

## Conclusion

This campaign did not confirm an unauthenticated DoS. The next highest-value
step is binary-guided, action-specific mutation of unauthenticated SOAP
handlers and their individual XML arguments, retaining the same health oracle
and deterministic replay requirements.
