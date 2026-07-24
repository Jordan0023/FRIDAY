# BCM6813 hybrid checkpoint

The exact ASUS 4.19.294 kernel was booted with QEMU's functioning ARMv8
platform device tree augmented by the production BCM6813 strap and UBUS
discovery nodes. No network device or host forwarding was configured.

This moved the failure from a missing-node/null-write in `bcm_ubus_config`
to the first authentic BCM6813 strap MMIO access:

```text
Internal error: synchronous external abort
pc : bcm_strap_early_scan_dt+0x170/0x1b4
x22: 00000000ff802600
```

The address corresponds to the production DT mapping:
`periph` base `0xff800000` plus strap offset `0x2600`.

This is useful progress: the stock kernel recognizes the hybrid BCM nodes
and reaches the exact first hardware register dependency. It also establishes
that DT completion alone cannot resolve the boot. A QEMU sysbus device must
provide behavior for the BCM6813 MMIO regions; returning invented constants
would be a synthetic boot and cannot prove physical stock activation.

Reproduce with:

```sh
python3 scripts/emulate_gtbe98_bcm6813_hybrid.py
```
