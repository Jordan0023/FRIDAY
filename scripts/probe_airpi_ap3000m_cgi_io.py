#!/usr/bin/env python3
"""Bounded unauthenticated cgi-io probes for the extracted AP3000M image."""

from __future__ import annotations

import argparse
import os
import subprocess
from pathlib import Path


def multipart(boundary: str, fields: list[tuple[str, str]]) -> bytes:
    body = bytearray()
    for name, value in fields:
        body.extend(
            f"--{boundary}\r\nContent-Disposition: form-data; name=\"{name}\"\r\n\r\n"
            f"{value}\r\n".encode()
        )
    body.extend(f"--{boundary}--\r\n".encode())
    return bytes(body)


def run_case(rootfs: Path, qemu: Path, name: str, body: bytes, boundary: str) -> bool:
    env = os.environ.copy()
    env.update(
        SCRIPT_NAME="/cgi-bin/cgi-upload",
        REQUEST_METHOD="POST",
        CONTENT_TYPE=f"multipart/form-data; boundary={boundary}",
        CONTENT_LENGTH=str(len(body)),
        PATH="/bin:/usr/bin:/sbin:/usr/sbin",
    )
    result = subprocess.run(
        [
            str(qemu), "-0", "cgi-upload", "-L", str(rootfs),
            str(rootfs / "usr/libexec/cgi-io"),
        ],
        input=body,
        capture_output=True,
        env=env,
        timeout=8,
    )
    text = (result.stdout + result.stderr).decode(errors="replace")
    denied = "permission denied" in text.lower()
    print(
        f"{name}: exit={result.returncode} denied={str(denied).lower()} "
        f"output={text.replace(chr(10), ' ')[:180]!r}"
    )
    return denied and result.returncode >= 0


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rootfs", required=True, type=Path)
    parser.add_argument("--qemu", required=True, type=Path)
    args = parser.parse_args()
    cases = []
    normal = "FRIDAY-AP3000M"
    base = [
        ("sessionid", ""),
        ("filename", "/tmp/friday-ap3000m"),
        ("filemode", "0600"),
        ("filedata", "control"),
    ]
    cases.append(("missing-session", multipart(normal, base), normal))
    forged = [(key, "f" * 32 if key == "sessionid" else value) for key, value in base]
    cases.append(("forged-session", multipart(normal, forged), normal))
    shell_path = [
        ("sessionid", ""),
        ("filename", "/tmp/x;touch${IFS}/tmp/friday-ap3000m-rce"),
        ("filemode", "0600"),
        ("filedata", "control"),
    ]
    cases.append(("shell-shaped-path", multipart(normal, shell_path), normal))
    long_boundary = "B" * 8192
    cases.append(("long-boundary", multipart(long_boundary, base), long_boundary))
    cases.append(("truncated-body", multipart(normal, base)[:-12], normal))
    failures = 0
    for name, body, boundary in cases:
        try:
            safe = run_case(args.rootfs, args.qemu, name, body, boundary)
        except subprocess.TimeoutExpired:
            print(f"{name}: timeout=true")
            safe = False
        failures += not safe
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
