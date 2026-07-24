#!/usr/bin/env python3
"""Isolated QEMU boundary validation for the AD7200 Qcmbr candidate."""
from __future__ import annotations

import json
import socket
import subprocess
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROOTFS = ROOT / "known_firmware/extracted/60f753419137504b/_AD7200_EU_US__V2.0_210430.zip.extracted/AD7200(EU_US)_V2.0_210430/_AD7200v2-up-ver2-0-2-P1[20210430-rel61094]_2021-05-06_11.48.13.bin.extracted/squashfs-root"
QEMU = Path("/tmp/qemu-user-static-local/usr/bin/qemu-arm-static")
PORT = 42400
EMULATED_BINARY = ROOT / "known_firmware/emulation/TP-Link_AD7200/Qcmbr-ioctl-emulated"
FRAMES = [b"A~", b"K~", b"K\x0b~", b"K\x0b\x16~", b"K\x0b\x16\x00~", b"\x00~", b"{~"]


def run_case(frame: bytes, port: int) -> dict:
    command = [str(QEMU), "-strace", "-L", str(ROOTFS), str(EMULATED_BINARY),
               "-port", str(port), "-console"]
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                               text=True, errors="replace")
    sock = None
    try:
        deadline = time.monotonic() + 5
        while time.monotonic() < deadline:
            if process.poll() is not None:
                break
            try:
                sock = socket.create_connection(("127.0.0.1", port), 0.2)
                break
            except OSError:
                time.sleep(0.05)
        if sock is None:
            return {"frame_hex": frame.hex(), "error": "listener unavailable", "returncode": process.poll()}
        sock.settimeout(1)
        sock.sendall(frame)
        try:
            response = sock.recv(512)
        except (TimeoutError, socket.timeout):
            response = b""
        time.sleep(0.2)
        return {"frame_hex": frame.hex(), "response_hex": response.hex(), "alive_with_client_open": process.poll() is None,
                "returncode_with_client_open": process.poll()}
    finally:
        if sock is not None:
            sock.close()
        if process.poll() is None:
            process.terminate()
            try: process.wait(timeout=2)
            except subprocess.TimeoutExpired: process.kill()
        output = process.stdout.read() if process.stdout else ""
        run_case.last_output = output


def main() -> int:
    results = []
    logs = []
    for index, frame in enumerate(FRAMES):
        result = run_case(frame, PORT + index)
        results.append(result)
        logs.append({"frame_hex": frame.hex(), "output": getattr(run_case, "last_output", "")})
    payload = {"emulator": str(QEMU), "original_binary": str(ROOTFS / "usr/sbin/Qcmbr"),
               "emulated_binary": str(EMULATED_BINARY), "emulation": "private ioctl 0x89fd returns success",
               "results": results, "logs": logs}
    output = ROOT / "known_firmware/reports/TP-Link_AD7200/QCMBR_IOCTL_EMULATION_VALIDATION_2026-07-20.json"
    output.write_text(json.dumps(payload, indent=2) + "\n")
    print(json.dumps(payload["results"], indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
