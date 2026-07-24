# RAX54S V1.0.17.144 Unauthenticated RCE/DoS Investigation

Date: 2026-07-23

Firmware SHA-256:
`12d0be80c7dfee7ffd6d6257f37afde4ddbef6951ee3e6b35674eca529f539a3`

## Result

No unauthenticated remote-code-execution path or service-level denial of
service was confirmed in this pass.

This is a negative result for the tested UPnP surface and inputs, not a claim
that the firmware is free of vulnerabilities. The proprietary HTTP/SOAP
daemon still needs full-system emulation because it did not initialize in the
user-mode lab.

## Corrected extraction

The earlier recursive Binwalk extraction stopped at its 768 MB limit after
carving false-positive nested XZ streams. The actual firmware was recovered as
follows:

- Netgear CHK payload begins with UBI at offset `0x3a`.
- UBI image sequence: `517458527`.
- The `rootfs_ubifs` volume is actually SquashFS 4.0 with XZ compression.
- Clean root filesystem: `known_firmware/extracted/12d0be80c7dfee7f/manual-rootfs`
- Recovered files: 2,722; ELF objects: 772.

The relevant exact binaries are:

- `usr/sbin/upnpd`: SHA-256
  `84ea21d0313d8b8b63c75f1d8f0cf85447c37815d946005f38c9e243c245d1ef`
- `usr/sbin/httpd`: SHA-256
  `7e01c8b99992fcaffd6f1d7dde8649d0343234d55f9d11dbdea110e6aa14adf7`

## Static UPnP analysis

The exact `upnpd` binary was exhaustively decompiled:

- functions discovered/attempted/succeeded: 279/279/279;
- failed or timed-out functions: 0;
- function-local source/sink leads: 6.

The six leads contain file-derived `fgets()` data near `system()`, `popen()`,
or unsafe-copy calls. None contains a recovered HTTP route or authentication
marker. Reviewed command calls include fixed command strings, commands derived
from locally generated route-table data, and firmware-update processing. This
pass did not establish network request data flowing into a command sink.

Artifacts:

- `decompile/upnpd-receipt.json`
- `decompile/upnpd-evidence.jsonl`
- `decompile/upnpd-candidate-functions.c`

## Isolated live validation

The exact ARM `upnpd` was launched in a privileged but networkless disposable
container with:

- synthetic `br0` at `192.168.1.1/24`;
- initialized ACOS NVRAM;
- UPnP enabled;
- a zero-initialized NAT shared-memory segment;
- no host port and no external network.

The daemon opened TCP port 56688 and accepted unauthenticated requests at
`/Public_UPNP_C3`.

Command-marker cases covered:

- command syntax in `SOAPAction`;
- `NewNTPServer1`;
- `NewFirmwareURL`;
- OOKLA speed-test server input.

Parser/resource cases covered:

- 16 KiB action name;
- 512 XML nesting levels;
- 256 KiB XML value;
- port-mapping descriptions from 16 through 2,048 bytes.

Outcome:

- command marker created: no;
- daemon exit or PID change: no;
- persistent listener failure: no;
- post-case baseline: passed;
- long action and 256 KiB value: individual connection reset only;
- 2,048-byte port-mapping description: HTTP 500, daemon remained alive.

The connection resets are not a service-level denial of service.

Probe: `scripts/probe_rax54s_upnp_security.py`

## Remaining priority

`usr/sbin/httpd` is the stronger remaining target. It exposes
`/soap/server_sa/` and imports `system`, `popen`, `doSystem`, `SYSTEM`,
`strcpy`, `strcat`, and `sprintf`. It did not reach a listening state in
user-mode emulation because child ARM utilities invoked without binfmt support
failed with `Exec format error`, and the daemon spun during initialization.

A full-system ARM boot or a user-mode binfmt/interposition harness is required
to validate:

1. unauthenticated proprietary SOAP actions;
2. password-recovery endpoints;
3. firmware URL and NTP fields;
4. parser limits for headers, action names, and XML values;
5. whether request data reaches command or unsafe-memory sinks.

## Disposition

- Confirmed unauthenticated RCE: **no**
- Confirmed unauthenticated service DoS: **no**
- UPnP per-connection malformed-input disruption: **yes**
- Zero-day claim justified: **no**
