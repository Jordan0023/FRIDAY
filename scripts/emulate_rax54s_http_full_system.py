#!/usr/bin/env python3
"""Build and run an isolated full-system RAX54S HTTP analysis lab."""

from __future__ import annotations

import argparse
import os
import re
import shutil
import socket
import ssl
import subprocess
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROOTFS = ROOT / "known_firmware/extracted/12d0be80c7dfee7f/manual-rootfs"
INIT = ROOT / "known_firmware/emulation/RAX54S/full_system_http_init"
SHIM = ROOT / "known_firmware/emulation/RAX30/rax30_emulation_shim.c"
DEVICE_SHIM = ROOT / "known_firmware/emulation/RAX54S/rax54s_device_shim.c"
LAB = ROOT / "known_firmware/emulation/RAX54S/full-system-http-lab"
STAGING = Path("/tmp/friday-rax54s-full-system-root")
KERNEL = Path("/tmp/ad7200-armmp-vmlinuz")
KMODS = Path("/tmp/ad7200-kmods/lib/modules")
QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-arm")
INITRAMFS = LAB / "rax54s-http-rootfs.cpio.gz"
SERIAL = LAB / "serial.log"
QEMU_LOG = LAB / "qemu.log"
PIDFILE = LAB / "qemu.pid"
HOST_HTTP_PORT = 25_080
HOST_HTTPS_PORT = 25_154
SECURITY_LOG = LAB / "http-security-probe.log"
GUEST_MEMORY_MB = 1024
GUEST_HTTP_PORT = 80
GUEST_HTTPS_PORT = 9443


def run(command: list[str], **kwargs: object) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, check=True, text=True, **kwargs)


def linker() -> Path:
    for candidate in ("ld.lld", "ld.lld-14"):
        path = shutil.which(candidate)
        if path:
            return Path(path)
    fallback = Path("/tmp/lld14-local/usr/lib/llvm-14/bin/ld.lld")
    if fallback.is_file():
        return fallback
    raise SystemExit("ARM-capable lld is missing")


def build() -> None:
    missing = [
        str(path)
        for path in (ROOTFS, INIT, SHIM, DEVICE_SHIM, KERNEL, KMODS, QEMU)
        if not path.exists()
    ]
    if missing:
        raise SystemExit("missing prerequisites: " + ", ".join(missing))
    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    shutil.copytree(ROOTFS, STAGING, symlinks=True)
    shutil.copytree(KMODS, STAGING / "lib/modules", dirs_exist_ok=True)
    entity = STAGING / "etc/cms_entity_info.d/eid_bcm_base.txt"
    text = entity.read_text()
    text, count = re.subn(
        r"\nBEGIN\n\s+eid\s+= EID_SSK\n.*?\nEND\n", "\n", text, count=1, flags=re.DOTALL
    )
    if count == 1:
        os.chmod(entity, entity.stat().st_mode | 0o200)
        entity.write_text(text)
    shutil.copy2(INIT, STAGING / "init")
    os.chmod(STAGING / "init", 0o755)
    run([
        "openssl", "req", "-x509", "-newkey", "rsa:2048", "-nodes",
        "-subj", "/CN=rax54s-lab", "-days", "2",
        "-keyout", str(STAGING / "etc/rax54s-lab.key"),
        "-out", str(STAGING / "etc/rax54s-lab.crt"),
    ], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    with (STAGING / "etc/rax54s-lab.pem").open("wb") as combined:
        combined.write((STAGING / "etc/rax54s-lab.key").read_bytes())
        combined.write((STAGING / "etc/rax54s-lab.crt").read_bytes())
    # The option parser accepts -E only with these two exact embedded paths.
    # The production boot generates both files in persistent storage.
    shutil.copy2(STAGING / "etc/rax54s-lab.pem", STAGING / "usr/sbin/httpsd.pem")
    shutil.copy2(STAGING / "etc/rax54s-lab.crt", STAGING / "usr/sbin/ca.pem")
    run([
        "clang", "--target=arm-linux-gnueabi", "-march=armv7-a", "-fPIC", "-shared",
        "-nostdlib", f"-fuse-ld={linker()}", "-Wl,-soname,rax54s_emulation_shim.so",
        "-DFRIDAY_TRACE_FATAL",
        "-o", str(STAGING / "lib/rax54s_emulation_shim.so"), str(SHIM),
    ])
    run([
        "clang", "--target=arm-linux-gnueabi", "-march=armv7-a", "-fPIC", "-shared",
        "-nostdlib", f"-fuse-ld={linker()}", "-Wl,-soname,rax54s_device_shim.so",
        "-o", str(STAGING / "lib/rax54s_device_shim.so"), str(DEVICE_SHIM),
    ])
    for relative in ("proc", "sys", "dev", "run", "tmp", "var/run", "var/log", "var/tmp"):
        directory = STAGING / relative
        if directory.is_symlink():
            directory.unlink()
        directory.mkdir(parents=True, exist_ok=True)
    command = (
        f"cd '{STAGING}' && find . -print0 | cpio --null -o --format=newc "
        f"2>/dev/null | gzip -1 > '{INITRAMFS}'"
    )
    subprocess.run(["/bin/sh", "-c", command], check=True)
    print(f"initramfs={INITRAMFS}")


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
    if not INITRAMFS.is_file():
        raise SystemExit("build the initramfs first")
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    forwards = (
        "user,id=lan,restrict=on,"
        f"hostfwd=tcp:127.0.0.1:{HOST_HTTP_PORT}-:{GUEST_HTTP_PORT}"
    )
    if HOST_HTTPS_PORT:
        forwards += f",hostfwd=tcp:127.0.0.1:{HOST_HTTPS_PORT}-:{GUEST_HTTPS_PORT}"
    command = [
        str(QEMU), "-M", "virt", "-cpu", "cortex-a15", "-m", f"{GUEST_MEMORY_MB}M",
        "-kernel", str(KERNEL), "-initrd", str(INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-nographic", "-monitor", "none", "-serial", f"file:{SERIAL}",
        "-netdev",
        forwards,
        "-device", "virtio-net-device,netdev=lan", "-no-reboot",
    ]
    with QEMU_LOG.open("wb") as output:
        process = subprocess.Popen(command, stdout=output, stderr=subprocess.STDOUT)
    PIDFILE.write_text(f"{process.pid}\n")
    print(
        f"qemu_pid={process.pid} "
        f"http=127.0.0.1:{HOST_HTTP_PORT}->guest:{GUEST_HTTP_PORT} "
        f"https=127.0.0.1:{HOST_HTTPS_PORT}->guest:{GUEST_HTTPS_PORT}"
    )


def foreground() -> None:
    if not INITRAMFS.is_file():
        raise SystemExit("build the initramfs first")
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    forwards = (
        "user,id=lan,restrict=on,"
        f"hostfwd=tcp:127.0.0.1:{HOST_HTTP_PORT}-:{GUEST_HTTP_PORT}"
    )
    if HOST_HTTPS_PORT:
        forwards += f",hostfwd=tcp:127.0.0.1:{HOST_HTTPS_PORT}-:{GUEST_HTTPS_PORT}"
    command = [
        str(QEMU), "-M", "virt", "-cpu", "cortex-a15", "-m", f"{GUEST_MEMORY_MB}M",
        "-kernel", str(KERNEL), "-initrd", str(INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-nographic", "-monitor", "none", "-serial", f"file:{SERIAL}",
        "-netdev",
        forwards,
        "-device", "virtio-net-device,netdev=lan", "-no-reboot",
    ]
    print(
        f"qemu_foreground=yes "
        f"http=127.0.0.1:{HOST_HTTP_PORT}->guest:{GUEST_HTTP_PORT} "
        f"https=127.0.0.1:{HOST_HTTPS_PORT}->guest:{GUEST_HTTPS_PORT}",
        flush=True,
    )
    raise SystemExit(subprocess.run(command).returncode)


def wait_ready(timeout: int = 600) -> str:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        text = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if "FRIDAY_RAX54S_HTTP_READY=1" in text:
            return text
        if "Kernel panic" in text:
            raise SystemExit("guest kernel panic")
        time.sleep(0.5)
    raise SystemExit("HTTP readiness timed out; inspect serial.log")


def tls_exchange(payload: bytes, timeout: float = 5) -> bytes:
    context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
    context.check_hostname = False
    context.verify_mode = ssl.CERT_NONE
    context.minimum_version = ssl.TLSVersion.TLSv1
    context.maximum_version = ssl.TLSVersion.TLSv1_2
    context.set_ciphers("ALL:@SECLEVEL=0")
    with socket.create_connection(("127.0.0.1", HOST_HTTPS_PORT), timeout=timeout) as raw:
        with context.wrap_socket(raw, server_hostname="routerlogin.net") as client:
            client.sendall(payload)
            response = bytearray()
            while True:
                chunk = client.recv(4096)
                if not chunk:
                    return bytes(response)
                response.extend(chunk)


def tls_request(timeout: float = 5) -> bytes:
    return tls_exchange(
        b"GET /currentsetting.htm HTTP/1.1\r\n"
        b"Host: routerlogin.net\r\nConnection: close\r\n\r\n",
        timeout,
    )


def soap_request(action: str, body: str) -> bytes:
    encoded = body.encode()
    request = (
        b"POST /soap/server_sa/ HTTP/1.1\r\n"
        b"Host: routerlogin.net\r\n"
        b"X-Forwarded-For: 192.168.1.2\r\n"
        b"Content-Type: text/xml; charset=\"utf-8\"\r\n"
        + f'SOAPAction: "{action}"\r\n'.encode()
        + f"Content-Length: {len(encoded)}\r\n".encode()
        + b"Connection: close\r\n\r\n"
        + encoded
    )
    return tls_exchange(request)


def response_status(response: bytes) -> str:
    return response.splitlines()[0].decode(errors="replace") if response else "empty"


def raw_post(path: bytes, headers: list[tuple[bytes, bytes]], body: bytes) -> bytes:
    request = bytearray(b"POST " + path + b" HTTP/1.1\r\n")
    for name, value in headers:
        request.extend(name + b": " + value + b"\r\n")
    request.extend(b"\r\n")
    request.extend(body)
    return tls_exchange(bytes(request), timeout=10)


def security_probe() -> None:
    wait_ready()
    deadline = time.monotonic() + 90
    while True:
        try:
            control = tls_request()
            if control.startswith(b"HTTP/"):
                break
        except (OSError, ssl.SSLError):
            pass
        if time.monotonic() >= deadline:
            raise SystemExit("stable HTTP control was not established")
        time.sleep(1)

    urn = "urn:NETGEAR-ROUTER:service"
    cases: list[tuple[str, str, str]] = [
        (
            "authenticate",
            f"{urn}:ParentalControl:1#Authenticate",
            f'<m:Authenticate xmlns:m="{urn}:ParentalControl:1"/>',
        ),
        (
            "soap-login",
            f"{urn}:DeviceConfig:1#SOAPLogin",
            f'<m:SOAPLogin xmlns:m="{urn}:DeviceConfig:1"/>',
        ),
        (
            "ntp-marker",
            f"{urn}:DeviceConfig:1#SetNTP",
            f'<m:SetNTP xmlns:m="{urn}:DeviceConfig:1">'
            "<NewNTPServer1>$(echo FRIDAY_RAX30_RCE_MARKER)</NewNTPServer1>"
            "</m:SetNTP>",
        ),
        (
            "firmware-url-marker",
            f"{urn}:DeviceConfig:1#CheckAndDownloadNewFirmware",
            f'<m:CheckAndDownloadNewFirmware xmlns:m="{urn}:DeviceConfig:1">'
            "<NewFirmwareURL>$(echo FRIDAY_RAX30_RCE_MARKER)</NewFirmwareURL>"
            "</m:CheckAndDownloadNewFirmware>",
        ),
        (
            "ookla-marker",
            f"{urn}:AdvancedQoS:1#SetOOKLASpeedTestStart",
            f'<m:SetOOKLASpeedTestStart xmlns:m="{urn}:AdvancedQoS:1">'
            "<NewServerID>$(echo FRIDAY_RAX30_RCE_MARKER)</NewServerID>"
            "</m:SetOOKLASpeedTestStart>",
        ),
    ]
    for size in (
        0, 64, 96, 100, 112, 128, 160, 256, 512, 1024, 2048, 4096, 8192, 16384
    ):
        cases.append(
            (
                f"get-info-padding-{size}",
                f"{urn}:DeviceInfo:1#GetInfo",
                f'<m:GetInfo xmlns:m="{urn}:DeviceInfo:1">'
                + ("A" * size)
                + "</m:GetInfo>",
            )
        )

    marker = "FRIDAY_RAX30_RCE_SINK="
    initial_serial = SERIAL.read_text(errors="replace")
    marker_count = initial_serial.count(marker)
    lines = [f"control_before={response_status(control)}"]
    for name, action, body in cases:
        response = b""
        try:
            response = soap_request(action, body)
            result = response_status(response)
        except (OSError, ssl.SSLError) as error:
            result = f"{type(error).__name__}: {error}"
        time.sleep(0.5)
        healthy = False
        for _ in range(5):
            try:
                healthy = tls_request().startswith(b"HTTP/")
            except (OSError, ssl.SSLError):
                healthy = False
            if healthy:
                break
            time.sleep(1)
        line = (
            f"{name}: response={result!r} bytes={len(response)} "
            f"service_alive={str(healthy).lower()} "
            f"marker_sink={str(SERIAL.read_text(errors='replace').count(marker) > marker_count).lower()}"
        )
        print(line)
        lines.append(line)
        current_marker_count = SERIAL.read_text(errors="replace").count(marker)
        if current_marker_count > marker_count:
            lines.append(f"command_sink_reached_by={name}")
            SECURITY_LOG.write_text("\n".join(lines) + "\n")
            raise SystemExit(3)
        marker_count = current_marker_count
        if not healthy:
            lines.append(f"stopped_after={name}")
            SECURITY_LOG.write_text("\n".join(lines) + "\n")
            raise SystemExit(2)

    base_body = (
        b'<m:GetInfo xmlns:m="urn:NETGEAR-ROUTER:service:DeviceInfo:1">'
        b"</m:GetInfo>"
    )
    base_action = b'"urn:NETGEAR-ROUTER:service:DeviceInfo:1#GetInfo"'
    raw_cases: list[tuple[str, bytes, list[tuple[bytes, bytes]], bytes]] = []
    for size in (256, 1024, 4096, 16384, 65536):
        raw_cases.append(
            (
                f"soapaction-{size}",
                b"/soap/server_sa/",
                [
                    (b"Host", b"routerlogin.net"),
                    (b"SOAPAction", b'"' + (b"A" * size) + b'"'),
                    (b"Content-Length", str(len(base_body)).encode()),
                    (b"Connection", b"close"),
                ],
                base_body,
            )
        )
    for name, header, size in (
        ("host", b"Host", 16384),
        ("forwarded-for", b"X-Forwarded-For", 16384),
    ):
        raw_cases.append(
            (
                f"{name}-{size}",
                b"/soap/server_sa/",
                [
                    (header, b"A" * size),
                    (b"Host", b"routerlogin.net"),
                    (b"SOAPAction", base_action),
                    (b"Content-Length", str(len(base_body)).encode()),
                    (b"Connection", b"close"),
                ],
                base_body,
            )
        )
    raw_cases.extend(
        [
            (
                "path-16384",
                b"/" + (b"A" * 16384),
                [(b"Host", b"routerlogin.net"), (b"Content-Length", b"0"),
                 (b"Connection", b"close")],
                b"",
            ),
            (
                "xml-body-65536",
                b"/soap/server_sa/",
                [(b"Host", b"routerlogin.net"), (b"SOAPAction", base_action),
                 (b"Content-Length", b"65536"), (b"Connection", b"close")],
                b"A" * 65536,
            ),
            (
                "conflicting-content-length",
                b"/soap/server_sa/",
                [(b"Host", b"routerlogin.net"), (b"SOAPAction", base_action),
                 (b"Content-Length", str(len(base_body)).encode()),
                 (b"Content-Length", b"65536"), (b"Connection", b"close")],
                base_body,
            ),
        ]
    )
    for name, path, headers, body in raw_cases:
        response = b""
        try:
            response = raw_post(path, headers, body)
            result = response_status(response)
        except (OSError, ssl.SSLError) as error:
            result = f"{type(error).__name__}: {error}"
        time.sleep(0.5)
        try:
            healthy = tls_request().startswith(b"HTTP/")
        except (OSError, ssl.SSLError):
            healthy = False
        line = (
            f"{name}: response={result!r} bytes={len(response)} "
            f"service_alive={str(healthy).lower()}"
        )
        print(line)
        lines.append(line)
        if not healthy:
            lines.append(f"stopped_after={name}")
            SECURITY_LOG.write_text("\n".join(lines) + "\n")
            raise SystemExit(2)
    lines.append("control_after=pass")
    SECURITY_LOG.write_text("\n".join(lines) + "\n")
    print(f"security_log={SECURITY_LOG}")


def probe() -> None:
    wait_ready()
    deadline = time.monotonic() + 90
    last_error: OSError | None = None
    first_response = b""
    while time.monotonic() < deadline:
        try:
            first_response = tls_request()
            if first_response.startswith(b"HTTP/"):
                break
            last_error = OSError("empty or non-HTTP response")
        except (OSError, ssl.SSLError) as error:
            last_error = error
            time.sleep(1)
    else:
        raise SystemExit(f"TLS readiness failed: {last_error}")

    stable_deadline = time.monotonic() + 60
    first_text = ""
    first_pids: list[str] = []
    primary_pid = ""
    while time.monotonic() < stable_deadline:
        first_text = SERIAL.read_text(errors="replace")
        if "FRIDAY_RAX29_FATAL" in first_text or "HTTPD_EXITED=1" in first_text:
            raise SystemExit("httpd crashed before reaching a stable PID")
        primary_match = re.search(r"^HTTPD_PID=(\d+)$", first_text, re.MULTILINE)
        primary_pid = primary_match.group(1) if primary_match else ""
        first_pids = re.findall(r"HTTPD_HEALTH_PID=(\d+)", first_text)
        if (
            primary_pid
            and len(first_pids) >= 2
            and first_pids[-1] == primary_pid
            and first_pids[-2] == primary_pid
        ):
            break
        time.sleep(1)
    else:
        raise SystemExit("httpd did not reach a stable PID")

    time.sleep(20)
    second_response = tls_request()
    second_text = SERIAL.read_text(errors="replace")
    second_pids = re.findall(r"HTTPD_HEALTH_PID=(\d+)", second_text)
    if (
        "FRIDAY_RAX29_FATAL" in second_text
        or "HTTPD_EXITED=1" in second_text
        or not second_pids
        or not second_response.startswith(b"HTTP/")
        or second_pids[-1] != primary_pid
    ):
        raise SystemExit("httpd did not remain healthy after TLS control traffic")

    def status_line(response: bytes) -> str:
        return response.splitlines()[0].decode(errors="replace") if response else "empty"

    print(
        f"tls_ready=true pid={second_pids[-1]} "
        f"first={status_line(first_response)!r} "
        f"second={status_line(second_response)!r}"
    )


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "action",
        choices=("build", "start", "foreground", "probe", "security", "run", "stop", "status"),
    )
    args = parser.parse_args()
    if args.action in ("build", "security", "run"):
        build()
    if args.action in ("start", "security", "run"):
        start()
    if args.action == "foreground":
        foreground()
    if args.action == "security":
        security_probe()
    if args.action in ("probe", "run"):
        probe()
    if args.action == "stop":
        stop()
    if args.action == "status":
        print(SERIAL.read_text(errors="replace")[-5000:] if SERIAL.exists() else "no serial log")


if __name__ == "__main__":
    main()
