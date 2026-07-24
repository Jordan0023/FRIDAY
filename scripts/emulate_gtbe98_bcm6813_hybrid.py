#!/usr/bin/env python3
"""Run the network-free GT-BE98 Pro stock-kernel/QEMU hybrid checkpoint."""

from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / "known_firmware/emulation/ASUS_GT-BE98_Pro"
KERNEL = BASE / "bcm6813-faithful/Image-4.19.294"
DTB = BASE / "bcm6813-hybrid/GT-BE98PRO-qemu-hybrid.dtb"
LOG = BASE / "bcm6813-hybrid/boot.log"
QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-aarch64")

command = [
    str(QEMU), "-M", "virt", "-cpu", "cortex-a53", "-smp", "4",
    "-m", "1024", "-nographic", "-no-reboot", "-kernel", str(KERNEL),
    "-dtb", str(DTB), "-append",
    "console=ttyAMA0,115200 earlycon=pl011,0x09000000 loglevel=8",
]

try:
    result = subprocess.run(
        command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
        timeout=25, check=False,
    )
    output = result.stdout
except subprocess.TimeoutExpired as error:
    output = error.stdout or b""

LOG.write_bytes(output)
text = output.decode(errors="replace")
print(text)
print(f"stock_kernel_seen={'Linux version 4.19.294 (root@asus)' in text}")
print(f"strap_mmio_boundary={'bcm_strap_early_scan_dt' in text}")
print("network_devices=none")
