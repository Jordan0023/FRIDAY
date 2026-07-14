# RT-AX82U end-to-end confirmation evidence

- Guest: exact RT-AX82U `3.0.0.4.388_25101` rootfs exported by Greenhouse
- Network: Docker internal-only network `friday-asus-proof-net`
- Route: authenticated `POST /upload_server_ovpn_cert.cgi`
- Multipart field: `import_cert_file`
- Archive SHA-256: `935f99f89c19f3549762e0ef7b46341ba0edb76a71008fa661a272dbf0cf7c44`
- HTTP result: `200 OK`, `parent.callback_upload_cert(1)`
- Marker: `/tmp/friday-proof/asus-http-marker`
- Marker SHA-256: `4dede3e8b04d5ad2b7dd04627ec6cfc303154e50851d86357ea605a7f1cdf6be`
- Marker content: `FRIDAY_ASUS_HTTP_PROOF\n`

The destination `/tmp/friday-proof` was pre-created to keep the symlink proof
bounded. It is outside the handler's `/tmp/server_ovpn_file` extraction
directory. The firmware handler invoked `/bin/tar`, created the marker, and
then removed its extraction directory; the marker remained.

Preserved files:

- `asus-http-marker`: the resulting out-of-directory file.
- `GREENHOUSE_STDLOG.e2e`: QEMU/Greenhouse log showing the exact ARM `httpd`
  launch and firmware `/bin/tar` execution.
- `trace.e2e.log`: syscall trace, including handler cleanup of
  `server_ovpn.tgz`, `pivot`, and `/tmp/server_ovpn_file`.

The trace and log hashes at collection time were:

```text
b169ce72a2c34a42a3e46257912e4b3c84afec94551fef17512fe7f2c70e03ba  trace.e2e.log
a395ae4a864ec62b496c0ff171f730d6296688c6940bfe813c9444eb897b75cd  GREENHOUSE_STDLOG.e2e
```

These logs contain earlier failed attempts in the same disposable guest as
well as the final successful replay. The last `/bin/tar` invocation corresponds
to the canonical marker above.
