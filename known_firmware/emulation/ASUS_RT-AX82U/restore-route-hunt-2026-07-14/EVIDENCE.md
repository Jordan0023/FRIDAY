explore the # Tokenless restore-route hunt

Target: ASUS RT-AX82U firmware `3.0.0.4.388_25101` in the isolated emulator.

## Static lead

The stripped `httpd` binary contains `upgrade.cgi*` in a secondary endpoint
table near other setup/app endpoints. The normal route entry still references
the common authentication callback. The web UI's configuration restore form
posts to `upload.cgi`, not `upgrade.cgi`.

## Dynamic controls

An inert, deliberately truncated `HDR1` file named `inert.CFG` was submitted as
multipart field `file` without an `asus_token` cookie. It is not a valid profile
and cannot apply settings.

- With synthetic NVRAM `x_Setting=1`, the server returned the login redirect
  page and did not create `/tmp/settings_u.prf`.
- With synthetic NVRAM `x_Setting=0`, the server again returned the login
  redirect page and did not create `/tmp/settings_u.prf`.
- The listener stayed alive.

## Conclusion

No tokenless restore-handler reachability was demonstrated. The secondary
endpoint table is not evidence of a blanket QIS authentication bypass. No
vulnerability is claimed from this lead.
