from __future__ import annotations

import json
import re
import subprocess
from dataclasses import asdict, dataclass
from pathlib import Path


@dataclass(frozen=True)
class KnownVulnerability:
    id: str
    product_pattern: str
    affected_versions: tuple[str, ...]
    fixed_in: str | None
    route: str
    parameter: str
    vulnerability_class: str
    auth: str
    references: tuple[str, ...]


@dataclass
class KnownCoverage:
    vulnerability: KnownVulnerability
    applicability: str
    route_present: bool
    parameter_present: bool
    notes: str


@dataclass
class RouteCandidate:
    route: str
    source: str
    parameters: list[str]
    matched_keywords: list[str]
    score: int
    evidence_level: str
    recommended_checks: list[str]


@dataclass
class ZeroDayTriage:
    rootfs: str
    known_coverage: list[KnownCoverage]
    candidates: list[RouteCandidate]
    sink_summary: dict[str, int]
    config_writers: list[str]
    notes: list[str]

    def to_json(self) -> str:
        return json.dumps(asdict(self), indent=2, sort_keys=True)


KNOWN_VULNERABILITIES: tuple[KnownVulnerability, ...] = (
    KnownVulnerability(
        id="CVE-2016-6277",
        product_pattern=r"\bR7000\b",
        affected_versions=("1.0.7.2",),
        fixed_in=None,
        route="/cgi-bin/;COMMAND",
        parameter="path",
        vulnerability_class="unauthenticated command injection",
        auth="none",
        references=("https://www.kb.cert.org/vuls/id/582384",),
    ),
    KnownVulnerability(
        id="CVE-2024-35520",
        product_pattern=r"\bR7000\b",
        affected_versions=("1.0.11.136",),
        fixed_in=None,
        route="RMT_invite.cgi",
        parameter="device_name2",
        vulnerability_class="command injection",
        auth="post-auth",
        references=("https://nvd.nist.gov/vuln/detail/CVE-2024-35520",),
    ),
    KnownVulnerability(
        id="NETGEAR-PSV-2023-0154",
        product_pattern=r"\bR7000\b",
        affected_versions=(),
        fixed_in="1.0.11.216",
        route="unknown",
        parameter="unknown",
        vulnerability_class="post-authentication command injection",
        auth="admin",
        references=(
            "https://kb.netgear.com/000066027/Security-Advisory-for-Post-Authentication-Command-Injection-on-the-R7000-PSV-2023-0154",
        ),
    ),
    KnownVulnerability(
        id="NETGEAR-PSV-2024-0013",
        product_pattern=r"\bR7000\b",
        affected_versions=(),
        fixed_in="1.0.11.216",
        route="unknown",
        parameter="unknown",
        vulnerability_class="post-authentication command injection",
        auth="admin",
        references=(
            "https://kb.netgear.com/000066083/Security-Advisory-for-Post-Authentication-Command-Injection-on-R7000-PSV-2024-0013",
        ),
    ),
)


ROUTE_RE = re.compile(
    r"""(?ix)
    (?:action|href|src)\s*=\s*["']?([^"'\s>]*?(?:cgi|cgi-bin|debug|openvpn|vpn|pppoe|wan|usb|readycloud)[^"'\s>]*)|
    \b([A-Za-z0-9_.-]+\.cgi)\b
    """
)
PARAM_RE = re.compile(r"""(?ix)\b(?:name|id)\s*=\s*["']?([A-Za-z0-9_.:-]{2,80})""")
SINK_PATTERNS = {
    "system": re.compile(r"\bsystem\b|/bin/sh|/bin/ash|\bsh -c\b", re.I),
    "popen": re.compile(r"\bpopen\b", re.I),
    "exec": re.compile(r"\bexec(?:l|le|lp|v|ve|vp)?\b", re.I),
    "unsafe_copy": re.compile(r"\b(?:strcpy|strcat|sprintf|gets|scanf)\b"),
    "file_write": re.compile(r"\b(?:fopen|fprintf|fputs|write)\b"),
}
RISK_KEYWORDS = {
    "command": 5,
    "debug": 4,
    "readycloud": 4,
    "vpn": 4,
    "openvpn": 4,
    "upload": 4,
    "upgrade": 4,
    "fw": 3,
    "wan": 3,
    "gateway": 3,
    "dns": 3,
    "ddns": 3,
    "ntp": 3,
    "ping": 3,
    "traceroute": 3,
    "usb": 3,
    "share": 3,
    "samba": 3,
    "pppoe": 3,
    "telnet": 3,
    "remote": 2,
    "hidden": 2,
}
RISK_PARAMS = {
    "cmd",
    "command",
    "host",
    "hostname",
    "ip",
    "addr",
    "address",
    "gateway",
    "wan_gateway",
    "apmode_gateway",
    "dns",
    "ddns",
    "ntp_server",
    "user_ntp_server",
    "device_name",
    "device_name2",
    "openvpn_push1",
    "path",
    "filename",
    "share_name",
}
CONFIG_MARKERS = (
    "openvpn",
    "server.conf",
    "client.conf",
    "dnsmasq.conf",
    "smb.conf",
    "iptables",
    "firewall",
    "crontab",
    "udhcpd.conf",
    "lighttpd.conf",
)


def analyze_zero_day_surface(rootfs: Path, product: str = "", version: str | None = None) -> ZeroDayTriage:
    rootfs = rootfs.resolve()
    files = [path for path in rootfs.rglob("*") if path.is_file()] if rootfs.exists() else []
    sample_files = _sample_files(files)
    strings_by_file = _collect_strings(sample_files)
    routes = _discover_routes(rootfs, sample_files, strings_by_file)
    all_params = _discover_parameters(rootfs, sample_files)
    sink_summary = _summarize_sinks(strings_by_file)
    config_writers = _find_config_writers(strings_by_file)
    known = _known_coverage(product, version, routes, all_params)
    candidates = _score_routes(routes, all_params, sink_summary)
    notes = [
        "Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.",
        "This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.",
    ]
    return ZeroDayTriage(
        rootfs=str(rootfs),
        known_coverage=known,
        candidates=candidates,
        sink_summary=sink_summary,
        config_writers=config_writers[:50],
        notes=notes,
    )


def render_zero_day_markdown(triage: ZeroDayTriage) -> str:
    lines = [
        "## Zero-day Triage",
        "",
        "This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.",
        "",
        "### Known Vulnerability Coverage",
        "",
    ]
    if not triage.known_coverage:
        lines.append("No known-vulnerability catalog entries matched this product name.")
    for item in triage.known_coverage:
        vuln = item.vulnerability
        lines.extend(
            [
                f"#### {vuln.id}",
                "",
                f"- Class: {vuln.vulnerability_class}",
                f"- Applicability: {item.applicability}",
                f"- Route present: {'yes' if item.route_present else 'no'} (`{vuln.route}`)",
                f"- Parameter present: {'yes' if item.parameter_present else 'no'} (`{vuln.parameter}`)",
                f"- Auth/precondition: {vuln.auth}",
                f"- Notes: {item.notes}",
                f"- References: {', '.join(vuln.references)}",
                "",
            ]
        )
    lines.extend(["### High-priority New Candidates", ""])
    if not triage.candidates:
        lines.append("No route candidates were identified.")
    for candidate in triage.candidates[:30]:
        params = ", ".join(candidate.parameters[:12]) if candidate.parameters else "none discovered"
        keywords = ", ".join(candidate.matched_keywords) if candidate.matched_keywords else "none"
        checks = "; ".join(candidate.recommended_checks)
        lines.extend(
            [
                f"#### `{candidate.route}`",
                "",
                f"- Score: {candidate.score}",
                f"- Evidence level: {candidate.evidence_level}",
                f"- Source: {candidate.source}",
                f"- Parameters: {params}",
                f"- Matched risk keywords: {keywords}",
                f"- Next checks: {checks}",
                "",
            ]
        )
    lines.extend(["### Sink Summary", ""])
    for name, count in sorted(triage.sink_summary.items()):
        lines.append(f"- {name}: {count}")
    lines.extend(["", "### Config Writer Leads", ""])
    if triage.config_writers:
        lines.extend(f"- `{item}`" for item in triage.config_writers[:30])
    else:
        lines.append("No config-writer markers found in sampled strings.")
    lines.extend(["", "### Triage Notes", ""])
    lines.extend(f"- {note}" for note in triage.notes)
    lines.append("")
    return "\n".join(lines)


def _sample_files(files: list[Path]) -> list[Path]:
    priority = []
    rest = []
    for path in files:
        rel = "/".join(path.parts[-4:]).lower()
        if any(key in rel for key in ("www", "cgi", "httpd", "net-cgi", "boa", "lighttpd", "rc", "init.d")):
            priority.append(path)
        else:
            rest.append(path)
    return (priority + rest)[:1500]


def _collect_strings(files: list[Path]) -> dict[str, list[str]]:
    strings_by_file: dict[str, list[str]] = {}
    strings_bin = _which_strings()
    for path in files:
        try:
            if path.stat().st_size > 25 * 1024 * 1024:
                continue
        except OSError:
            continue
        text = ""
        if path.suffix.lower() in {".htm", ".html", ".js", ".asp", ".cgi", ".sh", ".conf", ".xml"}:
            try:
                text = path.read_text(encoding="utf-8", errors="ignore")
            except OSError:
                continue
        elif strings_bin:
            try:
                result = subprocess.run([strings_bin, "-a", str(path)], text=True, capture_output=True, timeout=10)
            except (OSError, subprocess.TimeoutExpired):
                continue
            text = result.stdout
        if text:
            strings_by_file[str(path)] = [line.strip() for line in text.splitlines() if len(line.strip()) >= 3][:5000]
    return strings_by_file


def _discover_routes(rootfs: Path, files: list[Path], strings_by_file: dict[str, list[str]]) -> dict[str, str]:
    routes: dict[str, str] = {}
    www = rootfs / "www"
    if www.exists():
        for path in www.rglob("*"):
            if path.is_file() and (path.name.endswith(".cgi") or "cgi-bin" in path.parts):
                routes.setdefault(_normalize_route(path.name), f"file:{path.relative_to(rootfs)}")
    for path in files:
        lines = strings_by_file.get(str(path), [])
        if not lines:
            continue
        source = _short_source(rootfs, path)
        for line in lines[:5000]:
            for match in ROUTE_RE.finditer(line):
                route = match.group(1) or match.group(2)
                if route:
                    routes.setdefault(_normalize_route(route), source)
    return dict(sorted(routes.items()))


def _discover_parameters(rootfs: Path, files: list[Path]) -> dict[str, list[str]]:
    params_by_route: dict[str, set[str]] = {}
    for path in files:
        if path.suffix.lower() not in {".htm", ".html", ".js", ".asp", ".cgi"}:
            continue
        try:
            text = path.read_text(encoding="utf-8", errors="ignore")
        except OSError:
            continue
        params = {m.group(1) for m in PARAM_RE.finditer(text)}
        routes = {_normalize_route(m.group(1) or m.group(2)) for m in ROUTE_RE.finditer(text) if (m.group(1) or m.group(2))}
        if not routes and path.name.endswith(".cgi"):
            routes = {_normalize_route(path.name)}
        for route in routes:
            params_by_route.setdefault(route, set()).update(params)
    return {route: sorted(values) for route, values in sorted(params_by_route.items())}


def _summarize_sinks(strings_by_file: dict[str, list[str]]) -> dict[str, int]:
    summary = {name: 0 for name in SINK_PATTERNS}
    for lines in strings_by_file.values():
        text = "\n".join(lines)
        for name, pattern in SINK_PATTERNS.items():
            summary[name] += len(pattern.findall(text))
    return summary


def _find_config_writers(strings_by_file: dict[str, list[str]]) -> list[str]:
    leads: set[str] = set()
    for source, lines in strings_by_file.items():
        for line in lines:
            lower = line.lower()
            if any(marker in lower for marker in CONFIG_MARKERS):
                leads.add(f"{Path(source).name}: {line[:160]}")
    return sorted(leads)


def _known_coverage(
    product: str,
    version: str | None,
    routes: dict[str, str],
    params_by_route: dict[str, list[str]],
) -> list[KnownCoverage]:
    product_text = product or ""
    route_text = "\n".join(routes)
    param_text = "\n".join(param for params in params_by_route.values() for param in params)
    coverage: list[KnownCoverage] = []
    for vuln in KNOWN_VULNERABILITIES:
        if product_text and not re.search(vuln.product_pattern, product_text, re.I):
            continue
        applicability = _version_applicability(version, vuln)
        route_present = vuln.route != "unknown" and vuln.route.lower() in route_text.lower()
        parameter_present = vuln.parameter != "unknown" and vuln.parameter.lower() in param_text.lower()
        notes = "Known entry matched product; use route and parameter evidence to decide whether this exact issue carries over."
        if applicability == "tested version appears newer than listed fixed version":
            notes = "Known issue exists for this product family; tested version appears newer than the listed fixed release, so focus on patch regression or variants."
        coverage.append(KnownCoverage(vuln, applicability, route_present, parameter_present, notes))
    return coverage


def _score_routes(
    routes: dict[str, str],
    params_by_route: dict[str, list[str]],
    sink_summary: dict[str, int],
) -> list[RouteCandidate]:
    candidates: list[RouteCandidate] = []
    dangerous_sinks_present = sum(sink_summary.get(name, 0) for name in ("system", "popen", "exec")) > 0
    for route, source in routes.items():
        route_lower = route.lower()
        params = params_by_route.get(route, [])
        matched = [key for key in RISK_KEYWORDS if key in route_lower]
        score = 0
        score += 5 if route_lower.endswith(".cgi") or "cgi-bin" in route_lower else 0
        score += sum(RISK_KEYWORDS[key] for key in matched)
        risky_params = [param for param in params if param.lower() in RISK_PARAMS or any(key in param.lower() for key in RISK_PARAMS)]
        score += min(len(risky_params) * 3, 12)
        if dangerous_sinks_present:
            score += 3
        if "debug" in route_lower or "hidden" in route_lower:
            score += 2
        if score < 8:
            continue
        level = "L2" if dangerous_sinks_present else ("L1" if params else "L0")
        checks = [
            "map route to handler and auth gate",
            "trace each risky parameter into command/file/memory sinks",
        ]
        if dangerous_sinks_present:
            checks.append("prove or reject parameter-to-system/popen/exec flow")
        if any(key in route_lower for key in ("vpn", "dns", "ddns", "ntp", "share", "usb")):
            checks.append("check daemon config injection and service restart behavior")
        candidates.append(
            RouteCandidate(
                route=route,
                source=source,
                parameters=params,
                matched_keywords=matched,
                score=score,
                evidence_level=level,
                recommended_checks=checks,
            )
        )
    return sorted(candidates, key=lambda item: (-item.score, item.route))


def _version_applicability(version: str | None, vuln: KnownVulnerability) -> str:
    if not version:
        return "unknown tested version"
    normalized = _normalize_version(version)
    affected = {_normalize_version(item) for item in vuln.affected_versions}
    if normalized in affected:
        return "known affected version"
    if vuln.fixed_in and _compare_versions(normalized, _normalize_version(vuln.fixed_in)) >= 0:
        return "tested version appears newer than listed fixed version"
    if vuln.affected_versions or vuln.fixed_in:
        return "version not listed as known affected"
    return "product-family advisory; affected range not encoded"


def _normalize_version(version: str) -> str:
    match = re.search(r"(\d+(?:\.\d+){1,5})", version)
    return match.group(1) if match else version


def _compare_versions(left: str, right: str) -> int:
    left_parts = [int(part) for part in re.findall(r"\d+", left)]
    right_parts = [int(part) for part in re.findall(r"\d+", right)]
    width = max(len(left_parts), len(right_parts))
    left_parts.extend([0] * (width - len(left_parts)))
    right_parts.extend([0] * (width - len(right_parts)))
    return (left_parts > right_parts) - (left_parts < right_parts)


def _normalize_route(route: str) -> str:
    route = route.strip().strip("'\"")
    route = route.split("?", 1)[0]
    route = re.sub(r"^https?://[^/]+", "", route)
    route = route.lstrip("./")
    return route or "/"


def _short_source(rootfs: Path, path: Path) -> str:
    try:
        return f"string:{path.relative_to(rootfs)}"
    except ValueError:
        return f"string:{path}"


def _which_strings() -> str | None:
    for candidate in ("/usr/bin/strings", "/bin/strings"):
        if Path(candidate).exists():
            return candidate
    return None
