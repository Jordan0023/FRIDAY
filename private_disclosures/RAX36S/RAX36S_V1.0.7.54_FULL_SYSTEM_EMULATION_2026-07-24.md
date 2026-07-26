# RAX36S V1.0.7.54 full-system emulation status

Date: 2026-07-24

## Implemented

- QEMU ARMv7 `virt` guest with the extracted, byte-matched RAX36/RAX36S
  V1.0.7.54 userspace.
- Genuine firmware `datalib`, `config`, `lighttpd`, and `net-cgi`.
- One restricted user-mode LAN network (`br0`, `10.0.2.15`). WAN is omitted
  because a second QEMU slirp/NIC backend disrupts inbound LAN forwarding.
- Only guest TCP/80 is forwarded, to host loopback TCP/25136.
- Narrow MTD/config lifecycle shims; parsing, authentication, SOAP dispatch,
  and action code remain in the firmware's `net-cgi`.
- Reproducible build/start/attached-validation/stop commands and serial logs.

## Validation evidence

The guest boots without a kernel panic. Both virtio NICs are renamed and
configured. The genuine data service accepts config IPC, reports
`DATALIB_ALIVE=yes`, and password recovery is enabled. Genuine lighttpd reports
version 1.4.56, remains alive, and listens on TCP/80.

The supplied Debian ARM kernel does not contain `virtio_blk`, so the optional
ext4 data disk is not visible and the init reports `PERSISTENT_DATA=no`.

The apparent CGI stall was traced to QEMU networking: with two NIC backends,
the host-forward connection was accepted by slirp but no request reached
lighttpd. A guest-local request passed through genuine `net-cgi` with HTTP 200.
Removing the second NIC fixed inbound delivery. The full-system
`GetSecurityQuestions` probe now returns HTTP 200, 693 response bytes, and
`ResponseCode=000` without web authentication.

## Fidelity boundary

The vendor kernel, board device tree, Broadcom SoC peripherals, Wi-Fi,
switching, acceleration, TLS provisioning, and physical MTD are unavailable.
The current web/SOAP harness is appropriate for LAN-side action testing. It is
not appropriate for WAN exposure testing. Persistent configuration also
remains unavailable until a kernel with `virtio_blk` is supplied.
