att# Internal ASUS vulnerability assessment

This document is an internal report. It is not authorization to contact ASUS,
a CNA, or any other external party.

## Form fields

- Type: Product
- Product: WLan / Router
- Model: RT-AX82U
- BIOS / firmware: 3.0.0.4.388_25101
- Title: Authenticated arbitrary file write through OpenVPN server-certificate TAR extraction
- Subject: RT-AX82U `upload_server_ovpn_cert.cgi` follows TAR symlinks outside the extraction directory
- Suggested CVSS v4.0 vector: `CVSS:4.0/AV:N/AC:L/AT:N/PR:H/UI:N/VC:H/VI:H/VA:H/SC:N/SI:N/SA:N`

## Issue description

The authenticated OpenVPN server-certificate upload handler accepts a
multipart field named `import_cert_file`, stores it as
`/tmp/server_ovpn_file/server_ovpn.tgz`, and executes:

```text
tar -xzf /tmp/server_ovpn_file/server_ovpn.tgz -C /tmp/server_ovpn_file
```

The firmware does not validate archive member paths or reject symbolic-link
members before extraction. Its BusyBox 1.24.1 `tar` follows a symlink member
when extracting a subsequent regular file below that symlink. An authenticated
remote administrator can therefore write outside the intended extraction
directory with the privileges of the router HTTP service.

A payload can point a symlink at `/var/spool/cron/crontabs` and subsequently
write the `root` file through it. This provides a direct path to root command
execution at the next cron evaluation. The supplied proof is non-destructive:
it recreates the directory layout below `/tmp`, invokes the exact firmware
BusyBox under QEMU, and confirms that the root crontab path is written outside
the extraction directory.

The affected handler was traced from the `httpd` route
`upload_server_ovpn_cert.cgi*` through its multipart parser and response
handler to exported function `upload_server_ovpn_cert_cgi` in
`usr/lib/libwebapi.so`.

The issue persists in RT-AX82U firmware released after CVE-2024-0401:

- 3.0.0.4.388_25004, released 2024-10-09, contains the same extraction sequence.
- 3.0.0.4.388_25098, released 2025-10-28, contains the vulnerable binaries.
- 3.0.0.4.388_25101, released 2026-01-15, has byte-identical `httpd` and
  `libwebapi.so` binaries to 25098.

This appears distinct from CVE-2024-0401: the public CVE concerns a crafted
client OVPN profile and command injection, while this report concerns the
server-certificate TAR upload and symlink-based arbitrary file writing.
RT-AX82U is also absent from the published CVE-2024-0401 affected-model list.

## Proof of concept

Run from the repository root:

```bash
bash known_firmware/reports/ASUS_RT-AX82U/pocs/rt_ax82u_server_cert_tar_symlink_poc.sh
```

Expected result:

```text
CONFIRMED: firmware BusyBox escaped -C and wrote root crontab path: .../var/spool/cron/crontabs/root
```

The script writes only below `/tmp/asus-rt-ax82u-tar-proof` and does not alter
the workstation's real crontab.

## Attachment contents

- `RT-AX82U_3.0.0.4.388_25101_server-cert-tar-proof.md`: technical analysis,
  hashes, handler trace, cross-version evidence, impact, and limitations.
- `rt_ax82u_server_cert_tar_symlink_poc.sh`: non-destructive reproducer.
- `e2e-confirmation-2026-07-14/`: preserved marker, QEMU process log, syscall
  trace, hashes, and the canonical authenticated replay result.

## End-to-end emulation evidence

The exact ARM firmware HTTP service was rehosted in an internal-only Docker
network. A standard authenticated multipart request to the route wrote the
archive and invoked the exact firmware BusyBox `tar`. The same run created
`/tmp/friday-proof/asus-http-marker` outside `/tmp/server_ovpn_file`; the
handler then removed its extraction directory while the marker remained.
The bounded marker contains `FRIDAY_ASUS_HTTP_PROOF` and has SHA-256
`4dede3e8b04d5ad2b7dd04627ec6cfc303154e50851d86357ea605a7f1cdf6be`.

No physical-router replay was performed. The emulated run nevertheless joins
the real route, multipart parser, response handler, extraction command, exact
firmware BusyBox, and out-of-directory security effect in one execution.
