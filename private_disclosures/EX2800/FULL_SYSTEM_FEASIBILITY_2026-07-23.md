# EX2800 full-system emulation feasibility

The firmware image contains:

- Linux 2.6.36, MIPS32 R2
- MediaTek/Ralink MT7628-specific platform code
- kernel command line references to `console=ttyS0,115200`
- a SquashFS root filesystem

The installed `qemu-system-mipsel` supports only `malta`, `mipssim`, and
`none`. It has no MT7628 machine model. The extracted vendor kernel is a raw
LZMA-decompressed platform image rather than an ELF kernel; attempting to load
it with the Malta model fails with:

```text
qemu-system-mipsel: could not load kernel ...: The image is not ELF
```

Even if the raw kernel were wrapped or loaded at a guessed address, Malta does
not provide the MT7628 interrupt controller, timer, SPI flash, Ethernet, or
wireless devices expected by this kernel. A faithful boot therefore requires
an MT7628-capable emulator, a vendor board model, or physical hardware.

Component-level emulation remains the highest available local fidelity.

The original `/usr/bin/logic` configuration/message-bus daemon was brought
into its receive loop after narrowly bypassing hardware-only initialization:
an unsupported MT7628 flash ioctl and the aggregate failure/exit for optional
bridge, LED, procfs, flash, and wireless modules. Its configuration and IPC
functions were not stubbed. The daemon created `/var/pid/0x01`, reported all
modules initialized, and remained alive until a bounded timeout.

The HTTP-side blocker was subsequently resolved. The root-mode SIGSEGV was
uClibc `initgroups()` receiving a null username because the harness omitted
the vendor command's `-u root` argument. Launching with the exact options from
`/etc/init.d/daemon.rc` allowed the original HTTP daemon and `webproc` to
complete requests against the restored backend.

An unauthenticated route matrix and four direct diagnostic-object POSTs
produced no credential disclosure, configuration change, privileged marker,
or command execution. The parent HTTP service remained healthy. The static
`diagtest -m ping -d %s` path therefore remains a post-authentication review
candidate; it is not dynamically confirmed as pre-authentication reachable or
command-injectable.
