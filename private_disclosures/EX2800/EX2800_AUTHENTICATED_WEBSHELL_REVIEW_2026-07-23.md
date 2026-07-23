# EX2800 V1.0.1.84 authenticated web-shell review

Date: 2026-07-23

## Disposition

The firmware contains a high-confidence authenticated arbitrary-command
execution primitive in `usr/www/cgi-bin/webupg`, but an end-to-end physical
EX2800 reproduction is still required.

This finding must not currently be called a zero-day:

- the exact `webupg` `shell` / `twmode` mechanism has public prior art on
  firmware from another vendor;
- current searches did not identify an EX2800-specific public disclosure, but
  absence from web search is not a vendor/CNA duplicate determination; and
- the available partial emulator did not reproduce the complete authenticated
  HTTP session.

## Direct code evidence

Firmware: EX2800 V1.0.1.84

Firmware SHA-256:
`8d9a63c1224b5d8137833b861e9d0ba44a1202a892d927f942cf1e740cf02163`

`webupg` SHA-256:
`2f2b6eec48e73450a433a3b755e0b06448038e34415bc3184a5b7773cedc882d`

Ghidra decompilation of `UPGCGI_WebShell` at virtual address `0x12d34`
establishes:

1. Query parameters named `key` and `cmd` are URL-decoded.
2. `key` must equal the fixed literal `twmode`.
3. The attacker-supplied `cmd` is formatted as `%s 2>&1` into a 256-byte
   stack buffer.
4. The resulting string is passed directly to `popen(..., "r")`.
5. Command output is streamed into the HTTP response for up to approximately
   six seconds.

`UPGCGI_Main` dispatches the action name `shell` to this function after its
session check. No command allowlist, argument escaping, privilege reduction,
or diagnostic-mode state check exists inside the handler. The shipping HTTP
daemon is launched with `-u root`.

This is stronger than ordinary command injection: it is an intentional,
undocumented web-shell handler exposed inside the firmware-upgrade CGI.

## Dynamic outcome

Network-isolated QEMU/PRoot component tests used a harmless file-marker
command. They did not execute `webupg` through the complete HTTP path:

- `mini_httpd` accepted and parsed the request;
- its request child exited before `execve(webupg)` under the incomplete
  authentication/runtime environment;
- `/var/upgUnauth` was therefore not consumed and no marker was created.

System-call tracing attributes the negative result to failure before the CGI,
not rejection by `UPGCGI_WebShell`. It neither confirms nor refutes execution
on physical hardware.

## Prior-art result

A dated web search on 2026-07-23 found a historical public command example for
another embedded product using the same endpoint, action, key, and command
parameter. Therefore the mechanism itself is public knowledge. No indexed
result found by the searches named EX2800 or EX2800 V1.0.1.84.

This may still be an undisclosed affected-product variant, but “zero-day”
requires:

1. faithful reproduction on a physical EX2800 V1.0.1.84 using a legitimate
   administrator session;
2. confirmation that the handler is not an explicitly supported diagnostic
   feature;
3. affected-version and model-range testing;
4. confidential NETGEAR/CNA duplicate coordination.

## Recommended physical validation

Use a factory-reset EX2800 connected only to an isolated test workstation.
Authenticate normally through the web interface, preserve its legitimate
session cookie and anti-CSRF token, and submit only a benign identity/marker
command to the hidden shell action. Capture the request, response, device
process identity, and a post-request health check. Do not expose the target to
the internet or use persistence, credential modification, or destructive
commands.

## Remediation

Remove the `shell` dispatch and `UPGCGI_WebShell` from production builds.
Rotating the fixed key is not a fix. If a diagnostic shell is operationally
required, compile it only into separately signed service firmware and require
physical-presence activation, short-lived asymmetric authorization, strict
command allowlisting, and privilege separation.
