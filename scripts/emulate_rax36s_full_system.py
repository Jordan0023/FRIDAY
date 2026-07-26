#!/usr/bin/env python3
"""Build and run an isolated full-system RAX36S V1.0.7.54 web/SOAP lab."""

from __future__ import annotations

import argparse
import os
import shutil
import socket
import subprocess
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROOTFS = ROOT / "known_firmware/extracted/7dfad4f35401482f/manual-rootfs"
INIT = ROOT / "known_firmware/emulation/RAX36S/full_system_web_init"
SHIM = ROOT / "known_firmware/emulation/RAX36/rax36_datalib_mtd_shim.c"
WEB_SHIM = ROOT / "known_firmware/emulation/RAX36/rax36_web_shim.c"
LAB = ROOT / "known_firmware/emulation/RAX36S/full-system-web-lab"
STAGING = Path("/tmp/friday-rax36s-full-system-root")
KERNEL = Path("/tmp/ad7200-armmp-vmlinuz")
KMODS = Path("/tmp/ad7200-kmods/lib/modules")
QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-arm")
INITRAMFS = LAB / "rax36s-v1.0.7.54-rootfs.cpio.gz"
DATA_DISK = LAB / "rax36s-data.ext4"
SERIAL = LAB / "serial.log"
QEMU_LOG = LAB / "qemu.log"
PIDFILE = LAB / "qemu.pid"
PROBE_LOG = LAB / "probe.log"
HOST_PORT = 25_136


def run(command: list[str], **kwargs: object) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, check=True, text=True, **kwargs)


def linker() -> Path:
    for name in ("ld.lld", "ld.lld-14"):
        found = shutil.which(name)
        if found:
            return Path(found)
    fallback = Path("/tmp/lld14-local/usr/lib/llvm-14/bin/ld.lld")
    if fallback.is_file():
        return fallback
    raise SystemExit("ARM-capable lld is missing")


def build(reset_data: bool = False) -> None:
    missing = [
        str(p) for p in (ROOTFS, INIT, SHIM, WEB_SHIM, KERNEL, KMODS, QEMU)
        if not p.exists()
    ]
    if missing:
        raise SystemExit("missing prerequisites: " + ", ".join(missing))
    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    shutil.copytree(ROOTFS, STAGING, symlinks=True)
    shutil.copytree(KMODS, STAGING / "lib/modules", dirs_exist_ok=True)
    shutil.copy2(INIT, STAGING / "init")
    os.chmod(STAGING / "init", 0o755)
    run([
        "clang", "--target=arm-linux-gnueabi", "-march=armv7-a", "-fPIC", "-shared",
        "-nostdlib", f"-fuse-ld={linker()}", "-Wl,-soname,rax36_datalib_mtd_shim.so",
        "-o", str(STAGING / "lib/rax36_datalib_mtd_shim.so"), str(SHIM),
    ])
    run([
        "clang", "--target=arm-linux-gnueabi", "-march=armv7-a", "-fPIC", "-shared",
        "-nostdlib", f"-fuse-ld={linker()}", "-Wl,-soname,rax36_web_shim.so",
        "-o", str(STAGING / "lib/rax36_web_shim.so"), str(WEB_SHIM),
    ])
    for relative in ("proc", "sys", "dev", "run", "tmp", "var/run", "var/log", "var/tmp"):
        path = STAGING / relative
        if path.is_symlink():
            path.unlink()
        path.mkdir(parents=True, exist_ok=True)
    with INITRAMFS.open("wb") as output:
        find = subprocess.Popen(["find", ".", "-print0"], cwd=STAGING, stdout=subprocess.PIPE)
        cpio = subprocess.Popen(
            ["cpio", "--null", "-o", "--format=newc"],
            cwd=STAGING, stdin=find.stdout, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL,
        )
        assert find.stdout is not None and cpio.stdout is not None
        find.stdout.close()
        gzip = subprocess.run(["gzip", "-1"], stdin=cpio.stdout, stdout=output, check=True)
        cpio.stdout.close()
        if find.wait() or cpio.wait() or gzip.returncode:
            raise SystemExit("initramfs creation failed")
    if reset_data or not DATA_DISK.exists():
        with DATA_DISK.open("wb") as disk:
            disk.truncate(64 * 1024 * 1024)
        run(["mkfs.ext4", "-F", "-q", "-L", "RAX36S_DATA", str(DATA_DISK)])
    print(f"initramfs={INITRAMFS}\ndata_disk={DATA_DISK}")


def qemu_command() -> list[str]:
    lan = (
        f"user,id=lan,net=10.0.2.0/24,restrict=on,"
        f"hostfwd=tcp:127.0.0.1:{HOST_PORT}-10.0.2.15:80"
    )
    return [
        str(QEMU), "-M", "virt", "-cpu", "cortex-a15", "-m", "1024M",
        "-kernel", str(KERNEL), "-initrd", str(INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-display", "none", "-monitor", "none", "-serial", f"file:{SERIAL}",
        "-drive", f"if=none,file={DATA_DISK},format=raw,id=data",
        "-device", "virtio-blk-device,drive=data",
        "-netdev", lan, "-device", "virtio-net-device,netdev=lan",
        "-no-reboot",
    ]


def stop() -> None:
    if PIDFILE.exists():
        try:
            pid = int(PIDFILE.read_text())
            cmdline = Path(f"/proc/{pid}/cmdline")
            if cmdline.exists() and b"qemu-system-arm" in cmdline.read_bytes():
                os.kill(pid, 15)
        except (ValueError, ProcessLookupError, PermissionError):
            pass
        PIDFILE.unlink(missing_ok=True)


def start() -> None:
    if not INITRAMFS.is_file() or not DATA_DISK.is_file():
        raise SystemExit("run the build action first")
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    command = qemu_command() + [
        "-daemonize", "-pidfile", str(PIDFILE), "-D", str(QEMU_LOG),
    ]
    run(command)
    pid = PIDFILE.read_text().strip()
    print(f"qemu_pid={pid} http=http://127.0.0.1:{HOST_PORT}/")


def validate() -> None:
    """Keep QEMU attached while probing; useful in managed/sandboxed runners."""
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    with QEMU_LOG.open("wb") as output:
        process = subprocess.Popen(qemu_command(), stdout=output, stderr=subprocess.STDOUT)
        try:
            probe()
        finally:
            process.terminate()
            try:
                process.wait(timeout=10)
            except subprocess.TimeoutExpired:
                process.kill()


def wait_ready(timeout: int = 180) -> str:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        text = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if "FRIDAY_RAX36S_WEB_READY=1" in text:
            return text
        if "Kernel panic" in text:
            raise SystemExit("guest kernel panic; inspect serial.log")
        time.sleep(0.5)
    raise SystemExit("guest readiness timed out; inspect serial.log")


def request(method: str, path: str, headers: dict[str, str], body: bytes = b"") -> bytes:
    fields = {"Host": "routerlogin.net", "Connection": "close", **headers}
    if body:
        fields["Content-Length"] = str(len(body))
    wire = f"{method} {path} HTTP/1.1\r\n".encode()
    wire += b"".join(f"{k}: {v}\r\n".encode() for k, v in fields.items()) + b"\r\n" + body
    # The emulated single-core ARM CGI is much slower than the user-mode
    # component harness, especially on its first process start.
    with socket.create_connection(("127.0.0.1", HOST_PORT), timeout=60) as client:
        client.sendall(wire)
        chunks: list[bytes] = []
        while True:
            try:
                chunk = client.recv(65536)
            except TimeoutError:
                if chunks:
                    break
                raise
            if not chunk:
                break
            chunks.append(chunk)
    return b"".join(chunks)


def probe() -> None:
    serial = wait_ready()
    urn = "urn:NETGEAR-ROUTER:service:DeviceConfig:1"
    body = (
        f'<SOAP-ENV:Envelope xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/">'
        f'<SOAP-ENV:Body><m:GetSecurityQuestions xmlns:m="{urn}"/>'
        f"</SOAP-ENV:Body></SOAP-ENV:Envelope>"
    ).encode()
    soap = b""
    soap_error = ""
    try:
        soap = request("POST", "/soapapi", {
            "Content-Type": 'text/xml; charset="utf-8"',
            "SOAPAction": f'"{urn}#GetSecurityQuestions"',
            "User-Agent": "RAX36S-emulation-validation/1",
            "X-Forwarded-For": "10.0.2.2",
        }, body)
    except (OSError, TimeoutError) as error:
        soap_error = f"{type(error).__name__}: {error}"
    status = lambda r: r.splitlines()[0].decode(errors="replace") if r else "empty"
    report = (
        f"persistent_data={'yes' if 'PERSISTENT_DATA=yes' in serial else 'no'}\n"
        f"datalib_alive={'yes' if 'DATALIB_ALIVE=yes' in serial else 'no'}\n"
        f"lighttpd_alive={'yes' if 'LIGHTTPD_ALIVE=yes' in serial else 'no'}\n"
        f"get_security_questions={status(soap)} bytes={len(soap)}\n"
        f"soap_error={soap_error or 'none'}\n"
        f"soap_response_code_000={'yes' if b'<ResponseCode>000</ResponseCode>' in soap else 'no'}\n"
    )
    PROBE_LOG.write_text(report)
    print(report, end="")
    if not soap.startswith(b"HTTP/"):
        raise SystemExit(2)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "action",
        choices=("build", "reset-build", "start", "validate", "run", "probe", "stop", "status"),
    )
    args = parser.parse_args()
    if args.action in ("build", "reset-build", "run"):
        build(reset_data=args.action == "reset-build")
    if args.action == "start":
        start()
    if args.action in ("validate", "run"):
        validate()
    if args.action == "probe":
        probe()
    if args.action == "stop":
        stop()
    if args.action == "status":
        print(SERIAL.read_text(errors="replace")[-8000:] if SERIAL.exists() else "no serial log")


if __name__ == "__main__":
    main()
