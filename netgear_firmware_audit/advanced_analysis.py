from __future__ import annotations

import hashlib
import io
import json
import re
import tarfile
from dataclasses import asdict, dataclass, field
from pathlib import Path


TEXT_SUFFIXES = {".asp", ".cgi", ".conf", ".htm", ".html", ".js", ".json", ".lua", ".sh", ".xml"}
SINKS = {
    "command_execution": re.compile(r"\b(?:system|popen|execve|doSystem|eval)\s*\(|/bin/(?:a?sh)", re.I),
    "unsafe_memory": re.compile(r"\b(?:strcpy|strcat|sprintf|vsprintf|gets|sscanf)\b"),
    "file_write": re.compile(r"\b(?:fopen|open|write|rename|symlink|tar)\b", re.I),
    "deserialization": re.compile(r"\b(?:pickle|unserialize|json_decode|yaml_load|soap_deserialize)\b", re.I),
    "auth": re.compile(r"\b(?:login|password|passwd|auth|session|token|csrf)\b", re.I),
}
SOURCE_RE = re.compile(r"\b(?:QUERY_STRING|CONTENT_LENGTH|HTTP_COOKIE|getenv|websGetVar|cgiGetValue|nvram_get|ubus|uci_get)\b", re.I)


@dataclass(frozen=True)
class RuntimeProfile:
    vendor: str
    web_stack: list[str]
    state_backends: list[str]
    architectures: list[str]
    rootfs_candidates: list[str]
    executable_count: int


@dataclass(frozen=True)
class CorrelatedFlow:
    source_file: str
    sources: list[str]
    sinks: list[str]
    routes: list[str]
    confidence: str
    score: int


@dataclass(frozen=True)
class ValidationRecipe:
    vulnerability_class: str
    marker: str
    payloads: list[str]
    success_signal: str
    restrictions: list[str]


@dataclass(frozen=True)
class RuntimeRequirement:
    kind: str
    name: str
    value: str
    evidence: str


@dataclass(frozen=True)
class RuntimeLaunchPlan:
    vendor: str
    isolation: list[str]
    interfaces: list[dict[str, str]]
    requirements: list[RuntimeRequirement]
    startup_candidates: list[str]
    listener_candidates: list[str]


@dataclass(frozen=True)
class AuthTestCase:
    name: str
    headers: dict[str, str]
    expected_boundary: str


@dataclass(frozen=True)
class ArchiveTestCase:
    name: str
    members: list[dict[str, str]]
    expected: str


@dataclass(frozen=True)
class FuzzSeed:
    protocol: str
    route: str
    content_type: str
    template: str
    mutation_points: list[str]


@dataclass(frozen=True)
class FaultClassification:
    category: str
    signal: str | None
    fault_address: str | None
    preceding_failure: str | None
    security_relevant: bool
    rationale: str


@dataclass
class RouteProof:
    route: str
    network_reachable: bool = False
    handler_identified: bool = False
    auth_decision_proven: bool = False
    parameter_to_sink_proven: bool = False
    security_effect_reproduced: bool = False
    evidence: list[str] = field(default_factory=list)

    @property
    def level(self) -> str:
        if self.security_effect_reproduced and self.parameter_to_sink_proven:
            return "L5"
        if self.parameter_to_sink_proven and self.auth_decision_proven:
            return "L4"
        if self.parameter_to_sink_proven:
            return "L3"
        if self.handler_identified:
            return "L2"
        if self.network_reachable:
            return "L1"
        return "L0"

    @property
    def confirmed(self) -> bool:
        return self.level == "L5"


def discover_rootfs_candidates(base: Path) -> list[Path]:
    """Find real root filesystems regardless of extractor-specific directory names."""
    if not base.exists():
        return []
    candidates: list[tuple[int, Path]] = []
    for path in [base, *(p for p in base.rglob("*") if p.is_dir())]:
        try:
            score = sum((path / name).exists() for name in ("bin", "sbin", "etc", "lib", "usr", "www"))
            if score >= 3 and ((path / "bin").is_dir() or (path / "usr" / "bin").is_dir()):
                candidates.append((score, path))
        except (OSError, PermissionError):
            continue
    # Avoid returning nested copies of an already selected filesystem.
    chosen: list[Path] = []
    for _, path in sorted(candidates, key=lambda item: (-item[0], len(item[1].parts), str(item[1]))):
        if not any(parent == path or parent in path.parents for parent in chosen):
            chosen.append(path)
    return chosen


def executable_files(rootfs: Path, limit: int = 10000) -> list[Path]:
    result: list[Path] = []
    for path in rootfs.rglob("*"):
        if len(result) >= limit or not path.is_file() or path.is_symlink():
            continue
        try:
            with path.open("rb") as handle:
                magic = handle.read(4)
            if magic == b"\x7fELF" or (path.stat().st_mode & 0o111 and path.suffix in {"", ".cgi", ".sh"}):
                result.append(path)
        except OSError:
            pass
    return sorted(result, key=lambda p: (0 if any(x in p.name.lower() for x in ("http", "cgi", "web", "rpc", "ubus")) else 1, str(p)))


def profile_runtime(rootfs: Path, product: str = "") -> RuntimeProfile:
    names = {p.name.lower() for p in rootfs.rglob("*") if p.is_file()}
    product_lower = product.lower()
    vendor = "generic"
    for hint, name in (("asus", "asuswrt"), ("netgear", "netgear"), ("tp-link", "tp-link"), ("gl.inet", "openwrt")):
        if hint in product_lower:
            vendor = name
            break
    web = sorted({name for name in ("httpd", "uhttpd", "lighttpd", "nginx", "boa", "mini_httpd") if name in names})
    state = sorted({name for name in ("nvram", "ubus", "uci", "dbus", "xmldbc", "cmclient") if any(name in n for n in names)})
    arch = sorted({_elf_arch(p) for p in executable_files(rootfs, 500) if _elf_arch(p) != "unknown"})
    # The caller has already selected the extraction boundary. Searching its
    # parent can accidentally traverse unrelated, short-lived /tmp trees.
    roots = [str(p) for p in discover_rootfs_candidates(rootfs)[:10]]
    return RuntimeProfile(vendor, web, state, arch, roots, len(executable_files(rootfs)))


def correlate_flows(rootfs: Path, strings_by_file: dict[str, list[str]], routes_by_source: dict[str, list[str]]) -> list[CorrelatedFlow]:
    """Only correlate sources and sinks found in the same binary/script."""
    flows: list[CorrelatedFlow] = []
    for source_file, lines in strings_by_file.items():
        text = "\n".join(lines)
        sources = sorted(set(m.group(0) for m in SOURCE_RE.finditer(text)))
        sinks = sorted(name for name, pattern in SINKS.items() if pattern.search(text))
        routes = routes_by_source.get(source_file, [])
        if not sources or not sinks:
            continue
        score = 20 + min(len(sources) * 3, 12) + min(len(sinks) * 5, 20) + min(len(routes) * 2, 10)
        confidence = "L3-correlated" if routes else "L2-co-located"
        flows.append(CorrelatedFlow(_relative(rootfs, Path(source_file)), sources, sinks, routes, confidence, score))
    return sorted(flows, key=lambda f: (-f.score, f.source_file))


def safe_validation_recipes() -> list[ValidationRecipe]:
    restrictions = ["localhost or isolated namespace only", "no persistence", "no external network", "write only below /tmp/friday-proof"]
    return [
        ValidationRecipe("command_injection", "FRIDAY_CMD_MARKER", [";printf FRIDAY_CMD_MARKER", "$(printf FRIDAY_CMD_MARKER)"], "marker appears in captured argv/stdout", restrictions),
        ValidationRecipe("path_traversal", "FRIDAY_PATH_MARKER", ["../../tmp/friday-proof/marker", "..%2f..%2ftmp%2ffriday-proof%2fmarker"], "marker created inside modeled /tmp only", restrictions),
        ValidationRecipe("archive_escape", "FRIDAY_ARCHIVE_MARKER", ["ordered symlink then child file", "hardlink to modeled target"], "write escapes extraction root but remains inside sandbox", restrictions),
        ValidationRecipe("memory_corruption", "FRIDAY_CRASH_MARKER", ["cyclic bounded input lengths 64..4096"], "reproducible crash with instruction/register capture", restrictions),
        ValidationRecipe("auth_bypass", "FRIDAY_AUTH_MARKER", ["missing cookie", "duplicate cookie", "method override"], "protected handler returns distinct success state", restrictions),
    ]


def build_runtime_launch_plan(rootfs: Path, product: str = "") -> RuntimeLaunchPlan:
    profile = profile_runtime(rootfs, product)
    requirements: list[RuntimeRequirement] = []
    startup: list[str] = []
    listeners: set[str] = set()
    for path in sorted(rootfs.rglob("*")):
        if not path.is_file() or path.is_symlink():
            continue
        relative = _relative(rootfs, path)
        lower = relative.lower()
        if "/init.d/" in f"/{lower}" or path.name in {"rc", "preinit", "procd"}:
            startup.append(relative)
        if path.name.lower() in {"httpd", "uhttpd", "lighttpd", "nginx", "upnpd", "dnsmasq"}:
            listeners.add(relative)
        if path.name in {"nvram", "acos_nvram", "uci", "ubus"}:
            requirements.append(RuntimeRequirement("state_backend", path.name, relative, "firmware utility present"))
    text = _bounded_tree_text(rootfs)
    for key in sorted(set(re.findall(r"shmget\s*\(\s*(0x[0-9a-fA-F]+|\d+)", text))):
        requirements.append(RuntimeRequirement("sysv_shm", key, "size=derive-from-trace", "shmget call marker"))
    for device in sorted(set(re.findall(r"(/dev/[A-Za-z0-9_.-]+)", text)))[:50]:
        requirements.append(RuntimeRequirement("device", device, "stub-or-bind", "firmware path reference"))
    for port in sorted(set(re.findall(r"(?:listen|port)[^\n]{0,24}\b(\d{2,5})\b", text, re.I)))[:30]:
        requirements.append(RuntimeRequirement("listener", f"tcp/{port}", "isolated", "port/listen marker"))
    return RuntimeLaunchPlan(
        vendor=profile.vendor,
        isolation=["no external network", "no host ports by default", "disposable writable rootfs", "synthetic LAN client"],
        interfaces=[{"name": "br0", "address": "192.168.250.1/24"}, {"name": "probe", "address": "192.168.250.2/32"}],
        requirements=requirements[:100],
        startup_candidates=startup[:50],
        listener_candidates=sorted(listeners),
    )


def auth_test_matrix() -> list[AuthTestCase]:
    return [
        AuthTestCase("no_credentials", {}, "must not enter protected handler"),
        AuthTestCase("invalid_session", {"Cookie": "session=FRIDAY_INVALID", "Authorization": "Bearer FRIDAY_INVALID"}, "must match unauthenticated behavior"),
        AuthTestCase("low_privilege", {"Cookie": "session=FRIDAY_LOW_PRIV"}, "must not cross administrator boundary"),
    ]


def archive_test_cases() -> list[ArchiveTestCase]:
    return [
        ArchiveTestCase("dotdot", [{"name": "../../tmp/friday-proof/dotdot", "type": "file"}], "extractor rejects or confines member"),
        ArchiveTestCase("absolute", [{"name": "/tmp/friday-proof/absolute", "type": "file"}], "extractor rejects or strips absolute path"),
        ArchiveTestCase("symlink_pivot", [{"name": "pivot", "type": "symlink", "target": "../../tmp/friday-proof"}, {"name": "pivot/marker", "type": "file"}], "no write through symlink outside extraction root"),
        ArchiveTestCase("hardlink", [{"name": "marker", "type": "hardlink", "target": "../../tmp/friday-proof/hardlink"}], "hardlink target remains confined"),
        ArchiveTestCase("duplicate", [{"name": "same", "type": "file"}, {"name": "same", "type": "symlink", "target": "../../tmp/friday-proof"}], "duplicate type replacement is rejected"),
        ArchiveTestCase("long_name", [{"name": "A" * 240, "type": "file"}], "bounded rejection or confined extraction"),
        ArchiveTestCase("nested_archive", [{"name": "nested.tar", "type": "archive"}], "no implicit recursive extraction"),
    ]


def generate_archive_corpus(output: Path) -> list[Path]:
    output.mkdir(parents=True, exist_ok=True)
    written: list[Path] = []
    for case in archive_test_cases():
        target = output / f"{case.name}.tar"
        with tarfile.open(target, "w") as archive:
            for member in case.members:
                info = tarfile.TarInfo(member["name"])
                kind = member["type"]
                if kind == "symlink":
                    info.type = tarfile.SYMTYPE
                    info.linkname = member["target"]
                    archive.addfile(info)
                elif kind == "hardlink":
                    info.type = tarfile.LNKTYPE
                    info.linkname = member["target"]
                    archive.addfile(info)
                else:
                    payload = b"FRIDAY_ARCHIVE_MARKER"
                    info.size = len(payload)
                    archive.addfile(info, io.BytesIO(payload))
        written.append(target)
    manifest = output / "manifest.json"
    manifest.write_text(json.dumps([asdict(case) for case in archive_test_cases()], indent=2) + "\n", encoding="utf-8")
    written.append(manifest)
    return written


def build_fuzz_seeds(routes: list[str], params_by_route: dict[str, list[str]] | None = None) -> list[FuzzSeed]:
    params_by_route = params_by_route or {}
    seeds: list[FuzzSeed] = []
    for route in sorted(set(routes)):
        params = params_by_route.get(route, [])[:20]
        body = "&".join(f"{name}=FRIDAY_{index}" for index, name in enumerate(params))
        seeds.append(FuzzSeed("http", route, "application/x-www-form-urlencoded", f"POST /{route.lstrip('/')} HTTP/1.1\r\nHost: router.local\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: {{length}}\r\n\r\n{body}", params or ["path", "headers", "body"] ))
        if "soap" in route.lower() or "upnp" in route.lower():
            seeds.append(FuzzSeed("soap", route, "text/xml", "<s:Envelope><s:Body><Action><Value>FRIDAY_VALUE</Value></Action></s:Body></s:Envelope>", ["SOAPAction", "Action", "Value"]))
        if any(word in route.lower() for word in ("upload", "import", "restore", "cert")):
            seeds.append(FuzzSeed("multipart", route, "multipart/form-data", "--FRIDAY\r\nContent-Disposition: form-data; name=\"file\"; filename=\"seed.bin\"\r\n\r\nFRIDAY_FILE\r\n--FRIDAY--", ["filename", "part_name", "file_bytes"]))
    return seeds[:500]


def classify_trace(trace: str) -> FaultClassification:
    signal_match = re.findall(r"---\s+(SIG[A-Z]+).*?si_addr=(0x[0-9a-fA-F]+)", trace)
    failures = re.findall(r"^.*(?:ENOENT|EINVAL|ENODEV|EACCES|Connection refused|No such file).*$", trace, re.M)
    signal, address = signal_match[-1] if signal_match else (None, None)
    preceding = failures[-1].strip() if failures else None
    if signal and preceding and re.search(r"shm(?:get|at)|/dev/|ENODEV|ENOENT", preceding):
        return FaultClassification("emulation_dependency", signal, address, preceding, False, "fault immediately follows a missing runtime dependency")
    if signal and address and int(address, 16) < 0x10000:
        return FaultClassification("null_or_low_address", signal, address, preceding, False, "low fault address without demonstrated attacker control")
    if signal:
        return FaultClassification("security_crash_candidate", signal, address, preceding, True, "signal requires reproducibility and input-to-fault correlation")
    if re.search(r"HTTP/\d(?:\.\d)?\s+[45]\d\d", trace):
        return FaultClassification("handled_rejection", None, None, preceding, False, "target returned a handled client/server error")
    return FaultClassification("no_fault", None, None, preceding, False, "no terminating signal found")


def dynamic_sink_spec() -> list[dict[str, object]]:
    return [
        {"symbols": ["system", "popen", "execve"], "capture": ["pc", "argv", "route", "auth_state"]},
        {"symbols": ["memcpy", "strcpy", "sprintf"], "capture": ["pc", "destination", "source", "length", "before", "after"]},
        {"symbols": ["open", "fopen", "rename", "symlink"], "capture": ["pc", "path", "flags", "sandbox_escape"]},
        {"symbols": ["shmget", "shmat", "nvram_set", "uci_set"], "capture": ["pc", "key", "size", "return_value"]},
    ]


def variant_matches(trees: dict[str, Path]) -> list[dict[str, object]]:
    by_hash: dict[str, list[tuple[str, str]]] = {}
    for product, rootfs in trees.items():
        for relative, digest in fingerprint_tree(rootfs).items():
            by_hash.setdefault(digest, []).append((product, relative))
    return [
        {"sha256": digest, "occurrences": [{"product": product, "path": path} for product, path in sorted(items)]}
        for digest, items in sorted(by_hash.items()) if len({product for product, _ in items}) > 1
    ]


def confirmation_policy() -> dict[str, object]:
    return {
        "confirmed_label_requires": "L5",
        "confirmed_zero_day_requires": [
            "L5 reproducible security effect with fault/sink attribution",
            "novel reproducible pre-authentication exploitation path with no remote administrator session required",
            "LAN or WAN network reachability without credentials",
            "impact is remote code execution or a reliable input-specific denial of service",
            "denial of service reproduces from attacker input and is not generic resource exhaustion",
            "documented, dated public-prior-art search",
            "no matching public disclosure or publicly available fix at the recorded discovery time",
        ],
        "authenticated_admin_disposition": "confirmed vulnerability, but not a confirmed zero-day",
        "vendor_contact_required": False,
        "private_duplicate_caveat": "public novelty does not exclude an unknown private or embargoed duplicate",
        "L3": "route-specific attacker parameter reaches the sink",
        "L4": "authentication/validation boundary and trigger are proven",
        "L5": "reproducible security effect with fault/sink attribution",
        "forbidden_shortcut": "route string and dangerous symbol merely co-located in a binary",
        "impactful_hunt_scope": "unauthenticated LAN/WAN RCE or reliable input-specific denial of service",
    }


def fingerprint_tree(rootfs: Path) -> dict[str, str]:
    result: dict[str, str] = {}
    for path in executable_files(rootfs):
        try:
            result[_relative(rootfs, path)] = hashlib.sha256(path.read_bytes()).hexdigest()
        except OSError:
            pass
    return result


def diff_fingerprints(old: dict[str, str], new: dict[str, str]) -> dict[str, list[str]]:
    return {
        "added": sorted(set(new) - set(old)),
        "removed": sorted(set(old) - set(new)),
        "changed": sorted(path for path in set(old) & set(new) if old[path] != new[path]),
        "unchanged": sorted(path for path in set(old) & set(new) if old[path] == new[path]),
    }


def write_fingerprint(path: Path, rootfs: Path) -> None:
    path.write_text(json.dumps(fingerprint_tree(rootfs), indent=2, sort_keys=True) + "\n", encoding="utf-8")


def _elf_arch(path: Path) -> str:
    try:
        data = path.read_bytes()[:20]
    except OSError:
        return "unknown"
    if data[:4] != b"\x7fELF" or len(data) < 20:
        return "script" if path.suffix in {".cgi", ".sh"} else "unknown"
    endian = "little" if data[5] == 1 else "big"
    machine = int.from_bytes(data[18:20], endian)
    return {8: "mipsel" if endian == "little" else "mips", 40: "arm", 62: "x86_64", 183: "aarch64"}.get(machine, f"elf-{machine}")


def _relative(rootfs: Path, path: Path) -> str:
    try:
        return str(path.relative_to(rootfs))
    except ValueError:
        return str(path)


def _bounded_tree_text(rootfs: Path, limit: int = 300) -> str:
    chunks: list[str] = []
    for path in sorted(rootfs.rglob("*")):
        if len(chunks) >= limit or not path.is_file() or path.is_symlink():
            continue
        if path.suffix.lower() not in TEXT_SUFFIXES and path.name not in {"rc", "inittab", "services"}:
            continue
        try:
            chunks.append(path.read_text(encoding="utf-8", errors="ignore")[:100_000])
        except OSError:
            pass
    return "\n".join(chunks)
