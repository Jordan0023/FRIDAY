# GT-BE98 Pro full-system fidelity result

The combined emulator boots a generic ARM64 kernel, the original GT-BE98 Pro
root filesystem, and the original ASUS `/sbin/init` as PID 1. It supplies
two isolated virtio NICs modeled as WAN `eth0` and LAN `br0`, bridge and
netfilter modules, writable persistent ext4 storage, and no host forwarding.

The guest reached the stock init path, reported firmware
`3.0.0.6.102_39262-geaba2cf_1525-g8972c_BB0B`, and reached its console path.
It did not start `wl_server_socket` and did not expose TCP/8000.

The model-wide NVRAM compatibility pass now supplies signed-package-derived
`boardid`, boot-medium flags, and a clearly labeled placeholder base MAC
through a GLIBC-2.4-compatible ARM preload helper. This removed the former
`S40hndnvram` arithmetic failure: stock init reached `restore done!`,
`*** populated ***`, and the base-driver stage. It still did not start
`wl_server_socket` or expose TCP/8000.

The remaining blockers are demonstrated directly in the serial log:

- stock `bcm_knvram.ko` is built for Broadcom Linux 4.19.294 and cannot load
  into the generic 5.15 kernel;
- Broadcom WLCSM netlink initialization fails;
- the proprietary Broadcom base, RDPA, Ethernet, packet-runner, and wireless
  modules cannot load against the generic kernel;
- device-specific calibration/APG state and the physical unit's actual NVRAM
  remain unavailable.

Creating those values from guesses, patching the init scripts, or manually
starting the service would improve apparent boot progress but invalidate an
unmodified-stock activation claim.

Serial SHA-256:
`c0d3fa468211ceab148dcd1587f8c58b86808d9b597b52d04daa8b6c235ce5bb`.

The emulator is reproducible with:

```sh
python3 scripts/emulate_gtbe98_full_system.py run
```

An authentic physical `/proc/nvram` capture and bootloader NVRAM/ENVRAM dump
remain necessary to replace the modeled hardware state without fabrication.
