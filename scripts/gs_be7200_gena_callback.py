#!/usr/bin/env python3
"""Minimal QEMU guestfwd endpoint for isolated GENA callback validation."""

import os


request = bytearray()
while b"\r\n\r\n" not in request and len(request) < 65_536:
    chunk = os.read(0, 4096)
    if not chunk:
        break
    request.extend(chunk)
os.write(1, b"HTTP/1.1 200 OK\r\nContent-Length: 0\r\nConnection: close\r\n\r\n")
