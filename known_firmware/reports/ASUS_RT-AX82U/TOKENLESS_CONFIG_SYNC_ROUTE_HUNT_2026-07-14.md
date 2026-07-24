# Tokenless route hunt for the configuration-sync overflow

## Objective

Determine whether the confirmed `upload_config_sync_cgi` stack overflow can be
reached without an administrator-equivalent `asus_token` in RT-AX82U firmware
`3.0.0.4.388_25101`.

## Static dispatch result

The HTTP route table contains one registration for the vulnerable upload flow:

```text
upload_config_sync.cgi*
```

Its entry uses:

- upload callback `0x8c2a4`, which stages `/tmp/settings_u.prf`;
- response callback `0x8c6a8`, which calls `upload_config_sync_cgi`; and
- authentication callback `0x1e9c8`, shared by the adjacent protected
  configuration-management routes.

No second route-table entry or app-specific alias references the vulnerable
callback. `start_config_sync.cgi` is a distinct authenticated route whose
callback invokes `start_config_sync_cgi` to apply the already-generated JSON;
it does not invoke the vulnerable profile parser.

The general firmware/configuration restore flow also uses the pathname
`/tmp/settings_u.prf`, but has independent upload and restore callbacks in the
main HTTP binary. Static control flow did not identify a call from that path to
`upload_config_sync_cgi`; pathname reuse alone is not handler reachability.

## Dynamic controls

A harmless valid four-byte `HDR1` profile was used as the reachability oracle.
Successful entry into the vulnerable callback creates
`/tmp/save_config_sync.json`.

The following tokenless requests did not create that artifact:

- canonical `/upload_config_sync.cgi`;
- trailing path separator;
- duplicate leading separator;
- encoded trailing separator;
- encoded semicolon suffix;
- normalized path containing an encoded parent segment;
- ASUS mobile-app User-Agent; and
- `X-Forwarded-For: 127.0.0.1`.

The HTTP listener remained healthy. Earlier controls also rejected the
canonical tokenless request in factory/QIS state (`x_Setting=0`).

## Conclusion

No new tokenless route to this overflow was found. The confirmed vulnerability
continues to require an administrator-equivalent token. The conditional
CVE-2022-35401 retained-state behavior can recover such a token in a narrow
configuration/reboot window, but that is public prior art and still introduces
a token before the vulnerable callback is reached.

Any future tokenless claim requires a distinct authentication or dispatch
failure demonstrated by the small-profile reachability artifact before testing
the crashing profile.
