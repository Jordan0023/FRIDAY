#!/usr/bin/env python3
"""Run the RS700S V1.0.11.8 httpd in the isolated NETGEAR ARM lab."""

from __future__ import annotations

import importlib.util
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / "scripts/emulate_rax54s_http_full_system.py"

spec = importlib.util.spec_from_file_location("netgear_http_lab", BASE)
if spec is None or spec.loader is None:
    raise SystemExit(f"cannot load base harness: {BASE}")
lab = importlib.util.module_from_spec(spec)
spec.loader.exec_module(lab)

lab.ROOTFS = Path("/tmp/rs700-static/rootfs")
lab.INIT = ROOT / "known_firmware/emulation/RS700/full_system_http_init"
lab.LAB = ROOT / "known_firmware/emulation/RS700/full-system-http-lab"
lab.STAGING = Path("/tmp/friday-rs700-full-system-root")
lab.INITRAMFS = lab.LAB / "rs700-http-rootfs.cpio.gz"
lab.SERIAL = lab.LAB / "serial.log"
lab.QEMU_LOG = lab.LAB / "qemu.log"
lab.PIDFILE = lab.LAB / "qemu.pid"
lab.SECURITY_LOG = lab.LAB / "http-security-probe.log"
lab.HOST_HTTP_PORT = 27_080
lab.HOST_HTTPS_PORT = 27_154


original_tls_request = lab.tls_request
readiness_failures = 0


def traced_tls_request(timeout: float = 5) -> bytes:
    global readiness_failures
    try:
        return original_tls_request(timeout)
    except Exception as error:
        readiness_failures += 1
        if readiness_failures <= 3:
            print(
                f"rs700_tls_readiness_failure={type(error).__name__}:{error}",
                flush=True,
            )
        raise


lab.tls_request = traced_tls_request
# RS700 starts a secondary lighttpd from httpd before the inherited init
# reaches its explicit marker. The control loop below is the authoritative
# readiness check for this model.
lab.wait_ready = lambda timeout=600: ""


if __name__ == "__main__":
    lab.main()
