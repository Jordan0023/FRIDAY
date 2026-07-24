#!/usr/bin/env python3
"""Build and run a network-isolated full-system ASUS GS-BE7200 lab."""

from __future__ import annotations

import argparse
import os
import shutil
import socket
import struct
import subprocess
import time
import urllib.parse
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROOTFS = (
    ROOT
    / "known_firmware/extracted/1e0cff6743b3556f"
    / "_FW_GS-BE7200_300610258892.zip.extracted"
    / "_GS-BE7200_3.0.0.6_102_58892-g925ced9_488-gc6395_M7EE.trx.extracted"
    / "squashfs-root"
)
LAB = ROOT / "known_firmware/emulation/ASUS_GS-BE7200/full-system-lab"
INIT = ROOT / "known_firmware/emulation/ASUS_GS-BE7200/full_system_init"
NVRAM_SHIM = ROOT / "known_firmware/emulation/ASUS_GS-BE7200/libnvram-faker.so"
NVRAM = ROOT / "known_firmware/emulation/ASUS_GS-BE7200/nvram.ini"
UPNP_CONFIG = ROOT / "known_firmware/emulation/ASUS_GS-BE7200/miniupnpd-lab.conf"
GENA_CALLBACK = ROOT / "scripts/gs_be7200_gena_callback.py"
GENA_GUEST_PROBE = ROOT / "known_firmware/emulation/ASUS_GS-BE7200/gena_guest_probe"
NETOOL_CAPTURE = ROOT / "known_firmware/emulation/ASUS_GS-BE7200/netool_capture"
BOOT_INIT = ROOT / "known_firmware/emulation/ASUS_GS-BE7200/boot_init"
STAGING = Path("/tmp/friday-gsbe7200-full-system-root")
BOOT_STAGING = Path("/tmp/friday-gsbe7200-boot-initramfs")
KERNEL_TREE = Path("/tmp/friday-arm64-kernel")
KERNEL_VERSION = "5.15.0-186-generic"
KERNEL = KERNEL_TREE / f"boot/vmlinuz-{KERNEL_VERSION}"
MODULES = KERNEL_TREE / f"lib/modules/{KERNEL_VERSION}"
QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-aarch64")
STATIC_BUSYBOX = Path("/tmp/friday-arm64-busybox/bin/busybox")
STRACE_TREE = Path("/tmp/friday-arm64-strace")
DISK = LAB / "gs-be7200-root.ext4"
INITRAMFS = LAB / "gs-be7200-boot.cpio.gz"
SERIAL = LAB / "serial.log"
QEMU_LOG = LAB / "qemu.log"
PIDFILE = LAB / "qemu.pid"
SECURITY_LOG = LAB / "security-probe.log"
EXTENDED_LOG = LAB / "extended-probe.log"
L2_LOG = LAB / "layer2-probe.log"
PREAUTH_ROUTE_LOG = LAB / "preauth-route-probe.log"
PROFILE = LAB / "profile"
HOST_HTTP_PORT = 39_080
HOST_WAN_HTTP_PORT = 39_081
HOST_WAN_MAP_PORT = 40_080
HOST_UPNP_PORT = 39_500
HOST_SSDP_PORT = 39_190
HOST_NATPMP_PORT = 39_351
HOST_INFOSVR_PORT = 39_999
L2_INJECT_PORT = 40_101
L2_EGRESS_PORT = 40_100


def run(command: list[str], **kwargs: object) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, check=True, text=True, **kwargs)


def prepare_tree(enable_l2: bool = False, enable_netool: bool = False) -> None:
    required = (
        ROOTFS, INIT, BOOT_INIT, NVRAM_SHIM, NVRAM, UPNP_CONFIG,
        GENA_CALLBACK, GENA_GUEST_PROBE, NETOOL_CAPTURE,
        KERNEL, MODULES, QEMU, STATIC_BUSYBOX,
        STRACE_TREE / "usr/bin/strace",
    )
    missing = [str(path) for path in required if not path.exists()]
    if missing:
        raise SystemExit("missing prerequisites: " + ", ".join(missing))
    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    shutil.copytree(ROOTFS, STAGING, symlinks=True)

    for relative in ("proc", "sys", "dev", "run"):
        target = STAGING / relative
        if target.is_symlink():
            target.unlink()
        target.mkdir(parents=True, exist_ok=True)
    tmp = STAGING / "tmp"
    if tmp.is_symlink():
        tmp.unlink()
    tmp.mkdir(parents=True, exist_ok=True)

    shutil.copytree(MODULES, STAGING / f"lib/modules/{KERNEL_VERSION}", symlinks=True)
    shutil.copy2(INIT, STAGING / "init")
    os.chmod(STAGING / "init", 0o755)
    (STAGING / "greenhouse").mkdir(exist_ok=True)
    shutil.copy2(STATIC_BUSYBOX, STAGING / "greenhouse/busybox")
    (STAGING / "glibc").mkdir(exist_ok=True)
    shutil.copy2(STRACE_TREE / "usr/bin/strace", STAGING / "glibc/strace")
    for library in (STRACE_TREE / "lib/aarch64-linux-gnu").iterdir():
        if library.is_file() or library.is_symlink():
            shutil.copy2(library, STAGING / "glibc", follow_symlinks=False)
    shutil.copy2(NVRAM_SHIM, STAGING / "lib/libnvram-faker.so")
    shutil.copy2(NVRAM, STAGING / "gh_nvram.ini")
    (STAGING / "gh_nvram").mkdir(mode=0o777, exist_ok=True)
    shutil.copy2(UPNP_CONFIG, STAGING / "miniupnpd-lab.conf")
    shutil.copy2(GENA_GUEST_PROBE, STAGING / "gena_guest_probe")
    os.chmod(STAGING / "gena_guest_probe", 0o755)
    shutil.copy2(NETOOL_CAPTURE, STAGING / "netool_capture")
    os.chmod(STAGING / "netool_capture", 0o755)
    lldpcli_link = STAGING / "sbin/lldpcli"
    lldpcli_link.unlink(missing_ok=True)
    lldpcli_link.symlink_to("../usr/sbin/lldpcli")
    if enable_l2:
        (STAGING / "enable-lldpd").touch()
    if enable_netool:
        (STAGING / "enable-real-netool").touch()


def build(enable_l2: bool = False, enable_netool: bool = False) -> None:
    prepare_tree(enable_l2=enable_l2, enable_netool=enable_netool)
    DISK.unlink(missing_ok=True)
    run(["truncate", "-s", "1600M", str(DISK)])
    run(["mkfs.ext4", "-q", "-F", "-d", str(STAGING), str(DISK)])
    shutil.rmtree(BOOT_STAGING, ignore_errors=True)
    (BOOT_STAGING / "bin").mkdir(parents=True)
    (BOOT_STAGING / "dev").mkdir()
    (BOOT_STAGING / "proc").mkdir()
    (BOOT_STAGING / "sys").mkdir()
    (BOOT_STAGING / "newroot").mkdir()
    shutil.copy2(STATIC_BUSYBOX, BOOT_STAGING / "bin/busybox")
    shutil.copy2(BOOT_INIT, BOOT_STAGING / "init")
    os.chmod(BOOT_STAGING / "init", 0o755)
    shutil.copy2(
        MODULES / "kernel/drivers/block/virtio_blk.ko",
        BOOT_STAGING / "virtio_blk.ko",
    )
    command = (
        f"cd '{BOOT_STAGING}' && find . -print0 | cpio --null -o --format=newc "
        f"2>/dev/null | gzip -1 > '{INITRAMFS}'"
    )
    subprocess.run(["/bin/sh", "-c", command], check=True)
    profile = "layer2" if enable_l2 else "netool" if enable_netool else "http"
    PROFILE.write_text(profile + "\n")
    print(f"disk={DISK}")
    print(f"kernel={KERNEL}")
    print(f"initramfs={INITRAMFS}")


def stop() -> None:
    if PIDFILE.exists():
        try:
            pid = int(PIDFILE.read_text())
            cmdline = Path(f"/proc/{pid}/cmdline")
            if cmdline.exists() and b"qemu-system-aarch64" in cmdline.read_bytes():
                os.kill(pid, 15)
        except (ValueError, ProcessLookupError, PermissionError):
            pass
        PIDFILE.unlink(missing_ok=True)


def qemu_command() -> list[str]:
    lan = (
        "user,id=lan,restrict=on,net=10.0.2.0/24,"
        f"hostfwd=tcp:127.0.0.1:{HOST_HTTP_PORT}-10.0.2.15:80,"
        f"hostfwd=tcp:127.0.0.1:{HOST_UPNP_PORT}-10.0.2.15:5000,"
        f"hostfwd=udp:127.0.0.1:{HOST_SSDP_PORT}-10.0.2.15:1900,"
        f"hostfwd=udp:127.0.0.1:{HOST_NATPMP_PORT}-10.0.2.15:5351,"
        f"hostfwd=udp:127.0.0.1:{HOST_INFOSVR_PORT}-10.0.2.15:9999,"
        f"guestfwd=tcp:10.0.2.100:49152-cmd:{GENA_CALLBACK}"
    )
    wan = (
        "user,id=wan,restrict=on,ipv4=on,net=192.0.2.0/24,"
        "ipv6=on,ipv6-net=fd00:2::/64,"
        f"hostfwd=tcp:127.0.0.1:{HOST_WAN_HTTP_PORT}-192.0.2.15:80,"
        f"hostfwd=tcp:127.0.0.1:{HOST_WAN_MAP_PORT}-192.0.2.15:40080"
    )
    l2 = (
        f"socket,id=l2,udp=127.0.0.1:{L2_EGRESS_PORT},"
        f"localaddr=127.0.0.1:{L2_INJECT_PORT}"
    )
    command = [
        str(QEMU),
        "-M", "virt",
        "-cpu", "cortex-a72",
        "-smp", "2",
        "-m", "2048M",
        "-kernel", str(KERNEL),
        "-initrd", str(INITRAMFS),
        "-drive", f"file={DISK},if=none,format=raw,id=root",
        "-device", "virtio-blk-device,drive=root",
        "-append",
        "console=ttyAMA0 root=/dev/vda rw rootwait init=/init panic=-1",
        "-nographic",
        "-monitor", "none",
        "-serial", f"file:{SERIAL}",
        "-netdev", lan,
        "-device", "virtio-net-device,netdev=lan,mac=52:54:00:72:00:01",
        "-netdev", wan,
        "-device", "virtio-net-device,netdev=wan,mac=52:54:00:72:00:02",
    ]
    if PROFILE.is_file() and PROFILE.read_text().strip() == "layer2":
        command.extend([
            "-netdev", l2,
            "-device", "virtio-net-device,netdev=l2,mac=52:54:00:72:00:03",
        ])
    command.append("-no-reboot")
    return command


def start() -> None:
    if not DISK.is_file():
        raise SystemExit("build the lab first")
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    with QEMU_LOG.open("wb") as output:
        process = subprocess.Popen(qemu_command(), stdout=output, stderr=subprocess.STDOUT)
    PIDFILE.write_text(f"{process.pid}\n")
    print(
        f"qemu_pid={process.pid} "
        f"http=127.0.0.1:{HOST_HTTP_PORT} "
        f"wan_http=127.0.0.1:{HOST_WAN_HTTP_PORT} "
        f"upnp_http=127.0.0.1:{HOST_UPNP_PORT}"
    )


def foreground() -> None:
    if not DISK.is_file() or not INITRAMFS.is_file():
        raise SystemExit("build the lab first")
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    print(
        f"qemu_foreground=yes "
        f"http=127.0.0.1:{HOST_HTTP_PORT} "
        f"wan_http=127.0.0.1:{HOST_WAN_HTTP_PORT} "
        f"upnp_http=127.0.0.1:{HOST_UPNP_PORT}",
        flush=True,
    )
    raise SystemExit(subprocess.run(qemu_command()).returncode)


def wait_ready(timeout: int = 240) -> str:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        text = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if "FRIDAY_GSBE7200_READY=1" in text:
            return text
        if "Kernel panic" in text:
            raise SystemExit("guest kernel panic; inspect serial.log")
        time.sleep(0.5)
    raise SystemExit("guest readiness timed out; inspect serial.log")


def http_exchange(port: int, payload: bytes, timeout: float = 5) -> bytes:
    with socket.create_connection(("127.0.0.1", port), timeout=timeout) as client:
        client.sendall(payload)
        client.shutdown(socket.SHUT_WR)
        response = bytearray()
        while True:
            chunk = client.recv(4096)
            if not chunk:
                return bytes(response)
            response.extend(chunk)


def udp_exchange(port: int, payload: bytes, timeout: float = 2) -> bytes:
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client:
        client.settimeout(timeout)
        client.sendto(payload, ("127.0.0.1", port))
        try:
            response, _ = client.recvfrom(65_535)
            return response
        except socket.timeout:
            return b""


def control() -> None:
    wait_ready()
    for name, port, path in (
        ("httpd", HOST_HTTP_PORT, b"/Main_Login.asp"),
        ("miniupnpd", HOST_UPNP_PORT, b"/rootDesc.xml"),
    ):
        try:
            response = http_exchange(
                port,
                b"GET " + path + b" HTTP/1.1\r\n"
                b"Host: 10.0.2.15\r\nConnection: close\r\n\r\n",
            )
            status = response.splitlines()[0].decode(errors="replace") if response else "empty"
            print(f"{name}_control={status} bytes={len(response)}")
        except OSError as error:
            print(f"{name}_control={type(error).__name__}:{error}")
    text = SERIAL.read_text(errors="replace")
    health = [line for line in text.splitlines() if "FRIDAY_GSBE7200_" in line]
    print("\n".join(health[-20:]))


def status_line(response: bytes) -> str:
    return response.splitlines()[0].decode(errors="replace") if response else "empty"


def service_alive(port: int, path: bytes) -> bool:
    try:
        response = http_exchange(
            port,
            b"GET " + path + b" HTTP/1.1\r\n"
            b"Host: 10.0.2.15\r\nConnection: close\r\n\r\n",
            timeout=4,
        )
        return response.startswith(b"HTTP/")
    except OSError:
        return False


def security_probe() -> None:
    wait_ready()
    if not service_alive(HOST_HTTP_PORT, b"/Main_Login.asp"):
        raise SystemExit("httpd control is not healthy")
    if not service_alive(HOST_UPNP_PORT, b"/rootDesc.xml"):
        raise SystemExit("miniupnpd control is not healthy")

    results = [
        "scope=localhost-only QEMU full-system lab",
        "httpd_control_before=alive",
        "miniupnpd_control_before=alive",
    ]

    http_cases: list[tuple[str, bytes]] = []
    for route in (
        b"/QIS_default.cgi",
        b"/cfg_onboarding.cgi",
        b"/check_Auth.cgi",
        b"/findasus.cgi",
        b"/apply.cgi",
        b"/netool.cgi",
    ):
        http_cases.append(
            (
                "get-" + route[1:].decode(),
                b"GET " + route + b" HTTP/1.1\r\n"
                b"Host: 10.0.2.15\r\nConnection: close\r\n\r\n",
            )
        )

    marker_body = urllib.parse.urlencode(
        {
            "current_page": "Main_Analysis_Content.asp",
            "action_mode": " Refresh ",
            "SystemCmd": "echo FRIDAY_GSBE7200_RCE_MARKER >/tmp/FRIDAY_GSBE7200_RCE_MARKER",
        }
    ).encode()
    http_cases.append(
        (
            "unauth-systemcmd-canary",
            b"POST /apply.cgi HTTP/1.1\r\n"
            b"Host: 10.0.2.15\r\n"
            b"Content-Type: application/x-www-form-urlencoded\r\n"
            + f"Content-Length: {len(marker_body)}\r\n".encode()
            + b"Connection: close\r\n\r\n"
            + marker_body,
        )
    )
    for size in (256, 1024, 4096, 16384, 65536):
        http_cases.append(
            (
                f"host-{size}",
                b"GET /Main_Login.asp HTTP/1.1\r\nHost: "
                + (b"A" * size)
                + b"\r\nConnection: close\r\n\r\n",
            )
        )
    for size in (1024, 4096, 16384):
        http_cases.append(
            (
                f"path-{size}",
                b"GET /"
                + (b"A" * size)
                + b" HTTP/1.1\r\nHost: 10.0.2.15\r\nConnection: close\r\n\r\n",
            )
        )
    http_cases.extend(
        [
            (
                "duplicate-content-length",
                b"POST /login.cgi HTTP/1.1\r\nHost: 10.0.2.15\r\n"
                b"Content-Length: 0\r\nContent-Length: 65535\r\n"
                b"Connection: close\r\n\r\n",
            ),
            (
                "negative-content-length",
                b"POST /login.cgi HTTP/1.1\r\nHost: 10.0.2.15\r\n"
                b"Content-Length: -1\r\nConnection: close\r\n\r\n",
            ),
        ]
    )

    for name, request in http_cases:
        try:
            response = http_exchange(HOST_HTTP_PORT, request, timeout=8)
            outcome = status_line(response)
        except OSError as error:
            response = b""
            outcome = f"{type(error).__name__}:{error}"
        time.sleep(0.25)
        alive = service_alive(HOST_HTTP_PORT, b"/Main_Login.asp")
        line = (
            f"http:{name}: response={outcome!r} bytes={len(response)} "
            f"service_alive={str(alive).lower()}"
        )
        print(line)
        results.append(line)
        if not alive:
            results.append(f"httpd_stopped_after={name}")
            SECURITY_LOG.write_text("\n".join(results) + "\n")
            raise SystemExit(2)

    upnp_cases: list[tuple[str, bytes]] = []
    callbacks = [
        ("rax30-shape", b"http://10.0.2.2/FRIDAY_RAX30_PROBE_7b6f2a" + b"A" * 32),
        ("callback-256", b"http://10.0.2.2/" + b"A" * 236),
        ("callback-1024", b"http://10.0.2.2/" + b"A" * 1004),
        ("callback-4096", b"http://10.0.2.2/" + b"A" * 4076),
        ("callback-16384", b"http://10.0.2.2/" + b"A" * 16364),
    ]
    for name, callback in callbacks:
        upnp_cases.append(
            (
                name,
                b"SUBSCRIBE /evt/IPConn HTTP/1.1\r\n"
                b"Host: 10.0.2.15:5000\r\n"
                b"CALLBACK: <" + callback + b">\r\n"
                b"NT: upnp:event\r\n"
                b"TIMEOUT: Second-1800\r\n"
                b"Connection: close\r\n\r\n",
            )
        )
    for header, size in ((b"SID", 4096), (b"TIMEOUT", 4096), (b"NT", 4096)):
        upnp_cases.append(
            (
                header.decode().lower() + f"-{size}",
                b"SUBSCRIBE /evt/IPConn HTTP/1.1\r\n"
                b"Host: 10.0.2.15:5000\r\n"
                + header + b": " + (b"A" * size) + b"\r\n"
                b"Connection: close\r\n\r\n",
            )
        )
    soap_body = (
        b'<?xml version="1.0"?>'
        b'<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
        b"<s:Body><u:AddPortMapping "
        b'xmlns:u="urn:schemas-upnp-org:service:WANIPConnection:1">'
        b"<NewRemoteHost></NewRemoteHost><NewExternalPort>45678</NewExternalPort>"
        b"<NewProtocol>TCP</NewProtocol><NewInternalPort>45678</NewInternalPort>"
        b"<NewInternalClient>10.0.2.2</NewInternalClient><NewEnabled>1</NewEnabled>"
        b"<NewPortMappingDescription>$(touch /tmp/FRIDAY_GSBE7200_RCE_MARKER)"
        b"</NewPortMappingDescription><NewLeaseDuration>60</NewLeaseDuration>"
        b"</u:AddPortMapping></s:Body></s:Envelope>"
    )
    upnp_cases.append(
        (
            "soap-description-canary",
            b"POST /ctl/IPConn HTTP/1.1\r\n"
            b"Host: 10.0.2.15:5000\r\n"
            b'SOAPAction: "urn:schemas-upnp-org:service:WANIPConnection:1#AddPortMapping"\r\n'
            b"Content-Type: text/xml\r\n"
            + f"Content-Length: {len(soap_body)}\r\n".encode()
            + b"Connection: close\r\n\r\n"
            + soap_body,
        )
    )

    for name, request in upnp_cases:
        try:
            response = http_exchange(HOST_UPNP_PORT, request, timeout=8)
            outcome = status_line(response)
        except OSError as error:
            response = b""
            outcome = f"{type(error).__name__}:{error}"
        time.sleep(0.25)
        alive = service_alive(HOST_UPNP_PORT, b"/rootDesc.xml")
        line = (
            f"upnp:{name}: response={outcome!r} bytes={len(response)} "
            f"service_alive={str(alive).lower()}"
        )
        print(line)
        results.append(line)
        if not alive:
            results.append(f"miniupnpd_stopped_after={name}")
            SECURITY_LOG.write_text("\n".join(results) + "\n")
            raise SystemExit(3)

    time.sleep(11)
    serial = SERIAL.read_text(errors="replace")
    marker = "FRIDAY_GSBE7200_RCE_MARKER=present" in serial
    results.append(f"command_marker_present={str(marker).lower()}")
    results.append(
        f"httpd_control_after={str(service_alive(HOST_HTTP_PORT, b'/Main_Login.asp')).lower()}"
    )
    results.append(
        f"miniupnpd_control_after={str(service_alive(HOST_UPNP_PORT, b'/rootDesc.xml')).lower()}"
    )
    SECURITY_LOG.write_text("\n".join(results) + "\n")
    print("\n".join(results[-3:]))
    if marker:
        raise SystemExit(4)


def extended_probe() -> None:
    wait_ready()
    if not service_alive(HOST_UPNP_PORT, b"/rootDesc.xml"):
        raise SystemExit("miniupnpd control is not healthy")

    results = [
        "scope=localhost-only QEMU full-system lab",
        "limits=bounded protocol-aware cases; no flooding",
        "miniupnpd_control_before=alive",
    ]

    def record(family: str, name: str, response: bytes) -> None:
        alive = service_alive(HOST_UPNP_PORT, b"/rootDesc.xml")
        line = (
            f"{family}:{name}: bytes={len(response)} "
            f"prefix={response[:48].hex()} service_alive={str(alive).lower()}"
        )
        print(line)
        results.append(line)
        if not alive:
            EXTENDED_LOG.write_text("\n".join(results) + "\n")
            raise SystemExit(5)

    ssdp_cases = (
        (
            "rootdevice",
            b"M-SEARCH * HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\n"
            b'MAN: "ssdp:discover"\r\nMX: 1\r\n'
            b"ST: upnp:rootdevice\r\n\r\n",
        ),
        (
            "ssdp-all",
            b"M-SEARCH * HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\n"
            b'MAN: "ssdp:discover"\r\nMX: 1\r\nST: ssdp:all\r\n\r\n',
        ),
        (
            "duplicate-st",
            b"M-SEARCH * HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\n"
            b'MAN: "ssdp:discover"\r\nMX: 1\r\nST: ssdp:all\r\n'
            b"ST: upnp:rootdevice\r\n\r\n",
        ),
        (
            "oversize-st-4096",
            b"M-SEARCH * HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\n"
            b'MAN: "ssdp:discover"\r\nMX: 1\r\nST: ' + b"A" * 4096 + b"\r\n\r\n",
        ),
        ("binary-1024", bytes(range(256)) * 4),
    )
    for name, request in ssdp_cases:
        response = udp_exchange(HOST_SSDP_PORT, request)
        time.sleep(0.3)
        record("ssdp", name, response)

    subscribe = (
        b"SUBSCRIBE /evt/IPConn HTTP/1.1\r\nHost: 10.0.2.15:5000\r\n"
        b"CALLBACK: <http://10.0.2.100:49152/friday-event>\r\n"
        b"NT: upnp:event\r\nTIMEOUT: Second-60\r\nConnection: close\r\n\r\n"
    )
    first = http_exchange(HOST_UPNP_PORT, subscribe, timeout=8)
    headers = {}
    for line in first.split(b"\r\n")[1:]:
        if b":" in line:
            key, value = line.split(b":", 1)
            headers[key.strip().lower()] = value.strip()
    sid = headers.get(b"sid", b"")
    record("gena", "subscribe-new", first)

    gena_cases = [
        (
            "renew-valid",
            b"SUBSCRIBE /evt/IPConn HTTP/1.1\r\nHost: 10.0.2.15:5000\r\n"
            b"SID: " + sid + b"\r\nTIMEOUT: Second-120\r\nConnection: close\r\n\r\n",
        ),
        (
            "renew-mixed-new-and-sid",
            b"SUBSCRIBE /evt/IPConn HTTP/1.1\r\nHost: 10.0.2.15:5000\r\n"
            b"SID: " + sid + b"\r\nCALLBACK: <http://10.0.2.2/x>\r\n"
            b"NT: upnp:event\r\nConnection: close\r\n\r\n",
        ),
        (
            "unsubscribe-unknown",
            b"UNSUBSCRIBE /evt/IPConn HTTP/1.1\r\nHost: 10.0.2.15:5000\r\n"
            b"SID: uuid:00000000-0000-0000-0000-000000000000\r\n"
            b"Connection: close\r\n\r\n",
        ),
        (
            "unsubscribe-valid",
            b"UNSUBSCRIBE /evt/IPConn HTTP/1.1\r\nHost: 10.0.2.15:5000\r\n"
            b"SID: " + sid + b"\r\nConnection: close\r\n\r\n",
        ),
        (
            "renew-after-delete",
            b"SUBSCRIBE /evt/IPConn HTTP/1.1\r\nHost: 10.0.2.15:5000\r\n"
            b"SID: " + sid + b"\r\nTIMEOUT: Second-60\r\nConnection: close\r\n\r\n",
        ),
    ]
    for name, request in gena_cases:
        response = http_exchange(HOST_UPNP_PORT, request, timeout=8)
        time.sleep(0.3)
        record("gena", name, response)

    natpmp_cases = (
        ("public-address", b"\x00\x00"),
        ("tcp-map-zero", struct.pack("!BBHHHI", 0, 2, 0, 0, 0, 60)),
        ("udp-map-high", struct.pack("!BBHHHI", 0, 1, 0, 65_535, 65_535, 60)),
        ("unsupported-version", b"\xff\x00"),
        ("truncated-map", b"\x00\x01\x00"),
        ("oversize-1024", b"\x00\x01" + b"A" * 1022),
    )
    for name, request in natpmp_cases:
        response = udp_exchange(HOST_NATPMP_PORT, request)
        time.sleep(0.3)
        record("natpmp", name, response)

    pcp_client_ip = b"\x00" * 10 + b"\xff\xff" + socket.inet_aton("10.0.2.2")
    pcp_nonce = b"FRIDAYPCP001"
    pcp_map = (
        b"\x02\x01\x00\x00" + struct.pack("!I", 60) + pcp_client_ip
        + pcp_nonce + b"\x06\x00\x00\x00" + struct.pack("!H", 45_678)
        + struct.pack("!H", 0) + b"\x00" * 16
    )
    pcp_cases = (
        ("announce", b"\x02\x00\x00\x00" + struct.pack("!I", 0) + pcp_client_ip),
        ("map-tcp", pcp_map),
        ("unsupported-version", b"\xff\x00" + b"\x00" * 22),
        ("truncated", b"\x02\x01\x00"),
        ("option-truncated", pcp_map + b"\x01\x00\x00\x10AB"),
        ("oversize-1024", pcp_map + b"A" * (1024 - len(pcp_map))),
    )
    for name, request in pcp_cases:
        response = udp_exchange(HOST_NATPMP_PORT, request)
        time.sleep(0.3)
        record("pcp", name, response)

    def infosvr_packet(opcode: int, service: int = 12, packet_type: int = 21) -> bytearray:
        packet = bytearray(512)
        packet[:8] = struct.pack("<BBHI", service, packet_type, opcode, 0x46524944)
        packet[8:14] = b"FRIDAY"
        return packet

    getinfo = bytes(infosvr_packet(31))
    command = infosvr_packet(51)
    command_body = b"echo FRIDAY_GSBE7200_RCE_MARKER >/tmp/FRIDAY_GSBE7200_RCE_MARKER"
    command[46:48] = struct.pack("<H", len(command_body))
    command[48:48 + len(command_body)] = command_body

    infosvr_cases: list[tuple[str, bytes]] = [
        ("getinfo", getinfo),
        ("historical-opcode-51-canary", bytes(command)),
    ]
    for size in (0, 1, 2, 3, 4, 7, 8, 9, 45, 46, 47, 48, 127, 255, 511):
        infosvr_cases.append((f"truncated-{size}", b"A" * size))
    for opcode in (*range(29, 56), 0xFFFF):
        infosvr_cases.append((f"opcode-{opcode}", bytes(infosvr_packet(opcode))))
    for declared in (0, 1, 255, 256, 419, 420, 421, 463, 464, 465, 0xFFFF):
        packet = infosvr_packet(51)
        packet[46:48] = struct.pack("<H", declared)
        packet[48:] = b":" * (512 - 48)
        infosvr_cases.append((f"command-length-{declared}", bytes(packet)))
    for service, packet_type in ((0, 0), (12, 0), (0, 21), (12, 21), (255, 255)):
        infosvr_cases.append(
            (
                f"header-{service}-{packet_type}",
                bytes(infosvr_packet(31, service, packet_type)),
            )
        )
    for name, request in infosvr_cases:
        response = udp_exchange(HOST_INFOSVR_PORT, request, timeout=0.5)
        serial = SERIAL.read_text(errors="replace")
        alive = "infosvr=dead" not in serial.split("FRIDAY_GSBE7200_READY=1")[-1]
        line = (
            f"infosvr:{name}: bytes={len(response)} prefix={response[:48].hex()} "
            f"process_alive={str(alive).lower()}"
        )
        print(line)
        results.append(line)
        if not alive:
            EXTENDED_LOG.write_text("\n".join(results) + "\n")
            raise SystemExit(6)
        time.sleep(0.3)

    time.sleep(11)
    serial = SERIAL.read_text(errors="replace")
    marker = "FRIDAY_GSBE7200_RCE_MARKER=present" in serial
    results.append(
        f"miniupnpd_control_after={str(service_alive(HOST_UPNP_PORT, b'/rootDesc.xml')).lower()}"
    )
    results.append(
        "infosvr_health_after="
        + ("dead" if "infosvr=dead" in serial.split("FRIDAY_GSBE7200_READY=1")[-1] else "alive")
    )
    results.append(f"command_marker_present={str(marker).lower()}")
    EXTENDED_LOG.write_text("\n".join(results) + "\n")
    print("\n".join(results[-3:]))
    if marker:
        raise SystemExit(7)


def lldp_tlv(tlv_type: int, value: bytes) -> bytes:
    if not 0 <= tlv_type <= 127 or len(value) > 511:
        raise ValueError("invalid LLDP TLV")
    return struct.pack("!H", (tlv_type << 9) | len(value)) + value


def ethernet(destination: bytes, ethertype: int, payload: bytes) -> bytes:
    source = bytes.fromhex("020000000001")
    return destination + source + struct.pack("!H", ethertype) + payload


def cdp_checksum(data: bytes) -> int:
    if len(data) % 2:
        data += b"\x00"
    total = sum(struct.unpack(f"!{len(data) // 2}H", data))
    total = (total & 0xFFFF) + (total >> 16)
    total = (total & 0xFFFF) + (total >> 16)
    return (~total) & 0xFFFF


def layer2_probe() -> None:
    wait_ready()
    serial = SERIAL.read_text(errors="replace")
    if "FRIDAY_GSBE7200_LLDPD_READY=1" not in serial:
        raise SystemExit("lldpd control is not healthy")

    lldp_dst = bytes.fromhex("0180c200000e")
    chassis = lldp_tlv(1, b"\x04" + bytes.fromhex("020000000001"))
    port = lldp_tlv(2, b"\x05eth-test")
    ttl = lldp_tlv(3, struct.pack("!H", 120))
    end = b"\x00\x00"
    valid = chassis + port + ttl + end

    cases: list[tuple[str, bytes]] = [
        ("lldp-valid", ethernet(lldp_dst, 0x88CC, valid)),
        ("ethernet-short-13", b"A" * 13),
        ("lldp-empty", ethernet(lldp_dst, 0x88CC, b"")),
        ("lldp-one-byte-header", ethernet(lldp_dst, 0x88CC, b"\x02")),
        ("lldp-claimed-511-short", ethernet(lldp_dst, 0x88CC, b"\x03\xffA")),
        ("lldp-missing-mandatory", ethernet(lldp_dst, 0x88CC, end)),
        ("lldp-no-end", ethernet(lldp_dst, 0x88CC, chassis + port + ttl)),
        ("lldp-port-empty", ethernet(lldp_dst, 0x88CC, chassis + lldp_tlv(2, b"") + ttl + end)),
        ("lldp-ttl-short", ethernet(lldp_dst, 0x88CC, chassis + port + lldp_tlv(3, b"\x01") + end)),
        ("lldp-ttl-long", ethernet(lldp_dst, 0x88CC, chassis + port + lldp_tlv(3, b"\x00xAA") + end)),
        ("lldp-capabilities-short", ethernet(lldp_dst, 0x88CC, valid[:-2] + lldp_tlv(7, b"\x01") + end)),
        ("lldp-management-short", ethernet(lldp_dst, 0x88CC, valid[:-2] + lldp_tlv(8, b"\x01") + end)),
        ("lldp-org-short", ethernet(lldp_dst, 0x88CC, valid[:-2] + lldp_tlv(127, b"\x00\x12") + end)),
        ("lldp-unknown-max", ethernet(lldp_dst, 0x88CC, valid[:-2] + lldp_tlv(126, b"A" * 511) + end)),
        ("lldp-system-name-511", ethernet(lldp_dst, 0x88CC, valid[:-2] + lldp_tlv(5, b"N" * 511) + end)),
        ("lldp-duplicate-mandatory", ethernet(lldp_dst, 0x88CC, chassis + chassis + port + ttl + end)),
        ("lldp-wrong-destination", ethernet(bytes.fromhex("ffffffffffff"), 0x88CC, valid)),
        ("lldp-jumbo-4096", ethernet(lldp_dst, 0x88CC, valid + b"J" * (4096 - 14 - len(valid)))),
        ("lldp-valid-after-malformed", ethernet(lldp_dst, 0x88CC, valid)),
    ]

    def cdp_frame(tlvs: bytes, version: int = 2, declared_adjust: int = 0) -> bytes:
        body = bytes((version, 180, 0, 0)) + tlvs
        checksum = cdp_checksum(body)
        body = body[:2] + struct.pack("!H", checksum) + body[4:]
        llc = bytes.fromhex("aaaa0300000c2000")
        length = len(llc) + len(body) + declared_adjust
        return (
            bytes.fromhex("01000ccccccc020000000001")
            + struct.pack("!H", length & 0xFFFF)
            + llc + body
        )

    device = struct.pack("!HH", 1, 10) + b"FRIDAY"
    cdp_port = struct.pack("!HH", 3, 8) + b"eth2"
    cases.extend(
        [
            ("cdp-valid-minimal", cdp_frame(device + cdp_port)),
            ("cdp-short", bytes.fromhex("01000ccccccc0200000000010001") + b"A"),
            ("cdp-version-zero", cdp_frame(device + cdp_port, version=0)),
            ("cdp-size-underflow", cdp_frame(device + cdp_port, declared_adjust=-4)),
            ("cdp-size-overflow", cdp_frame(device + cdp_port, declared_adjust=64)),
            ("cdp-tlv-length-zero", cdp_frame(struct.pack("!HH", 1, 0))),
            ("cdp-tlv-length-three", cdp_frame(struct.pack("!HH", 1, 3))),
            ("cdp-tlv-length-ffff", cdp_frame(struct.pack("!HH", 1, 0xFFFF) + b"A")),
            ("cdp-address-short", cdp_frame(struct.pack("!HH", 2, 5) + b"\x00")),
            ("cdp-native-vlan-short", cdp_frame(struct.pack("!HH", 10, 5) + b"\x00")),
            ("lldp-valid-final", ethernet(lldp_dst, 0x88CC, valid)),
        ]
    )

    results = [
        "scope=localhost-only QEMU socket-netdev Ethernet injection",
        f"case_count={len(cases)}",
        "lldpd_control_before=alive",
    ]
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as injector:
        for name, frame in cases:
            injector.sendto(frame, ("127.0.0.1", L2_INJECT_PORT))
            time.sleep(0.2)
            current = SERIAL.read_text(errors="replace")
            alive = "lldpd=dead" not in current.split("FRIDAY_GSBE7200_READY=1")[-1]
            line = f"layer2:{name}: bytes={len(frame)} lldpd_alive={str(alive).lower()}"
            print(line)
            results.append(line)
            if not alive:
                L2_LOG.write_text("\n".join(results) + "\n")
                raise SystemExit(8)

    time.sleep(11)
    current = SERIAL.read_text(errors="replace")
    alive = "lldpd=dead" not in current.split("FRIDAY_GSBE7200_READY=1")[-1]
    results.append(f"lldpd_control_after={str(alive).lower()}")
    L2_LOG.write_text("\n".join(results) + "\n")
    print(results[-1])
    if not alive:
        raise SystemExit(9)


def preauth_route_probe() -> None:
    wait_ready()
    if not service_alive(HOST_HTTP_PORT, b"/Main_Login.asp"):
        raise SystemExit("httpd control is not healthy")

    values = (
        ("local-control", "QIS_wizard.htm?flag=welcome"),
        ("scheme-relative", "//friday.invalid/path"),
        ("backslash-authority", "\\\\friday.invalid/path"),
        ("single-quote-script", "';FRIDAY_XSS_CANARY;//"),
        ("double-quote", '"FRIDAY_XSS_CANARY'),
        ("javascript-scheme", "javascript:FRIDAY_XSS_CANARY"),
        ("encoded-crlf", "\r\nFRIDAY_XSS_CANARY"),
        ("length-127", "A" * 127),
        ("length-128", "A" * 128),
        ("length-512", "A" * 512),
    )
    cases: list[tuple[str, bytes, str]] = []
    for name, value in values:
        query = urllib.parse.urlencode({"url": value})
        cases.append(
            (
                "page-default-" + name,
                f"/page_default.cgi?{query}".encode(),
                value,
            )
        )
    for name, value in values[:7]:
        query = urllib.parse.urlencode({"flag": value})
        cases.append(
            (
                "qis-default-" + name,
                f"/QIS_default.cgi?{query}".encode(),
                value,
            )
        )
    for route in (
        "/cfg_onboarding.cgi", "/findasus.cgi", "/check_Auth.cgi",
        "/apply.cgi", "/netool.cgi", "/appGet.cgi",
    ):
        cases.append(("auth-gate-" + route[1:-4], route.encode(), ""))
    for route in (
        "/get_IFTTTtoken.cgi",
        "/enable_ig_guest.cgi",
        "/get_eptoken.cgi",
        "/asusrouter_request_token.cgi",
        "/asusrouter_request_access_token.cgi",
        "/endpoint_request_token.cgi",
    ):
        cases.append(("token-empty-" + route[1:-4], route.encode(), ""))

    results = [
        "scope=localhost-only QEMU full-system lab",
        "httpd_control_before=alive",
        f"case_count={len(cases)}",
    ]
    for name, path, supplied in cases:
        try:
            response = http_exchange(
                HOST_HTTP_PORT,
                b"GET " + path + b" HTTP/1.1\r\n"
                b"Host: 10.0.2.15\r\nConnection: close\r\n\r\n",
                timeout=12,
            )
            outcome = status_line(response)
        except OSError as error:
            response = b""
            outcome = f"{type(error).__name__}:{error}"
        body = response.split(b"\r\n\r\n", 1)[-1].decode(errors="replace")
        normalized = body.replace("\r", "\\r").replace("\n", "\\n")
        alive = service_alive(HOST_HTTP_PORT, b"/Main_Login.asp")
        reflected = bool(supplied) and supplied in body
        canary = "FRIDAY_XSS_CANARY" in body
        line = (
            f"http:{name}: response={outcome!r} bytes={len(response)} "
            f"reflected={str(reflected).lower()} canary={str(canary).lower()} "
            f"service_alive={str(alive).lower()} body={normalized[:300]!r}"
        )
        print(line)
        results.append(line)
        if not alive:
            PREAUTH_ROUTE_LOG.write_text("\n".join(results) + "\n")
            raise SystemExit(10)

    results.append(
        f"httpd_control_after={str(service_alive(HOST_HTTP_PORT, b'/Main_Login.asp')).lower()}"
    )
    PREAUTH_ROUTE_LOG.write_text("\n".join(results) + "\n")
    print(results[-1])


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "command",
        choices=(
            "build", "build-layer2", "build-netool", "start", "foreground",
            "stop", "control",
            "security-probe", "extended-probe", "layer2-probe",
            "preauth-route-probe", "run",
        ),
    )
    args = parser.parse_args()
    if args.command == "build":
        build()
    elif args.command == "build-layer2":
        build(enable_l2=True)
    elif args.command == "build-netool":
        build(enable_netool=True)
    elif args.command == "start":
        start()
    elif args.command == "foreground":
        foreground()
    elif args.command == "stop":
        stop()
    elif args.command == "control":
        control()
    elif args.command == "security-probe":
        security_probe()
    elif args.command == "extended-probe":
        extended_probe()
    elif args.command == "layer2-probe":
        layer2_probe()
    elif args.command == "preauth-route-probe":
        preauth_route_probe()
    else:
        build()
        start()
        control()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
