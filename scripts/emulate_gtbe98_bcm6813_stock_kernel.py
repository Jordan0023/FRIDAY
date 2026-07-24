#!/usr/bin/env python3
"""Boot the exact GT-BE98 Pro vendor kernel in an isolated ARMv8 harness.

This is a kernel-ABI fidelity harness, not a BCM6813 peripheral emulator.
It intentionally provides no network devices.  The stock kernel's failure
point records which missing SoC model must be implemented before the result
can honestly be called a faithful BCM6813 board emulation.
"""

from __future__ import annotations

import hashlib
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ARTIFACTS = ROOT / "known_firmware/emulation/ASUS_GT-BE98_Pro/bcm6813-faithful"
KERNEL = ARTIFACTS / "Image-4.19.294"
DTB = ARTIFACTS / "GT-BE98PRO.dtb"
LOG = ARTIFACTS / "stock-kernel-qemu-virt.log"
QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-aarch64")

EXPECTED = {
    KERNEL: "ed63aa6d775bf98b9b9c814d551307ad468b1f38e92281d9438bc81a9c5e4838",
    DTB: "5e991fa26c4df092da0b1e1bf467a962af0ba01f281771ffded2b6024b287df8",
}


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def main() -> int:
    for path, expected in EXPECTED.items():
        actual = sha256(path)
        if actual != expected:
            raise SystemExit(f"hash mismatch for {path}: {actual}")
    if not QEMU.exists():
        raise SystemExit(f"QEMU not found: {QEMU}")

    command = [
        str(QEMU),
        "-M", "virt",
        "-cpu", "cortex-a53",
        "-smp", "4",
        "-m", "1024",
        "-nographic",
        "-no-reboot",
        "-kernel", str(KERNEL),
        "-append",
        "console=ttyAMA0,115200 earlycon=pl011,0x09000000 loglevel=8",
    ]
    try:
        result = subprocess.run(
            command,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            timeout=25,
            check=False,
        )
        output = result.stdout
    except subprocess.TimeoutExpired as error:
        output = error.stdout or b""
    LOG.write_bytes(output)
    text = output.decode("utf-8", errors="replace")
    print(text)
    print(f"log={LOG}")
    print(f"stock_kernel_seen={'Linux version 4.19.294 (root@asus)' in text}")
    print(f"bcm_ubus_failure={'bcm_ubus_config' in text}")
    print("network_devices=none")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
