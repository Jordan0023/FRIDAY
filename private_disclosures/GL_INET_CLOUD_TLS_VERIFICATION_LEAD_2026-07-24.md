# GL.iNet cloud-agent TLS verification lead

Date: 2026-07-24

## Status

Unconfirmed, separate research lead. This is not part of the global WebUI
lockout disclosure and should not be reported as a vulnerability without
runtime proof.

## Evidence obtained

- The cloud agent is disabled in the factory configuration examined.
- The genuine AArch64 cloud-agent binary was started in a disposable emulation
  environment with networking disabled.
- Recovered program constants include an `insecure` TLS option near cloud HTTP
  request paths.

## What is not proved

- that a factory-enabled or normally enabled request sets `insecure=true`;
- that certificate or hostname verification is disabled on a security-relevant
  connection;
- that an attacker can redirect or intercept the relevant connection;
- that any unauthenticated WAN-to-management chain follows from the cloud
  agent.

## Next bounded experiment

Run the genuine agent in an isolated network against a researcher-controlled
TLS endpoint, with the cloud feature explicitly enabled in the lab. Present:

1. a valid trusted certificate;
2. a self-signed certificate;
3. a trusted certificate with the wrong hostname.

Capture the request outcome and TLS handshake for each case. Only advance the
lead if the agent accepts case 2 or 3 on a security-relevant path. Do not use
production GL.iNet services or intercept another user's traffic.
