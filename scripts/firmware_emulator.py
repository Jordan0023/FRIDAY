#!/usr/bin/env python3
from __future__ import annotations

import argparse
import html
import json
import os
import re
import shutil
import subprocess
import sys
import urllib.error
import urllib.request
from dataclasses import dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
KNOWN = ROOT / "known_firmware"
LOCAL_HOSTS = {"127.0.0.1", "localhost", "::1"}


@dataclass
class FirmwareTarget:
    product: str
    filename: str
    sha256: str
    rootfs: Path
    arch: str
    emulator: str | None
    web_binaries: list[Path]
    cgi_files: list[Path]
    notes: list[str]


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Inventory and safely validate extracted firmware under local emulation."
    )
    sub = parser.add_subparsers(dest="command", required=True)

    sub.add_parser("inventory", help="List emulation targets and missing prerequisites.")

    plan = sub.add_parser("plan", help="Show safe commands for manually launching candidate web services.")
    plan.add_argument("--product", help="Only show plans for one product, e.g. AC1450.")

    cgi = sub.add_parser("cgi-smoke", help="Run non-mutating GET-style CGI smoke tests under QEMU.")
    cgi.add_argument("--product", required=True, help="Product to test, e.g. BE9300.")
    cgi.add_argument("--limit", type=int, default=5, help="Maximum CGI files to smoke test.")

    probe = sub.add_parser("probe-http", help="Run safe localhost-only HTTP probes against a launched service.")
    probe.add_argument("--base-url", required=True, help="Local URL, e.g. http://127.0.0.1:8080")
    probe.add_argument("--product", help="Use paths discovered for a specific product.")

    launch = sub.add_parser("launch-web", help="Launch a localhost-only lighttpd instance for one firmware.")
    launch.add_argument("--product", required=True, help="Product to launch, e.g. BE9300.")
    launch.add_argument("--port", type=int, default=8080, help="Localhost port to bind.")
    launch.add_argument("--static-only", action="store_true", help="Serve static web files without CGI backend.")

    args = parser.parse_args()
    targets = discover_targets()

    if args.command == "inventory":
        print_inventory(targets)
        return 0
    if args.command == "plan":
        print_plan(filter_targets(targets, args.product))
        return 0
    if args.command == "cgi-smoke":
        return cgi_smoke(filter_targets(targets, args.product), args.limit)
    if args.command == "probe-http":
        return probe_http(args.base_url, filter_targets(targets, args.product))
    if args.command == "launch-web":
        return launch_web(filter_targets(targets, args.product), args.port, args.static_only)
    return 2


def discover_targets() -> list[FirmwareTarget]:
    manifest = json.loads((KNOWN / "manifest.json").read_text(encoding="utf-8"))
    targets: list[FirmwareTarget] = []
    for record in sorted(manifest.get("firmware", {}).values(), key=lambda r: (r["product"], r["filename"])):
        sha = record["sha256"]
        extracted = KNOWN / "extracted" / sha[:16]
        rootfs_candidates = sorted(extracted.rglob("squashfs-root*")) if extracted.exists() else []
        rootfs_dirs = [path for path in rootfs_candidates if path.is_dir() and (path / "bin").exists()]
        if not rootfs_dirs:
            targets.append(
                FirmwareTarget(
                    product=record["product"],
                    filename=record["filename"],
                    sha256=sha,
                    rootfs=extracted,
                    arch="unknown",
                    emulator=None,
                    web_binaries=[],
                    cgi_files=[],
                    notes=["No extracted root filesystem found."],
                )
            )
            continue
        for rootfs in rootfs_dirs:
            web_binaries = find_web_binaries(rootfs)
            cgi_files = find_cgi_files(rootfs)
            arch = detect_arch(web_binaries or executable_files(rootfs)[:20])
            emulator = emulator_for_arch(arch)
            notes = []
            if arch == "unknown":
                notes.append("Architecture could not be identified from executable files.")
            elif not emulator:
                notes.append(f"Missing emulator for {arch}; install qemu-user-static to run binaries.")
            if not web_binaries and not cgi_files:
                notes.append("No obvious web service or CGI entry points found.")
            targets.append(
                FirmwareTarget(
                    product=record["product"],
                    filename=record["filename"],
                    sha256=sha,
                    rootfs=rootfs,
                    arch=arch,
                    emulator=emulator,
                    web_binaries=web_binaries,
                    cgi_files=cgi_files,
                    notes=notes,
                )
            )
    return targets


def find_web_binaries(rootfs: Path) -> list[Path]:
    names = {"httpd", "boa", "mini_httpd", "uhttpd", "lighttpd", "net-cgi"}
    matches = []
    for path in rootfs.rglob("*"):
        if path.is_file() and path.name in names and is_binary_candidate(path):
            matches.append(path)
    return sorted(matches)


def is_binary_candidate(path: Path) -> bool:
    try:
        result = subprocess.run(["file", str(path)], text=True, capture_output=True, timeout=10)
    except (OSError, subprocess.TimeoutExpired):
        return False
    return "ELF" in result.stdout


def find_cgi_files(rootfs: Path) -> list[Path]:
    matches = []
    www = rootfs / "www"
    if not www.exists():
        return matches
    for path in www.rglob("*"):
        if path.is_file() and (path.name.endswith(".cgi") or "cgi-bin" in path.parts):
            matches.append(path)
    return sorted(matches)


def executable_files(rootfs: Path) -> list[Path]:
    return sorted(path for path in rootfs.rglob("*") if path.is_file() and os.access(path, os.X_OK))


def detect_arch(paths: list[Path]) -> str:
    for path in paths:
        try:
            result = subprocess.run(["file", str(path)], text=True, capture_output=True, timeout=10)
        except (OSError, subprocess.TimeoutExpired):
            continue
        text = result.stdout
        if "ARM" in text:
            return "arm"
        if "MIPS" in text and "LSB" in text:
            return "mipsel"
        if "MIPS" in text:
            return "mips"
        if "AArch64" in text:
            return "aarch64"
        if "Intel 80386" in text or "x86-64" in text:
            return "native"
    return "unknown"


def emulator_for_arch(arch: str) -> str | None:
    candidates = {
        "arm": ("qemu-arm-static", "qemu-arm"),
        "aarch64": ("qemu-aarch64-static", "qemu-aarch64", "qemu-arm64"),
        "mips": ("qemu-mips-static", "qemu-mips"),
        "mipsel": ("qemu-mipsel-static", "qemu-mipsel"),
        "native": "",
    }
    binaries = candidates.get(arch)
    if binaries == "":
        return "native"
    if not binaries:
        return None
    for binary in binaries:
        found = shutil.which(binary)
        if found:
            return found
    return None


def print_inventory(targets: list[FirmwareTarget]) -> None:
    for target in targets:
        print(f"{target.product}: {target.filename}")
        print(f"  rootfs: {target.rootfs}")
        print(f"  arch: {target.arch}")
        print(f"  emulator: {target.emulator or 'not available'}")
        print(f"  web binaries: {len(target.web_binaries)}")
        for path in target.web_binaries[:6]:
            print(f"    - /{path.relative_to(target.rootfs)}")
        print(f"  CGI files: {len(target.cgi_files)}")
        for path in target.cgi_files[:6]:
            print(f"    - /{path.relative_to(target.rootfs)}")
        for note in target.notes:
            print(f"  note: {note}")
        print()


def print_plan(targets: list[FirmwareTarget]) -> None:
    for target in targets:
        print(f"{target.product}: {target.filename}")
        if target.emulator is None:
            print("  Cannot run yet: install qemu-user-static for this architecture.")
        for binary in target.web_binaries:
            rel = "/" + str(binary.relative_to(target.rootfs))
            if target.emulator == "native":
                prefix = str(binary)
            elif target.emulator:
                prefix = f"{target.emulator} -L {target.rootfs} {binary}"
            else:
                prefix = f"<qemu-for-{target.arch}> -L {target.rootfs} {binary}"
            print(f"  candidate: {rel}")
            print(f"    cd {target.rootfs}")
            print(f"    {prefix}")
        print("  Probe only with localhost URLs, for example:")
        print(f"    python3 scripts/firmware_emulator.py probe-http --product {target.product} --base-url http://127.0.0.1:8080")
        print()


def cgi_smoke(targets: list[FirmwareTarget], limit: int) -> int:
    if not targets:
        print("No matching firmware target.")
        return 1
    failures = 0
    for target in targets:
        if not target.cgi_files:
            print(f"{target.product}: no CGI files discovered.")
            continue
        if not target.emulator:
            print(f"{target.product}: cannot run CGI smoke tests; emulator missing for {target.arch}.")
            failures += 1
            continue
        for cgi in target.cgi_files[:limit]:
            env = os.environ.copy()
            env.update(
                {
                    "REQUEST_METHOD": "GET",
                    "QUERY_STRING": "",
                    "SCRIPT_NAME": "/" + str(cgi.relative_to(target.rootfs)),
                    "SERVER_NAME": "localhost",
                    "SERVER_PORT": "8080",
                    "REMOTE_ADDR": "127.0.0.1",
                    "DOCUMENT_ROOT": str(target.rootfs / "www"),
                }
            )
            cmd = [str(cgi)] if target.emulator == "native" else [target.emulator, "-L", str(target.rootfs), str(cgi)]
            try:
                result = subprocess.run(
                    cmd,
                    cwd=target.rootfs,
                    env=env,
                    text=True,
                    capture_output=True,
                    timeout=10,
                )
            except subprocess.TimeoutExpired:
                print(f"{target.product} / {cgi.name}: timeout")
                failures += 1
                continue
            print(f"{target.product} / {cgi.name}: exit {result.returncode}, stdout {len(result.stdout)} bytes, stderr {len(result.stderr)} bytes")
    return 1 if failures else 0


def probe_http(base_url: str, targets: list[FirmwareTarget]) -> int:
    parsed_host = urllib.request.urlparse(base_url).hostname
    if parsed_host not in LOCAL_HOSTS:
        print("Refusing to probe non-localhost target. Use 127.0.0.1 or localhost.")
        return 2
    paths = ["/", "/index.htm", "/debug.htm", "/unauth.cgi"]
    for target in targets:
        paths.extend("/" + str(path.relative_to(target.rootfs / "www")) for path in target.cgi_files[:10] if (target.rootfs / "www") in path.parents)
    seen = []
    for path in paths:
        if path not in seen:
            seen.append(path)
    for path in seen:
        url = base_url.rstrip("/") + path
        req = urllib.request.Request(url, headers={"User-Agent": "firmware-emulator/1.0"})
        try:
            with urllib.request.urlopen(req, timeout=5) as response:
                body = response.read(512)
                print(f"{response.status} {path} {len(body)} sample-bytes")
        except urllib.error.HTTPError as exc:
            print(f"{exc.code} {path}")
        except OSError as exc:
            print(f"ERR {path}: {exc}")
    return 0


def launch_web(targets: list[FirmwareTarget], port: int, static_only: bool = False) -> int:
    if port < 1024 or port > 65535:
        print("Refusing to bind privileged or invalid port; choose 1024-65535.")
        return 2
    if static_only:
        return launch_static_web(targets, port)
    target = next((item for item in targets if any(path.name == "lighttpd" for path in item.web_binaries)), None)
    if not target:
        print("No lighttpd target found for this product.")
        return 1
    if not target.emulator:
        print(f"Cannot launch: emulator missing for {target.arch}.")
        return 1
    return launch_chroot_lighttpd(target, port)


def launch_chroot_lighttpd(target: FirmwareTarget, port: int) -> int:
    rootfs = target.rootfs
    qemu = Path(target.emulator or "")
    qemu_guest = "/usr/bin/" + qemu.name
    config_guest = "/tmp/emulator-lighttpd.conf"
    prepare_chroot_runtime(target, port, qemu)
    shell = f"""
set -e
ROOT={sh_quote(str(rootfs))}
mount --bind {sh_quote(str(qemu))} "$ROOT{qemu_guest}"
for pair in "mke2fs:mke2fs" "openssl:openssl"; do
  stub="${{pair%%:*}}"
  tool="${{pair#*:}}"
  if [ -e "$ROOT/bin/$tool" ] && [ ! -L "$ROOT/bin/$tool" ] && [ -e "$ROOT/tmp/emulator-bin/$stub" ]; then
    mount --bind "$ROOT/tmp/emulator-bin/$stub" "$ROOT/bin/$tool"
  fi
done
if [ -e "$ROOT/usr/bin/openssl" ] && [ ! -L "$ROOT/usr/bin/openssl" ] && [ -e "$ROOT/tmp/emulator-bin/openssl" ]; then
  mount --bind "$ROOT/tmp/emulator-bin/openssl" "$ROOT/usr/bin/openssl"
fi
if [ -e "$ROOT/usr/sbin/cryptsetup" ] && [ ! -L "$ROOT/usr/sbin/cryptsetup" ] && [ -e "$ROOT/tmp/emulator-bin/cryptsetup" ]; then
  mount --bind "$ROOT/tmp/emulator-bin/cryptsetup" "$ROOT/usr/sbin/cryptsetup"
fi
cd "$ROOT"
echo "Launching {target.product} full CGI emulator on http://127.0.0.1:{port}"
echo "Rootfs: $ROOT"
chroot "$ROOT" /bin/sh -c 'export PATH=/tmp/emulator-bin:/bin:/sbin:/usr/bin:/usr/sbin; {qemu_guest} -L / /usr/sbin/lighttpd -m /usr/lib/lighttpd -f {config_guest} -D'
"""
    subprocess.run(
        ["unshare", "--map-root-user", "--user", "--mount", "--ipc", "--fork", "--pid", "--mount-proc", "bash", "-lc", shell],
        check=False,
    )
    return 0


def prepare_chroot_runtime(target: FirmwareTarget, port: int, qemu: Path) -> None:
    rootfs = target.rootfs
    ensure_runtime_path(rootfs / "tmp")
    ensure_runtime_path(rootfs / "tmp" / "var" / "run")
    ensure_runtime_path(rootfs / "tmp" / "secure" / "etc" / "lighttpd" / "certs")
    ensure_runtime_path(rootfs / "tmp" / "secure" / "etc" / "sso")
    ensure_runtime_path(rootfs / "tmp" / "kdata")
    ensure_runtime_path(rootfs / "etc" / "lighttpd" / "certs")
    ensure_runtime_path(rootfs / "tmp" / "emulator-bin")
    ensure_runtime_path(rootfs / "usr" / "bin")
    ensure_runtime_path(rootfs / "dev")
    ensure_runtime_path(rootfs / "proc")
    ensure_runtime_path(rootfs / "sys" / "block" / "mmcblk0")
    null_path = rootfs / "dev" / "null"
    if not null_path.exists():
        null_path.touch()
    mtd_path = rootfs / "proc" / "mtd"
    if not mtd_path.exists():
        mtd_path.write_text(
            "dev:    size   erasesize  name\n"
            "mtd0: 00100000 00020000 \"boot\"\n"
            "mtd1: 00100000 00020000 \"pot\"\n"
            "mtd2: 00200000 00020000 \"language\"\n"
            "mtd3: 00400000 00020000 \"firmware\"\n",
            encoding="utf-8",
        )
    (rootfs / "tmp" / "kdata" / ".secure-key").write_text("emulator\n", encoding="utf-8")
    server_pem = rootfs / "etc" / "lighttpd" / "certs" / "server.pem"
    if not server_pem.exists():
        server_pem.write_text("emulator\n", encoding="utf-8")
    write_runtime_stubs(rootfs / "tmp" / "emulator-bin")
    qemu_target = rootfs / "usr" / "bin" / qemu.name
    if not qemu_target.exists():
        qemu_target.touch()
    config = rootfs / "tmp" / "emulator-lighttpd.conf"
    config.write_text(
        "\n".join(
            [
                'server.modules = ( "mod_setenv", "mod_rewrite", "mod_cgi" )',
                'setenv.add-environment = ( "PATH" => "/tmp/emulator-bin:/bin:/sbin:/usr/bin:/usr/sbin" )',
                'server.document-root = "/www"',
                'server.upload-dirs = ( "/tmp" )',
                'server.errorlog = "/tmp/emulator-lighttpd-error.log"',
                'server.pid-file = "/tmp/emulator-lighttpd.pid"',
                'server.bind = "127.0.0.1"',
                f"server.port = {port}",
                'index-file.names = ( "index.php", "index.html", "start.htm", "home.html", "index.htm", "default.htm" )',
                'static-file.exclude-extensions = ( ".php", ".pl", ".fcgi" )',
                'url.rewrite = (',
                '  "^.*/api/([^?]*)\\?_=(.*)$" => "restapi?$1 timestamp=$2",',
                '  "^.*/api/([^?]*)$" => "restapi?$1",',
                '  "^.*/shares([^?]*)$" => "/shares?/shares$1",',
                '  "^.*/soap/server_sa/?$" => "/soapapi"',
                ")",
                'cgi.assign = ( "" => "/usr/sbin/net-cgi" )',
                'cgi.x-sendfile = "enable"',
                'cgi.x-sendfile-docroot = ( "/www/", "/tmp/mnt/" )',
                "",
            ]
        ),
        encoding="utf-8",
    )


def ensure_runtime_path(path: Path) -> None:
    if path.is_symlink():
        target = os.readlink(path)
        if target == "/dev/null":
            path.unlink()
            path.mkdir(parents=True, exist_ok=True)
            return
    path.mkdir(parents=True, exist_ok=True)


def write_runtime_stubs(stub_dir: Path) -> None:
    stubs = {
        "ntgrcryptwd": "#!/bin/sh\nmkdir -p /tmp/kdata /tmp/secure/etc/lighttpd/certs /tmp/secure/etc/sso\ntouch /tmp/kdata/.secure-key\nexit 0\n",
        "part_dev": "#!/bin/sh\ncase \"$1\" in\n  language) echo /dev/mtd2 ;;\n  pot) echo /dev/mtd1 ;;\n  firmware|image) echo /dev/mtd3 ;;\n  *) echo /dev/mtd0 ;;\nesac\nexit 0\n",
        "mkfs.ext4": "#!/bin/sh\nexit 0\n",
        "mke2fs": "#!/bin/sh\nexit 0\n",
        "cryptsetup": "#!/bin/sh\nexit 0\n",
        "mount": "#!/bin/sh\nexit 0\n",
        "umount": "#!/bin/sh\nexit 0\n",
        "openssl": "#!/bin/sh\nmkdir -p /tmp/secure/etc/lighttpd/certs\ncat > /tmp/secure/etc/lighttpd/certs/server.pem <<'EOF'\n-----BEGIN PRIVATE KEY-----\n-----END PRIVATE KEY-----\n-----BEGIN CERTIFICATE-----\n-----END CERTIFICATE-----\nEOF\nexit 0\n",
    }
    for name, content in stubs.items():
        path = stub_dir / name
        path.write_text(content, encoding="utf-8")
        path.chmod(0o755)


def sh_quote(value: str) -> str:
    return "'" + value.replace("'", "'\"'\"'") + "'"


def launch_static_web(targets: list[FirmwareTarget], port: int) -> int:
    target = next((item for item in targets if (item.rootfs / "www").is_dir()), None)
    if not target:
        print("No static /www directory found for this product.")
        return 1
    www = target.rootfs / "www"
    view_dir = build_static_view(target, www)
    print(f"Launching {target.product} static web view on http://127.0.0.1:{port}")
    print(f"Serving: {view_dir}")
    print("Static mode does not execute firmware CGI/backend code.")
    cmd = [
        sys.executable,
        "-m",
        "http.server",
        str(port),
        "--bind",
        "127.0.0.1",
        "--directory",
        str(view_dir),
    ]
    subprocess.run(cmd, check=False)
    return 0


def build_static_view(target: FirmwareTarget, www: Path) -> Path:
    view_dir = KNOWN / "logs" / f"emulator-{target.product.lower()}-view"
    rendered_dir = view_dir / "rendered"
    view_dir.mkdir(parents=True, exist_ok=True)
    rendered_dir.mkdir(parents=True, exist_ok=True)
    link = view_dir / "firmware"
    if link.exists() or link.is_symlink():
        if link.is_symlink():
            link.unlink()
        elif link.is_dir():
            shutil.rmtree(link)
        else:
            link.unlink()
    link.symlink_to(www, target_is_directory=True)

    pages = select_static_pages(www)
    rendered_pages = render_static_pages(www, rendered_dir, pages)
    first_page = choose_first_page(pages, rendered_dir)
    cards = "\n".join(
        f'<button class="page-button" data-path="{html.escape(rendered_pages.get(path, "firmware/" + path))}">'
        f"<strong>{html.escape(label)}</strong><span>{html.escape(path)}</span></button>"
        for label, path in pages
    )
    (view_dir / "index.html").write_text(
        f"""<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>{html.escape(target.product)} Emulator</title>
    <style>
      * {{ box-sizing: border-box; }}
      body {{
        margin: 0;
        min-width: 320px;
        background: #eef2f5;
        color: #17202a;
        font-family: Inter, ui-sans-serif, system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
      }}
      header {{
        display: flex;
        align-items: center;
        justify-content: space-between;
        gap: 12px;
        padding: 12px 16px;
        background: #18212b;
        color: #fff;
      }}
      h1 {{ margin: 0; font-size: 20px; line-height: 1.2; }}
      .meta {{ margin-top: 3px; color: #adc4ce; font-size: 12px; }}
      .shell {{
        display: grid;
        grid-template-columns: 280px minmax(0, 1fr);
        gap: 10px;
        padding: 10px;
        height: calc(100vh - 61px);
      }}
      aside, main {{
        min-height: 0;
        background: #fff;
        border: 1px solid #d7dee6;
        border-radius: 8px;
        overflow: hidden;
      }}
      .toolbar {{
        display: grid;
        gap: 8px;
        padding: 10px;
        border-bottom: 1px solid #d7dee6;
      }}
      input {{
        width: 100%;
        min-height: 34px;
        padding: 0 10px;
        border: 1px solid #d7dee6;
        border-radius: 6px;
        font: inherit;
      }}
      .pages {{
        display: grid;
        gap: 6px;
        max-height: calc(100vh - 142px);
        overflow: auto;
        padding: 10px;
      }}
      .page-button {{
        display: grid;
        gap: 2px;
        width: 100%;
        padding: 8px 10px;
        border: 1px solid #d7dee6;
        border-radius: 6px;
        background: #f8fafb;
        color: #17202a;
        text-align: left;
        cursor: pointer;
      }}
      .page-button:hover, .page-button.active {{ border-color: #0f766e; background: #ecf7f5; }}
      .page-button strong {{ font-size: 13px; }}
      .page-button span {{ color: #667381; font-size: 12px; overflow-wrap: anywhere; }}
      .frame-head {{
        display: flex;
        align-items: center;
        justify-content: space-between;
        gap: 8px;
        min-height: 42px;
        padding: 8px 10px;
        border-bottom: 1px solid #d7dee6;
      }}
      #currentPath {{ color: #667381; font-size: 12px; overflow-wrap: anywhere; }}
      a {{
        color: #0f766e;
        font-size: 13px;
        font-weight: 700;
        text-decoration: none;
      }}
      iframe {{
        display: block;
        width: 100%;
        height: calc(100% - 42px);
        border: 0;
        background: #fff;
      }}
      @media (max-width: 820px) {{
        .shell {{ grid-template-columns: 1fr; height: auto; }}
        .pages {{ max-height: 260px; }}
        main {{ height: 70vh; }}
      }}
    </style>
  </head>
  <body>
    <header>
      <div>
        <h1>{html.escape(target.product)} Static Emulator</h1>
        <div class="meta">Static firmware web files only. CGI/backend code is not executed.</div>
      </div>
      <a href="firmware/" target="_blank" rel="noreferrer">Raw files</a>
    </header>
    <section class="shell">
      <aside>
        <div class="toolbar">
          <input id="search" type="search" placeholder="Search pages">
        </div>
        <div id="pages" class="pages">{cards}</div>
      </aside>
      <main>
        <div class="frame-head">
          <span id="currentPath">{html.escape(rendered_pages.get(first_page, "firmware/" + first_page))}</span>
          <a id="openPage" href="firmware/{html.escape(first_page)}" target="_blank" rel="noreferrer">Raw</a>
        </div>
        <iframe id="preview" src="{html.escape(rendered_pages.get(first_page, "firmware/" + first_page))}" title="Firmware page preview"></iframe>
      </main>
    </section>
    <script>
      const buttons = Array.from(document.querySelectorAll(".page-button"));
      const preview = document.querySelector("#preview");
      const currentPath = document.querySelector("#currentPath");
      const openPage = document.querySelector("#openPage");
      const search = document.querySelector("#search");
      function select(button) {{
        buttons.forEach((item) => item.classList.toggle("active", item === button));
        const path = button.dataset.path;
        preview.src = path;
        currentPath.textContent = path;
        openPage.href = path;
      }}
      buttons.forEach((button, index) => {{
        button.addEventListener("click", () => select(button));
        if (index === 0) select(button);
      }});
      search.addEventListener("input", () => {{
        const query = search.value.toLowerCase();
        buttons.forEach((button) => {{
          button.hidden = !button.textContent.toLowerCase().includes(query);
        }});
      }});
    </script>
  </body>
</html>
""",
        encoding="utf-8",
    )
    return view_dir


def render_static_pages(www: Path, rendered_dir: Path, pages: list[tuple[str, str]]) -> dict[str, str]:
    rendered: dict[str, str] = {}
    for _, rel in pages:
        source = www / rel
        if not source.is_file() or source.suffix.lower() not in {".htm", ".html"}:
            continue
        target = rendered_dir / rel
        target.parent.mkdir(parents=True, exist_ok=True)
        text = source.read_text(encoding="utf-8", errors="ignore")
        target.write_text(sanitize_firmware_template(text), encoding="utf-8")
        rendered[rel] = "rendered/" + rel
    return rendered


def choose_first_page(pages: list[tuple[str, str]], rendered_dir: Path) -> str:
    preferred = ["index.htm", "home.html", "BAS_basic.htm", "WAN_wan.htm", "LAN_lan.htm", "WLG_wireless.htm"]
    available = {path for _, path in pages}
    for path in preferred:
        if path in available and (rendered_dir / path).stat().st_size > 500:
            return path
    for _, path in pages:
        rendered = rendered_dir / path
        if rendered.exists() and rendered.stat().st_size > 500:
            return path
    return pages[0][1] if pages else "firmware/"


def sanitize_firmware_template(text: str) -> str:
    text = re.sub(r"<%.*?%>", "", text, flags=re.S)
    text = re.sub(r"\$[A-Za-z_][A-Za-z0-9_]*", "", text)
    text = re.sub(r"(?m)^\s{2,}$", "", text)
    marker = "</head>"
    style = """
<style>
  body { margin: 0 !important; }
  body::before {
    content: "Static preview: router-side template directives have been hidden.";
    display: block;
    padding: 8px 10px;
    background: #fff4db;
    color: #7a4b00;
    border-bottom: 1px solid #ecd08a;
    font: 12px Inter, system-ui, sans-serif;
  }
</style>
"""
    if marker in text:
        text = text.replace(marker, style + marker, 1)
    return text


def select_static_pages(www: Path) -> list[tuple[str, str]]:
    preferred = [
        "start.htm",
        "index.htm",
        "home.html",
        "BAS_basic.htm",
        "WAN_wan.htm",
        "LAN_lan.htm",
        "WLG_wireless.htm",
        "FW_forward.htm",
        "debug.htm",
        "RST_status.htm",
        "UPG_check_version.htm",
    ]
    pages: list[tuple[str, str]] = []
    seen: set[str] = set()
    for name in preferred:
        if (www / name).is_file():
            pages.append((label_for_page(name), name))
            seen.add(name)
    for path in sorted(www.glob("*.htm"))[:80]:
        rel = path.name
        if rel not in seen:
            pages.append((label_for_page(rel), rel))
            seen.add(rel)
    for path in sorted(www.glob("*.html"))[:40]:
        rel = path.name
        if rel not in seen:
            pages.append((label_for_page(rel), rel))
            seen.add(rel)
    return pages[:90]


def label_for_page(name: str) -> str:
    stem = Path(name).stem
    words = stem.replace("_", " ").replace("-", " ").split()
    return " ".join(word.upper() if len(word) <= 3 else word.capitalize() for word in words) or name


def filter_targets(targets: list[FirmwareTarget], product: str | None) -> list[FirmwareTarget]:
    if not product:
        return targets
    needle = product.upper()
    return [target for target in targets if target.product.upper() == needle]


if __name__ == "__main__":
    raise SystemExit(main())
