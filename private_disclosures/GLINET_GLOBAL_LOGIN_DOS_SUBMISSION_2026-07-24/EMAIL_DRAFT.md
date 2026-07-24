To: security@gl-inet.com
Subject: Coordinated disclosure: unauthenticated global WebUI login lockout on GL-MT5000 and GL-MT2500

Hello GL.iNet Security,

I am privately reporting an unauthenticated administrative WebUI denial of
service affecting:

- GL-MT5000 firmware 4.8.6 and 4.9.0
- GL-MT2500/MT2500A firmware 4.7.4

The session service maintains one process-global failure counter and lockout
timer. Ten challenge failures from an unauthenticated client using an unknown
username activate a roughly 600-second lockout for every source and account.
A separate client with correct credentials is then denied a new WebUI session.
The attack does not require a username, password, token, or high request rate.

The behavior was confirmed using genuine firmware components in isolated
native-architecture emulation, including a two-client end-to-end HTTP
confirmation on MT5000 4.9.0 and MT2500 4.7.4. The demonstrated impact is
limited to new WebUI authentication; I am not claiming loss of routing or
other services.

The stock WAN firewall blocks the endpoint when remote access is disabled.
The same `/rpc` endpoint becomes WAN reachable when supported DDNS remote
HTTPS is enabled; Drop-in Gateway mode is a second conditional path. I have
not claimed default WAN exposure, and physical WAN validation remains pending.

Suggested classification: CWE-307. Suggested default-deployment CVSS 3.1:
CVSS:3.1/AV:A/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:L (4.3).

The attached package contains full technical reports, firmware hashes,
two-client transcripts, and the WAN reachability analysis. Please acknowledge
receipt, provide a tracking identifier, and let me know whether this is a
duplicate. I am requesting coordinated remediation and CVE coordination, with
a proposed 90-day disclosure target of 2026-10-22, adjustable by mutual
agreement.

Regards,

[Researcher name]
[Preferred contact]
