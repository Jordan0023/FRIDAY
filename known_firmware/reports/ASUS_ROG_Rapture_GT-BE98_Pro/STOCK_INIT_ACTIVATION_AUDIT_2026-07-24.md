# GT-BE98 Pro stock-init activation audit

Date: 2026-07-24

## Question

Does an unmodified supported GT-BE98 Pro firmware boot start
`wl_server_socket` without prior authentication?

## Original boot artifacts

The outer firmware FIT identifies the package as `GT-BE98_PRO`. Its nested
boot FIT contains:

- ARM64 Linux kernel, LZO-compressed, load/entry address `0x00200000`
- exact board configuration `conf_lx_GT-BE98PRO`
- exact board DTB `fdt_GT-BE98PRO`
- ARM Trusted Firmware and U-Boot

The extracted hashes match the hashes embedded in the FIT:

- kernel LZO:
  `f017d5e93819f47c85c5762b77d2b6de638029272eaba17f798a605c16941ea6`
- GT-BE98 Pro DTB:
  `5e991fa26c4df092da0b1e1bf467a962af0ba01f281771ffded2b6024b287df8`

The board DTB describes Broadcom 96813-specific memory, interrupt, NAND,
Ethernet/XRDP, PMC, and peripheral controllers. Its boot console is
`ttyAMA0,115200`.

## Original-kernel boot attempt

The exact kernel and `fdt_GT-BE98PRO` were supplied to
`qemu-system-aarch64`. QEMU's generic `virt` machine could not load the
kernel: the stock image is linked to start at `0x00200000`, while generic
QEMU `virt` RAM begins at `0x40000000`. QEMU also has no Broadcom 96813
machine implementation for the devices in the board DTB.

Changing the kernel load address or replacing the DTB would no longer test
the original board boot, so that result was not used as activation evidence.

## Stock-init execution

The extracted root filesystem's `/sbin/init` is a symlink to the stock
32-bit ARM `/sbin/rc`. A disposable rootfs copy was used only to add the
QEMU execution trampoline and writable runtime directories. The original
`rc` was not changed:

`73768740c435de23c6f6d09517530e3a1ddfb6d81bed4f7767550b38a92ee92a`

The stock init was run as PID 1 in a privileged, network-disabled container.
Recursive `execve` tracing was enabled so ARM child programs were also
executed and observed. The boot:

- entered `init_main`;
- identified firmware
  `3.0.0.6.102_39262-geaba2cf_1525-g8972c_BB0B`;
- ran the firmware's Broadcom and ASUS initialization commands;
- attempted UBI, kernel-NVRAM, watchdog, wireless and device setup;
- reached the firmware console path.

Hardware-dependent operations failed where the generic host kernel lacks
Broadcom UBI, NVRAM, WLAN netlink and watchdog devices. No external network
was available to the guest.

## Activation result

Neither the parent syscall trace nor the recursively executed child trace
contains an execution or reference to:

- `wl_server_socket`
- `/tmp/RWL`

The earlier complete filesystem reference scan likewise found no launcher
outside the vulnerable binary itself. `wl` and `dhd` contain Broadcom
RemoteWL protocol code, but they do not supply a stock invocation of the
standalone server.

Trace hashes:

- `stock-init.trace`:
  `9eef44918025acbfb0e4ddcb5ca43baaefa529d7567b415f979ba84afbbffc57`
- `stock-child.trace`:
  `b9908e9cd52189b7180dd5232acb8b7d71ef29849536e4a0ac99fc6e522dc158`

## Conclusion

This test did **not** prove stock activation. The evidence currently supports
a vulnerable, unauthenticated command-execution component that becomes LAN
or WAN reachable when launched, but it does not support calling the shipping
GT-BE98 Pro a confirmed zero-day.

The remaining activation gap is hardware state unavailable from the firmware
update alone: real bootloader NVRAM/ENVRAM contents and Broadcom device
behavior. Supplying invented values until the daemon starts would create an
emulator-induced activation and would not be valid evidence.

The decisive remaining test is observation of an unmodified physical unit's
process/listener state, or a captured NVRAM/ENVRAM and boot log from such a
unit that can be replayed without guessing.
