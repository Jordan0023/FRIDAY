# GL-X3000 bounded follow-up research addendum

Date: 2026-07-24

## Work completed

- Re-inspected the 4.8.3 root filesystem and eSIM service configuration.
- Confirmed `/sdk/v1` remains a direct Nginx proxy to loopback TCP/3456 without
  the ordinary WebUI access hook.
- Confirmed the push service uses a hard-coded plaintext TCP destination,
  `34.196.94.121:1887`; ordinary DNS redirection is therefore insufficient.
- Reviewed the available firmware corpus, which includes GL-X3000 releases
  through 4.8.3.
- Reused the existing isolated confirmation evidence showing that a private
  replacement server needs no server credential before the daemon accepts
  `sh_exec`.
- Preserved the negative result: no unauthenticated local API method was found
  that changes the push destination or reaches the push command dispatcher.
- Added a defensive two-identity command-validation model and tests for
  cross-device delivery, replay, expiry, missing signatures, wrong keys,
  tampering, and forbidden shell operations.
- Executed all eight regression cases successfully on 2026-07-24.
- Added network and host detection guidance and a firmware patch specification.

## Classification

The result remains a confirmed device-side root command-execution vulnerability
with conditional WAN reachability. No unconditional arbitrary-Internet chain
was established.

Testing GL.iNet's production ACLs or publishing to enrolled devices requires
written authorization, named test devices, a staging or approved publisher,
rate limits, and stop conditions. No production endpoint was contacted during
this follow-up.

## New artifacts

- `scripts/x3000_push_security_regression.py`
- `private_disclosures/GL-X3000/X3000_PUSH_SECURITY_REGRESSION_RESULT_2026-07-24.txt`
- `private_disclosures/GL-X3000/X3000_SECURITY_PATCH_AND_REGRESSION_2026-07-24.md`
- `private_disclosures/GL-X3000/X3000_DEFENSIVE_DETECTIONS_2026-07-24.md`
