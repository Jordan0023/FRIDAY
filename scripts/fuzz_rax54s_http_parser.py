#!/usr/bin/env python3
"""Deterministic bounded mutational fuzzing for the isolated RAX54S HTTP lab."""

from __future__ import annotations

import argparse
import hashlib
import random
import ssl
import time
from pathlib import Path

import emulate_rax54s_http_full_system as lab


LOG = lab.LAB / "http-parser-fuzz.log"
CRASH = lab.LAB / "http-parser-fuzz-reproducer.bin"


def mutate(seed: bytes, rng: random.Random, index: int) -> bytes:
    data = bytearray(seed)
    operations = 1 + rng.randrange(6)
    tokens = (
        b"\x00", b"\r", b"\n", b":", b"\"", b"<", b">", b"&",
        b"%00", b"%ff", b"../", b"$(", b"`", b"A" * 256,
    )
    for _ in range(operations):
        choice = rng.randrange(4)
        position = rng.randrange(len(data) + 1)
        if choice == 0 and data:
            del data[rng.randrange(len(data))]
        elif choice == 1 and data:
            data[rng.randrange(len(data))] ^= 1 << rng.randrange(8)
        elif choice == 2:
            data[position:position] = rng.choice(tokens)
        else:
            run = min(16384, 1 << rng.randrange(4, 15))
            data[position:position] = bytes([65 + (index % 26)]) * run
    return bytes(data[:131072])


def request_from_blob(blob: bytes, index: int) -> bytes:
    modes = index % 4
    action = b'"urn:NETGEAR-ROUTER:service:DeviceInfo:1#GetInfo' + blob + b'"'
    body = (
        b'<m:GetInfo xmlns:m="urn:NETGEAR-ROUTER:service:DeviceInfo:1">'
        + blob
        + b"</m:GetInfo>"
    )
    path = b"/soap/server_sa/" + (blob if modes == 2 else b"")
    headers = [
        (b"Host", b"routerlogin.net" + (blob if modes == 1 else b"")),
        (b"X-Forwarded-For", b"192.168.1.2" + (blob if modes == 3 else b"")),
        (b"SOAPAction", action),
        (b"Content-Type", b'text/xml; charset="utf-8"'),
        (b"Content-Length", str(len(body)).encode()),
        (b"Connection", b"close"),
    ]
    request = bytearray(b"POST " + path + b" HTTP/1.1\r\n")
    for name, value in headers:
        request.extend(name + b": " + value + b"\r\n")
    request.extend(b"\r\n" + body)
    return bytes(request)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cases", type=int, default=256)
    parser.add_argument("--seed", type=int, default=0x52415854)
    args = parser.parse_args()

    lab.build()
    lab.start()
    lab.wait_ready()
    deadline = time.monotonic() + 120
    while True:
        try:
            if lab.tls_request().startswith(b"HTTP/"):
                break
        except (OSError, ssl.SSLError):
            pass
        if time.monotonic() >= deadline:
            raise SystemExit("baseline HTTP control did not become ready")
        time.sleep(1)

    rng = random.Random(args.seed)
    seed = b"seed"
    signatures: set[str] = set()
    lines = [f"seed={args.seed} cases={args.cases}"]
    for index in range(args.cases):
        blob = mutate(seed, rng, index)
        request = request_from_blob(blob, index)
        response = b""
        error = ""
        try:
            response = lab.tls_exchange(request, timeout=12)
        except (OSError, ssl.SSLError) as exc:
            error = f"{type(exc).__name__}:{exc}"
        signature = hashlib.sha256(response[:4096]).hexdigest()[:16]
        signatures.add(f"{lab.response_status(response)}:{len(response)}:{signature}:{error}")
        serial = lab.SERIAL.read_text(errors="replace")
        crashed = "FRIDAY_RAX29_FATAL" in serial or "HTTPD_EXITED=1" in serial
        try:
            healthy = lab.tls_request().startswith(b"HTTP/")
        except (OSError, ssl.SSLError):
            healthy = False
        line = (
            f"case={index} request={len(request)} response={len(response)} "
            f"status={lab.response_status(response)!r} healthy={healthy} "
            f"fatal={crashed} signature={signature} error={error!r}"
        )
        lines.append(line)
        if crashed or not healthy:
            CRASH.write_bytes(request)
            lines.append(f"reproducer={CRASH}")
            LOG.write_text("\n".join(lines) + "\n")
            print(line)
            return 2
        if index % 32 == 31:
            print(f"completed={index + 1} unique_signatures={len(signatures)}")
    lines.append(f"control_after=pass unique_signatures={len(signatures)}")
    LOG.write_text("\n".join(lines) + "\n")
    print(lines[-1])
    print(f"log={LOG}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
