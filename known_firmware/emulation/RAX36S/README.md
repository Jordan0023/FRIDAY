# RAX36S V1.0.7.54 full-system web/SOAP lab

This lab boots the extracted RAX36S firmware userspace as an ARMv7 initramfs.
It runs the firmware's genuine `datalib`, `config`, `lighttpd`, and `net-cgi`
programs. One isolated QEMU user-mode network represents LAN; its HTTP port is
forwarded only to host loopback. A second QEMU NIC is deliberately omitted:
testing confirmed that another slirp/NIC backend prevents inbound LAN
host-forward delivery in this machine configuration. WAN behavior is therefore
outside this web/SOAP harness.

Build, start, and validate:

```sh
python3 scripts/emulate_rax36s_full_system.py run
```

The endpoint is `http://127.0.0.1:25136/` while the VM is running. Other useful
actions are `start`, `probe`, `validate`, `status`, `stop`, and `reset-build`.
`validate` keeps QEMU attached for runners that reap background processes. A
normal `build` retains the ext4 data image; `reset-build` recreates it. The
current generic kernel does not include `virtio_blk`, so the serial log reports
`PERSISTENT_DATA=no`; persistence becomes active when a compatible module or
kernel is supplied. A narrow preload supplies configuration and encrypted-flash
lifecycle calls that physical MTD normally provides; request parsing,
authentication, SOAP dispatch, and action implementations remain in `net-cgi`.

Run the bounded unauthenticated crash-oriented campaign with:

```sh
python3 scripts/fuzz_rax36s_unauth_http.py
```

Every exact request, its SHA-256, per-case response, post-case health control,
and the guest serial log are saved beneath `full-system-web-lab/`. Use
`--case NAME` to replay one deterministic case. The corpus avoids reset,
firmware-update, and persistent configuration actions.

For handler-specific recovery/password argument boundaries, use:

```sh
python3 scripts/fuzz_rax36s_unauth_http.py --profile actions
```

The emulation is service-realistic, not hardware-exact. It uses a generic QEMU
ARM `virt` machine and Debian ARM kernel because the vendor kernel and board
device tree are unavailable. Flash reads/writes alone are shimmed so `datalib`
can operate without the physical MTD. TLS, Wi-Fi, switching, acceleration, and
SoC-specific kernel drivers are outside this lab's fidelity boundary.
