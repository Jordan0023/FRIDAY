# GL-X3000 push security patch and regression specification

Date: 2026-07-24

## Required firmware changes

1. Remove the generic `sh_exec` message type. Do not pass remote data to
   `sh -c`, even after authentication.
2. Replace raw TCP/1887 with TLS 1.3 and strict hostname and certificate-chain
   validation. Prefer mutual TLS with a unique device certificate.
3. Give each device unique command-verification key material. Do not embed a
   fleet-wide shared secret.
4. Sign the canonical command envelope, including device identity, operation,
   parameters, expiry, and nonce.
5. Reject wrong-device, unsigned, expired, future-dated, replayed, unknown, and
   shell-shaped operations before dispatch.
6. Persist a bounded replay cache across daemon restarts.
7. Run the eSIM daemon as a dedicated unprivileged account with filesystem,
   process, and network sandboxing.
8. Add the normal administrator-session access hook to Nginx `/sdk/v1`.
9. Bind the backend to loopback and retain firewall denial for direct TCP/3456.

## Reference regression model

`scripts/x3000_push_security_regression.py` is a local defensive model. It
does not contact a router or vendor service. It verifies that:

- one valid, device-bound, signed operation is accepted;
- unsigned commands are rejected;
- cross-device commands are rejected;
- commands signed by another device key are rejected;
- replayed and expired commands are rejected;
- tampering invalidates the signature; and
- `sh_exec` is rejected even if correctly signed.

The HMAC used by the model is illustrative. Production should use a
vendor-managed asymmetric signing hierarchy plus per-device mutual TLS.

## Release gate

A repaired firmware must pass the regression model and an isolated integration
test using two synthetic device identities. It must also demonstrate that the
eSIM daemon cannot spawn a command interpreter under any accepted message.
