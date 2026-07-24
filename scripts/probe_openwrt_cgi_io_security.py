#!/usr/bin/env python3
"""Bounded ACL and multipart probes for a disposable OpenWrt cgi-io rootfs."""
from __future__ import annotations

import argparse
import os
import subprocess
from pathlib import Path


def multipart(boundary: str, fields: list[tuple[str, str, str | None]], close: bool = True) -> bytes:
    body = bytearray()
    for name, value, filename in fields:
        body.extend(f"--{boundary}\r\nContent-Disposition: form-data; name=\"{name}\"".encode())
        if filename is not None:
            body.extend(f"; filename=\"{filename}\"".encode())
        body.extend(b"\r\n\r\n")
        body.extend(value.encode())
        body.extend(b"\r\n")
    if close:
        body.extend(f"--{boundary}--\r\n".encode())
    return bytes(body)


def run_case(
    rootfs: Path,
    qemu: Path,
    name: str,
    token: str,
    *,
    boundary: str = "FRIDAY-EW1200-BOUNDARY",
    close: bool = True,
    filename: str | None = "probe.txt",
) -> tuple[int, str, str, str, bool]:
    guest_target = f"/etc/luci-uploads/friday-{name}.txt"
    host_target = rootfs / guest_target.lstrip("/")
    host_target.unlink(missing_ok=True)
    fields = [
        ("sessionid", token, None),
        ("filename", guest_target, None),
        ("filemode", "0600", None),
        ("filedata", "FRIDAY_EW1200_MULTIPART_CONTROL", filename),
    ]
    body = multipart(boundary, fields, close=close)
    env = os.environ.copy()
    env.update(
        SCRIPT_NAME="/cgi-bin/cgi-upload",
        REQUEST_METHOD="POST",
        CONTENT_TYPE=f"multipart/form-data; boundary={boundary}",
        CONTENT_LENGTH=str(len(body)),
        PATH="/bin:/usr/bin:/sbin:/usr/sbin",
    )
    cmd = [
        "unshare", "-Ur", "--map-root-user", "chroot", str(rootfs),
        "/tmp/qemu-mipsel-static", "/www/cgi-bin/cgi-upload",
    ]
    result = subprocess.run(cmd, input=body, capture_output=True, env=env, timeout=10)
    first = result.stdout.splitlines()[0].decode(errors="replace") if result.stdout else "NO_OUTPUT"
    response = result.stdout.decode(errors="replace").replace("\r", " ").replace("\n", " ")[:240]
    error = " | ".join(
        line.decode(errors="replace") for line in result.stderr.splitlines()[-3:]
    )
    return result.returncode, first, response, error, host_target.is_file()


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rootfs", type=Path, required=True)
    parser.add_argument("--qemu", type=Path, required=True)
    parser.add_argument("--root-token", required=True)
    parser.add_argument("--limited-token", required=True)
    args = parser.parse_args()
    if not args.qemu.is_file():
        parser.error("qemu must exist")
    if not (args.rootfs / "usr/libexec/cgi-io").is_file():
        parser.error("rootfs does not contain cgi-io")

    cases = [
        ("missing", "", {}),
        ("forged", "f" * 32, {}),
        ("limited", args.limited_token, {}),
        ("root", args.root_token, {}),
        ("missing_close", args.root_token, {"close": False}),
        ("empty_filename", args.root_token, {"filename": None}),
        ("long_boundary", args.root_token, {"boundary": "B" * 8192}),
    ]
    failures = 0
    for name, token, kwargs in cases:
        try:
            code, status, response, error, created = run_case(
                args.rootfs, args.qemu, name, token, **kwargs
            )
        except subprocess.TimeoutExpired:
            print(f"{name}: timeout=true")
            failures += 1
            continue
        print(
            f"{name}: exit={code} status={status!r} error={error!r} "
            f"target_created={str(created).lower()} response={response!r}"
        )
        if name in {"missing", "forged", "limited"} and created:
            failures += 1
        if name == "root" and not created:
            failures += 1
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
