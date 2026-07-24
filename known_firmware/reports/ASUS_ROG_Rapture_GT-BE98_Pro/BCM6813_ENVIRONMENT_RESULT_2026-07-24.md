# GT-BE98 Pro BCM6813 environment result

The signed GT-BE98 Pro package contains the exact ASUS/Broadcom boot artifacts.
They have now been extracted without modification:

- ARM64 Linux 4.19.294, built by ASUS with Buildroot GCC 10.3.0;
- `fdt_GT-BE98PRO`, the 62,232-byte production device tree;
- the complete 4.19.294 module set already present in the stock rootfs;
- the signed ATF and U-Boot payloads in the nested FIT.

Artifact hashes:

- decompressed kernel:
  `ed63aa6d775bf98b9b9c814d551307ad468b1f38e92281d9438bc81a9c5e4838`;
- production DTB:
  `5e991fa26c4df092da0b1e1bf467a962af0ba01f281771ffded2b6024b287df8`;
- compressed kernel, matching its FIT hash:
  `f017d5e93819f47c85c5762b77d2b6de638029272eaba17f798a605c16941ea6`.

The exact kernel successfully starts on an isolated QEMU ARMv8 machine and
reports its authentic build:

```text
Linux version 4.19.294 (root@asus) ... #1 SMP PREEMPT Mon Apr 27 18:36:51 CST 2026
```

It then panics in the built-in `bcm_ubus_config` initialization because QEMU
does not implement the BCM6813 UBUS/PMC/strap/register fabric. The panic is a
null write at `bcm_ubus_config+0x98`, after the strap read returns
`0xffffffff`. This occurs before initramfs or stock userspace can start.

This resolves the kernel-version and module-ABI uncertainty, but proves that
a faithful board cannot be produced merely by selecting QEMU's generic
ARM machine. QEMU 6.2 has no BCM6813 machine. A real board model requires
implementations of at least the BCM6813 interrupt map, UBUS, PMC, straps,
OTP, NAND controller, XRDP/Ethernet fabric, PCIe, and Broadcom wireless-facing
interfaces. Their behavioral specifications and per-unit OTP/calibration
state are not present in the firmware package.

The reproducible, network-free kernel harness is:

```sh
python3 scripts/emulate_gtbe98_bcm6813_stock_kernel.py
```

This harness must not be described as physical-board-equivalent. It is the
highest-fidelity executable checkpoint possible from the public signed
firmware alone. Physical hardware, a vendor BCM6813 simulator, or sufficient
register-level documentation is required to cross the remaining boundary.
