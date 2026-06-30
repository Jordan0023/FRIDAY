from __future__ import annotations

import re
import shutil
import subprocess
from pathlib import Path

from .models import FirmwareRecord, safe_name


class FirmwareAuditor:
    def __init__(
        self,
        root: Path,
        ghidra_headless: str | None = None,
        max_ghidra_files: int = 5,
        max_extract_bytes: int | None = None,
    ) -> None:
        self.root = root
        self.ghidra_headless = ghidra_headless or _find_ghidra_headless()
        self.max_ghidra_files = max_ghidra_files
        self.max_extract_bytes = max_extract_bytes

    def audit(self, record: FirmwareRecord) -> Path:
        firmware_path = self.root / record.path
        extract_dir = self.root / "extracted" / record.sha256[:16]
        report_dir = self.root / "reports" / safe_name(record.product)
        report_dir.mkdir(parents=True, exist_ok=True)
        report_path = report_dir / f"{safe_name(record.filename)}.md"

        extraction_notes = self._extract(firmware_path, extract_dir)
        files = [p for p in extract_dir.rglob("*") if p.is_file()] if extract_dir.exists() else []
        strings = self._collect_strings(files[:200])
        findings = self._findings(strings, files)
        ghidra_notes = self._run_ghidra(files, record)

        report_path.write_text(
            self._render_report(record, firmware_path, extraction_notes, ghidra_notes, findings),
            encoding="utf-8",
        )
        return report_path

    def _extract(self, firmware_path: Path, extract_dir: Path) -> list[str]:
        notes: list[str] = []
        extract_dir.mkdir(parents=True, exist_ok=True)
        if any(extract_dir.rglob("*")):
            notes.append(f"Using existing extraction directory: {extract_dir}")
            return notes
        if shutil.which("binwalk"):
            cmd = ["binwalk", "-eM", "--directory", str(extract_dir), str(firmware_path)]
            notes.append(self._run_extract_command(cmd, extract_dir))
        else:
            notes.append("binwalk not found; extraction skipped.")
        return notes

    def _run_extract_command(self, cmd: list[str], extract_dir: Path) -> str:
        if not self.max_extract_bytes:
            result = subprocess.run(cmd, text=True, capture_output=True, timeout=1800)
            return _command_note(cmd, result)

        process = subprocess.Popen(cmd, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        try:
            stdout, stderr = process.communicate(timeout=5)
        except subprocess.TimeoutExpired:
            stdout = ""
            stderr = ""

        while process.poll() is None:
            if _directory_size(extract_dir) > self.max_extract_bytes:
                process.kill()
                tail = ""
                try:
                    _stdout, stderr = process.communicate(timeout=10)
                    tail = (stderr or "").strip().splitlines()[-1] if stderr else ""
                except subprocess.TimeoutExpired:
                    pass
                limit_mb = round(self.max_extract_bytes / (1024 * 1024))
                return f"{' '.join(cmd[:4])} stopped: extraction exceeded {limit_mb} MB" + (f": {tail}" if tail else "")
            try:
                stdout, stderr = process.communicate(timeout=5)
            except subprocess.TimeoutExpired:
                continue

        result = subprocess.CompletedProcess(cmd, process.returncode or 0, stdout, stderr)
        return _command_note(cmd, result)

    def _collect_strings(self, files: list[Path]) -> list[str]:
        strings_bin = shutil.which("strings")
        if not strings_bin:
            return []
        out: list[str] = []
        for path in files:
            if path.stat().st_size > 50 * 1024 * 1024:
                continue
            try:
                result = subprocess.run([strings_bin, "-a", str(path)], text=True, capture_output=True, timeout=20)
            except subprocess.TimeoutExpired:
                continue
            out.extend(line.strip() for line in result.stdout.splitlines() if len(line.strip()) >= 4)
            if len(out) > 250000:
                break
        return out

    def _run_ghidra(self, files: list[Path], record: FirmwareRecord) -> list[str]:
        if not self.ghidra_headless:
            return ["Ghidra analyzeHeadless not found; decompiler import skipped."]
        elf_files = [p for p in files if _is_elf(p)][: self.max_ghidra_files]
        if not elf_files:
            return ["No ELF binaries found for Ghidra import."]
        project_dir = self.root / "ghidra_projects"
        project_dir.mkdir(parents=True, exist_ok=True)
        notes: list[str] = []
        for path in elf_files:
            project_name = f"{safe_name(record.product)}_{record.sha256[:8]}"
            cmd = [
                self.ghidra_headless,
                str(project_dir),
                project_name,
                "-import",
                str(path),
                "-analysisTimeoutPerFile",
                "120",
                "-deleteProject",
            ]
            try:
                result = subprocess.run(cmd, text=True, capture_output=True, timeout=240)
                notes.append(_command_note(cmd, result))
            except subprocess.TimeoutExpired:
                notes.append(f"Ghidra timed out on {path}.")
        return notes

    def _findings(self, strings: list[str], files: list[Path]) -> list[dict[str, str]]:
        joined = "\n".join(strings)
        findings: list[dict[str, str]] = []
        rules = [
            (
                "Private keys or certificates bundled in firmware",
                r"-----BEGIN (?:RSA |DSA |EC |OPENSSH )?PRIVATE KEY-----|-----BEGIN CERTIFICATE-----",
                "Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.",
            ),
            (
                "Hard-coded credentials or secrets",
                r"(?i)\b(password|passwd|pwd|secret|apikey|api_key|token)\s*[:=]\s*['\"]?[^'\"\s]{4,}",
                "Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.",
            ),
            (
                "Remote shell services present",
                r"(?i)\b(telnetd|dropbear|sshd|inetd)\b",
                "Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.",
            ),
            (
                "HTTP CGI/admin attack surface",
                r"(?i)\b(cgi-bin|mini_httpd|boa|uhttpd|lighttpd|httpd)\b",
                "Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.",
            ),
            (
                "Command execution helpers",
                r"(?i)\b(system|popen|/bin/sh|/bin/ash|eval)\b",
                "Command execution paths are common command-injection sinks when reachable from web or network inputs.",
            ),
            (
                "Potential memory-unsafe C functions",
                r"\b(strcpy|strcat|sprintf|gets|scanf)\b",
                "Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.",
            ),
            (
                "Outdated crypto/library markers",
                r"(?i)\b(OpenSSL\s+0\.|OpenSSL\s+1\.0\.|OpenSSL\s+1\.1\.0|BusyBox v1\.(?:[0-2][0-9]|30))\b",
                "Old OpenSSL/BusyBox versions may contain known CVEs and should be mapped to package versions.",
            ),
        ]
        for title, pattern, description in rules:
            matches = sorted(set(re.findall(pattern, joined)))[:20]
            if matches:
                findings.append(
                    {
                        "title": title,
                        "description": description,
                        "evidence": ", ".join(str(m if isinstance(m, str) else m[0]) for m in matches),
                    }
                )
        if files:
            setuid = [str(p) for p in files if _mode_has_setuid(p)][:20]
            if setuid:
                findings.append(
                    {
                        "title": "Setuid files present",
                        "description": "Setuid binaries can become privilege-escalation paths if they process attacker-controlled input.",
                        "evidence": ", ".join(setuid),
                    }
                )
        return findings

    def _render_report(
        self,
        record: FirmwareRecord,
        firmware_path: Path,
        extraction_notes: list[str],
        ghidra_notes: list[str],
        findings: list[dict[str, str]],
    ) -> str:
        lines = [
            f"# Firmware Audit: {record.product} / {record.filename}",
            "",
            f"- Source URL: {record.url}",
            f"- Local path: {firmware_path}",
            f"- SHA-256: `{record.sha256}`",
            f"- Size: {record.size} bytes",
            f"- Version: {record.version or 'unknown'}",
            f"- Release date: {record.release_date or 'unknown'}",
            "",
            "## Static Findings",
            "",
        ]
        if not findings:
            lines.append("No heuristic findings were identified. This does not prove the firmware is vulnerability-free.")
        for finding in findings:
            lines.extend(
                [
                    f"### {finding['title']}",
                    "",
                    finding["description"],
                    "",
                    f"Evidence: `{finding['evidence']}`",
                    "",
                ]
            )
        lines.extend(["## Extraction Notes", ""])
        lines.extend(f"- {note}" for note in extraction_notes)
        lines.extend(["", "## Decompiler Notes", ""])
        lines.extend(f"- {note}" for note in ghidra_notes)
        lines.extend(
            [
                "",
                "## Validation Needed",
                "",
                "These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.",
                "",
            ]
        )
        return "\n".join(lines)


def _command_note(cmd: list[str], result: subprocess.CompletedProcess[str]) -> str:
    summary = " ".join(cmd[:4])
    stderr = result.stderr.strip().splitlines()[-1:] or []
    return f"{summary} exited {result.returncode}" + (f": {stderr[0]}" if stderr else "")


def _is_elf(path: Path) -> bool:
    try:
        with path.open("rb") as handle:
            return handle.read(4) == b"\x7fELF"
    except OSError:
        return False


def _mode_has_setuid(path: Path) -> bool:
    try:
        return bool(path.stat().st_mode & 0o4000)
    except OSError:
        return False


def _find_ghidra_headless() -> str | None:
    found = shutil.which("analyzeHeadless")
    if found:
        return found
    tools_dir = Path.home() / "Tools"
    for candidate in sorted(tools_dir.glob("ghidra_*_PUBLIC/support/analyzeHeadless"), reverse=True):
        if candidate.is_file():
            return str(candidate)
    return None


def _directory_size(path: Path) -> int:
    total = 0
    if not path.exists():
        return total
    for child in path.rglob("*"):
        try:
            if child.is_file():
                total += child.stat().st_size
        except OSError:
            continue
    return total
