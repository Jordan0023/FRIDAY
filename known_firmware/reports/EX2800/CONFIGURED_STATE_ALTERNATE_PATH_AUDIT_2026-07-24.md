# EX2800 / EX3110 / EX5000 / EX6110 configured-state alternate-path audit

Date: 2026-07-24  
Firmware family: 1.0.1.84

## Conclusion

No alternate unauthenticated network path to the `webupg` command-execution
sink was established for a normally configured device.

The one-shot bypass is structurally constrained:

1. `webproc::WEB_GetCgiVars` creates `/var/upgUnauth` only in the branch that
   first confirms `/var/unconfig` exists.
2. `webupg::UPGCGI_CheckAuth` accepts `/var/upgUnauth`, immediately unlinks it,
   and otherwise performs the normal session/token validation.
3. No other analyzed executable contains the `/var/upgUnauth` pathname.

The marker therefore has one identified writer (`webproc`) and one identified
reader/consumer (`webupg`). Static xrefs found no second writer that could be
reached after configuration.

## Setup-state ownership

`logic` both creates and removes `/var/unconfig` as part of internal
configuration-state transitions. Those transitions are reached through the
firmware's local message/configuration subsystem, not through a newly
identified public network listener. The normal configured-state web boundary
still protects requests that can change those objects.

`mini_httpd` also reads `/var/unconfig` when selecting setup-time route
exceptions. Its pathname normalization and exception logic do not themselves
write either marker. Previously tested dot-segment, encoded-slash, path-info,
method-override, proxy-header, malformed-auth, and setup-page variants produced
no privileged configured-state effect.

## Separate configured-state lead

`mini_httpd` contains a direct `start_telnet` route whose fixed privileged
effects occur before the ordinary CGI authentication path. This route is not a
second entry into the `webupg` injection bug and does not create
`/var/upgUnauth`; it is a separate authorization flaw.

Isolated emulation previously confirmed that the route installs and starts a
root Telnet service even without HTTP credentials. The shipped Telnet login
accepts the static `root` password, but command execution on an unmodified
image remains conditional because the firmware contains conflicting root-shell
records and lacks one referenced shell path. Physical-device validation is
still required.

## Assessment

- Same `webupg` root-command sink on a configured device: **no reachable
  alternate path found**.
- Re-creation of setup state over unauthenticated HTTP: **not demonstrated**.
- Separate configured-state unauthenticated privileged action:
  **`start_telnet` is a strong lead**, but it is not yet an end-to-end,
  unmodified-device RCE confirmation.
- Confidence: high for marker ownership and direct-xref coverage; medium for
  whole-firmware negative reachability because indirect pathname construction
  and undiscovered local-message producers remain possible.

## Evidence

Decompiler output:

- `router-agent-results/20260724T-EX6110-configured-path-audit/decompile/webproc-marker-xrefs.txt`
- `router-agent-results/20260724T-EX6110-configured-path-audit/decompile/webupg-marker-xrefs.txt`
- `router-agent-results/20260724T-EX6110-configured-path-audit/decompile/logic-marker-xrefs.txt`
- `router-agent-results/20260724T-EX6110-configured-path-audit/decompile/mini_httpd-marker-xrefs.txt`

The four products share byte-identical critical 1.0.1.84 components for this
path, so the static result applies to EX2800, EX3110, EX5000, and EX6110.
