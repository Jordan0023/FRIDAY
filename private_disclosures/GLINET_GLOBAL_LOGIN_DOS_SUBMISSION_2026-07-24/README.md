# GL.iNet coordinated-disclosure package

Prepared: 2026-07-24

## Claim

GL-MT5000 firmware 4.8.6 and 4.9.0, and GL-MT2500 firmware 4.7.4, contain an
unauthenticated global WebUI authentication lockout. Ten failures from one
client prevent new authentication by other clients for about 600 seconds.

Default exposure is LAN/adjacent. WAN reachability is conditional on a
supported configuration such as DDNS remote HTTPS or Drop-in Gateway mode.
Stock WAN with remote access disabled rejects router-local input. Physical WAN
validation is pending because no applicable device is attached to the test
host.

## Package contents

- `EMAIL_DRAFT.md`: vendor-ready cover message.
- `MANIFEST.sha256`: checksums for every supplied report and transcript.
- `evidence/`: reports, reachability assessments, and dynamic transcripts.

The cloud-agent TLS lead is intentionally excluded because it is unconfirmed
and independent.
